
#include "Minmaxss/Scanner.h"

#include <cstdio>
#include <cstdlib>

int main()
{
	using namespace Minmaxss;

	Scanner<char32_t> sScanner{U"var a = false;\nvar a2 = **lol;\n\n"};

	for (;;)
	{
		auto sToken{sScanner.nextToken()};

		if (sToken.eType == TokenType::EndOfFile)
			break;
	}

	return 0;
}