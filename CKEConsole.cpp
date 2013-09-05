#include "CKEConsole.h"
#include <BGSEditorExtenderBase_Resource.h>

namespace CreationKitExtender
{
	namespace Console
	{
		void Initialize()
		{
			BGSEECONSOLE->InitializeUI(BGSEEUI->GetMainWindow(), BGSEEMAIN->GetExtenderHandle());
		}
	}
}