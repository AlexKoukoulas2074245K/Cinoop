#pragma once

#define FLAGS_ZERO 0x80 // 1 << 7
#define FLAGS_NEGATIVE 0x40 // 1 << 6
#define FLAGS_HALFCARRY 0x20 // 1 << 5
#define FLAGS_CARRY 0x10 // 1 << 4

#define FLAGS_ISZERO		(registers.f & FLAGS_ZERO)
#define FLAGS_ISNEGATIVE	(registers.f & FLAGS_NEGATIVE)
#define FLAGS_ISCARRY		(registers.f & FLAGS_CARRY)
#define FLAGS_ISHALFCARRY	(registers.f & FLAGS_HALFCARRY)

#define FLAGS_ISSET(x)	(registers.f & (x))
#define FLAGS_SET(x)	(registers.f |= (x))
#define FLAGS_CLEAR(x)	(registers.f &= ~(x))

struct instruction {
	char *disassembly;
	unsigned char operandLength;
	void *execute;
	//unsigned char ticks;
} extern const instructions[256];

extern const unsigned char instructionTicks[256];

extern unsigned long ticks;

void reset(void);
void cpuStep(void);

void nop(void);
void dec_b(void);
void ld_b_n(unsigned char operand);
void dec_c(void);
void ld_c_n(unsigned char operand);
void jr_nz_n(char operand);
void ld_hl_nn(unsigned short operand);
void ld_sp_nn(unsigned short operand);
void ldd_hlp_a(void);
void ld_hlp_n(unsigned char operand);
void inc_a(void);
void ld_a_n(unsigned char operand);
void ld_b_e(void);
void xor_a(void);
void jp_nn(unsigned short operand);
void ld_ff_n_ap(unsigned char operand);
void ld_nnp_a(unsigned short operand);
void ld_ff_ap_n(unsigned char operand);
void di(void);
void ei(void);
void cp_n(unsigned char operand);
