#include "SettingCollection.h"

INISettingCollection**				INISettingCollection::Instance = (INISettingCollection**)VOLATILE(0x01B5A6B8);
INIPrefSettingCollection**			INIPrefSettingCollection::Instance = (INIPrefSettingCollection**)VOLATILE(0x01B55D8C);

GameSettingCollection**				GameSettingCollection::Instance = (GameSettingCollection**)VOLATILE(0x012BE3A8);

Setting* SettingCollectionList::LookupByName( const char* Name )
{
	for (SettingListT::Iterator Itr = settingList.Begin(); Itr.End() == false && Itr.Get(); ++Itr)
	{
		Setting* Current = Itr.Get();
		SME_ASSERT(Current);

		if (!_stricmp(Name, Current->name))
			return Current;
	}

	return NULL;
}