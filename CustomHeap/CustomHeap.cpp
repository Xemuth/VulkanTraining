#include <Core/Core.h>
#include "SmartAllocator.h"

using namespace Upp;

CONSOLE_APP_MAIN
{
	StdLogSetup(LOG_COUT | LOG_FILE | LOG_TIMESTAMP);
	
	struct T2{
		int i1;
		int i2;
	};
	
	SmartAllocator& sa = SmartAllocator::GetAllocator(16, 8);
	
	T2* one = (T2*) sa._malloc(sizeof(T2));
	
	T2* two = (T2*) sa._malloc(sizeof(T2));
	
	T2* three = (T2*) sa._malloc(sizeof(T2));
	
	sa._free(three); //Should do nothing
	sa._free(two);
	three = (T2*) sa._malloc(sizeof(T2));
	sa._free(one);
	T2* four = (T2*) sa._malloc(sizeof(T2));
	sa._free(four);
	sa._free(three);
	
	SmartAllocator::DestroyAllocator();
}
