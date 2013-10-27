#pragma once

// 20
class SubWindow
{
public:
	typedef BSSimpleList<HWND>		ControlListT;

	/*00*/ ControlListT     controls;		// items are actually HWNDs; declared as such due to tList's definition
	/*08*/ HWND             hDialog;		// handle of parent dialog window
	/*0C*/ HINSTANCE        hInstance;		// module instance of dialog template
	/*10*/ POINT            position;		// position of subwindow within parent dialog
	/*18*/ HWND             hContainer;		// handle of container control (e.g. Tab Control)
	/*1C*/ HWND             hSubwindow;		// handle of subwindow, if created
};
STATIC_ASSERT(sizeof(SubWindow) == 0x20);

// Reference selection is managed by a different class this time around
// This has been relegated to just managing form selections made in edit dialogs and dropping objects into the render window
// 18
class TESObjectSelection
{
public:
	// 0C
	struct SelectedObjectsEntry
	{
		/*00*/ TESForm*					Data;
		/*08*/ SelectedObjectsEntry*	Prev;
		/*0C*/ SelectedObjectsEntry*	Next;
	};

	// members
	/*00*/ SelectedObjectsEntry*		selectionList;
	/*04*/ UInt32						selectionCount;
	/*08*/ Vector3						selectionPositionVectorSum;				// calculated for references
	/*14*/ float						selectionBounds;						// calculated for references

	static TESObjectSelection**			PrimaryInstance;
};
STATIC_ASSERT(sizeof(TESObjectSelection) == 0x18);