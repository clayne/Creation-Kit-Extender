#pragma once

class AbstractHeap;
class HeapBlocks;		// derives from AbstractHeap?

// 5D0+?
class MemoryManager
{
public:
	/*000*/ UInt32			unk000;
	/*004*/ UInt32			unk004[(0x394 - 0x4) >> 2];
	/*394*/ UInt16			unk394;
	/*396*/ UInt16			unk396;
	/*398*/ AbstractHeap**	unk398;									// dynamic pointer that points to the (dynamic) heap object
	/*39C*/ UInt32			unk39C[(0x3A8 - 0x39C) >> 2];
	/*3A8*/ AbstractHeap*	unk3A8;									// caches unk398
	/*3AC*/ UInt32			unk3AC[(0x5D0 - 0x3AC) >> 2];

	void*					Allocate(UInt32 Size, UInt32 Alignment, bool Align);
	void					Free(void* Pointer, bool Align);

	static MemoryManager*	Singleton;
};

// archaic nomenclature - the standard heap is named 'Default Heap'
void*	FormHeap_Allocate(UInt32 Size);
void	FormHeap_Free(void* Ptr);

// macro for overloading new & delete operators to use the main heap
#define USEFORMHEAP inline void* operator new (size_t size) {return FormHeap_Allocate(size);} \
					inline void* operator new[] (size_t size) {return FormHeap_Allocate(size);} \
					inline void operator delete (void *object) {FormHeap_Free(object);} \
					inline void operator delete[] (void *object) {FormHeap_Free(object);}
