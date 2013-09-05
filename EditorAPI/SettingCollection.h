#pragma once

#include "TESForm.h"
#include "Setting.h"
#include "BSTCaseInsensitiveStringMap.h"

// Mostly copied from CSE's API
/*
	SettingCollection is an abstract interface for managing settings from a common source (file, registery, etc.)
	INISettingCollection and it's descendents manage settings from the assorted INI files
	RegSettingCollection managed windows registry values.
	GameSettingCollection manages the configurable game settings.

	NOTE:
	SettingCollection and it's abstract descendents are actually templated to accept arbitrary data types.  The only template
	parameter used is 'Setting', so functionally the classes defined here are identical to those defined in the game/CS.
	However, as with many of the template classes reproduced (rather than imported) in COEF, dynamic casting may not work
	as expected with these types.
*/

class   TESFile;

// 10C
class SettingCollection // actually SettingCollection<Setting*>
{
public:
	// members
	//     /*000*/ void**           vtbl;
	/*004*/ char            filename[0x104];	// full path of ini file for ini settings, ignored for other collections
	/*108*/ void*           fileObject;			// actual type depends on class, but must be nonzero when file is open
												// TESFile* for gmst, HKEY for RegSetting, this* pointer for INISetting

	virtual ~SettingCollection();
};

// 114
class SettingCollectionList : public SettingCollection  // actually SettingCollectionList<Setting*>
{
public:
	typedef BSSimpleList<Setting*> SettingListT;

	// members
	//     /*000*/ SettingCollection
	/*10C*/ SettingListT	settingList;

	// methods
	Setting*				LookupByName(const char* Name);
};

// 114
class INISettingCollection : public SettingCollectionList
{
public:
	// fileName holds the ini file name
	// fileObject holds the this* pointer when file is "open", and is zero otherwise
	// file is not actually opened; all i/o uses Get/WritePrivateProfileString()

	// no additional members

	static INISettingCollection**		Instance;
};

// 114
class INIPrefSettingCollection : public SettingCollectionList
{
public:
	// no additional members

	static INIPrefSettingCollection**	Instance;
};

// 120
class SettingCollectionMap : public SettingCollection   // actually SettingCollectionMap<Setting*>
{
public:
	typedef BSTCaseInsensitiveStringMap<Setting*>	SettingMapT;

	// members
	//     /*000*/ SettingCollection
	/*10C*/ SettingMapT      settingMap;
};

// 120
class GameSettingCollection : public SettingCollectionMap
{
public:
	// fileName seems to be ignored
	// fileObject holds a TESFile* for loading/saving the setting

	// no additional members

	static GameSettingCollection**		Instance;
};