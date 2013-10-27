#pragma once

#include "BSTArray.h"

template <typename T> class BSTEventSink;

// 04
class BSIntrusiveRefCounted
{
public:
	/*00*/ volatile UInt32			refCount;
};
STATIC_ASSERT(sizeof(BSIntrusiveRefCounted) == 0x4);

// 04
template<typename T>
class BSTSmartPointer
{
public:
	/*00*/ T*						data;			// BSIntrusiveRefCounted*
};
STATIC_ASSERT(sizeof(BSTSmartPointer<void>) == 0x4);

// 08
class BSSpinLock
{
	enum
	{
		kFastSpinThreshold		=	10000
	};

	/*00*/ volatile DWORD			threadID;
	/*04*/ UInt32					lockCount;
public:
	BSSpinLock() : threadID(0), lockCount(0) {}

	void			Lock(void);
	void			Release(void);
};
STATIC_ASSERT(sizeof(BSSpinLock) == 0x8);

enum EventResult
{
	kEvent_Continue = 0,
	kEvent_Abort
};

// 30
template <typename EventT, typename EventArgT = EventT>
class BSTEventSource
{
protected:
	typedef BSTEventSink<EventT>		SinkT;
	typedef BSTArray<SinkT*>			SinkArrayT;

	/*00*/ BSSpinLock					lock;
	/*08*/ SinkArrayT					eventSinks;
	/*14*/ SinkArrayT					addBuffer;			// schedule for add
	/*20*/ SinkArrayT					removeBuffer;		// schedule for remove
	/*2C*/ UInt8						stateFlag;			// some internal state changed while sending
	/*2D*/ UInt8						pad2D[3];
public:
	void								AddEventSink(SinkT* eventSink)
	{
		thisCall<void*>(VOLATILE(0x004D9650), this, eventSink);
	}

	void								RemoveEventSink(SinkT* eventSink)
	{
		thisCall<void*>(VOLATILE(0x004D96E0), this, eventSink);
	}

	void								SendEvent(EventArgT* eventArgs)
	{
		thisCall<void*>(VOLATILE(0x0073BBD0), this, eventArgs);
	}
};
STATIC_ASSERT(sizeof(BSTEventSource<void*>) == 0x30);

// 04
template <typename T>
class BSTEventSink
{
public:
	// members
	//     /*00*/ void**		vtbl

	// no additional members

	virtual ~BSTEventSink();

	virtual	EventResult					ReceiveEvent(T* eventArgs, BSTEventDispatcher<T>* dispatcher) = 0;
};
STATIC_ASSERT(sizeof(BSTEventSink<void*>) == 0x4);