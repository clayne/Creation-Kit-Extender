#include "ExtraDataList.h"
#include "ExtraData.h"

BSExtraData* BaseExtraList::GetExtraDataByType(UInt8 Type)
{
	return thisCall<BSExtraData*>(VOLATILE(0x004FFB10), this, Type);
}