#pragma once

// template type's size MUST be 4 bytes
// 08
template <typename T>
class BSSimpleList
{
public:
	// 08
	struct Node
	{
		/*00*/ T			data;
		/*04*/ Node*		next;
	};

	/*00*/ Node				head;
};
STATIC_ASSERT(sizeof(BSSimpleList<void*>) == 0x8);
