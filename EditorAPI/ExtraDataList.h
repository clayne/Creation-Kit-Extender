#pragma once

class BSExtraData;

// Beth took this engine optimization business very seriously
// 04
class BaseExtraList
{
public:
	// members
	/*00*/ BSExtraData*				extraList;				// LL of extra data nodes
															// runtime class has a bitfield for quick lookup
	// no additional members
	
	BSExtraData*					GetExtraDataByType(UInt8 Type);
};
STATIC_ASSERT(sizeof(BaseExtraList) == 0x4);

// ExtraDataList is apparently only used by TESForm classes
// 04
class ExtraDataList : public BaseExtraList
{
public:
	// no additional members
};
STATIC_ASSERT(sizeof(ExtraDataList) == 0x4);