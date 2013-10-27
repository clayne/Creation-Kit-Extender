#pragma once

// Derived from the Setting class in CSE's API
// 0C
class Setting
{
public:
	enum SettingTypes
	{
		kSetting_Bool           = 0x0,  // 'b' size 1
		kSetting_Char           = 0x1,  // 'c' size 1
		kSetting_UnsignedChar   = 0x2,  // 'h' size 1
		kSetting_SignedInt      = 0x3,  // 'i' size 4
		kSetting_UnsignedInt    = 0x4,  // 'u' size 4
		kSetting_Float          = 0x5,  // 'f' size 4
		kSetting_String         = 0x6,  // 'S'/'s' size indet. See note below^^
		kSetting_RGB            = 0x7,  // 'r' size 4. alpha byte set to 255 (?)
		kSetting_RGBA           = 0x8,  // 'a' size 4
		kSetting__MAX           = 0x9
	};

	// union for various value types
	union SettingValue
	{
		bool        b;
		char        c;
		UInt8       h;
		SInt32      i;
		UInt32      u;
		float       f;
		const char* s;
		struct
		{
			// alpha is least sig. byte, *opposite* standard windows order
			UInt8   alpha;
			UInt8   blue;
			UInt8   green;
			UInt8   red;
		}			rgba;
	};

	// members
	//     /*00*/ void**		vtbl
	/*04*/ SettingValue			value;
	/*08*/ const char*			name;   // must begin with one of the type characters

	virtual ~Setting();
};
STATIC_ASSERT(sizeof(Setting) == 0x0C);

// wrappers used to automatically add instances to a particular collection
typedef Setting					SettingT_INISettingCollection;				// actually SettingT<INISettingCollection>
typedef Setting					SettingT_INIPrefSettingCollection;			// actually SettingT<INIPrefSettingCollection>