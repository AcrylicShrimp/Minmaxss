
#include "Minmaxss/Scanner.h"

#include <cstdio>
#include <cstdlib>

int main()
{
	using namespace Minmaxss;

	Scanner_s sScanner{"//+++fdsa+fdsfafa+--***=**="};

	for (;;)
	{
		auto sToken{sScanner.nextToken()};

		if (sToken.eType == TokenType::EndOfFile)
			break;
	}

	return 0;
}