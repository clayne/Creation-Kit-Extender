#pragma once

#include "NiTypes.h"
#include "SKSE\NiObjects.h"

class NiPixelData;
class NiRenderTargetGroup;
class NiDX9VertexBufferManager;
class NiD3DGeometryGroupManager;
class NiDX9IndexBufferManager;
class NiUnsharedGeometryGroup;
class NiDynamicGeometryGroup;

// 30+?, possibly includes the first 8 bytes of NiDX9Renderer
class NiRenderer : public NiObject
{
public:
	// members
	//     /*00*/ NiObject
	/*08*/ UInt32				unk08;
	/*0C*/ UInt32				unk0C;
	/*10*/ UInt32				unk10;
	/*14*/ UInt32				unk14;
	/*18*/ UInt32				unk18;
	/*1C*/ UInt32				unk1C;
	/*20*/ UInt32				unk20;
	/*24*/ UInt32				unk24;
	/*28*/ UInt32				unk28;
	/*2C*/ UInt8				unk2C;
	/*2D*/ UInt8				unk2D;
	/*2E*/ UInt16				pad3E;

	static NiRenderer**			Singleton;
};
STATIC_ASSERT(sizeof(NiRenderer) == 0x30);

// 880
class NiDX9Renderer : public NiRenderer
{
public:
	// 54
	struct Unk4A4T
	{
		/*00*/ UInt32							unk00[0x54 >> 2];
	};

	typedef NiTPrimitiveArray<bool (__cdecl *)(bool, void *)>		DeviceResetFunctionListT;
	typedef NiTPrimitiveArray<void *>								DeviceResetFunctionDataListT;
	typedef NiTPrimitiveArray<bool (__cdecl *)(void *)>				UnkCallbackListT;
	typedef NiTPrimitiveArray<void *>								UnkCallbackDataListT;

	// members
	//     /*000*/ NiRenderer
	/*030*/ UInt32								unk030;
	/*034*/ UInt32								unk034;
	/*038*/ IDirect3DDevice9*					d3dDevice;
	/*03C*/ D3DCAPS9							deviceCaps;
	/*16C*/ HWND								unk16C;
	/*170*/ HWND								focusWindow;
	/*174*/ char								rendererDebugBuffer[0x200];
	/*374*/ UInt32								d3DAdaptor;
	/*378*/ D3DDEVTYPE							deviceType;						
	/*37C*/ DWORD								behaviourFlags;
	/*380*/ UInt32								unk380;
	/*384*/ UInt8								unk384;
	/*385*/ UInt8								unk385;
	/*386*/ UInt16								pad386;
	/*388*/ UInt32								unk388;
	/*38C*/ UInt32								unk38C;
	/*390*/ D3DCOLOR							clearColor;						// init to 0xFF808080
	/*394*/ float								clearZ;							// init to 1.0
	/*398*/ UInt32								clearStencil;
	/*39C*/ UInt32								unk39C;
	/*3A0*/ char								rendererDebugBufferAux[0x20];				
	/*3C0*/ NiTPointerMap<void*, void*>			prepackObjects;					// NiTPointerMap<class NiVBBlock *, class NiDX9Renderer::PrePackObject *>
	/*3D0*/ UInt32								unk3D0;
	/*3D4*/ UInt32								unk3D4;
	/*3D8*/ NiPoint3							unk3D8[4];
	/*408*/ NiPoint3							unk408;							// init to zero
	/*414*/ UInt32								unk414;
	/*418*/ NiPoint3							unk418;
	/*424*/ UInt32								unk424;
	/*428*/ float								unk428;							// init to 0.1
	/*42C*/ float								unk42C;							// init to 100
	/*430*/ D3DMATRIX							identityMatrix;
	/*470*/ D3DVIEWPORT9						viewPort;
	/*488*/ UInt32								maxVertexBlendMatrices;
	/*48C*/ UInt32								maxStreams;
	/*490*/ UInt32								maxPixelShaderVersion;
	/*494*/ UInt32								maxVertexShaderVersion;
	/*498*/ UInt8								unk498;
	/*499*/ UInt8								pad499[3];
	/*49C*/ UInt32								unk49C;
	/*4A0*/ UInt8								deviceLost;
	/*4A1*/ UInt8								pad4A1[3];
	/*4A4*/ Unk4A4T								unk4A4[4];
	/*5F4*/ UInt32								unk5F4[(0x614 - 0x5F4) >> 2];
	/*614*/ NiPixelData*						pixelData[4];
	/*624*/ UInt32								unk624;							// init to 22
	/*628*/ NiRenderTargetGroup*				renderTargetGroup[3];
	/*634*/ NiTPointerMap<void*, void*>			renderTargets;					// NiTPointerMap<struct HWND__ *, class NiPointer<class NiRenderTargetGroup>>
	/*644*/ UInt32								unk644;
	/*648*/ UInt8								unk648;
	/*649*/ UInt8								unk649;
	/*64A*/ UInt16								pad64A;
	/*64C*/ NiD3DGeometryGroupManager*			geometryGroupManager;
	/*650*/ NiUnsharedGeometryGroup*			unsharedGeometryGroup;						
	/*654*/ NiDynamicGeometryGroup*				dynamicGeometryGroup;						
	/*658*/ NiDX9VertexBufferManager*			vertexBufferManager;
	/*65C*/ NiDX9IndexBufferManager*			indexBufferManager;	
	/*660*/ NiTPointerMap<void*, void*>			renderedTextureDataMap;			// NiTPointerMap<class NiRenderedTexture *, class NiDX9RenderedTextureData *>
	/*670*/ NiTPointerMap<void*, void*>			renderedCubeMapDatamap;			// NiTPointerMap<class NiRenderedCubeMap *, class NiDX9RenderedCubeMapData *>
	/*680*/ UInt32								unk680[4];
	/*690*/ UInt32								unk690[3];
	/*69C*/ D3DMATRIX							m44World;
	/*6DC*/ D3DMATRIX							m44View;
	/*71C*/ D3DMATRIX							m44Proj;
	/*75C*/ UInt32								unk75C[(0x7E8 - 0x75C) >> 2];
	/*7E8*/ UInt32								screenWidth;
	/*7EC*/ UInt32								screenHeight;
	/*7F0*/ UInt32								flags;
	/*7F4*/ HWND								unk7F4;
	/*7F8*/ HWND								unk7F8;
	/*7FC*/ UInt32								adaptor;
	/*800*/ UInt32								unk800;
	/*804*/ D3DFORMAT							surfaceFormat;
	/*808*/ UInt32								unk808;
	/*80C*/ UInt32								presentInterval;
	/*810*/ UInt32								unk810[4];
	/*820*/ UInt8								unk820;
	/*821*/ UInt8								pad821[3];
	/*824*/ DeviceResetFunctionListT			deviceResetFunctions;
	/*834*/ DeviceResetFunctionDataListT		deviceResetFunctionData;
	/*844*/ UnkCallbackListT					unkCallbackList;
	/*854*/ UnkCallbackDataListT				unkCallbackListData;
	/*864*/ NiTMap<void*, void*>				d3DPixelFormatMap;					// NiTMap<enum  _D3DFORMAT, class NiPixelFormat *>
	/*874*/ UInt32								unk874[(0x880 - 0x874) >> 2];
};
STATIC_ASSERT(offsetof(NiDX9Renderer, unk3D0) == 0x3D0);
STATIC_ASSERT(offsetof(NiDX9Renderer, unk75C) == 0x75C);
STATIC_ASSERT(sizeof(NiDX9Renderer) == 0x880);
STATIC_ASSERT(sizeof(NiDX9Renderer::Unk4A4T) == 0x54);
