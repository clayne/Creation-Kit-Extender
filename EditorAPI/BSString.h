#pragma once

// aka StringCache::Ref
// 04
class BSFixedString
{
public:
	// members
	/*00*/ const char*			data;
};
STATIC_ASSERT(sizeof(BSFixedString) == 0x4);

// 04
class IBGSLocalizedString
{
public:
	// members
	//     /*00*/ void**		vtbl

	virtual ~IBGSLocalizedString();
};
STATIC_ASSERT(sizeof(IBGSLocalizedString) == 0x4);

// 08
class BGSLocalizedString : public IBGSLocalizedString
{
public:
	// members
	//     IBGSLocalizedString
	/*04*/ BSFixedString		string;
};
STATIC_ASSERT(sizeof(BGSLocalizedString) == 0x8);

// 0C
class BGSLocalizedStringDL : public IBGSLocalizedString
{
public:
	// members
	//     IBGSLocalizedString
	/*04*/ SInt32				unk04;		// init to -1, index into the string table?
	/*08*/ BSFixedString		string;
};
STATIC_ASSERT(sizeof(BGSLocalizedStringDL) == 0xC);

// 08
class BGSLocalizedStringIL : public IBGSLocalizedString
{
public:
	// members
	//     IBGSLocalizedString
	/*04*/ BSFixedString		string;
};
STATIC_ASSERT(sizeof(BGSLocalizedStringIL) == 0x8);

// legacy implementation
// 08
class BSString
{
public:
	// members
	/*00*/ char*				data;
	/*04*/ UInt16				dataLength;
	/*06*/ UInt16				bufferLength;
};
STATIC_ASSERT(sizeof(BSString) == 0x8);
