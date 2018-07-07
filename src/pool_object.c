#include "pool_object.h"

#include "utils/zmalloc.h"
#include "utils/zutils.h"

Pool_Object * newPoolObject(void * object){
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

	return object;
}

void destroyPoolObject(Pool_Factory* factory,Pool_Object * object){

	factory->destroy_method(object->object);
	zfree(object);
	
}

