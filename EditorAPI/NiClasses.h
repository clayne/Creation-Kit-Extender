#pragma once

// 10
class NiBinaryStream
{
public:
	// read/write function callbacks.  Component size and number are for custom byte ordering
	typedef UInt32 (*ReadFNT)(NiBinaryStream* pkThis, void* pvBuffer, UInt32 uiBytes, UInt32* puiComponentSizes, UInt32 uiNumComponents);
	typedef UInt32 (*WriteFNT)(NiBinaryStream* pkThis, const void* pvBuffer, UInt32 uiBytes, UInt32* puiComponentSizes, UInt32 uiNumComponents);

	// members
	//     /*00*/ void**        vtbl;
	/*04*/ UInt32				m_unk04;	// not present in Oblivion, an offset of sorts, added in New Vegas
	/*08*/ ReadFNT				m_pfnRead;  // called to actually read from stream
	/*0C*/ WriteFNT				m_pfnWrite; // called to actually write to stream

	// virtual methods
	virtual ~NiBinaryStream();
};
STATIC_ASSERT(sizeof(NiBinaryStream) == 0x10);


// 30
class NiFile : public NiBinaryStream
{
public:
	enum FileModes
	{
		kFileMode_ReadOnly      = 0,
		kFileMode_WriteOnly     = 1,
		kFileMode_AppendOnly    = 2,
	};

	// members
	//     /*00*/ NiBinaryStream
	/*10*/ UInt32        m_uiBufferAllocSize;	// size of buffer
	/*14*/ UInt32        m_uiBufferReadSize;	// init to 0
	/*18*/ UInt32		 m_unk18;				// init to 0 when initializing the buffer, not present in Oblivion
												// appears to be another offset into the file, m_uiPos == this member?
	/*1C*/ UInt32        m_uiPos;				// init to 0
	/*20*/ void*         m_pBuffer;
	/*24*/ FILE*         m_pFile;
	/*28*/ UInt32        m_eMode;				// file mode
	/*2C*/ UInt8         m_bGood;				// true if file is open
	/*2D*/ UInt8		 m_pad2D[3];
};
STATIC_ASSERT(sizeof(NiFile) == 0x30);
