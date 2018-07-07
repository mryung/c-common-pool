#include "pool_object.h"

#include "utils/zmalloc.h"
#include "utils/zutils.h"

Pool_Object * newPoolObject(Pool_Factory* factory,void * object){
	Pool_Object * object;

	object = zmalloc(size(Pool_Object));
	if(object == NULL){
		//内存分配失败
		printf("malloc pool object error!\n");
		return NULL;
	}

	object->object = object;
	object->create_time = getCurrentMillisecond();
	object->borrow_times = 0;
	object->destory_method = factory->destroy_method;
	return object;
}

void destroyPoolObject(Pool_Object * object){
	if(object->object != null){
		object->destory_method(object->object);
	}
	zfree(object);
}

