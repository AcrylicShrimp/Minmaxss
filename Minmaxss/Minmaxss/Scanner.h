
/*
	2019.01.03
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_MINMAXSS_SCANNER_H

#define _CLASS_MINMAXSS_SCANNER_H

#include <cctype>
#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>

namespace Minmaxss
{
	enum class TokenType : std::uint64_t
	{
		/*
			Special Mark
		*/
		EndOfFile,
		Error,

		/*
			Literal
		*/
		LiteralBool,
		LiteralNumber,
		LiteralString,

		/*
			Punctuation Mark
		*/
		Dot,
		Comma,
		Colon,
		Semicolon,
		ParenOpen,
		ParenClose,
		BracketOpen,
		BracketClose,
		BraceOpen,
		BraceClose,

		/*
			Operator
		*/
		Assign,
		AssignAdd,
		AssignSubtract,
		AssignMultiply,
		AssignDivide,
		AssignModulo,
		AssignPower,
		AssignBitwiseNot,
		AssignBitwiseXor,
		AssignBitwiseAnd,
		AssignBitwiseOr,
		AssignShiftLeft,
		AssignShiftRight,

		Increment,
		Decrement,

		Add,
		Subtract,
		Multiply,
		Divide,
		Modulo,
		Power,

		BitwiseNot,
		BitwiseXor,
		BitwiseAnd,
		BitwiseOr,
		ShiftLeft,
		ShiftRight,

		LogicalNot,
		LogicalAnd,
		LogicalOr,

		Equal,
		NotEqual,
		Less,
		LessEqual,
		Greater,
		GreaterEqual,

		/*
			Keyword
		*/
		KeywordVar,
		KeywordIf,
		KeywordFor,

		Identifier
	};

	template<class T> struct Token
	{
	public:
		using String = std::basic_string<T>;

		TokenType eType;
		std::uint64_t nLine;
		std::uint64_t nOffset;
		String sString;

	public:
		Token(TokenType eType, std::uint64_t nLine, std::uint64_t nOffset, const String &sString) :
			eType{eType},
			nLine{nLine},
			nOffset{nOffset},
			sString{sString}
		{
			//Empty.
		}

		Token(TokenType eType, std::uint64_t nLine, std::uint64_t nOffset, String &&sString) :
			eType{eType},
			nLine{nLine},
			nOffset{nOffset},
			sString{std::move(sString)}
		{
			//Empty.
		}
	};

	template<class T> class Scanner final
	{
	public:
		using String = std::basic_string<T>;
		using StringView = std::basic_string_view<T>;

	private:
		String sString;
		std::uint64_t nLine;
		std::uint64_t nOffset;
		std::uint64_t nIndex;
		std::uint64_t nMaxIndex;

	public:
		Scanner(StringView sString);
		Scanner(const Scanner &sSrc) = default;
		Scanner(Scanner &&sSrc) = default;
		~Scanner() = default;
		
	public:
		Scanner &operator=(const Scanner &sSrc) = default;
		Scanner &operator=(Scanner &&sSrc) = default;
		
	public:
		Token<T> nextToken();

	private:
		Token<T> parseNumber();
		Token<T> parseString();
		Token<T> parseStringMultiline();
		Token<T> parseKeyword();
	};

	using Scanner_s = Scanner<char>;
	using Scanner_w = Scanner<wchar_t>;
}

#include "Scanner.hpp"

#endif