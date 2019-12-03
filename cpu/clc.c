#include "mos6502.h"

static int clc(mos6502_t *cpu)
{
    mos6502_set_flag(cpu, CARRY, 0);
    return 2;
}

void mos6502_register_clc(mos6502_t *cpu)
{
    mos6502_register_opcode(cpu, 0x18, clc);
}

#ifdef _TEST

static int test_clc(mos6502_t *cpu)
{
    mos6502_set_flag(cpu, CARRY, 1);
    mos6502_write8(cpu, 0x8000, 0x18);
    int ticks = mos6502_tick(cpu);

    return ticks == 2 && mos6502_get_flag(cpu, CARRY) == 0 && cpu->pc == 0x8001;
}

void test_mos6502_clc(mos6502_t *cpu)
{
    RUN_TEST(test_clc);
}

#endif