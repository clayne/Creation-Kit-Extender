#include "MemoryHeap.h"

MemoryManager*					MemoryManager::Singleton = (MemoryManager*)VOLATILE(0x01B0D6B0);

void* MemoryManager::Allocate(UInt32 Size, UInt32 Alignment, bool Align)
{
	return thisCall<void*>(VOLATILE(0x009384E0), this, Size, Alignment, Align);
}

void MemoryManager::Free(void* Pointer, bool Align)
{
	thisCall<void*>(VOLATILE(0x00937E80), this, Pointer, Align);
}

void* FormHeap_Allocate(UInt32 Size)
{
	return MemoryManager::Singleton->Allocate(Size, 0, false);
}

void FormHeap_Free(void* Ptr)
{
	MemoryManager::Singleton->Free(Ptr, false);
}