#include "Plugin.h"
#include "Measure.h"

HINSTANCE MODULE_INSTANCE;

/*
* Called once, at skin load or refresh
* Read any options that need to be constant here
*/
PLUGIN_EXPORT void Initialize(void** data, void* rm)
{
	Measure* measure = new Measure(rm);
	*data = measure;
}

/*
* Called once after Initialize
* Called before every Update if DynamicVariables=1 is defined
* Read options that can require dynamic variables here
*/
PLUGIN_EXPORT void Reload(void* data, void* rm, double* maxValue)
{
	Measure* measure = (Measure*)data;
	*maxValue = 1;
}

/*
* Called at every measure update
* Update your values here
*/
PLUGIN_EXPORT double Update(void* data)
{
	Measure* measure = (Measure*)data;
	SYSTEM_POWER_STATUS sps;
	GetSystemPowerStatus(&sps);
	return sps.SystemStatusFlag == 1 ? 1.0 : 0.0;
}

/*
* Called once, at skin unload (a skin is unloaded when you Refresh it)
* Perform any necessary cleanups here
*/
PLUGIN_EXPORT void Finalize(void* data)
{
	Measure* measure = (Measure*)data;
	delete measure;
}
