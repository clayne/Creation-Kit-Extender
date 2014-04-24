#include "CKEMain.h"
#include "VersionInfo.h"

#include "CKEConsole.h"
#include "CKEUIManager.h"

namespace CreationKitExtender
{
	PluginHandle								XSEPluginHandle = kPluginHandle_Invalid;

	CKEReleaseNameTable							CKEReleaseNameTable::Instance;

	CKEReleaseNameTable::CKEReleaseNameTable() :
		BGSEditorExtender::BGSEEReleaseNameTable()
	{
		RegisterRelease(0, 0, "Pitt The Glint In The Milkman's Eye");
	}

	CKEReleaseNameTable::~CKEReleaseNameTable()
	{
		;//
	}

	CKEInitCallbackQuery::CKEInitCallbackQuery( const SKSEInterface* SKSE ) :
		BGSEditorExtender::BGSEEDaemonCallback(),
		SKSE(SKSE)
	{
		;//
	}

	CKEInitCallbackQuery::~CKEInitCallbackQuery()
	{
		;//
	}

	bool CKEInitCallbackQuery::Handle(void* Parameter)
	{
		return true;
	}

	CKEInitCallbackLoad::CKEInitCallbackLoad( const SKSEInterface* SKSE ) :
		BGSEditorExtender::BGSEEDaemonCallback(),
		SKSE(SKSE)
	{
		;//
	}

	CKEInitCallbackLoad::~CKEInitCallbackLoad()
	{
		;//
	}

	bool CKEInitCallbackLoad::Handle(void* Parameter)
	{
		BGSEECONSOLE_MESSAGE("Initializing Hooks");
		BGSEECONSOLE->Indent();
		TODO("Kommt hier Dinge")
		BGSEECONSOLE->Exdent();

		BGSEECONSOLE_MESSAGE("Initializing UI Manager");
		BGSEECONSOLE->Indent();
		bool ComponentInitialized = BGSEEUI->Initialize("CreationKit", /*LoadMenu(BGSEEMAIN->GetExtenderHandle(), MAKEINTRESOURCE(IDR_MAINMENU))*/);
		BGSEECONSOLE->Exdent();

		if (ComponentInitialized == false)
			return false;

		return true;
	}

	CKEInitCallbackPostMainWindowInit::~CKEInitCallbackPostMainWindowInit()
	{
		;//
	}

	bool CKEInitCallbackPostMainWindowInit::Handle(void* Parameter)
	{
		TODO("Main window subclassing comes here")
		TODO("Including the big three")

		return true;
	}

	CKEInitCallbackEpilog::~CKEInitCallbackEpilog()
	{
		;//
	}

	bool CKEInitCallbackEpilog::Handle(void* Parameter)
	{
		SME::MersenneTwister::init_genrand(GetTickCount());
		
		BGSEECONSOLE_MESSAGE("Initializing Console");
		BGSEECONSOLE->Indent();
		Console::Initialize();
		BGSEECONSOLE->Exdent();

		BGSEECONSOLE_MESSAGE("Initializing UI Manager, again");
		BGSEECONSOLE->Indent();
		UIManager::Initialize();
		BGSEECONSOLE->Exdent();

		TODO("Init panic save file")

		BGSEECONSOLE->ExdentAll();
		BGSEECONSOLE_MESSAGE("%s Initialized!", BGSEEMAIN_EXTENDERLONGNAME);
		BGSEECONSOLE->Pad(2);

#ifndef NDEBUG
		char UsernameBuffer[0x200] = {0};
		DWORD UsernameSize = sizeof(UsernameBuffer);
		GetUserName(UsernameBuffer, &UsernameSize);

		if (_stricmp(UsernameBuffer, "shadeMe"))
		{
			BGSEECONSOLE->LogMsg("shadeMe", "This is a DEBUG build");
			BGSEECONSOLE->LogMsg("shadeMe", "Please proceed to your local police precinct and turn yourself in for not being me");
			BGSEECONSOLE->LogMsg("shadeMe", "Or get hold of a transmogrifier that goes BOINK!");
			BGSEECONSOLE->Pad(1);
			BGSEECONSOLE->Indent();
			BGSEECONSOLE->Indent();
			BGSEECONSOLE->Indent();
			BGSEECONSOLE->Indent();
			BGSEECONSOLE->LogMsg("shadeMe", "Thank you kindly");
			BGSEECONSOLE->LogMsg("shadeMe", "The guy who wrote this message");
			BGSEECONSOLE->ExdentAll();
			BGSEECONSOLE->Pad(2);
		}
#endif

		return true;
	}

	CKEDeinitCallback::~CKEDeinitCallback()
	{
		;//
	}

	bool CKEDeinitCallback::Handle(void* Parameter)
	{
		TODO("Flush main window rects to INI")

		BGSEECONSOLE_MESSAGE("Flushed CK INI Settings");

		return true;
	}

	CKECrashCallback::~CKECrashCallback()
	{
		;//
	}

	bool CKECrashCallback::Handle(void* Parameter)
	{
		BGSEECONSOLE->Pad(2);
		BGSEECONSOLE_MESSAGE("The editor crashed, dammit!");
		BGSEECONSOLE->Indent();

		BGSEECONSOLE_MESSAGE("Attempting to salvage the active file...");
		BGSEECONSOLE->Indent();

		TODO("Salvage active file..")
/*		if (_DATAHANDLER->PanicSave())
			BGSEECONSOLE_MESSAGE("Yup, we're good! Look for the panic save file in the Backup directory");
		else
			BGSEECONSOLE_MESSAGE("BollocksBollocksBollocks! No can do...");
*/

		BGSEECONSOLE->Exdent();
		BGSEECONSOLE->Exdent();

		CR_CRASH_CALLBACK_INFO* CrashInfo = (CR_CRASH_CALLBACK_INFO*)Parameter;
		bool ResumeExecution = false;

		int CrashHandlerMode = Settings::General::kCrashHandlerMode.GetData().i;

		if (CrashHandlerMode == kCrashHandlerMode_Terminate)
			ResumeExecution = false;
		else if (CrashHandlerMode == kCrashHandlerMode_Resume)
			ResumeExecution = true;
		else if (CrashHandlerMode == kCrashHandlerMode_Ask)
		{
			int MBFlags = MB_TASKMODAL|MB_TOPMOST|MB_SETFOREGROUND|MB_ICONERROR;
			MBFlags |= MB_YESNO;

			const char* Jingle = "The editor has encountered a critical error! An error report will be generated shortly.\n\nDo you wish to resume execution?\n\nPS: It is almost always futile to select 'Yes'.";

			switch (MessageBox(NULL, Jingle,
							BGSEEMAIN->ExtenderGetShortName(),
							MBFlags))
			{
			case IDYES:
				ResumeExecution = true;

				break;
			case IDNO:
				ResumeExecution = false;

				break;
			}
		}

		return ResumeExecution;
	}

	void CKEStartupManager::LoadStartupPlugin()
	{
		bool Load = Settings::Startup::kLoadPlugin.GetData().i;
		const char* PluginName = Settings::Startup::kPluginName.GetData().s;

		if (Load)
		{
			TODO("Load startup plugin")
		}
	}

	void CKEStartupManager::LoadStartupWorkspace()
	{
		bool Load = Settings::Startup::kSetWorkspace.GetData().i;
		const char* WorkspacePath = Settings::Startup::kWorkspacePath.GetData().s;

		if (Load)
		{
			TODO("Load startup workspace")
		}
	}
}

using namespace CreationKitExtender;

extern "C"
{
	__declspec(dllexport) bool SKSEPlugin_Query(const SKSEInterface * SKSE, PluginInfo * info)
	{
		info->infoVersion = PluginInfo::kInfoVersion;
		info->name = BGSEEMAIN_EXTENDERSHORTNAME;
		info->version = PACKED_SME_VERSION;
		PANIC("Fix version number packing")

		XSEPluginHandle = SKSE->GetPluginHandle();

		if (SKSE->isEditor == false)
		{
			return false;
		}

		BGSEditorExtender::INISettingDepotT CKEINISettings;

		Settings::Register(CKEINISettings);

		bool ComponentInitialized = BGSEEMAIN->Initialize(BGSEEMAIN_EXTENDERLONGNAME,
														BGSEEMAIN_EXTENDERSHORTNAME,
														CKEReleaseNameTable::Instance.LookupRelease(VERSION_MAJOR, VERSION_MINOR),
														PACKED_SME_VERSION,
														BGSEditorExtender::BGSEEMain::kExtenderParentEditor_TES5CK,
														EDITOR_VERSION_1_9_32_0,
														SKSE->editorVersion,
														GetSkyrimDirectory(),
														XSEPluginHandle,
														PANIC("SKSE passes the packed version integer - use the release index instead, needs adding to the pluginAPI")
														PANIC("same here - pass te minimum required release index"),
														CKEINISettings,
														"v4.0.30319",
#ifdef NDEBUG
														false,
#else
														true,
#endif
														false,
#ifdef NDEBUG
														true);
		TODO("Save debug symbols, dammit!")
#else
														false);
#endif

		SME_ASSERT(ComponentInitialized);

		BGSEEMAIN->Daemon()->RegisterInitCallback(BGSEditorExtender::BGSEEDaemon::kInitCallback_Query, new CKEInitCallbackQuery(SKSE));
		BGSEEMAIN->Daemon()->RegisterInitCallback(BGSEditorExtender::BGSEEDaemon::kInitCallback_Load, new CKEInitCallbackLoad(SKSE));
		BGSEEMAIN->Daemon()->RegisterInitCallback(BGSEditorExtender::BGSEEDaemon::kInitCallback_PostMainWindowInit, new CKEInitCallbackPostMainWindowInit());
		BGSEEMAIN->Daemon()->RegisterInitCallback(BGSEditorExtender::BGSEEDaemon::kInitCallback_Epilog, new CKEInitCallbackEpilog());
		BGSEEMAIN->Daemon()->RegisterDeinitCallback(new CKEDeinitCallback());
		BGSEEMAIN->Daemon()->RegisterCrashCallback(new CKECrashCallback());

		if (BGSEEMAIN->Daemon()->ExecuteInitCallbacks(BGSEditorExtender::BGSEEDaemon::kInitCallback_Query) == false)
		{
			MessageBox(NULL,
					"The Creation Kit Extender failed to initialize correctly!\n\nIt's highly advised that you close the CK right away. The plugin's log will now open.",
					"The Bob Loblaw Law Blog",
					MB_TASKMODAL|MB_SETFOREGROUND|MB_ICONERROR|MB_OK);

			BGSEECONSOLE->OpenDebugLog();

			return false;
		}

		return true;
	}

	__declspec(dllexport) bool SKSEPlugin_Load(const SKSEInterface * SKSE)
	{
		if (BGSEEMAIN->Daemon()->ExecuteInitCallbacks(BGSEditorExtender::BGSEEDaemon::kInitCallback_Load) == false)
		{
			MessageBox(NULL,
					"The Creation Kit Extender failed to load correctly!\n\nIt's highly advised that you close the CK right away. The plugin's log will now open.",
					"Steve Holt!",
					MB_TASKMODAL|MB_SETFOREGROUND|MB_ICONERROR|MB_OK);
			
			BGSEECONSOLE->OpenDebugLog();

			return false;
		}

		return true;
	}
};