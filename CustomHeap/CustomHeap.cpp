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
	
	T2* one = (T2*) sa.SAMalloc(sizeof(T2));
	
	T2* two = (T2*) sa.SAMalloc(sizeof(T2));
	
	T2* three = (T2*) sa.SAMalloc(sizeof(T2));
	
	sa.SAFree(three); //Should do nothing
	sa.SAFree(two);
	three = (T2*) sa.SAMalloc(sizeof(T2));
	sa.SAFree(one);
	T2* four = (T2*) sa.SAMalloc(sizeof(T2));
	sa.SAFree(four);
	sa.SAFree(three);
	
	SmartAllocator::DestroyAllocator();
}
