
#define LEVEL0_BEGIN																						\
auto nErrorStartLine{this->nLine};																			\
auto nErrorStartOffset{this->nOffset};																		\
auto nErrorStartIndex{this->nIndex};																		\
																											\
while (this->nIndex < this->nMaxIndex)																		\
	switch (this->sString[this->nIndex]) {

#define LEVEL0_END																							\
		default: {																							\
			if (std::isspace(this->sString[this->nIndex]) && nErrorStartIndex != this->nIndex)				\
				return Token<T>{TokenType::Error, nErrorStartLine, nErrorStartOffset,						\
				String{this->sString.cbegin() + nErrorStartIndex, this->sString.cbegin() + this->nIndex}};	\
																											\
			if (this->sString[this->nIndex] == '\n') {														\
				++this->nLine;																				\
				this->nOffset = 0;																			\
			} else																							\
				++this->nOffset;																			\
																											\
			if (std::isspace(this->sString[this->nIndex]) && nErrorStartIndex == this->nIndex) {			\
				++this->nIndex;																				\
				nErrorStartLine = this->nLine;																\
				nErrorStartOffset = this->nOffset;															\
				nErrorStartIndex = this->nIndex;															\
			} else																							\
				++this->nIndex;																				\
																											\
			continue;																						\
		}																									\
	}																										\
																											\
if (nErrorStartIndex != this->nIndex)																		\
	return Token<T>{TokenType::Error, nErrorStartLine, nErrorStartOffset,									\
	String{this->sString.cbegin() + nErrorStartIndex, this->sString.cend()}};								\
																											\
return Token<T>{TokenType::EndOfFile, this->nLine, this->nOffset, ""};

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
		LEVEL0_BEGIN
			LEVEL1_BEGIN('.')
			LEVEL_END_ACCEPT(TokenType::Dot)

			LEVEL1_BEGIN(',')
			LEVEL_END_ACCEPT(TokenType::Comma)

			LEVEL1_BEGIN(':')
			LEVEL_END_ACCEPT(TokenType::Colon)

			LEVEL1_BEGIN(';')
			LEVEL_END_ACCEPT(TokenType::Semicolon)

			LEVEL1_BEGIN('(')
			LEVEL_END_ACCEPT(TokenType::ParenOpen)

			LEVEL1_BEGIN(')')
			LEVEL_END_ACCEPT(TokenType::ParenClose)

			LEVEL1_BEGIN('{')
			LEVEL_END_ACCEPT(TokenType::BracketOpen)

			LEVEL1_BEGIN('}')
			LEVEL_END_ACCEPT(TokenType::BracketClose)

			LEVEL1_BEGIN('[')
			LEVEL_END_ACCEPT(TokenType::BraceOpen)

			LEVEL1_BEGIN(']')
			LEVEL_END_ACCEPT(TokenType::BraceClose)

			LEVEL1_BEGIN('=')
				LEVELN_BEGIN('=')
				LEVEL_END_ACCEPT(TokenType::Equal)
			LEVEL_END_ACCEPT(TokenType::Assign)

			LEVEL1_BEGIN('+')
				LEVELN_BEGIN('=')
				LEVEL_END_ACCEPT(TokenType::AssignAdd)
				LEVELN_BEGIN('+')
				LEVEL_END_ACCEPT(TokenType::Increment)
			LEVEL_END_ACCEPT(TokenType::Add)

			LEVEL1_BEGIN('-')
				LEVELN_BEGIN('=')
				LEVEL_END_ACCEPT(TokenType::AssignSubtract)
				LEVELN_BEGIN('-')
				LEVEL_END_ACCEPT(TokenType::Decrement)
			LEVEL_END_ACCEPT(TokenType::Subtract)

			LEVEL1_BEGIN('*')
				LEVELN_BEGIN('=')
				LEVEL_END_ACCEPT(TokenType::AssignMultiply)
				LEVELN_BEGIN('*')
					LEVELN_BEGIN('=')
					LEVEL_END_ACCEPT(TokenType::AssignPower)
				LEVEL_END_ACCEPT(TokenType::Power)
			LEVEL_END_ACCEPT(TokenType::Multiply)

			LEVEL1_BEGIN('/')
				LEVELN_BEGIN('=')
				LEVEL_END_ACCEPT(TokenType::AssignDivide)
			LEVEL_END_ACCEPT(TokenType::Divide)
		LEVEL0_END
	}
}