#pragma once

#include "NiTMap.h"

// actually derives from NiTArray
// 10
template <typename T>
class NiTPrimitiveArray
{
public:
	//     /*00*/ void**		vtbl
	/*04*/ T*					entries;
	/*08*/ UInt16				unk08;
	/*0A*/ UInt16				unk0A;
	/*0C*/ UInt16				unk0C;
	/*0E*/ UInt16				unk0E;		// grow size?

	virtual ~NiTPrimitiveArray();
};
STATIC_ASSERT(sizeof(NiTPrimitiveArray<void*>) == 0x10);