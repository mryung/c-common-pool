
#ifndef __Z_MALLOC__
#define __Z_MALLOC__

#include "ztype.h"

/**
* 分配内存
*/
void *zmalloc(m_size size);

/**
*分配并初始化内存
*/
void *zcalloc(m_size size);
void *zcalloc(m_size num_elements,m_size size);

/**
* 动态扩展内存
*/
void *zrealloc(void *ptr, m_size size);

/**
*释放内存
*/
void zfree(void *ptr);

/**
* 内存定义
*/
void zmemset(void *ptr,size_t size);

#endif