#ifndef _ONT_PLATFORM_MEMORY_H_
#define _ONT_PLATFORM_MEMORY_H_


# ifdef __cplusplus
extern "C" {
# endif

#include "config.h"

/**
 * �����ڴ�
 * @param  size ��Ҫ������ڴ��ֽ���
 * @return ����ɹ��󷵻�ָ���·�����ڴ�ָ�룬���򷵻� NULL
 */
void *ont_platform_malloc(size_t size);

/**
 * �ͷ��� @see ont_platform_malloc������ڴ�
 * @param ptr ָ��Ҫ���ͷŵ��ڴ�
 */
void ont_platform_free(void *ptr);


# ifdef __cplusplus
}      /* extern "C" */
# endif

#endif /* _ONT_PLATFORM_MEMORY_H_ */
