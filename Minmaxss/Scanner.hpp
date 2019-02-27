
#define LEVEL1_BEGIN(CHAR)																					\
case (CHAR): {																								\
	auto nTokenStartLine{this->nLine};																		\
	auto nTokenStartOffset{this->nOffset};																	\
	auto nTokenStartIndex{this->nIndex};																	\
																											\
	++this->nOffset;																						\
	++this->nIndex;																							\
																											\
	if (this->nIndex < this->nMaxIndex)																		\
		switch (this->sString[this->nIndex]) {

#define LEVEL_END_REJECT																					\
		default:																							\
			break;																							\
		}																									\
																											\
	return Token<T>{TokenType::Error, nErrorStartLine, nErrorStartOffset,									\
    String{this->sString.cbegin() + nErrorStartIndex, this->sString.cbegin() + this->nIndex}};				\
}

#define LEVEL_END_ACCEPT(TYPE)																				\
		default:																							\
			break;																							\
		}																									\
																											\
	if (nErrorStartIndex != nTokenStartIndex) {																\
		this->nLine = nTokenStartLine;																		\
		this->nOffset = nTokenStartOffset;																	\
		this->nIndex = nTokenStartIndex;																	\
																											\
		return Token<T>{TokenType::Error, nErrorStartLine, nErrorStartOffset,								\
		String{this->sString.cbegin() + nErrorStartIndex, this->sString.cbegin() + this->nIndex}};			\
	}																										\
																											\
	return Token<T>{(TYPE), nTokenStartLine, nTokenStartOffset,												\
	String{this->sString.cbegin() + nTokenStartIndex, this->sString.cbegin() + this->nIndex}};				\
}

#define LEVELN_BEGIN(CHAR)																					\
case (CHAR): {																								\
	++this->nOffset;																						\
	++this->nIndex;																							\
																											\
	if (this->nIndex < this->nMaxIndex)																		\
		switch (this->sString[this->nIndex]) {

#define LEVEL1_ACCEPT_IF(CHAR, TYPE)																		\
case (CHAR): {																								\
	auto nTokenStartLine{this->nLine};																		\
	auto nTokenStartOffset{this->nOffset};																	\
	auto nTokenStartIndex{this->nIndex};																	\
																											\
	++this->nOffset;																						\
	++this->nIndex;																							\
																											\
	return Token<T>{(TYPE), nTokenStartLine, nTokenStartOffset,												\
	String{this->sString.cbegin() + nTokenStartIndex, this->sString.cbegin() + this->nIndex}};				\
}

#define LEVELN_ACCEPT_IF(CHAR, TYPE)																		\
case (CHAR): {																								\
	++this->nOffset;																						\
	++this->nIndex;																							\
																											\
	return Token<T>{(TYPE), nTokenStartLine, nTokenStartOffset,												\
	String{this->sString.cbegin() + nTokenStartIndex, this->sString.cbegin() + this->nIndex}};				\
}

namespace Minmaxss
{
	template<class T> Scanner<T>::Scanner(StringView sString) :
		sString{sString},
		nLine{0},
		nOffset{0},
		nIndex{0},
		nMaxIndex{sString.length()}
	{
		//Empty.
	}

	template<class T> Token<T> Scanner<T>::nextToken()
	{
		auto nErrorStartLine{this->nLine};
		auto nErrorStartOffset{this->nOffset};
		auto nErrorStartIndex{this->nIndex};

		while (this->nIndex < this->nMaxIndex)
			switch (this->sString[this->nIndex])
			{
				LEVEL1_BEGIN('.')
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case '0':
						return this->parseNumber();
				LEVEL_END_ACCEPT(TokenType::Dot)

				LEVEL1_ACCEPT_IF(',', TokenType::Comma)
				LEVEL1_ACCEPT_IF(':', TokenType::Colon)
				LEVEL1_ACCEPT_IF(';', TokenType::Semicolon)
				LEVEL1_ACCEPT_IF('(', TokenType::ParenOpen)
				LEVEL1_ACCEPT_IF(')', TokenType::ParenClose)
				LEVEL1_ACCEPT_IF('{', TokenType::BracketOpen)
				LEVEL1_ACCEPT_IF('}', TokenType::BracketClose)
				LEVEL1_ACCEPT_IF('[', TokenType::BraceOpen)
				LEVEL1_ACCEPT_IF(']', TokenType::BraceClose)

				LEVEL1_BEGIN('=')
					LEVELN_BEGIN('=')
					LEVEL_END_ACCEPT(TokenType::Equal)
				LEVEL_END_ACCEPT(TokenType::Assign)

				LEVEL1_BEGIN('+')
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case '0':
					case 'e':
					case 'E':
					case '.':
						return this->parseNumber();
					LEVELN_ACCEPT_IF('=', TokenType::AssignAdd)
					LEVELN_ACCEPT_IF('+', TokenType::Increment)
				LEVEL_END_ACCEPT(TokenType::Add)

				LEVEL1_BEGIN('-')
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case '0':
					case 'e':
					case 'E':
					case '.':
						return this->parseNumber();
					LEVELN_ACCEPT_IF('=', TokenType::AssignSubtract)
					LEVELN_ACCEPT_IF('-', TokenType::Decrement)
				LEVEL_END_ACCEPT(TokenType::Subtract)

				LEVEL1_BEGIN('*')
					LEVELN_ACCEPT_IF('=', TokenType::AssignMultiply)
					LEVELN_BEGIN('*')
						LEVELN_ACCEPT_IF('=', TokenType::AssignPower)
					LEVEL_END_ACCEPT(TokenType::Power)
				LEVEL_END_ACCEPT(TokenType::Multiply)

				LEVEL1_BEGIN('/')
					LEVELN_ACCEPT_IF('=', TokenType::AssignDivide)
				LEVEL_END_ACCEPT(TokenType::Divide)

				LEVEL1_BEGIN('%')
					LEVELN_ACCEPT_IF('=', TokenType::AssignModulo)
				LEVEL_END_ACCEPT(TokenType::Modulo)

				LEVEL1_BEGIN('~')
					LEVELN_ACCEPT_IF('=', TokenType::AssignBitwiseNot)
				LEVEL_END_ACCEPT(TokenType::BitwiseNot)

				LEVEL1_BEGIN('^')
					LEVELN_ACCEPT_IF('=', TokenType::AssignBitwiseXor)
				LEVEL_END_ACCEPT(TokenType::BitwiseXor)

				LEVEL1_BEGIN('&')
					LEVELN_ACCEPT_IF('=', TokenType::AssignBitwiseAnd)
					LEVELN_ACCEPT_IF('&', TokenType::LogicalAnd)
				LEVEL_END_ACCEPT(TokenType::BitwiseAnd)

				LEVEL1_BEGIN('|')
					LEVELN_ACCEPT_IF('=', TokenType::AssignBitwiseOr)
					LEVELN_ACCEPT_IF('|', TokenType::LogicalOr)
				LEVEL_END_ACCEPT(TokenType::BitwiseOr)

				LEVEL1_BEGIN('<')
					LEVELN_ACCEPT_IF('=', TokenType::LessEqual)
					LEVELN_BEGIN('<')
						LEVELN_ACCEPT_IF('=', TokenType::AssignShiftLeft)
					LEVEL_END_ACCEPT(TokenType::ShiftLeft)
				LEVEL_END_ACCEPT(TokenType::Less)

				LEVEL1_BEGIN('>')
					LEVELN_ACCEPT_IF('=', TokenType::GreaterEqual)
					LEVELN_BEGIN('>')
						LEVELN_ACCEPT_IF('=', TokenType::AssignShiftRight)
					LEVEL_END_ACCEPT(TokenType::ShiftRight)
				LEVEL_END_ACCEPT(TokenType::Greater)

				LEVEL1_BEGIN('!')
					LEVELN_ACCEPT_IF('=', TokenType::NotEqual)
				LEVEL_END_ACCEPT(TokenType::LogicalNot)

				case '\'':
				case '"':
					return this->parseString();

				case '`':
					return this->parseStringMultiline();

				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				case '0':
					return this->parseNumber();

				default:
				{
					++this->nOffset;

					if (std::isspace(this->sString[this->nIndex]))
					{
						if (nErrorStartIndex != this->nIndex)
							return Token<T>{TokenType::Error, nErrorStartLine, nErrorStartOffset, String{this->sString.cbegin() + nErrorStartIndex, this->sString.cbegin() + this->nIndex}};

						if (this->sString[this->nIndex] == '\n')
						{
							++this->nLine;
							this->nOffset = 0;
						}

						nErrorStartLine = this->nLine;
						nErrorStartOffset = this->nOffset;
						nErrorStartIndex = this->nIndex + 1;
					}
					else
						switch (this->sString[this->nIndex])
						{
							case '\\':
							case '\'':
							case '"':
							case '`':
							case '.':
							case ',':
							case ':':
							case ';':
							case '(':
							case ')':
							case '{':
							case '}':
							case '[':
							case ']':
							case '=':
							case '+':
							case '-':
							case '*':
							case '/':
							case '%':
							case '~':
							case '^':
							case '&':
							case '|':
							case '<':
							case '>':
							case '!':
							case '1':
							case '2':
							case '3':
							case '4':
							case '5':
							case '6':
							case '7':
							case '8':
							case '9':
							case '0':
								break;

							default:
								--this->nOffset;

								return this->parseKeyword();
						}

					++this->nIndex;

					continue;
				}
			}

		if (nErrorStartIndex != this->nIndex)
			return Token<T>{TokenType::Error, nErrorStartLine, nErrorStartOffset, String{this->sString.cbegin() + nErrorStartIndex, this->sString.cend()}};

		return Token<T>{TokenType::EndOfFile, this->nLine, this->nOffset, ""};
	}

	template<class T> Token<T> Scanner<T>::parseNumber()
	{
		return Token<T>{TokenType::LiteralBool, this->nLine, this->nOffset, ""};
	}

	template<class T> Token<T> Scanner<T>::parseString()
	{
		return Token<T>{TokenType::LiteralString, this->nLine, this->nOffset, ""};
	}

	template<class T> Token<T> Scanner<T>::parseStringMultiline()
	{
		return Token<T>{TokenType::LiteralString, this->nLine, this->nOffset, ""};
	}

	template<class T> Token<T> Scanner<T>::parseKeyword()
	{
		static const std::unordered_map<String, TokenType> sKeywordMap
		{
			{"true", TokenType::LiteralBool},
			{"false", TokenType::LiteralBool},

			{"var", TokenType::KeywordVar},
			{"if", TokenType::KeywordIf},
			{"for", TokenType::KeywordFor}
		};

		Token<T> sToken{TokenType::Identifier, this->nLine, this->nOffset, String{this->sString.cbegin() + this->nIndex, this->sString.cbegin() + this->nIndex + 1}};

		for (++this->nIndex; this->nIndex < this->nMaxIndex; ++this->nOffset, ++this->nIndex)
		{
			if (std::isspace(this->sString[this->nIndex]))
				break;

			auto bPunctuationMark{false};

			switch (this->sString[this->nIndex])
			{
				case '\\':
				case '\'':
				case '"':
				case '`':
				case '.':
				case ',':
				case ':':
				case ';':
				case '(':
				case ')':
				case '{':
				case '}':
				case '[':
				case ']':
				case '=':
				case '+':
				case '-':
				case '*':
				case '/':
				case '%':
				case '~':
				case '^':
				case '&':
				case '|':
				case '<':
				case '>':
				case '!':
					bPunctuationMark = true;
					break;

				default:
					sToken.sString.push_back(this->sString[this->nIndex]);
					break;
			}

			if (bPunctuationMark)
				break;
		}

		auto iIndex{sKeywordMap.find(sToken.sString)};

		if (iIndex != sKeywordMap.cend())
			sToken.eType = iIndex->second;

		return sToken;
	}
}