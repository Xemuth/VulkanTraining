#include <Core/Core.h>
#include "UVKengine.h"
using namespace Upp;


CONSOLE_APP_MAIN
{
	StdLogSetup(LOG_COUT | LOG_TIMESTAMP | LOG_FILE );
	
	UVKapp app;
#if defined(_DEBUG)
	app.EnableValidationLayers(true);
#endif
	app.Create(true);
}
		