#pragma once

#include "BSFile.h"
#include "TESForm.h"
#include "NiTypes.h"
#include "BSString.h"

// Many of the following classes have been copied from the CSE's API
// It's unlikely that they have changed (much) in the Creation Engine but the possibility remains (particularly with the various flags)

/*
	A "chunk" is the basic unit of the TES4 mod file. A chunk is headed by a type code and size field, followed by binary data
	This struct is public (not a subclass of TESFile) because it is also used by RecordInfo
*/

// 08 (NOTE: 06 for non-record chunks on disk, see below)
class ChunkInfo
{
public:
	/*00*/ UInt32    chunkType;		// e.g. 'GRUP', 'GLOB', etc.
	/*04*/ UInt32    chunkLength;	// size from end of chunk header (NOTE: chunkLength field is a UInt16 for non-record chunks on disk)
};

/*
	Records are chunks whose data consists entirely of subchunks.  They have additional identifying information in the header
	During serialization, each form corresponds to a single record, but there are also a few records (e.g. GRUP,TES4) that do not correspond to any form
	This struct is public (not a subclass of TESFile) because it is also used by TESForm.h
*/

// 14
class RecordInfo : public ChunkInfo
{
public:
	enum RecordFlags
	{
		// not sure what flags are specific to forms, references, or records, and what is shared
		kRecordFlags__FormFlags                = 0x000A8EE0, // flag bits copied from forms for form records
		kRecordFlags__FileFlags                = 0xFF000091, // flag bits copied from files for TES4 records
		kRecordFlags_Ignored            = /*0C*/ 0x00001000, // record is ignored during loading
		kRecordFlags_Compressed         = /*12*/ 0x00040000, // record data is compressed using ZLib.  Note that group records cannot be compressed
	};

	//     /*00*/ ChunkInfo
	/*08*/ UInt32        recordFlags; //
	// form records: see 'record flags' above
	// TES4 records: fileFlags
	// group records: contained form chunk type / parent formid / block number / grid coords
	/*0C*/ UInt32        recordID; //
	// form records: formID
	// TES4 records: 0
	// group records: group class (0-10) indicating what kind of group record
	/*10*/ TrackingData  trackingData; // used for internal revision control
};


// 440
class TESFile
{
public:
	static const UInt32 kMAX_PATH = 260;			// i.e. windows constant MAX_PATH

	enum FileFlags
	{
		kFileFlag_Master        = /*00*/ 0x00000001, // set for master files (as indicated by bit in TES4 record flags)
		kFileFlag_Open          = /*01*/ 0x00000002, // set in OpenBSFile()
		kFileFlag_Loaded        = /*02*/ 0x00000004, // flags file for loading, set before file is actually loaded
		kFileFlag_Active        = /*03*/ 0x00000008, // set for the currently active file
		kFileFlag_Unk04			= /*04*/ 0x00000010,
		kFileFlag_LittleEndian	= /*06*/ 0x00000040, // not set in XBox ESMs
		kFileFlag_Delocalized	= /*07*/ 0x00000080,
	};

	enum FileErrorStates
	{
		kFileState_None         = 0x0,
		kFileState_Unk2         = 0x2, // set in OpenBSFile
		kFileState_Unk9         = 0x9, // set in OpenBSFile
		kFileState_WriteError   = 0xA,
		kFileState_NoHeader		= 0xB,
		kFileState_UnkC         = 0xC, // set in OpenBSFile
	};

	// 0C
	struct FileHeaderInfo
	{
		/*00*/ float         fileVersion;
		/*04*/ UInt32        numRecords; // number of record blocks in file
		/*08*/ UInt32        nextFormID; // including file index in highest byte
	};

	// Data for Master files - compared against size in findData of masters to check if they have changed since last edit
	// 08
	struct MasterFileData
	{
		/*00*/ DWORD		nFileSizeHigh;
		/*04*/ DWORD		nFileSizeLow;
	};

	typedef BSSimpleList<MasterFileData*>		MasterDataListT;
	typedef BSSimpleList<char*>					MasterNameListT;

	// Group record struct
	// 18
	class GroupInfo : public RecordInfo
	{
		//     /*00*/ RecordInfo		// for group records, the size includes the 14 bytes of the header
		/*14*/ UInt32        recordOffset;   // used internally to track header offsets of all open groups
	};

	typedef BSSimpleList<GroupInfo*>					GroupListT;
	typedef NiTPointerMap< UInt32, TESFile* >			ChildThreadFileMapT;

	// members
	/*000*/ UInt32								errorState;
	/*004*/ TESFile*							ghostFileParent;					// for ghost files, the parent TESFile* from the main thread
	/*008*/ ChildThreadFileMapT*				childThreadGhostFiles;				// read-only duplicate files mapped by threadID for child threads
	/*00C*/ BSFile*								unkFile00C;							// temp file for backups?
	/*010*/ BSFile*								bsFile;								// used for actual read from / write to disk operations
	/*014*/ UInt32								unk004;
	/*018*/ UInt32								unk018;
	/*01C*/ UInt32								unk01C;
	/*020*/ char								fileName[kMAX_PATH];
	/*124*/ char								filePath[kMAX_PATH];				// relative to the game's root directory
	/*228*/ void*								unk228;								// simple object. no dtor
	/*22C*/ UInt32								bufferSize;							// used in OpenBSFile, init to 0x2800
	/*230*/ UInt32								unk230;
	/*234*/ UInt32								unk234;
	/*238*/ UInt32								unk238;
	/*23C*/ UInt32								unk23C;
	/*240*/ GroupInfo							currentRecord;						// is this a GroupInfo object?
	/*258*/ ChunkInfo							currentChunk;
	/*260*/ UInt32								fileSize;
	/*264*/ UInt32								currentRecordOffset;				// offset of current record in file
	/*268*/ UInt32								currentChunkOffset;					// offset of current chunk in record
	/*26C*/ UInt32								fetchedChunkDataSize;				// number of bytes read in last GetChunkData() call
	/*270*/ GroupInfo							unk270;								// used when saving empty form records, e.g. for deleted forms
	/*288*/ UInt32								unk288;								// same as above, bsfile->bsPos/unk38
	/*28C*/ UInt32								unk28C;
	/*290*/ GroupListT							openGroups;							// stack of open group records, from lowest level to highest
	/*298*/ UInt8								headerRead;							// set to 1 after the file's TES4 header has been read
	/*299*/ UInt8								byteSwapEnabled;					// set to 1 for big-endian plugins
	 																				// byte swapping will be performed before writing chunks, when enabled
	/*29A*/ UInt8								pad29A[2];
	/*29C*/ WIN32_FIND_DATA						findData;
	/*3DC*/ FileHeaderInfo						fileHeader;
	/*3E8*/ UInt32								fileFlags;
	/*3EC*/ MasterNameListT						masterNames;
	/*3F4*/ MasterDataListT						masterData;
	/*3FC*/ UInt32								masterCount;
	/*400*/ TESFile**							masterFiles;						// pointer to TESFile*[masterCount] of currently loaded masters
	/*404*/ UInt32								unk404;
	/*408*/ UInt32								unk408;
	/*40C*/ UInt8								fileIndex;
	/*40D*/ UInt8								pad40D[3];
	/*410*/ BSString							authorName;
	/*418*/ BSString							description;
	/*420*/ void*								unk420;								// same as recordDCBuffer? used for compression?
	/*424*/ UInt32								unk424;								// same as recordDCLength?
	/*428*/ void*								recordDCBuffer;
	/*42C*/ UInt32								recordDCLength;
	/*430*/ TESFile*							unk430;								// file this object was cloned from. used for local copies of network files?
	/*434*/ UInt32								unk434;								// init to INTV (byte swapped if required)
	/*438*/ UInt32*								overrideData;						// ONAM data, directly read from the file
	/*43C*/ UInt32								overrideDataSize;
};
STATIC_ASSERT(sizeof(TESFile) == 0x440);