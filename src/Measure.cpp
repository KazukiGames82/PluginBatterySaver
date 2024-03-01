#include "Plugin.h"
#include "Measure.h"

Measure::Measure(void* _rm) :
	rm(_rm),
	skin(RmGetSkin(_rm))
{
}

Measure::~Measure()
{
}
