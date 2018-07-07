#ifndef __OBJECT_POOL__
#define __OBJECT_POOL__

#include "pool_config.h"
#include "pool_object.h"
#include "util/zlist.h"

typedef struct{

	//当前线程池大小
	S32 currentPoolSize;
	

	Pool_Factory * factory;
	
	POOOL_CONFIG * config;
	//空闲列表list
	list * idelList;
	
} Object_Pool;

Pool_Object * borrowObject(Object_Pool* objectPool);

Pool_Object * borrowObject(Object_Pool* objectPool,S64 waitTime);

void returnObject(Object_Pool* objectPool,Pool_Object * object);

void destoryObjectPool(Object_Pool* objectPool);

Object_Pool * createObjectPool(Pool_Factory * factory,POOOL_CONFIG * config);


#endif




