#ifndef __LENA_THREADS_H__
#define __LENA_THREADS_H__

/**************************************************************************//**
 * @file     lthreads.h
 * @brief    Project L - Lena programming language lthreads 
 * @version  V0.0.1
 * @date     7. Jan 2024
 ******************************************************************************/

/* Standard libraires */

#include <stdint.h>
#include <stdbool.h>

/* Libraries */
// No dependencies

#ifdef _WIN32

#include <windows.h>

/* lthread basics */

typedef struct {
    HANDLE hThread;
    DWORD IdThread;
} lthread_t;

typedef DWORD lthread_func_t;
#define LENA_API WINAPI
#define LTHREAD_ARGS        LPVOID lpParam
#define LTHREAD_CALLBACK    0

/* lthread create */

lthread_t lthread_create(LPTHREAD_START_ROUTINE func);

/* lthread get error */

typedef enum {
    LTHREAD_SUCCESS                 = 0b00000011,
    /* NEXT LINES OF CODE ARE NOT CROSS-PLATFORM */
    LTHREAD_ERROR_INVALID_POINTER   = 0b00000001,
    LTHREAD_ERROR_INVALID_ID        = 0b00000010,
} lthread_error_t;

lthread_error_t lthread_get_error(lthread_t thread);

/* lthread join */

#define LTHREAD_WAIT_INFINITE (DWORD)(INFINITE)
typedef DWORD lthread_wait_t;

void lthread_join(lthread_t* thread, lthread_wait_t wait_ms);

#else /* Linux */

#define _GNU_SOURCE
#include <pthread.h>
#include <features.h>
#include <sys/time.h>

/* Funcrions prototypes */

int pthread_tryjoin_np(pthread_t thread, void **retval);

int pthread_timedjoin_np(pthread_t thread, void **retval,
                         const struct timespec *abstime);

/* lthread basics */

typedef enum {
    LTHREAD_SUCCESS = 0,
    /* NEXT LINES OF CODE ARE NOT CROSS-PLATFORM */
    /** LTHREAD_ERROR_N
     *  -> N is error code;
     * 
    */
} lthread_error_t;

typedef struct {
    pthread_t pThread;
    int32_t errThread;
} lthread_t;

typedef void* lthread_func_t;
#define LENA_API
#define LTHREAD_ARGS        void* arg
#define LTHREAD_CALLBACK    NULL

/* lthread create */

lthread_t lthread_create(void *(*func)(void *));

/* lthread get error */

// enum lthread_error_t is defined above

lthread_error_t lthread_get_error(lthread_t thread);

/* lthread join */

#define LTHREAD_WAIT_INFINITE 0
typedef uint32_t lthread_wait_t;

void lthread_join(lthread_t* thread, lthread_wait_t wait_ms);

#endif
#endif // __LENA_THREADS_H__