#include "PageCache.h"

Span* PageCache::NewSpan(size_t numpage)
{
	if (!_spanLists[numpage].Empty())
	{
		Span* span = _spanLists[numpage].Begin();
		_spanLists[numpage].PopFront();
		return span;
	}

	for (size_t i = numpage+1; i < MAX_PAGES; ++i)
	{
		if (!_spanLists[i].Empty())
		{
			// ╥жая
			Span* span = _spanLists[i].Begin();
			_spanLists[i].PopFront();

			Span* splitspan = new Span;
			splitspan->_pageid = span->_pageid + numpage;
			splitspan->_pagesize = span->_pagesize - numpage;

			span->_pagesize = numpage;

			_spanLists[splitspan->_pagesize].PushFront(splitspan);

			return span;
		}
	}

	void* ptr = SystemAlloc(MAX_PAGES - 1);

	Span* bigspan = new Span;
	bigspan->_pageid = (PAGE_ID)ptr >> PAGE_SHIFT;
	bigspan->_pagesize = MAX_PAGES - 1;
	
	_spanLists[bigspan->_pagesize].PushFront(bigspan);
	
	return NewSpan(numpage);
}
