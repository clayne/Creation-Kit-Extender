#pragma once

#include "BSSystem.h"

class NiNode;
class BSTempNodeManager;
class GridArray;
class GridCellArray;
class NiDirectionalLight;
class TESObjectCELL;
class BSFogProperty;
class Sky;
class TESWorldSpace;
class NavMeshInfoMap;


// actually BSResource::ArchiveStreamOpenedEvent
// 04+?
struct ArchiveStreamOpenedEvent
{
	/*00*/ UInt32				unk00;
};

// 08
struct CellAttachDetachEvent
{
	enum
	{
		kType_AttachBegin		= 0,
		kType_AttachEnd,
		kType_DetachBegin,
		kType_DetachEnd,

		kType__MAX
	};

	/*00*/ TESObjectCELL*		cell;
	/*04*/ UInt32				type;
};


// actual base class hierarchy - BSTSingletonExplicit<ICellAttachDetachEventSource>, BSTEventSource<CellAttachDetachEvent>
// 34
class ICellAttachDetachEventSource : public BSTEventSource<CellAttachDetachEvent>
{
	// members
	//     /*00*/ void**		vtbl
	//     /*04*/ BSTSingletonExplicit<ICellAttachDetachEventSource>	- no members, used to initialize a singleton
	//	   /*04*/ BSTEventSource<CellAttachDetachEvent>

	// no additional members

	virtual ~ICellAttachDetachEventSource();
};
STATIC_ASSERT(sizeof(ICellAttachDetachEventSource) == 0x34);

// E4
class TES : public ICellAttachDetachEventSource, public BSTEventSink<ArchiveStreamOpenedEvent>
{
public:
	// members
	//     /*00*/ ICellAttachDetachEventSource
	//	   /*34*/ BSTEventSink<ArchiveStreamOpenedEvent>
	/*38*/ UInt32									unk38;
	/*3C*/ GridCellArray*							gridCellArray;
	/*40*/ NiNode*									sceneObjectRoot;
	/*44*/ NiNode*									sceneLandLOD;
	/*48*/ void*									unk48;
	/*4C*/ BSTempNodeManager*						tempNodeManager;
	/*50*/ NiDirectionalLight*						sunDirectionalLight;
	/*54*/ BSFogProperty*							fogProperty;
	/*58*/ SInt32									extXCoord;						// in the current worldspace
	/*5C*/ SInt32									extYCoord;
	/*60*/ SInt32									unk60;							// same as extXCoord, probably gets updated to store some offset into the loaded cell grid
	/*64*/ SInt32									unk64;							// same as above but for Y
	/*68*/ TESObjectCELL*							currentInteriorCell;
	/*6C*/ TESObjectCELL*							interiorCellBufferStack;
	/*70*/ TESObjectCELL*							exteriorCellBufferStack;
	/*74*/ SInt32									unk74;
	/*78*/ SInt32									unk78;
	/*7C*/ SInt32									unk7C;
	/*80*/ SInt32									unk80;
	/*84*/ UInt32									unk84;
	/*88*/ UInt32									unk88;
	/*8C*/ UInt32									unk8C;
	/*90*/ Sky*										sky;
	/*94*/ UInt32									unk94;
	/*98*/ UInt32									unk98;
	/*9C*/ UInt32									unk9C;
	/*A0*/ UInt32									unkA0;
	/*A4*/ UInt8									unkA4[4];
	/*A8*/ UInt8									unkA8[4];						// 0xAA and 0xA9 used when tracking file loading
	/*AC*/ UInt8									unkAC;							// similar to above
	/*AD*/ UInt8									padAD[3];
	/*B0*/ float									unkB0;
	/*B4*/ float									unkB4;
	/*B8*/ TESWorldSpace*							currentWorldSpace;
	/*BC*/ UInt32									unkBC[(0xDC - 0xBC) >> 2];
	/*DC*/ NavMeshInfoMap*							navMeshInfoMap;
	/*E0*/ BSTArray<void*>*							unkE0;							// used to track file loading during a cell load operation

	static TES**									Singleton;
};
STATIC_ASSERT(sizeof(TES) == 0xE4);

#define _TES										(*TES::Singleton)

// copied from CSE's API, both of them
// ### appears to be as large as 0x10, the corresponding members in GridCellArray are probably members of this class
// strangely, the c'tor only inits the vtbl ptr. however, vtbl+4 seems to do the same for the other members
// 04+?
class GridArray
{
public:
	// members
	/// *00* / void**					vtbl;

	virtual ~GridArray();
};
STATIC_ASSERT(sizeof(GridArray) == 0x4);

// 020
class GridCellArray : public GridArray
{
public:
	// 8+?
	struct CellInfo
	{
		/*00*/ TES::WaterPlaneData*		waterData;
		/*04*/ NiNode*					niNode;		// ### cell's node? confirm
	};

	// 04
	struct GridEntry
	{
		/*00*/ TESObjectCELL*	cell;
		/*04*/ CellInfo*		info;
	};

	// members
	//     /*00*/ GridArray
	/*04*/ UInt32			worldX;				// worldspace x coordinate of cell at center of grid
	/*08*/ UInt32			worldY;				// worldspace y
	/*0C*/ UInt32			size;				// grid is size ^ 2, size = uGridsToLoad
	/*10*/ GridEntry*		grid;				// dynamically alloc'ed array of GridEntry[size ^ 2]
	/*14*/ Vector3			extents;			// x = 4096 * worldX (exterior cells are 4096 square units),  y = 4096 * worldY, z = seen 0.0
												// init'ed with coords and passed to a bhkWorldM method, which calculates the extents
};
STATIC_ASSERT(sizeof(GridCellArray) == 0x20);