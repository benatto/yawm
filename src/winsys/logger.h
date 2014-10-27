#ifndef __H_LOGGER_H__
#define __H_LOGGER_H__

#include <stdio.h>

#define YAWM_ERROR(fmt, ...) \
{\
	printf("[ERROR] - WinSYS - %s()@%s - " fmt, __func__, __FILE__,  ##__VA_ARGS__); \
}

#define YAWM_INFO(fmt, ...) \
{\
	printf("[INFO] - WinSYS - " fmt, ##__VA_ARGS__); \
}

#ifdef DEBUG
#define YAWM_DEBUG(fmt, ...) \
{\
	printf("[DEBUG] - WinSYS - %s()@%s:%d - " fmt, __func__, __FILE__, __LINE__, ##__VA_ARGS__); \
}
#else
#endif
#define YAWN_DEBUG(fmt, ...) {}
#endif
