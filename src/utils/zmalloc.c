#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>



#ifndef defined USE_Z_MALLOC
#define USE_Z_MALLOC


#define z_malloc(size) malloc(size) 
#define z_calloc(count,size) calloc(count,size) 
#define z_realloc(ptr,size) realloc(ptr,size) 
#define z_free(ptr) free(ptr) 
#define z_memset(ptr) memset(ptr) 

void *zmalloc(m_size size) {
    void *ptr = z_malloc(size);
 
    return ptr;
}
void *zcalloc(m_size size) {

    void *ptr = z_calloc(1, size);   
    return ptr;
}

void *zcalloc(m_size num_elements,m_size size) {

    void *ptr = z_calloc(num_elements, size);   
    return ptr;
}


void zfree(void *ptr) {
    z_free(ptr);
}

void *zrealloc(void *ptr, m_size size){
	void *ptr = z_realloc(ptr, size);

}

void zmemset(void *ptr,m_size size){
	z_memset(ptr,size);
}

#endif


