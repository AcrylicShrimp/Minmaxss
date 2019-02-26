
/*
	2018.08.05
	Created by AcrylicShrimp
*/

#include "Instruction.h"

namespace Minmaxss
{
	//void InstructionList::pass()
	//{
	//	this->sBuffer.emplace_back(static_cast<std::uint8_t>(Instruction::PASS));
	//}
	//
	//void InstructionList::fill(Register rDst, std::uint8_t nValue)
	//{
	//	this->sBuffer.emplace_back(static_cast<std::uint8_t>(Instruction::FILL));
	//	this->sBuffer.emplace_back(rDst);
	//	this->sBuffer.emplace_back(nValue);
	//}
	//
	//void InstructionList::fill(Register rDst, std::uint16_t nValue)
	//{
	//	this->sBuffer.emplace_back(static_cast<std::uint8_t>(Instruction::FILL));
	//	this->sBuffer.emplace_back(rDst);
	//
	//	if (Endianess::big())
	//	{
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[1]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[0]);
	//	}
	//	else
	//	{
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[0]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[1]);
	//	}
	//}
	//
	//void InstructionList::fill(Register rDst, std::uint32_t nValue)
	//{
	//	this->sBuffer.emplace_back(static_cast<std::uint8_t>(Instruction::FILL));
	//	this->sBuffer.emplace_back(rDst);
	//
	//	if (Endianess::big())
	//	{
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[3]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[2]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[1]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[0]);
	//	}
	//	else
	//	{
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[0]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[1]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[2]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[3]);
	//	}
	//}
	//
	//void InstructionList::fill(Register rDst, std::uint64_t nValue)
	//{
	//	this->sBuffer.emplace_back(static_cast<std::uint8_t>(Instruction::FILL));
	//	this->sBuffer.emplace_back(rDst);
	//
	//	if (Endianess::big())
	//	{
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[7]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[6]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[5]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[4]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[3]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[2]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[1]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[0]);
	//	}
	//	else
	//	{
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[0]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[1]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[2]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[3]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[4]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[5]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[6]);
	//		this->sBuffer.emplace_back(reinterpret_cast<const std::uint8_t *>(&nValue)[7]);
	//	}
	//}
	//
	//void InstructionList::load(Register rDst, Register rAddr)
	//{
	//	this->sBuffer.emplace_back(static_cast<std::uint8_t>(Instruction::LOAD));
	//	this->sBuffer.emplace_back(rDst);
	//	this->sBuffer.emplace_back(rAddr);
	//}
	//
	//void InstructionList::store(Register rAddr, Register rSrc)
	//{
	//	this->sBuffer.emplace_back(static_cast<std::uint8_t>(Instruction::STORE));
	//	this->sBuffer.emplace_back(rAddr);
	//	this->sBuffer.emplace_back(rSrc);
	//}
	//
	//void InstructionList::push(Register rValue)
	//{
	//
	//}
	//
	//void InstructionList::pop(Register rValue)
	//{
	//
	//}
	//
	//void InstructionList::copy(Register rDst, Register rSrc)
	//{
	//
	//}
	//
	//void InstructionList::zero(Register rValue)
	//{
	//
	//}
	//
	//void InstructionList::inc(Register rValue)
	//{
	//
	//}
	//
	//void InstructionList::dec(Register rValue)
	//{
	//
	//}
	//
	//void InstructionList::neg(Register rValue)
	//{
	//
	//}
	//
	//void InstructionList::add(Register rDst, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::sub(Register rDst, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::mul(Register rDst, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::div(Register rDst, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::mod(Register rDst, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::not(Register rDst, Register rSrc)
	//{
	//
	//}
	//
	//void InstructionList:: xor (Register rDst, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList:: and (Register rDst, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList:: or (Register rDst, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::shl(Register rDst, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::shr(Register rDst, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::shrs(Register rDst, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::ret()
	//{
	//
	//}
	//
	//void InstructionList::calla(Register rValue)
	//{
	//
	//}
	//
	//void InstructionList::callr(Register rValue)
	//{
	//
	//}
	//
	//void InstructionList::jump(Register rValue)
	//{
	//
	//}
	//
	//void InstructionList::jz(Register rAddr, Register rSrc)
	//{
	//
	//}
	//
	//void InstructionList::jnz(Register rAddr, Register rSrc)
	//{
	//
	//}
	//
	//void InstructionList::je(Register rAddr, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::jne(Register rAddr, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::ja(Register rAddr, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::jae(Register rAddr, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::jb(Register rAddr, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::jbe(Register rAddr, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::jg(Register rAddr, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::jge(Register rAddr, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::jl(Register rAddr, Register rSrc1, Register rSrc2)
	//{
	//
	//}
	//
	//void InstructionList::jle(Register rAddr, Register rSrc1, Register rSrc2)
	//{
	//
	//}
}