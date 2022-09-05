#ifndef __DEF_PERF_TEST_EFL_H__
#define __DEF_PERF_TEST_EFL_H__

#include <dlog.h>

#ifdef  LOG_TAG
#undef  LOG_TAG
#endif
#define LOG_TAG "PerfTestEFL"

//#define BODER_EDJ "/usr/apps/performance-test-efl/res/performance-test-efl.edj"

typedef struct _appdata
{
    Evas_Object *win;
    Evas_Object *rootview;
    Evas_Object *buttonview;
    Evas_Object *contentview;
    Evas_Object *laundryview;
    Evas_Object *dryerview;

} appdata;

#endif

