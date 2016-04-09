#pragma once

#include <string>
#include "StructureID.h"

namespace DS
{
	class DSRoutines
	{
	public:
		static StructureADT convertADStoADT(const StructureADS& ads);

		static bool rangeCheck(const int index, const size_t size, const bool throwException = false, const std::string* message = nullptr);

	private:
		DSRoutines();

	};

}
