#include <UtilsDefines.h>
#include "CLogger.h"

#if 0
#define _INFO(message, ...) NOTHING
#define _WARN(message, ...) NOTHING
#define _FATAL(message, ...) NOTHING
#define _DEBUG(message, ...) NOTHING
#else
#define _DEBUG(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::DEBUG, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#define _INFO(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::INFO, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#define _WARN(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::WARN, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#define _FATAL(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::FATAL, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#endif

