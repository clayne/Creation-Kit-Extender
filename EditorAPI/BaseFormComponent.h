#pragma once

#include "BSString.h"
#include "BSTArray.h"
#include "BSSimpleList.h"

class TESForm;
class EnchantmentItem;
class IngredientItem;
class TESGlobal;
class TESSound;
class TESRace;
class SpellItem;
class TESLevSpell;
class TESShout;
class TESFaction;
class TESIdleForm;
class BGSExplosion;
class BGSDebris;
class BGSEquipSlot;
class TESImageSpace;
class TESImageSpaceModifier;
class BGSSoundDescriptorForm;
class TESObjectARMO;
class BGSKeyword;
class BGSImpactDataSet;
class BGSMaterialType;
class TESObjectSTAT;
class BGSAttackData;
class BGSListForm;
class BGSPerk;
class TESCombatStyle;
class TESPackage;
class BGSTextureSet;
class TESActorBase;

// 04
class BaseFormComponent
{
public:
	// members
	//     /*00*/ void**		vtbl
	
	virtual ~BaseFormComponent();
};
STATIC_ASSERT(sizeof(BaseFormComponent) == 0x4);

// 04
class BGSPreloadable : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	
	// no additional members
};
STATIC_ASSERT(sizeof(BGSPreloadable) == 0x4);

// 18
class TESTexture : public BaseFormComponent
{
public:
	// a NiDevImageConverter related class, bitmap data probably
	// 0C
	struct TextureData
	{
		/*00*/ UInt32			width;
		/*04*/ UInt32			height;
		/*08*/ void*			unk08;			// some struct { BITMAPINFO, bitmap data(length = 4 * width * height) }
	};

	// members
	//     /*00*/ BaseFormComponent
	/*04*/ BSFixedString		path;
	/*08*/ TextureData*			unk08;
	/*0C*/ int					textBoxID;		// 2496
	/*10*/ int					buttonID;		// 2423
	/*14*/ int					previewID;		// 1058
};
STATIC_ASSERT(sizeof(TESTexture) == 0x18);

// 18
class TESIcon : public TESTexture
{
public:
	// members
	//     /*00*/ TESTexture

	// no additional members
};
STATIC_ASSERT(sizeof(TESIcon) == 0x18);

// 1C
class BGSMessageIcon : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ TESIcon				icon; 

};
STATIC_ASSERT(sizeof(BGSMessageIcon) == 0x1C);

// 18
class TESTexture1024 : public TESTexture
{
public:
	// members
	//     /*00*/ TESTexture

	// no additional members
};
STATIC_ASSERT(sizeof(TESTexture1024) == 0x18);

// 08
class BGSAttackDataForm : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ BSTSmartPointer<BGSAttackData>	attackData;
};
STATIC_ASSERT(sizeof(BGSAttackDataForm) == 0x8);

// 20
class TESAIForm : public BaseFormComponent
{
public:
	enum
	{
		kAggroRadius_Warn			= 0,
		kAggroRadius_WarnAttack,
		kAggroRadius_Attack,

		kAggroRadius__MAX
	};

	typedef BSSimpleList<TESPackage*>	PackageListT;

	// members
	//     /*00*/ BaseFormComponent
	/*04*/ UInt8				aggressionLevel;		// set to ActorValue::kAVTrait_XXX_
	/*05*/ UInt8				confidenceLevel;
	/*06*/ UInt8				energy;					// integral value
	/*07*/ UInt8				moralityLevel;
	/*08*/ UInt8				moodLevel;
	/*09*/ UInt8				assistanceLevel;
	/*0A*/ UInt8				aggroRadiusBehaviour;
	/*0B*/ UInt8				pad0B;
	/*0C*/ SInt32				aggroRadius[3];			// set to -1 if >= 0xFFFF
	/*18*/ PackageListT			packages;
};
STATIC_ASSERT(sizeof(TESAIForm) == 0x20);

// 34
class TESActorBaseData : public BaseFormComponent
{
public:
	enum
	{
		kActorFlags_Essential						= 1 << 1,
		kActorFlags_Respawn							= 1 << 3,
		kActorFlags_Unique							= 1 << 5,
		kActorFlags_DoesntAffectStealthMeter		= 1 << 6,
		kActorFlags_PCLevelMulti					= 1 << 7,
		kActorFlags_Encumbrance						= 1 << 11,
		kActorFlags_Unk13							= 1 << 13,			// checkbox 1183
		kActorFlags_Summonable						= 1 << 14,
		kActorFlags_BleedOutOverride				= 1 << 18,
		kActorFlags_SimpleActor						= 1 << 20,
		kActorFlags_IsGhost							= 1 << 29,
		kActorFlags_Invulnerable					= 1 << 31,
	};

	enum
	{
		kTemplateDataFlags_UseTraits				= 1 << 0,
		kTemplateDataFlags_UseStats					= 1 << 1,
		kTemplateDataFlags_UseFactions				= 1 << 2,
		kTemplateDataFlags_UseSpellList				= 1 << 3,
		kTemplateDataFlags_UseAIData				= 1 << 4,
		kTemplateDataFlags_UseAIPackages			= 1 << 5,
		kTemplateDataFlags_UseBaseData				= 1 << 7,
		kTemplateDataFlags_UseInventory				= 1 << 8,
		kTemplateDataFlags_UseScript				= 1 << 9,
		kTemplateDataFlags_UseDefPackList			= 1 << 10,
		kTemplateDataFlags_UseAttackData			= 1 << 11,
		kTemplateDataFlags_UseKeywords				= 1 << 12,
	};

	// 08
	struct FactionData
	{
		/*00*/ TESFaction*		faction;
		/*04*/ SInt8			rank;
		/*05*/ UInt8			pad05[3];
	};

	typedef BSTArray<FactionData*>		FactionArrayT;

	// members
	//     /*00*/ BaseFormComponent
	/*04*/ UInt32				flags;
	/*08*/ UInt16				magickaOffset;
	/*0A*/ UInt16				staminaOffset;
	/*0C*/ UInt16				level;				// also doubles as level multiplier (value * 1000)
	/*0E*/ UInt16				minLevel;
	/*10*/ UInt16				maxLevel;
	/*12*/ UInt16				speed;				// init to 100
	/*14*/ UInt16				dispositionBase;
	/*16*/ UInt16				templateDataFlags;
	/*18*/ UInt16				healthOffset;
	/*1A*/ UInt16				bleedOutOverride;
	/*1C*/ TESForm*				deathItem;
	/*20*/ BGSVoiceType*		voiceType;
	/*24*/ TESActorBase*		templateData;
	/*28*/ FactionArrayT		factionData;
};
STATIC_ASSERT(sizeof(TESActorBaseData) == 0x34);


// 8
class TESAttackDamageForm : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ UInt16				damage;
	/*06*/ UInt16				pad06;
};
STATIC_ASSERT(sizeof(TESAttackDamageForm) == 0x8);

// 1C
class TESModel : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ BSFixedString		modelPath;
	/*08*/ UInt32				unk08;
	/*0C*/ UInt32				unk0C;
	/*10*/ UInt16				unk10;
	/*12*/ UInt8				unk12;
	/*13*/ UInt8				unk13;
	/*14*/ int					textboxID;		// 2421
	/*18*/ int					buttonID;		// 2420
};
STATIC_ASSERT(sizeof(TESModel) == 0x1C);

// 28
class TESModelTextureSwap : public TESModel
{
public:
	// 0C
	struct SwapData
	{
		/*00*/ BGSTextureSet*	texSet;
		/*04*/ SInt32			unk04;			// init to -1, some sort of index?
		/*08*/ BSFixedString	name;
	};

	// members
	//     /*00*/ TESModel
	/*1C*/ int					unk1C;			// same as textboxID, 2421
	/*20*/ SwapData*			swaps;
	/*24*/ UInt32				count;
};
STATIC_ASSERT(sizeof(TESModelTextureSwap) == 0x28);

// 1C
class TESModelRDT : public TESModel
{
public:
	// members
	//     /*00*/ TESModel

	// no additional members
};
STATIC_ASSERT(sizeof(TESModelRDT) == 0x1C);

// 1C
class TESModelTri : public TESModel
{
public:
	// members
	//     /*00*/ TESModel

	// no additional members
};
STATIC_ASSERT(sizeof(TESModelTri) == 0x1C);

// D8
class TESBipedModelForm : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ TESModelTextureSwap		textureSwap[2];
	/*54*/ TESIcon					icon[2];
	/*84*/ BGSMessageIcon			msgIcon[2];
	/*BC*/ TESModelRDT				modelRDT;
};
STATIC_ASSERT(sizeof(TESBipedModelForm) == 0xD8);

// 0C
class BGSBipedObjectForm : public BaseFormComponent
{
public:
	// applicable to DefaultRace
	enum
	{
		kPart_Head =		1 << 0,
		kPart_Hair =		1 << 1,
		kPart_Body =		1 << 2,
		kPart_Hands =		1 << 3,
		kPart_Forearms =	1 << 4,
		kPart_Amulet =		1 << 5,
		kPart_Ring =		1 << 6,
		kPart_Feet =		1 << 7,
		kPart_Calves =		1 << 8,
		kPart_Shield =		1 << 9,
		kPart_Unnamed10 =	1 << 10,
		kPart_LongHair =	1 << 11,
		kPart_Circlet =		1 << 12,
		kPart_Ears =		1 << 13,
		kPart_Unnamed14 =	1 << 14,
		kPart_Unnamed15 =	1 << 15,
		kPart_Unnamed16 =	1 << 16,
		kPart_Unnamed17 =	1 << 17,
		kPart_Unnamed18 =	1 << 18,
		kPart_Unnamed19 =	1 << 19,
		kPart_Unnamed20 =	1 << 20,
		kPart_Unnamed21 =	1 << 21,
		kPart_Unnamed22 =	1 << 22,
		kPart_Unnamed23 =	1 << 23,
		kPart_Unnamed24 =	1 << 24,
		kPart_Unnamed25 =	1 << 25,
		kPart_Unnamed26 =	1 << 26,
		kPart_Unnamed27 =	1 << 27,
		kPart_Unnamed28 =	1 << 28,
		kPart_Unnamed29 =	1 << 29,
		kPart_Unnamed30 =	1 << 30,
		kPart_FX01 =		1 << 31,
	};

	enum
	{
		kWeightClass_Light =	0,
		kWeightClass_Heavy,
		kWeightClass_None,
	};

	// 8
	struct Data
	{
		/*00*/ UInt32			parts;
		/*04*/ UInt32			weightClass;		// init to kWeightClass_None
	};

	// members
	//     /*00*/ BaseFormComponent
	/*04*/ Data					data;
};
STATIC_ASSERT(sizeof(BGSBipedObjectForm) == 0xC);

// 0C
class TESContainer : public BaseFormComponent
{
public:
	// 0C
	struct ContentEntry
	{
		// 10
		struct StackData
		{
			/*00*/ TESForm*			owner;		// probably a union, either a TESActorBase* or TESFaction*
			/*04*/ TESGlobal*		global;
			/*08*/ float			health;		// init (and normalized) to 1.0
			/*0C*/ UInt32			unk0C;		// not init'd in ctor, never accessed?
		};

		/*00*/ SInt32			count;
		/*04*/ TESForm*			form;
		/*08*/ StackData*		data;
	};

	/// members
	//     /*00*/ BaseFormComponent
	/*04*/ ContentEntry**		entries;				
	/*08*/ UInt32				count;
};
STATIC_ASSERT(sizeof(TESContainer) == 0x0C);

typedef TESContainer::ContentEntry::StackData		ItemStackData;

// 14
class TESDescription : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ int						textBoxID;		// 1138
	/*08*/ BGSLocalizedStringDL		description;
};
STATIC_ASSERT(sizeof(TESDescription) == 0x14);

// 0C
class TESEnchantableForm : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ EnchantmentItem*			enchantment;
	/*08*/ UInt16					enchantmentType;
	/*0A*/ UInt16					maxCharge;
};
STATIC_ASSERT(sizeof(TESEnchantableForm) == 0xC);

// 0C
class TESFullName : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ BGSLocalizedString		name;
};
STATIC_ASSERT(sizeof(TESEnchantableForm) == 0xC);

// 0C
class TESFullName : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ BGSLocalizedString		name;
};
STATIC_ASSERT(sizeof(TESFullName) == 0xC);

// 10
class TESLeveledList : public BaseFormComponent
{
public:
	enum
	{
		kFlags_CalcForAllLevels		= 1 << 0,
		kFlags_CalcForEachItem		= 1 << 1,
		kFlags_UseAll				= 1 << 2,
		kFlags_SpecialLoot			= 1 << 3,
	};

	// 0C
	struct ContentEntry
	{
		/*00*/ TESForm*				form;
		/*04*/ UInt16				count;
		/*06*/ UInt16				level;
		/*08*/ ItemStackData*		data;
	};

	// members
	//     /*00*/ BaseFormComponent
	/*04*/ ContentEntry*			entries;
	/*08*/ UInt8					chanceNone;
	/*09*/ UInt8					flags;
	/*0A*/ UInt8					count;		// max = 0xFF, obviously
	/*0B*/ UInt8					pad0B;
	/*0C*/ TESGlobal*				global;
};
STATIC_ASSERT(sizeof(TESLeveledList) == 0x10);

// 10
class TESProduceForm : public BaseFormComponent
{
public:
	enum
	{
		kSeason_Spring		= 0,
		kSeason_Summer,
		kSeason_Fall,
		kSeason_Winter,

		kSeason__MAX
	};

	// members
	//     /*00*/ BaseFormComponent
	/*04*/ IngredientItem*		ingredient;
	/*08*/ TESSound*			harvestSound;
	/*0C*/ UInt8				produceChance[4];
};
STATIC_ASSERT(sizeof(TESProduceForm) == 0x10);

// 08
class TESQualityForm : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ float				quality;
};
STATIC_ASSERT(sizeof(TESQualityForm) == 0x8);

// 08
class TESRaceForm : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ TESRace*				race;
};
STATIC_ASSERT(sizeof(TESRaceForm) == 0x8);

// 08
class TESSpellList : public BaseFormComponent
{
public:
	// 18
	struct Data
	{
		/*00*/ SpellItem**			spells;		// null terminated
		/*04*/ TESLevSpell**		levSpells;
		/*08*/ TESShout*			shouts;
		/*0C*/ UInt32				spellCount;
		/*10*/ UInt32				levSpellCount;
		/*14*/ UInt32				shoutCount;
	};

	// members
	//     /*00*/ BaseFormComponent
	/*04*/ Data*				spells;
};
STATIC_ASSERT(sizeof(TESSpellList) == 0x8);

// 08
class TESValueForm : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ UInt32				value;
};
STATIC_ASSERT(sizeof(TESValueForm) == 0x8);

// 08
class TESWeightForm : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ float				weight;
};
STATIC_ASSERT(sizeof(TESWeightForm) == 0x8);

// 10
class TESReactionForm : public BaseFormComponent
{
public:
	// 0C
	struct ReactionInfo
	{
		enum
		{
			kCombatReaction_Neutral		= 0,
			kCombatReaction_Enemy,
			kCombatReaction_Ally,
			kCombatReaction_Friend,

			kCombatReaction__MAX,
		};

		/*00*/ TESFaction*			faction;
		/*04*/ SInt32				modifier;
		/*08*/ UInt32				combatReaction;
	};

	typedef BSSimpleList<ReactionInfo*> ReactionListT;

	// members
	//     /*00*/ BaseFormComponent
	/*04*/ ReactionListT			reactionList;
	/*0C*/ UInt8					unk0C;			// initialized to 11
	/*0D*/ UInt8					pad0D[3];
};
STATIC_ASSERT(sizeof(TESReactionForm) == 0x10);

// 10
class BGSIdleCollection : public BaseFormComponent
{
public:
	enum
	{
		kFlags_RunInSequence	= 1 << 0,			// otherwise, randomly pick an idle
		kFlags_DoOnce			= 1 << 2,
	};

	// members
	//     /*00*/ BaseFormComponent
	/*04*/ UInt8				flags;
	/*05*/ UInt8				idleCount;
	/*06*/ UInt16				pad06;
	/*08*/ TESIdleForm**		idles;
	/*0C*/ float				idleTimer;
};
STATIC_ASSERT(sizeof(BGSIdleCollection) == 0x10);

// 08
class BGSDestructibleObjectForm : public BaseFormComponent
{
public:
	// 0C
	struct DestructionData
	{
		// 18
		struct Data
		{
			enum
			{
				kFlags_CapDamage	= 1 << 0,
				kFlags_Disable		= 1 << 1,
				kFlags_Destroy		= 1 << 2,
				kFlags_IgnoreExtDmg	= 1 << 3,
			};

			/*00*/ UInt8						damageStage;	// range = 0-8
			/*01*/ UInt8						health;			// percentage
			/*02*/ UInt8						flags;
			/*03*/ UInt8						pad03;
			/*04*/ UInt32						selfDPS;
			/*08*/ BGSExplosion*				explosion;
			/*0C*/ BGSDebris*					debris;			
			/*10*/ UInt32						debrisCount;
			/*14*/ TESModelTextureSwap*			replacementModel;
		};

		/*00*/ SInt32		health;
		/*04*/ UInt8		count;
		/*05*/ UInt8		vatsTargetable;
		/*06*/ UInt16		pad05;
		/*08*/ Data**		entries;
	};

	// members
	//     /*00*/ BaseFormComponent
	/*04*/ DestructionData*			data;
};
STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 0x8);

// 08
class BGSEquipType : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ BGSEquipSlot*		slot;
};
STATIC_ASSERT(sizeof(BGSEquipType) == 0x8);

// 08
class TESImageSpaceModifiableForm : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ TESImageSpaceModifier*		imageSpaceMod;
};
STATIC_ASSERT(sizeof(TESImageSpaceModifiableForm) == 0x8);

// 0C
class BGSPickupPutdownSounds : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ BGSSoundDescriptorForm*		pickUp;
	/*08*/ BGSSoundDescriptorForm*		putDown;
};
STATIC_ASSERT(sizeof(BGSPickupPutdownSounds) == 0xC);

// 0C
class BGSSkinForm : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ TESObjectARMO*			armor;
	/*08*/ int						comboBoxID;		// 1087
};
STATIC_ASSERT(sizeof(BGSSkinForm) == 0xC);

// 0C
class BGSKeywordForm : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ BGSKeyword**			keywords;
	/*08*/ UInt32				count;
};
STATIC_ASSERT(sizeof(BGSKeywordForm) == 0xC);

// 0C
class BGSBlockBashData : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ BGSImpactDataSet*			impactDataSet;
	/*08*/ BGSMaterialType*				materialType;
};
STATIC_ASSERT(sizeof(BGSBlockBashData) == 0xC);

// 08
class BGSMenuDisplayObject : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ TESObjectSTAT*				menuDisplayStatic;
};
STATIC_ASSERT(sizeof(BGSMenuDisplayObject) == 0x8);

// 14
class BGSOverridePackCollection : public BaseFormComponent
{
public:
	// members
	//     /*00*/ BaseFormComponent
	/*04*/ BGSListForm*				spectatorOverride;			// form lists contain TESPackage forms
	/*08*/ BGSListForm*				observeDeadBodyOverride;
	/*0C*/ BGSListForm*				guardWarnOverride;
	/*10*/ BGSListForm*				combatOverride;
};
STATIC_ASSERT(sizeof(BGSOverridePackCollection) == 0x14);

// 08
class BGSPerkRankArray : public BaseFormComponent
{
public:
	// 08
	struct Entry
	{
		/*00*/ BGSPerk*				perk;
		/*04*/ UInt8				rank;		// always 1?
		/*05*/ UInt8				pad05[3];
	};

	typedef BSTArray<Entry*>		PerkArrayT;

	// members
	//     /*00*/ BaseFormComponent
	/*04*/ PerkArrayT*				data;
};
STATIC_ASSERT(sizeof(BGSPerkRankArray) == 0x8);
