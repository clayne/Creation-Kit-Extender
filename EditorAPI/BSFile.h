#pragma once

#include "NiTypes.h"

// copied from CSE's API, nothing appears to have been changed
// 15C
class BSFile : public NiFile
{
public:
	// members
	//     /*000*/ NiFile
	/*030*/ UInt32			unk30;
	/*034*/ UInt32			unk34;
	/*038*/ SInt32			unk38;  // init to -1, used instead of bsPos in the TESFile::Write(Deleted?)FormHeader when != -1
	/*03C*/ UInt32			unk3C;
	/*040*/ UInt32			unk40;
	/*044*/ char			fileName[0x104];
	/*148*/ UInt32			unk148;
	/*14C*/ UInt32			unk14C;
	/*150*/ UInt32			bsPos;  // (?) tracks current offset like NiFile::m_uiPos, but not reset by Flush()
	/*154*/ UInt32			unk154;
	/*158*/ UInt32			fileSize;
};
STATIC_ASSERT(sizeof(BSFile) == 0x15C);