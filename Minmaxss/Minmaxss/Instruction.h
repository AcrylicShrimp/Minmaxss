
/*
	2018.08.04
	Created by AcrylicShrimp.
*/

#ifndef _ENUM_MINMAXSS_INSTRUCTION_H

#define _ENUM_MINMAXSS_INSTRUCTION_H

#include "Endianess.h"

#include <cstdint>
#include <vector>

namespace Minmaxss
{
	enum class Instruction : std::uint8_t
	{
		//Reserved
		PASS,

		//Memory
		FILL,
		LOAD,
		STORE,
		PUSH,
		POP,

		//Manipulation
		COPY,
		ZERO,
		INC,
		DEC,

		//Arithmetic
		NEG,
		ADD,
		SUB,
		MUL,
		DIV,
		MOD,

		//Bitwise
		NOT,
		XOR,
		AND,
		OR,
		SHL,
		SHR,
		SHRS,

		//Flow
		RET,
		CALLA,
		CALLR,
		JUMP,
		JZ,
		JNZ,
		JE,
		JNE,
		JA,
		JAE,
		JB,
		JBE,
		JG,
		JGE,
		JL,
		JLE
	};

	using Register = std::uint8_t;

	class InstructionList final
	{
	private:
		std::vector<std::uint8_t> sBuffer;

	public:
		InstructionList() = default;
		InstructionList(const InstructionList &sSrc) = default;
		InstructionList(InstructionList &&sSrc) = default;
		~InstructionList() = default;

	public:
		InstructionList &operator=(const InstructionList &sSrc) = default;
		InstructionList &operator=(InstructionList &&sSrc) = default;

	public:
		//Reserved
		void pass();

		//Memory
		void fill(Register rDst, std::uint8_t nValue);
		void fill(Register rDst, std::uint16_t nValue);
		void fill(Register rDst, std::uint32_t nValue);
		void fill(Register rDst, std::uint64_t nValue);
		void load(Register rDst, Register rAddr);
		void store(Register rAddr, Register rSrc);
		void push(Register rValue);
		void pop(Register rValue);

		//Manipulation
		void copy(Register rDst, Register rSrc);
		void zero(Register rValue);
		void inc(Register rValue);
		void dec(Register rValue);

		//Arithmetic
		void neg(Register rValue);
		void add(Register rDst, Register rSrc1, Register rSrc2);
		void sub(Register rDst, Register rSrc1, Register rSrc2);
		void mul(Register rDst, Register rSrc1, Register rSrc2);
		void div(Register rDst, Register rSrc1, Register rSrc2);
		void mod(Register rDst, Register rSrc1, Register rSrc2);

		//Bitwise
		//void not(Register rDst, Register rSrc);
		//void xor(Register rDst, Register rSrc1, Register rSrc2);
		//void and(Register rDst, Register rSrc1, Register rSrc2);
		//void or(Register rDst, Register rSrc1, Register rSrc2);
		//void shl(Register rDst, Register rSrc1, Register rSrc2);
		//void shr(Register rDst, Register rSrc1, Register rSrc2);
		//void shrs(Register rDst, Register rSrc1, Register rSrc2);
		//
		////Flow
		//void ret();
		//void calla(Register rValue);
		//void callr(Register rValue);
		//void jump(Register rValue);
		//void jz(Register rAddr, Register rSrc);
		//void jnz(Register rAddr, Register rSrc);
		//void je(Register rAddr, Register rSrc1, Register rSrc2);
		//void jne(Register rAddr, Register rSrc1, Register rSrc2);
		//void ja(Register rAddr, Register rSrc1, Register rSrc2);
		//void jae(Register rAddr, Register rSrc1, Register rSrc2);
		//void jb(Register rAddr, Register rSrc1, Register rSrc2);
		//void jbe(Register rAddr, Register rSrc1, Register rSrc2);
		//void jg(Register rAddr, Register rSrc1, Register rSrc2);
		//void jge(Register rAddr, Register rSrc1, Register rSrc2);
		//void jl(Register rAddr, Register rSrc1, Register rSrc2);
		//void jle(Register rAddr, Register rSrc1, Register rSrc2);
	};
}

#endif