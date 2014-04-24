#pragma once

#include "TESForm.h"
#include "NiTypes.h"
#include "BSSystem.h"

class GameSetting;
class BGSKeyword;
class BGSLocationRefType;
class BGSAction;
class BGSTextureSet;
class BGSMenuIcon;
class TESGlobal;
class TESClass;
class TESFaction;
class BGSHeadPart;
class TESEyes;
class TESRace;
class TESSound;
class BGSAcousticSpace;
class EffectSetting;
class Script;
class TESLandTexture;
class EnchantmentItem;
class SpellItem;
class ScrollItem;
class TESObjectACTI;
class BGSTalkingActivator;
class TESObjectARMO;
class TESObjectBOOK;
class TESObjectCONT;
class TESObjectDOOR;
class IngredientItem;
class TESObjectLIGH;
class TESObjectMISC;
class BGSApparatus;
class TESObjectSTAT;
class BGSStaticCollection;
class BGSMovableStatic;
class TESGrass;
class TESObjectTREE;
class TESFlora;
class TESFurniture;
class TESObjectWEAP;
class TESAmmo;
class TESNPC;
class TESLevCharacter;
class TESKey;
class AlchemyItem;
class BGSIdleMarker;
class BGSNote;
class BGSConstructibleObject;
class BGSProjectile;
class BGSHazard;
class TESSoulGem;
class TESLevItem;
class TESWeather;
class TESClimate;
class BGSShaderParticleGeometryData;
class BGSReferenceEffect;
class TESRegion;
class NavMeshInfoMap;
class TESObjectCELL;
class TESObjectREFR;
class MissileProjectile;
class ArrowProjectile;
class GrenadeProjectile;
class BeamProjectile;
class FlameProjectile;
class ConeProjectile;
class BarrierProjectile;
class Hazard;
class TESWorldSpace;
class TESObjectLAND;
class NavMesh;
class TESTopic;
class TESTopicInfo;
class TESQuest;
class TESIdleForm;
class TESPackage;
class TESCombatStyle;
class TESLoadScreen;
class TESLevSpell;
class TESObjectANIO;
class TESWaterForm;
class TESEffectShader;
class BGSExplosion;
class BGSDebris;
class TESImageSpace;
class TESImageSpaceModifier;
class BGSListForm;
class BGSPerk;
class BGSBodyPartData;
class BGSAddonNode;
class ActorValueInfo;
class BGSCameraShot;
class BGSCameraPath;
class BGSVoiceType;
class BGSMaterialType;
class BGSImpactData;
class BGSImpactDataSet;
class TESObjectARMA;
class BGSEncounterZone;
class BGSLocation;
class BGSMessage;
class BGSRagdoll;
class BGSDefaultObjectManager;
class BGSLightingTemplate;
class BGSMusicType;
class BGSFootstep;
class BGSFootstepSet;
class BGSStoryManagerBranchNode;
class BGSStoryManagerQuestNode;
class BGSStoryManagerEventNode;
class BGSDialogueBranch;
class BGSMusicTrackFormWrapper;
class BGSDialogueView;
class TESWordOfPower;
class TESShout;
class BGSEquipSlot;
class BGSRelationship;
class BGSScene;
class BGSAssociationType;
class BGSOutfit;
class BGSArtObject;
class BGSMaterialObject;
class BGSMovementType;
class BGSSoundDescriptorForm;
class BGSDualCastData;
class BGSSoundCategory;
class BGSSoundOutput;
class BGSCollisionLayer;
class BGSColorForm;
class BGSReverbParameters;

class TESFile;
class TESRegionList;
class TESRegionDataManager;
class TESRegionDataManagerEditor;		// derives from TESRegionDataManager

// 04
struct TESDataHandlerEditorEvent
{
	enum
	{
		kType_SaveActivePluginStart		= 0,
		kType_SaveActivePluginEnd,
		kType_CloseOpenPlugins,

		kType__MAX
	};

	/*00*/ UInt32				type;
};

// AE8+?, probably no larger
class TESDataHandler : public BSTEventSource<TESDataHandlerEditorEvent>
{
public:
	// defined for easy access, elements can be directly cast into their actual classes
	typedef BSTArray<TESForm*>											UniqueFormArrayT;
	typedef BSTArray<void*>												UnknownArrayT;
	typedef BSSimpleList<TESFile*>										PluginFileListT;

	// members
	//     /*000*/ BSTEventSource<TESDataHandlerEditorEvent>
	/*030*/ UInt32											unk030;
	/*034*/ UInt32											unk034;
	/*038*/ UniqueFormArrayT								formStore[TESForm::kFormType__MAX];
															// Special cases:
															//		kFormType_None						- BSTArray<TESForm*> persistenceForms { PapyrusPersistenceForm, CommandingActorPersistenceForm }
															//		kFormType_TES4/Group/TLOD/TOFT		- Always empty
															//		kFormType_GameSetting				- Always empty, objects are registered to the GameSettingCollection singleton
															//		kFormType_EffectSetting				- Always empty, objects are stored in a separate linked list
															//		kFormType_ActorValueInfo			- Always empty, objects are stored in a statically allocated array
															//		kFormType_Cell/AddonNode			- Only exterior cells/Always empty
	/*68C*/ TESRegionList*									regionList;
	/*690*/ NiTPrimitiveArray<TESObjectCELL*>				interiorCells;
	/*6A0*/ NiTPrimitiveArray<BGSAddonNode*>				addonNodes;				// add-on nodes need to have unique "indices" apparently
	/*6B0*/ UnknownArrayT									garbageArray;			// garbage array for invalid/unsupported forms (mostly bad TESObjectREFR types)
	/*6BC*/ UInt32											nextFormID;
	/*6C0*/ TESFile*										activeFile;
	/*6C4*/ PluginFileListT									fileList;				// all files in Data\ directory
	/*6CC*/ UInt32											fileCount;				// loaded file count
	/*6D0*/ TESFile*										filesByID[0xFF];		// loaded files
	/*ACC*/ UInt8											unkACC[3];
	/*ACF*/ UInt8											autoSaving;
	/*AD0*/ UInt8											unkAD0;
	/*AD1*/	UInt8											clearingData;
	/*AD2*/ UInt8											unkAD2;					// init to 1
	/*AD3*/ UInt8											unkAD3;
	/*AD4*/ UInt8											loadingPlugins;			// set to 1 when loading plugins, reset before post-load init
	/*AD5*/ UInt8											unkAD5;
	/*AD6*/ UInt8											unkAD6;					// set in TESDataHandler::ConstructTESForm
	/*AD7*/ UInt8											unkAD7;
	/*AD8*/ UInt8											unkAD8[4];
	/*ADC*/ TESRegionDataManagerEditor*						regionDataManager;
	/*AE0*/ UInt32											unkAE0;					// ContainerExtraData* ?
	/*AE4*/ UInt8											unkAE4;
	/*AE5*/ UInt8											padAE5[3];				// most probably

	static TESDataHandler*									Singleton;
};
STATIC_ASSERT(offsetof(TESDataHandler, regionDataManager) == 0xADC);
STATIC_ASSERT(sizeof(TESDataHandler) == 0xAE8);

#define _DATAHANDLER										(TESDataHandler::Singleton)

