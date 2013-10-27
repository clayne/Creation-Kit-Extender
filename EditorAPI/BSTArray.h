#pragma once

#include "MemoryHeap.h"

// 0C
template<typename T>
class BSTArray
{
public:
	// 08
	struct Buffer
	{
		/*00*/ T*		entries;
		/*04*/ UInt32	capacity;
	};

	/*00*/ Buffer		data;
	/*08*/ UInt32		size;

	inline T&			operator[](UInt32 Index)
	{
		SME_ASSERT(Index >= 0);
		SME_ASSERT(Index < size);

		return data.entries[Index];
	}
};