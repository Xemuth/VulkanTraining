#include <Core/Core.h>
#include "SmartAllocator.h"

using namespace Upp;

CONSOLE_APP_MAIN
{
	SmartAllocator& sa = SmartAllocator::GetAllocator(16, 8);
	SmartAllocator::DestroyAllocator();
}
