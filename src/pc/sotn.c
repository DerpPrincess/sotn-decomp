#include "pc.h"
#include "dra.h"
#include "servant.h"
#include "sfx.h"
#include <SDL2/SDL.h>

extern SDL_Window* g_Window;
extern SDL_Renderer* g_Renderer;
bool g_IsQuitRequested;
int g_Frame = 0;

void HandleTitle();
void HandlePlay();

GameApi g_ApiInit = {0};
Equipment g_EquipDefs[0x100] = {0};
Accessory g_AccessoryDefs[0x100] = {0};
RelicDesc g_RelicDefs[0x100] = {0};
void (*D_80170000)(s32 arg0); // ServantDesc D_80170000 = {0};
Weapon D_8017A000 = {0};
Weapon D_8017D000 = {0};

void StageOvlCb() {
    SetGameState(Game_NowLoading);
    g_GameStep = NowLoading_2;
}

void WeaponLoadPaletteStub(s32 arg0) { NOT_IMPLEMENTED; }

// list of exposed API
void FreePrimitives(s32 index);
s32 AllocPrimitives(u8 primType, s32 count);
s32 func_800EA5E4(u32);
void LoadGfxAsync(s32 gfxId);
void func_800EA538(s32 arg0);
void func_8010DFF0(s32 arg0, s32 arg1);
void DebugInputWait(const char* msg);

// stub to the original UpdateGame
void func_800F298C() { PlaySfx(MU_REQUIEM_FOR_THE_GODS); }

int MyDrawSync(int mode) {
    SDL_RenderPresent(g_Renderer);
    SDL_RenderSetScale(g_Renderer, SCREEN_SCALE, SCREEN_SCALE);

    // SDL event handling
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            g_IsQuitRequested = 1;
            break;
        }
    }
    // Clear the renderer
    SDL_SetRenderDrawColor(g_Renderer, 0, 0, 0, 255);
    SDL_RenderClear(g_Renderer);

    DEBUGF("-------------------- frame %d --------------------", g_Frame);
    DEBUGF("state: %d, game step: %d", g_GameState, g_GameStep);

    g_Frame++;
    return 0;
}

// called before MainGame
void InitGame() {
    // These two are necessary to make HandleTitle working
    GameApi api;
    api.FreePrimitives = FreePrimitives;
    api.AllocPrimitives = AllocPrimitives;
    api.CheckCollision = NULL;
    api.func_80102CD8 = NULL;
    api.UpdateAnim = NULL;
    api.SetSpeedX = NULL;
    api.GetFreeDraEntity = NULL;
    api.GetEquipProperties = NULL;
    api.func_800EA5E4 = func_800EA5E4;
    api.LoadGfxAsync = LoadGfxAsync;
    api.PlaySfx = NULL;
    api.func_800EDB58 = NULL;
    api.func_800EA538 = func_800EA538;
    api.g_pfn_800EA5AC = NULL;
    api.func_801027C4 = NULL;
    api.func_800EB758 = NULL;
    api.CreateEntFactoryFromEntity = NULL;
    api.func_80131F68 = NULL;
    api.func_800EDB08 = NULL;
    api.func_80106A28 = NULL;
    api.func_80118894 = NULL;
    api.enemyDefs = NULL;
    api.func_80118970 = NULL;
    api.func_80118B18 = NULL;
    api.UpdateUnarmedAnim = NULL;
    api.func_8010DBFC = NULL;
    api.func_80118C28 = NULL;
    api.func_8010E168 = NULL;
    api.func_8010DFF0 = func_8010DFF0;
    api.DealDamage = NULL;
    api.LoadEquipIcon = NULL;
    api.equipDefs = g_EquipDefs;
    api.accessoryDefs = g_AccessoryDefs;
    api.AddHearts = NULL;
    api.LoadMonsterLibrarianPreview = NULL;
    api.TimeAttackController = NULL;
    api.func_8010E0A8 = NULL;
    api.func_800FE044 = NULL;
    api.AddToInventory = NULL;
    api.relicDefs = g_RelicDefs;
    api.InitStatsAndGear = NULL;
    api.func_80134714 = NULL;
    api.func_80134678 = NULL;
    api.func_800F53A4 = NULL;
    api.CheckEquipmentItemCount = NULL;
    api.func_8010BF64 = NULL;
    api.func_800F1FC4 = NULL;
    api.func_800F2288 = NULL;
    api.func_8011A3AC = NULL;
    api.func_800FF460 = NULL;
    api.func_800FF494 = NULL;
    api.CdSoundCommandQueueEmpty = NULL;
    api.func_80133950 = NULL;
    api.func_800F27F4 = NULL;
    api.func_800FF110 = NULL;
    api.func_800FD664 = NULL;
    api.func_800FD5BC = NULL;
    api.LearnSpell = NULL;
    api.DebugInputWait = DebugInputWait;
    api.unused12C = NULL;
    api.unused130 = NULL;
    api.unused134 = NULL;
    api.unused138 = NULL;
    api.unused13C = NULL;
    api.o.Update = NULL;
    api.o.TestCollisions = StageOvlCb;
    api.o.unk08 = NULL;
    api.o.InitRoomEntities = StageOvlCb;
    api.o.rooms = NULL;
    api.o.spriteBanks = NULL;
    api.o.cluts = NULL;
    api.o.unk1C = NULL;
    api.o.tileLayers = NULL;
    api.o.gfxBanks = NULL;
    api.o.unk28 = NULL;
    api.o.unk2c = NULL;
    api.o.unk30 = NULL;
    api.o.unk34 = NULL;
    api.o.unk38 = NULL;
    api.o.unk3C = NULL;
    memcpy(&g_ApiInit, &api, sizeof(g_ApiInit));

    D_8017A000.LoadWeaponPalette = WeaponLoadPaletteStub;
    D_8017D000.LoadWeaponPalette = WeaponLoadPaletteStub;
}