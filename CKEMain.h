#pragma once
#include <BGSEEMain.h>

namespace CreationKitExtender
{
	class CKEReleaseNameTable : public BGSEditorExtender::BGSEEReleaseNameTable
	{
	protected:
		CKEReleaseNameTable();
	public:
		virtual ~CKEReleaseNameTable();

		static CKEReleaseNameTable						Instance;
	};

	extern CKEReleaseNameTable							ReleaseNameTable;

	class CKEInitCallbackQuery : public BGSEditorExtender::BGSEEDaemonCallback
	{
		const SKSEInterface*				SKSE;
	public:
		CKEInitCallbackQuery(const SKSEInterface* SKSE);
		virtual ~CKEInitCallbackQuery();

		virtual bool						Handle(void* Parameter = NULL);
	};

	class CKEInitCallbackLoad : public BGSEditorExtender::BGSEEDaemonCallback
	{
		const SKSEInterface*				SKSE;
	public:
		CKEInitCallbackLoad(const SKSEInterface* SKSE);
		virtual ~CKEInitCallbackLoad();

		virtual bool						Handle(void* Parameter = NULL);
	};

	class CKEInitCallbackPostMainWindowInit : public BGSEditorExtender::BGSEEDaemonCallback
	{
	public:
		virtual ~CKEInitCallbackPostMainWindowInit();

		virtual bool						Handle(void* Parameter = NULL);
	};

	class CKEInitCallbackEpilog : public BGSEditorExtender::BGSEEDaemonCallback
	{
	public:
		virtual ~CKEInitCallbackEpilog();

		virtual bool						Handle(void* Parameter = NULL);
	};

	class CKEDeinitCallback : public BGSEditorExtender::BGSEEDaemonCallback
	{
	public:
		virtual ~CKEDeinitCallback();

		virtual bool						Handle(void* Parameter = NULL);
	};

	class CKECrashCallback : public BGSEditorExtender::BGSEEDaemonCallback
	{
		enum
		{
			kCrashHandlerMode_Terminate = 0,
			kCrashHandlerMode_Resume,
			kCrashHandlerMode_Ask,
		};
	public:
		virtual ~CKECrashCallback();

		virtual bool						Handle(void* Parameter = NULL);
	};
	
	class CKEStartupManager
	{
	public:
		static void							LoadStartupWorkspace();
		static void							LoadStartupPlugin();
	};

#define BGSEEMAIN_EXTENDERLONGNAME		"Creation Kit Extender"
#define BGSEEMAIN_EXTENDERSHORTNAME		"CKE"

#define CKE_CODADEPOT					"Coda\\"
#define CKE_CODABGDEPOT					"Coda\\Background\\"
}

extern "C"
{
	__declspec(dllexport) bool SKSEPlugin_Query(const SKSEInterface * SKSE, PluginInfo * info);
	__declspec(dllexport) bool SKSEPlugin_Load(const SKSEInterface * SKSE);
};
