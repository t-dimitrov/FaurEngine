#pragma once
#include "Logger.h"

#ifdef FAUR_DEBUG
    #define FAUR_CORE_ASSERT(condition, msg) { if (!(condition)) { FAUR_CORE_CRITICAL("Assertion Failed: {0}", msg); __debugbreak(); } }
    #define FAUR_ASSERT(condition, msg) { if (!(condition)) { FAUR_CRITICAL("Assertion Failed: {0}", msg); __debugbreak(); } }
#else
    #define FAUR_CORE_ASSERT(condition, msg)
    #define FAUR_ASSERT(condition, msg)
#endif
