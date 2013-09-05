#include "BSSystem.h"

void BSSpinLock::Lock(void)
{
	DWORD myThreadID = GetCurrentThreadId();
	if (threadID == myThreadID)
	{
		lockCount++;
		return;
	}

	UInt32 spinCount = 0;
	while (InterlockedCompareExchange(&threadID, myThreadID, 0))
		Sleep(++spinCount > kFastSpinThreshold);

    lockCount = 1;
}

void BSSpinLock::Release(void)
{
	if (--lockCount == 0)
		InterlockedCompareExchange(&threadID, 0, threadID);
}