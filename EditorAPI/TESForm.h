#pragma once

#include "BaseFormComponent.h"

class TESFile;

// 0C
struct FormTypeInfo
{
	/*00*/ UInt32          formType;	// form type code, also offset in array
	/*04*/ const char*     shortName;	// offset to 4-letter type descriptor: 'GRUP', 'ARMO', etc.
	/*08*/ UInt32          chunkType;	// appears to be name string in byte-reversed order, used to mark form records
};

// Version control tracking data, also used by TESFile
// 04
struct TrackingData
{
	/*00*/ UInt16  date;               // low byte is day of month, high byte is number of months with 1 = Jan. 2003 (Decembers are a little weird)
	/*02*/ UInt8   lastUser;           // userID that last had this form checked out
	/*03*/ UInt8   currentUser;        // userID that has this form checked out
};

// 1C
class TESForm : public BaseFormComponent
{
public:
	enum FormType
	{
		kFormType_None = 0,			//	00	NONE
		kFormType_TES4,				//	01	TES4
		kFormType_Group,			//	02	GRUP	
		kFormType_GMST,				//	03	GMST	GameSetting
		kFormType_Keyword,			//	04	KYWD	BGSKeyword
		kFormType_LocationRef,		//	05	LCRT	BGSLocationRefType
		kFormType_Action,			//	06	AACT	BGSAction
		kFormType_TextureSet,		//	07	TXST	BGSTextureSet
		kFormType_MenuIcon,			//	08	MICN	BGSMenuIcon
		kFormType_Global,			//	09	GLOB	TESGlobal
		kFormType_Class,			//	0A	CLAS	TESClass
		kFormType_Faction,			//	0B	FACT	TESFaction
		kFormType_HeadPart,			//	0C	HDPT	BGSHeadPart
		kFormType_Eyes,				//	0D	EYES	TESEyes
		kFormType_Race,				//	0E	RACE	TESRace
		kFormType_Sound,			//	0F	SOUN	TESSound
		kFormType_AcousticSpace,	//	10	ASPC	BGSAcousticSpace
		kFormType_Skill,			//	11	SKIL	Replaced by ActorValueInfo
		kFormType_EffectSetting,	//	12	MGEF	EffectSetting
		kFormType_Script,			//	13	SCPT	Script
		kFormType_LandTexture,		//	14	LTEX	TESLandTexture
		kFormType_Enchantment,		//	16	ENCH	EnchantmentItem
		kFormType_Spell,			//	16	SPEL	SpellItem
		kFormType_ScrollItem,		//	17	SCRL	ScrollItem
		kFormType_Activator,		//	18	ACTI	TESObjectACTI
		kFormType_TalkingActivator,	//	19	TACT	BGSTalkingActivator
		kFormType_Armor,			//	1A	ARMO	TESObjectARMO
		kFormType_Book,				//	1B	BOOK	TESObjectBOOK
		kFormType_Container,		//	1C	CONT	TESObjectCONT
		kFormType_Door,				//	1D	DOOR	TESObjectDOOR
		kFormType_Ingredient,		//	1E	INGR	IngredientItem
		kFormType_Light,			//	1F	LIGH	TESObjectLIGH
		kFormType_Misc,				//	20	MISC	TESObjectMISC
		kFormType_Apparatus,		//	21	APPA	BGSApparatus
		kFormType_Static,			//	22	STAT	TESObjectSTAT
		kFormType_StaticCollection,	//	23	SCOL	BGSStaticCollection
		kFormType_MovableStatic,	//	24	MSTT	BGSMovableStatic
		kFormType_Grass,			//	24	GRAS	TESGrass
		kFormType_Tree,				//	26	TREE	TESObjectTREE
		kFormType_Flora,			//	27	FLOR	TESFlora
		kFormType_Furniture,		//	28	FURN	TESFurniture
		kFormType_Weapon,			//	29	WEAP	TESObjectWEAP
		kFormType_Ammo,				//	2A	AMMO	TESAmmo
		kFormType_NPC,				//	2B	NPC_	TESNPC
		kFormType_LeveledCharacter,	//	2C	LVLN	TESLevCharacter
		kFormType_Key,				//	2D	KEYM	TESKey
		kFormType_Potion,			//	2E	ALCH	AlchemyItem
		kFormType_IdleMarker,		//	2F	IDLM	BGSIdleMarker
		kFormType_Note,				//	30	NOTE	BGSNote
		kFormType_ConstructibleObject,
									//	31	COBJ	BGSConstructibleObject
		kFormType_Projectile,		//	32	PROJ	BGSProjectile
		kFormType_Hazard,			//	33	HAZD	BGSHazard
		kFormType_SoulGem,			//	34	SLGM	TESSoulGem
		kFormType_LeveledItem,		//	35	LVLI	TESLevItem
		kFormType_Weather,			//	36	WTHR	TESWeather
		kFormType_Climate,			//	37	CLMT	TESClimate
		kFormType_SPGD,				//	38	SPGD	BGSShaderParticleGeometryData
		kFormType_ReferenceEffect,	//	39	RFCT	BGSReferenceEffect
		kFormType_Region,			//	3A	REGN	TESRegion
		kFormType_NAVI,				//	3B	NAVI	NavMeshInfoMap
		kFormType_Cell,				//	3C	CELL	TESObjectCELL
		kFormType_Reference,		//	3D	REFR	TESObjectREFR / Actor
		kFormType_Character,		//	3E	ACHR	Character / PlayerCharacter
		kFormType_Missile,			//	3F	PMIS	MissileProjectile
		kFormType_Arrow,			//	40	PARW	ArrowProjectile
		kFormType_Grenade,			//	41	PGRE	GrenadeProjectile
		kFormType_BeamProj,			//	42	PBEA	BeamProjectile
		kFormType_FlameProj,		//	43	PFLA	FlameProjectile
		kFormType_ConeProj,			//	44	PCON	ConeProjectile
		kFormType_BarrierProj,		//	45	PBAR	BarrierProjectile
		kFormType_PHZD,				//	46	PHZD	Hazard
		kFormType_WorldSpace,		//	47	WRLD	TESWorldSpace
		kFormType_Land,				//	48	LAND	TESObjectLAND
		kFormType_NAVM,				//	49	NAVM	NavMesh
		kFormType_TLOD,				//	4A	TLOD	?
		kFormType_Topic,			//	4B	DIAL	TESTopic
		kFormType_TopicInfo,		//	4C	INFO	TESTopicInfo
		kFormType_Quest,			//	4D	QUST	TESQuest
		kFormType_Idle,				//	4E	IDLE	TESIdleForm
		kFormType_Package,			//	4F	PACK	TESPackage
		kFormType_CombatStyle,		//	50	CSTY	TESCombatStyle
		kFormType_LoadScreen,		//	51	LSCR	TESLoadScreen
		kFormType_LeveledSpell,		//	52	LVSP	TESLevSpell
		kFormType_ANIO,				//	53	ANIO	TESObjectANIO
		kFormType_Water,			//	54	WATR	TESWaterForm
		kFormType_EffectShader,		//	55	EFSH	TESEffectShader
		kFormType_TOFT,				//	56	TOFT	?
		kFormType_Explosion,		//	57	EXPL	BGSExplosion
		kFormType_Debris,			//	58	DEBR	BGSDebris
		kFormType_ImageSpace,		//	59	IMGS	TESImageSpace
		kFormType_ImageSpaceMod,	//	5A	IMAD	TESImageSpaceModifier
		kFormType_ListForm,			//	5B	FLST	BGSListForm
		kFormType_Perk,				//	5C	PERK	BGSPerk
		kFormType_BodyPartData,		//	5D	BPTD	BGSBodyPartData
		kFormType_AddonNode,		//	5E	ADDN	BGSAddonNode
		kFormType_ActorValueInfo,	//	5F	AVIF	ActorValueInfo
		kFormType_CameraShot,		//	60	CAMS	BGSCameraShot
		kFormType_CameraPath,		//	61	CPTH	BGSCameraPath
		kFormType_VoiceType,		//	62	VTYP	BGSVoiceType
		kFormType_MaterialType,		//	63	MATT	BGSMaterialType
		kFormType_ImpactData,		//	64	IPCT	BGSImpactData
		kFormType_ImpactDataSet,	//	65	IPDS	BGSImpactDataSet
		kFormType_ArmorAddon,		//	66	ARMA	TESObjectARMA
		kFormType_EncounterZone,	//	67	ECZN	BGSEncounterZone
		kFormType_Location,			//	68	LCTN	BGSLocation
		kFormType_Message,			//	69	MESH	BGSMessage
		kFormType_Ragdoll,			//	6A	RGDL	BGSRagdoll
		kFormType_DOBJ,				//	6B	DOBJ	BGSDefaultObjectManager
		kFormType_LightingTemplate,	//	6C	LGTM	BGSLightingTemplate
		kFormType_MusicType,		//	6D	MUSC	BGSMusicType
		kFormType_Footstep,			//	6E	FSTP	BGSFootstep
		kFormType_FootstepSet,		//	6F	FSTS	BGSFootstepSet
		kFormType_StoryBranchNode,	//	70	SMBN	BGSStoryManagerBranchNode
		kFormType_StoryQuestNode,	//	71	SMQN	BGSStoryManagerQuestNode
		kFormType_StoryEventNode,	//	72	SMEN	BGSStoryManagerEventNode
		kFormType_DialogueBranch,	//	73	DLBR	BGSDialogueBranch
		kFormType_MusicTrack,		//	74	MUST	BGSMusicTrackFormWrapper
		kFormType_DialogueView,		//	75	DLVW	BGSDialogueView
		kFormType_WordOfPower,		//	76	WOOP	TESWordOfPower
		kFormType_Shout,			//	77	SHOU	TESShout
		kFormType_EquipSlot,		//	78	EQUP	BGSEquipSlot
		kFormType_Relationship,		//	79	RELA	BGSRelationship
		kFormType_Scene,			//	7A	SCEN	BGSScene
		kFormType_AssociationType,	//	7B	ASTP	BGSAssociationType
		kFormType_Outfit,			//	7C	OTFT	BGSOutfit
		kFormType_ArtObject,		//	7D	ARTO	BGSArtObject
		kFormType_Material,			//	7E	MATO	BGSMaterialObject
		kFormType_MovementType,		//	7F	MOVT	BGSMovementType
		kFormType_SoundDescriptor,	//	80	SNDR	BGSSoundDescriptorForm
		kFormType_DualCastData,		//	81	DUAL	BGSDualCastData
		kFormType_SoundCategory,	//	82	SNCT	BGSSoundCategory
		kFormType_SoundOutput,		//	83	SOPM	BGSSoundOutput
		kFormType_CollisionLayer,	//	84	COLL	BGSCollisionLayer
		kFormType_ColorForm,		//	85	CLFM	BGSColorForm
		kFormType_ReverbParam,		//	86	REVB	BGSReverbParameters
		
		kFormType__MAX,
	};

	enum
	{
		kFormFlags_FromMasterFile				= 1 << 0,
		kFormFlags_Modified						= 1 << 1,
		kFormFlags_Unk02						= 1 << 2,
		kFormFlags_Linked						= 1 << 3,
		kFormFlags_Deleted						= 1 << 5,
		kFormFlags_Unk06						= 1 << 6,
		kFormFlags_Unk08						= 1 << 8,
		kFormFlags_Unk09						= 1 << 9,
		kFormFlags_Temporary					= 1 << 14,
		kFormFlags_Unk17						= 1 << 17,
		kFormFlags_Unk19						= 1 << 19,
		kFormFlags_Unk25						= 1 << 25,
	};

	// 08
	struct OverrideData
	{
		/*00*/ TESFile**		files;
		/*04*/ UInt32			count;
	};

	// members
	//     /*00*/ BaseFormComponent
	/*04*/ OverrideData*		overrides;
	/*08*/ UInt32				formFlags;
	/*0C*/ UInt32				formID;
	/*10*/ BSFixedString		editorID;
	/*14*/ TrackingData			versionControlData;
	/*18*/ UInt8				unk18;						// init to 0, probably VC related
	/*19*/ UInt8				unk19;						// init to 1, VC related? 
	/*1A*/ UInt8				formType;
	/*1B*/ UInt8				pad1B;
};
STATIC_ASSERT(sizeof(TESForm) == 0x1C);
STATIC_ASSERT(TESForm::kFormType__MAX == 0x87);

// 1C
class TESFormIDListView : public TESForm
{
public:
	enum FormIDListViewType
	{
		kFormIDListViewType_ActorValue				= kFormType_ActorValueInfo,
		kFormIDListViewType_DialogueView			= kFormType_DialogueView,
		kFormIDListViewType_GMST					= kFormType_GMST,
		kFormIDListViewType_LightingTemplate		= kFormType_LightingTemplate,
		kFormIDListViewType_ImageSpace				= kFormType_ImageSpace,
		kFormIDListViewType_ImageSpaceMod			= kFormType_ImageSpaceMod,
		kFormIDListViewType_WorldSpace				= kFormType_WorldSpace,
	};

	// members
	//     /*00*/ TESForm

	// no additional members
};
STATIC_ASSERT(sizeof(TESFormIDListView) == 0x1C);