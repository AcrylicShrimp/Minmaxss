
/*
	2018.08.05
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_MINMAXSS_ENDIANESS_H

#define _CLASS_MINMAXSS_ENDIANESS_H

#include <cstdint>

namespace Minmaxss
{
	class Endianess final
	{
	private:
		static std::uint16_t nEndian;

	public:
		Endianess() = delete;
		Endianess(const Endianess &sSrc) = delete;
		~Endianess() = delete;
		
	public:
		Endianess &operator=(const Endianess &sSrc) = delete;
		
	public:
		static inline bool big();
		static inline bool little();
	};

	inline bool Endianess::big()
	{
		return *reinterpret_cast<const std::uint8_t *>(&Endianess::nEndian) == 0;
	}

	inline bool Endianess::little()
	{
		return *reinterpret_cast<const std::uint8_t *>(&Endianess::nEndian) == 1;
	}
}

#endif