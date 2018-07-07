#ifndef  __POOL_OBJECT__
#define  __POOL_OBJECT__

#include "utils/z_type.h"

typedef void (*destory_pool_object)(void *);

typedef struct{

	/**
	*
	*对象产生时间
	*/
	S64 create_time;

	/**
	*最近租借时间
	*/
	S64 last_borrow_time;

	/**
	* 租借次数
	*/
	S64 borrow_times; 



	/**
	* 真正对象
	*/
	void * object;

	destory_pool_object  destory_method;

	
} Pool_Object;



typedef void * (*make_object)(void *);

typedef void  (*destroy_object) (void *);

typedef Boolean (*validate_object)(void *);

typedef struct{

	void * initValue;

	make_object create_method;
	
	destroy_object destroy_method;
	
	validate_object validate_method;
	
} Pool_Factory;


Pool_Object * newPoolObject(void *);

void destroyPoolObject(Pool_Object * object);


#endif

