#ifndef __POOL_CONFIG__
#define __POOL_CONFIG__

#include "utils/z_type.h"

typedef struct{

	int max_active;
	int max_idle;
	int min_idle;

	S64 max_wait;
	
	S64 min_evictable_idle_time_millis; 
	S64 soft_evictable_idle_time_millis;

	Boolean test_on_return;

	Boolean test_on_borrow;

	S64 time_between_eviction_runs_millis;
	
} POOOL_CONFIG;

#endif