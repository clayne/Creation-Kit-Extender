#pragma once


class SubWindow;
class TESPreviewControl;

// 08
class BSExtraData
{
public:
	enum DialogExtraTypes
	{
		kDialogExtra_Param							= 0x00,
		kDialogExtra_LocalCopy						= 0x01,
		// kDialogExtra_LocalBaseObjectCopy			= 0x01,
		// kDialogExtra_LocalBaseReferenceCopy		= 0x01,
		// Unknown									= 0x02,
		kDialogExtra_ColorControl					= 0x03,
		// Unknown									= 0x04,
		kDialogExtra_SubWindow						= 0x05,
		kDialogExtra_ConditionsDialog				= 0x06,
		// Unknown									= 0x07,
		kDialogExtra_WorkingData					= 0x08,
		kDialogExtra_FactionData					= 0x09,
		kDialogExtra_PopupMenu						= 0x0A,
		kDialogExtra_RefSelectControl				= 0x0B,
		// Unknown									= 0x0C,
		kDialogExtra_ReactionData					= 0x0D,
		kDialogExtra_PreviewControl					= 0x0E,
		kDialogExtra_FreeformFaceControl			= 0x0F,
		kDialogExtra_DialogData						= 0x10,
		kDialogExtra_NotifyInfo						= 0x11,
		kDialogExtra_QuestStageData					= 0x12,
		kDialogExtra_Timer							= 0x13,
		kDialogExtra_QuestFilter					= 0x14,
		kDialogExtra_Rects							= 0x15,
		// Unknown									= 0x16,
		kDialogExtra_HavokAnimationPreview			= 0x17,
		kDialogExtra_StoryManagerData				= 0x18,
		kDialogExtra_WindowStartingRects			= 0x19,
		kDialogExtra_Weather						= 0x1A,
		kDialogExtra_ScriptList						= 0x1B,
		kDialogExtra_NPCDlgData						= 0x1C,
		kDialogExtra_NPCAnimationPreviewData		= 0x1D,

		kDialogExtra__MAX							= 0x1E
	};

	enum ExtraDataTypes
	{
		kExtra_Havok							= 0x1,
		kExtra_Cell3D							= 0x2,
		kExtra_CellWaterType					= 0x3,
		kExtra_RegionList						= 0x4,
		kExtra_SeenData							= 0x5,
		kExtra_EditorID							= 0x6,
		kExtra_CellMusicType					= 0x7,
		kExtra_CellSkyRegion					= 0x8,
		kExtra_ProcessMiddleLow					= 0x9,
		kExtra_DetachTime						= 0xA,
		kExtra_PersistentCell					= 0xB,
		// Unknown								= 0xC,
		kExtra_Action							= 0xD,
		kExtra_StartingPosition					= 0xE,
		// Unknown								= 0xF,
		kExtra_AnimGraphManager					= 0x10,
		// Unknown								= 0x11,
		kExtra_UsedMarkers						= 0x12,
		kExtra_DistantData						= 0x13,
		kExtra_RagDollData						= 0x14,
		kExtra_ContainerChanges					= 0x15,
		kExtra_Worn								= 0x16,
		kExtra_WornLeft							= 0x17,
		kExtra_PackageStartLocation				= 0x18,
		kExtra_Package							= 0x19,
		kExtra_TresPassPackage					= 0x1A,
		kExtra_RunOncePacks						= 0x1B,
		kExtra_ReferenceHandle					= 0x1C,
		kExtra_Follower							= 0x1D,
		kExtra_LevCreaModifier					= 0x1E,
		kExtra_Ghost							= 0x1F,
		kExtra_OriginalReference				= 0x20,
		kExtra_Ownership						= 0x21,
		kExtra_Global							= 0x22,
		kExtra_Rank								= 0x23,
		kExtra_Count							= 0x24,
		kExtra_Health							= 0x25,
		// Unknown								= 0x26,
		kExtra_TimeLeft							= 0x27,
		kExtra_Charge							= 0x28,
		kExtra_Light							= 0x29,
		kExtra_Lock								= 0x2A,
		kExtra_Teleport							= 0x2B,
		kExtra_MapMarker						= 0x2C,
		kExtra_LeveledCreature					= 0x2D,
		kExtra_LeveledItem						= 0x2E,
		kExtra_Scale							= 0x2F,
		kExtra_Seed								= 0x30,
		kExtra_MagicCaster						= 0x31,
		// Unknown								= 0x32, 
		// Unknown								= 0x33, 
		kExtra_PlayerCrimeList					= 0x34,
		// Unknown								= 0x35,
		kExtra_EnableStateParent				= 0x36,
		kExtra_EnableStateChildren				= 0x37,
		kExtra_ItemDropper						= 0x38,
		kExtra_DroppedItemList					= 0x39,
		kExtra_RandomTeleportMarker 			= 0x3A,
		// Unknown								= 0x3B
		kExtra_SavedHavokData					= 0x3C,
		kExtra_CannotWear						= 0x3D,
		kExtra_Poison							= 0x3E,
		// Unknown								= 0x3F
		kExtra_LastFinishedSequence				= 0x40,
		kExtra_SavedAnimation					= 0x41,
		kExtra_NorthRotation					= 0x42,
		kExtra_SpawnContainer					= 0x43,
		kExtra_FriendHits						= 0x44,
		kExtra_HeadingTarget					= 0x45,
		// Unknown								= 0x46
		kExtra_RefractionProperty				= 0x47,
		kExtra_StartingWorldOrCell				= 0x48,
		kExtra_Hotkey							= 0x49,				
		// Unknown								= 0x4A
		kExtra_EditiorRefMoveData				= 0x4B,
		kExtra_InfoGeneralTopic					= 0x4C,
		kExtra_HasNoRumors						= 0x4D,
		kExtra_Sound							= 0x4E,
		kExtra_TerminalState					= 0x4F,
		kExtra_LinkedRef						= 0x50,
		kExtra_LinkedRefChildren				= 0x51,
		kExtra_ActivateRef						= 0x52,
		kExtra_ActivateRefChildren				= 0x53,
		kExtra_CanTalkToPlayer					= 0x54,
		kExtra_ObjectHealth						= 0x55,
		kExtra_CellImageSpace					= 0x56,
		kExtra_NavMeshPortal					= 0x57,
		kExtra_ModelSwap						= 0x58,
		kExtra_Radius							= 0x59,
		// Unknown								= 0x5A,
		kExtra_FactionChanges					= 0x5B,
		kExtra_DismemberedLimbs					= 0x5C,
		kExtra_ActorCause						= 0x5D,
		kExtra_MultiBound						= 0x5E,
		kExtra_MultiBoundData					= 0x5F,
		kExtra_MultiBoundRef					= 0x60,
		kExtra_ReflectedRefs					= 0x61,
		kExtra_ReflectorRefs					= 0x62,
		kExtra_EmittanceSource					= 0x63,
		kExtra_RadioData						= 0x64,
		kExtra_CombatStyle						= 0x65,
		// Unknown								= 0x66,
		kExtra_Primitive						= 0x67,
		kExtra_OpenCloseActivateRef				= 0x68,
		kExtra_AnimNoteReceiver					= 0x69,
		kExtra_Ammo								= 0x6A,
		kExtra_PatrolRefData					= 0x6B,
		kExtra_PackageData						= 0x6C,
		kExtra_OcclusionShape					= 0x6D,
		kExtra_CollisionData					= 0x6E,
		kExtra_SayTopicInfoOnceADay				= 0x6F,
		kExtra_EncounterZone					= 0x70,
		kExtra_SayTopicInfo						= 0x71,
		kExtra_OcclusionPlaneRefData			= 0x72,
		kExtra_PortalRefData					= 0x73,
		kExtra_Portal							= 0x74,
		kExtra_Room								= 0x75,
		kExtra_HealthPerc						= 0x76,
		kExtra_RoomRefData						= 0x77,
		kExtra_GuardedRefData					= 0x78,
		kExtra_CreatureAwakeSound				= 0x79,
		// Unknown								= 0x7A,
		kExtra_Horse							= 0x7B,
		kExtra_IgnoredBySandbox					= 0x7C,
		kExtra_CellAcousticSpace				= 0x7D,
		kExtra_ReservedMarkers					= 0x7E,
		kExtra_WeaponIdleSound					= 0x7F,
		kExtra_WaterLightRefs					= 0x80,
		kExtra_LitWaterRefs						= 0x81,
		kExtra_WeaponAttackSound				= 0x82,
		kExtra_ActivateLoopSound				= 0x83,
		kExtra_PatrolRefInUseData				= 0x84,
		kExtra_AshPileRef						= 0x85,
		// Unknown								= 0x86
		kExtra_FollowerSwimBreadcrumbs			= 0x87,
		kExtra_AliasInstanceArray				= 0x88,
		kExtra_Location							= 0x89,
		// Unknown								= 0x8A,
		kExtra_LocationRefType					= 0x8B,
		kExtra_PromotedRef						= 0x8C,
		// Unknown								= 0x8D,
		kExtra_OutfitItem						= 0x8E,
		// Unknown								= 0x8F,
		kExtra_LeveledItemBase					= 0x90,
		kExtra_LightData						= 0x91,
		kExtra_SceneData						= 0x92,
		kExtra_BadPosition						= 0x93,
		kExtra_HeadTrackingWeight				= 0x94,
		kExtra_FromAlias						= 0x95,
		kExtra_ShouldWear						= 0x96,
		kExtra_FavorCost						= 0x97,
		kExtra_AttachedArrows3D					= 0x98,
		kExtra_TextDisplayData					= 0x99,
		kExtra_AlphaCutoff						= 0x9A,
		kExtra_Enchantment						= 0x9B,
		kExtra_Soul								= 0x9C,
		kExtra_ForcedTarget						= 0x9D,
		// Unknown								= 0x9E,
		kExtra_UniqueID							= 0x9F,
		kExtra_Flags							= 0xA0,
		kExtra_RefrPath							= 0xA1,
		kExtra_DecalGroup						= 0xA2,
		kExtra_LockList							= 0xA3,
		kExtra_ForcedLandingMarker				= 0xA4,
		kExtra_LargeRefOwnerCells				= 0xA5,
		kExtra_CellWaterEnvMap					= 0xA6,
		kExtra_CellGrassData					= 0xA7,
		kExtra_TeleportName						= 0xA8,
		kExtra_Interaction						= 0xA9,
		kExtra_WaterData						= 0xAA,
		kExtra_WaterCurrentZoneData				= 0xAB,
		kExtra_AttachRef						= 0xAC,
		kExtra_AttachRefChildren				= 0xAD,
		kExtra_GroupConstraint					= 0xAE,
		kExtra_ScriptedAnimDependence 			= 0xAF,
		kExtra_CachedScale						= 0xB0,
		kExtra_RaceData							= 0xB1,
		kExtra_GIDBuffer						= 0xB2,
		kExtra_MissingRefIDs					= 0xB3,

		kExtra__MAX								= 0xB4
	};

	// members
	//     /*00*/ void**			vtbl
	/*08*/ BSExtraData*				extraNext;

	virtual ~BSExtraData();

	virtual UInt8					GetType() = 0;
};
STATIC_ASSERT(sizeof(BSExtraData) == 0x08);

// 10
class DialogExtraSubWindow : public BSExtraData
{
public:
	// members
	//     /*00*/ BSExtraData
	/*08*/ SubWindow*			subWindow;
	/*0C*/ int					templateID;
};
STATIC_ASSERT(sizeof(DialogExtraSubWindow) == 0x10);

// 10
class DialogExtraWorkingData : public BSExtraData
{
public:
	// members
	//     /*00*/ BSExtraData
	/*08*/ void*				sourceObject;
	/*0C*/ void*				localCopy;
};
STATIC_ASSERT(sizeof(DialogExtraWorkingData) == 0x10);

// 10
class DialogExtraColorControl : public BSExtraData
{
public:
	// 20
	struct ControlIDData
	{
		/*00*/ int				editR;
		/*04*/ int				editG;
		/*08*/ int				editB;
		/*0C*/ int				spinR;			// numeric up-down controls
		/*10*/ int				spinG;
		/*14*/ int				spinB;
		/*18*/ int				btnSelect;
		/*1C*/ int				picPreview;
	};

	// 24
	struct ColorData
	{
		/*00*/ HWND				parent;
		/*04*/ ControlIDData	controls;
	};

	// members
	//     /*00*/ BSExtraData
	/*08*/ ColorData*			data;
	/*0C*/ int					controlID;		// set to data->editR, used for quick lookup
};
STATIC_ASSERT(sizeof(DialogExtraColorControl) == 0x10);

// 10
class DialogExtraPreviewControl : public BSExtraData
{
public:
	// members
	//     /*00*/ BSExtraData
	/*08*/ TESPreviewControl*		previewControl;
	/*0C*/ int						previewControlID;
};
STATIC_ASSERT(sizeof(DialogExtraPreviewControl) == 0x10);
