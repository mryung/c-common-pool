#include "object_pool.h"
#include "utils/zlist.h"
#include "utils/zmalloc.h"
#include <stdio.h>
#include <stdlib.h>


Pool_Object * borrowObject(Object_Pool* objectPool){
	int currentPoolSize;
	Pool_Object * value;
	POOOL_CONFIG * config;
	Pool_Factory factory;
	config = objectPool->config;
	currentPoolSize = objectPool->currentPoolSize;
	
		//从空闲节点上摘下一个
	while(True){
		if(objectPool->idelList->len > 0){
			value = listGetAndDelHeadValue(objectPool->idelList)
			if(value){
				value->borrow_times++;
				return value;
			}else{
				//阻塞等待
				
			}
		}else{
			break;
		}
	}
	if(currentPoolSize > config.max_active){
		printf("over line the pool\n")
		return NULL;
	}else{
		//得到创建一个连接
		value = newPoolObject(objectPool->factory);
		if(value){
			value->borrow_times++;
			objectPool->currentPoolSize++;
			return value;
		}
		return NULL;
	}
}

Pool_Object * borrowObject(Object_Pool* objectPool,S64 waitTime){

	return NULL;
}

void returnObject(Object_Pool* objectPool,Pool_Object * object)
{
	int returnPoolSize;
	list * tempList;

	returnPoolSize = objectPool->currentPoolSize + 1;
	
	if(returnPoolSize > objectPool->config->max_idle){

		//销毁这个对象
		destroyPoolObject(object);
		objectPool->config--;
	
	}else{
		//更行租借时间，返回空闲列表
		object->last_borrow_time = getCurrentMillisecond();
		tempList = listAddNodeTail(objectPool->idelList,object);
		if(tempList == NULL){
			//加入空闲队列失败 销毁这个对象
			printf("add idel queue error\n")
			destroyPoolObject(object);
		}
		objectPool->currentPoolSize = returnPoolSize;		
	}

}

void destoryObjectPool(Object_Pool* objectPool){
	//**没有销毁 factory 和 config ，外面申请，外面销毁**/

	//销毁list
	listRelease(objectPool->idelList);
	zfree(objectPool);
}

Object_Pool * createObjectPool(Pool_Factory * factory,POOOL_CONFIG * config){

	Object_Pool * objectPool;
	objectPool = zmalloc(sizeof(Object_Pool));
	if(objectPool == NULL){
		//内存分配失败
		printf("malloc pool object error!\n");
		return NULL;
	}
	objectPool->factory = factory;
	objectPool->config = config;
	objectPool->idelList = listCreate();
	objectPool->idelList->free = destroyPoolObject;

	return objectPool;
}



