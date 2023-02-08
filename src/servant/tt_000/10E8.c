#include "servant.h"

u16 D_80170448[];
Sprite D_80170608[];
s32 D_80171090;

void func_80171ED4(s32 arg0);
void func_80172120(Entity* self);
void func_80172C30(Entity* self);
void func_8017339C(void);
void func_801733A4(void);
void func_801733AC(void);
void func_801733B4(void);
void func_801733BC(void);
void func_801733C4(void);
void func_801733CC(void);
void func_801733D4(Entity* self);
void func_80173C0C(void);
void func_80173C14(void);
void func_80173C1C(void);
void func_80173C24(void);
void func_80173C2C(Entity* self);

ServantDesc g_ServantDesc = {
    func_80171ED4, func_80172120, func_80172C30, func_8017339C,
    func_801733A4, func_801733AC, func_801733B4, func_801733BC,
    func_801733C4, func_801733CC, func_801733D4, func_80173C0C,
    func_80173C14, func_80173C1C, func_80173C24, func_80173C2C,
};

void func_80174210(s32 arg0, s32 arg1);
s32 func_80174864(void);

void func_801710E8(Entity* entity, s32* arg1) {
    if (entity->unk4C != arg1) {
        entity->unk4C = arg1;
        entity->animationFrameIndex = 0;
        entity->animationFrameDuration = 0;
    }
}

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_8017110C);

s32 func_801713C8(Entity* entity);
#ifndef NON_EQUIVALENT
INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_801713C8);
#else
s32 func_801713C8(Entity* entity) {
    s32 ret;

    ret = 0;
    if (entity->unk3C != 0) {
        ret = 0;

        if (entity->posX.i.hi < -0x10)
            return 0;
        if (entity->posX.i.hi > 0x110)
            return 0;

        ret = 0;
        if (entity->posY.i.hi > 0xF0 ||
            entity->posY.i.hi >= 0 &&
                (ret = entity->hitPoints > 0, !(entity->hitPoints < 0x7000))) {
            ret = 0;
        }
    }
    return ret;
}
#endif

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_80171434);

void func_80171560(void) {}

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_80171568);

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_8017160C);

void func_8017170C(Entity* entity, s32 frameIndex) {
    POLY_GT4* poly;
    s32 tpage;
    s32 x;
    s32 y;
    s32 index;

    poly = &D_80086FEC[entity->firstPolygonIndex];
    if (frameIndex == 0) {
        poly->pad3 = 8;
        return;
    }
    index = frameIndex - 1;
    if (entity->facing != 0) {
        x = entity->posX.i.hi + 2;
    } else {
        x = entity->posX.i.hi - 16;
    }
    y = entity->posY.i.hi - 16;

    poly->x0 = poly->x2 = x - D_80170608[index].x;
    poly->y0 = poly->y1 = y - D_80170608[index].y;
    poly->x1 = poly->x3 = poly->x0 + D_80170608[index].width;
    poly->y2 = poly->y3 = poly->y0 + D_80170608[index].height;
    poly->clut = D_80170608[index].clut;
    tpage = D_80170608[index].tpage;
    if (tpage < 0) {
        tpage += 3;
    }
    poly->tpage = tpage >> 2;
    poly->u0 = poly->u2 = D_80170608[index].texLeft;
    poly->v0 = poly->v1 = D_80170608[index].texTop;
    poly->u1 = poly->u3 = D_80170608[index].texRight;
    poly->v2 = poly->v3 = D_80170608[index].texBottom;
    poly->pad2 = entity->zPriority + 1;
    poly->pad3 = 0x102;
}

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_801718A0);

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_801719E0);

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_80171ED4);

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_80172120);

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_80172C30);

void func_8017339C(void) {}

void func_801733A4(void) {}

void func_801733AC(void) {}

void func_801733B4(void) {}

void func_801733BC(void) {}

void func_801733C4(void) {}

void func_801733CC(void) {}

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_801733D4);

void func_80173C0C(void) {}

void func_80173C14(void) {}

void func_80173C1C(void) {}

void func_80173C24(void) {}

extern s32 D_80174D3C;

void func_80173C2C(Entity* entity) {
    if (entity->subId == 0xF) {
        D_80174D3C = 1;
    }
    DestroyEntity(entity);
}

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_80173C64);

void DestroyEntity(Entity* entity) {
    s32 i;
    s32 length;
    u32* ptr;

    if (entity->unk34 & 0x800000) {
        g_api.FreePolygons(entity->firstPolygonIndex);
    }

    ptr = (u32*)entity;
    length = sizeof(Entity) / sizeof(u32);
    for (i = 0; i < length; i++)
        *ptr++ = 0;
}

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_80173E78);

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_80173EB0);

s32 func_80173F30(Entity* entity, s16 arg1, s16 arg2);
INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_80173F30);

#ifndef NON_EQUIVALENT
INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_80173F74);
#else
s32 func_80173F74(s16 arg0, s16 arg1, s16 arg2) {
    s32 new_var2;
    s16 new_var;
    s16 var_v0_2;
    s16 var_v0;

    new_var2 = arg1 - arg0;
    var_v0_2 = new_var2;
    if (new_var2 < 0) {
        var_v0_2 = -var_v0_2;
    }
    new_var = var_v0_2;
    if (new_var < arg2) {
        arg2 = var_v0_2;
    }
    if (arg1 < arg0) {
        var_v0 = arg2 + arg1;
        if (arg0 >= 0x800) {
            var_v0 = arg1 - arg2;
        }
    } else {
        var_v0 = arg2 + arg1;
        if (arg0 < 0x800) {
            var_v0 = arg1 - arg2;
        }
    }
    return var_v0 & 0xFFF;
}
#endif

s32 func_80173FE8(Entity* entity, s32 x, s32 y) {
    s32 diffX = x - entity->posX.i.hi;
    s32 diffY = y - entity->posY.i.hi;

    return SquareRoot12((diffX * diffX + diffY * diffY) << 12, diffX) >> 12;
}

// PSY-Q 3.5 match as in GCC a jump skips a 'nop'
#ifndef NON_MATCHING
INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_80174038);
#else
void func_80174038(Entity* entity) {
    switch (entity->step) {
    case 0:
        entity->unk34 = 0x04020000;
        if (D_8003C704 == 0) {
            if (g_api.func_80133940() != 0) {
                g_api.PlaySfx(16);
                entity->step++;
            }
        }
        break;

    case 1:
        if (g_api.func_80133950() != 0) {
            entity->step++;
        }
        break;
    case 2:
        g_api.PlaySfx(entity->subId);
        entity->step++;
        break;

    case 3:
        if (g_api.func_80131F68() != 0) {
            entity->step++;
        }
        break;

    case 4:
        if (g_api.func_80131F68() == 0) {
            entity->step++;
        }
        break;

    case 5:
        if ((D_8003C708 & 0x60) != 0) {
            D_80171090 = 99;
            DestroyEntity(entity);
            return;
        }
        if (g_api.func_80133940() != 0) {
            g_api.PlaySfx(17);
            entity->step++;
        }
        break;

    case 6:
        if (g_api.func_80133950() != 0) {
            D_80171090 = 99;
            DestroyEntity(entity);
            return;
        }
        break;

    case 7:
        g_api.PlaySfx(10);
        entity->step = 4;
        break;

    case 8:
        D_80171090 = 99;
        DestroyEntity(entity);
        return;
    }

    D_80171090 = (s32)entity->step;
}
#endif

// TODO func_80174210
INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_80174210);

void func_801745E4(Entity* entityParent, u16 objectId, u16 subId);
INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_801745E4);

// PSY-Q 3.5 match as in GCC a jump skips a 'nop'
#ifndef NON_MATCHING
INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_801746A0);
#else
s32 func_801746A0(s32 arg0) {
    if (D_800733E4 < 0 && !(*D_80072F20 & 1))
        return 1;

    if (D_800733E4 > 0 && !(*D_80072F20 & 2))
        return 1;

    if (D_800733E0 < 0 && !(*D_80072F20 & 8))
        return 1;

    if (D_800733E0 > 0 && !(*D_80072F20 & 4))
        return 1;

    if (arg0 == 0)
        return 0;

    if (D_80072F70 != D_80073404)
        return 1;

    if (D_80072F70 != 0)
        return 1;

    if (D_80072F72 != D_80073406)
        return 1;

    return D_80072F72 != 0 && D_80072F72 != 4;
}
#endif

INCLUDE_ASM("config/../asm/servant/tt_000/nonmatchings/10E8", func_801747B8);

s32 func_80174864(void) {
    int tmp;

    if (g_StageId - 0x20 < 0x15) {
        if (D_8003C708 == 0x22) {
            return 1;
        }

        tmp = (D_8003C708 != 0x20) * 2;
        return tmp;
    }

    if (D_8003C708 == 0x22) {
        return 0;
    }

    tmp = 0x20;
    return D_8003C708 != tmp ? 2 : 1;
}