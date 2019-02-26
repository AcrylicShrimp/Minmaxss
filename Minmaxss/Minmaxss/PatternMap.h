
/*
	2019.02.03
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_MINMAXSS_PATTERNMAP_H

#define _CLASS_MINMAXSS_PATTERNMAP_H

#include <cstdint>
#include <map>
#include <regex>
#include <string_view>
#include <vector>

namespace Minmaxss
{
	template<class T> class PatternMap final
	{
	public:
		using Regex = std::basic_regex<T>;
		using StringView = std::basic_string_view<T>;

	public:
		// TODO : Make below pattern shared between instances of pattern map.
		struct Pattern
		{
			Regex sRegex;
			std::uint64_t nType;
			std::uint64_t nPriority;

		public:
			Pattern(StringView sRegex, std::uint64_t nType, std::uint64_t nPriority) :
				sRegex{sRegex.data(), Regex::ECMAScript | Regex::optimize},
				nType{nType},
				nPriority{nPriority}
			{
				//Empty.
			}
		};

	private:
		std::map<std::uint64_t, std::vector<Pattern>> sPatternMap;

	public:
		Scanner() = default;
		Scanner(const Scanner &sSrc) = default;
	};
}

#endif