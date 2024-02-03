#include <UtilsDefines.h>
#include "CLogger.h"

#if 0
#define uINFO(message, ...) NOTHING
#define uWARN(message, ...) NOTHING
#define uFATAL(message, ...) NOTHING
#define uDEBUG(message, ...) NOTHING
#else
#define uDEBUG(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::DEBUG, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#define uINFO(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::INFO, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#define uWARN(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::WARN, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#define uFATAL(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::FATAL, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#endif

