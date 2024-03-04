#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <lib/printf.h>

#ifdef DEBUG
#define debug printf
#else
#define debug(...) do {} while(0)
#endif

#endif

/* LOGGING */

#define LOG_LEVEL_NONE				0
#define LOG_LEVEL_ERR				10
#define LOG_LEVEL_WRN				20
#define LOG_LEVEL_INF				30
#define LOG_LEVEL_DBG				40
#define LOG_LEVEL				LOG_LEVEL_NONE

#if (LOG_LEVEL >= LOG_LEVEL_ERR)
#define LOG_ERR(...)				printf("ERR " __VA_ARGS__)
#else
#define LOG_ERR(...)
#endif

#if (LOG_LEVEL >= LOG_LEVEL_WRN)
#define LOG_WRN(...)				printf("WRN " __VA_ARGS__)
#else
#define LOG_WRN(...)
#endif

#if (LOG_LEVEL >= LOG_LEVEL_INF)
#define LOG_INF(...)				printf("INF " __VA_ARGS__)
#else
#define LOG_INF(...)
#endif

#if (LOG_LEVEL >= LOG_LEVEL_DBG)
#define LOG_DBG(...)				printf("DBG " __VA_ARGS__)
#else
#define LOG_DBG(...)
#endif
