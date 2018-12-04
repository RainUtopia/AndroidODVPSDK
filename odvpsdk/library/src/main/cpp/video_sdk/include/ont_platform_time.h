#ifndef ONT_INCLUDE_TIME_H_
#define ONT_INCLUDE_TIME_H_

# ifdef __cplusplus
extern "C" {
# endif

#include "config.h"


/**
 * ��ȡ��ǰʱ�䣬��λ��
 * @return ���ؾ���ĳ�̶�ʱ��������
 */
uint32_t ont_platform_time();

/**
 * ˯�� milliseconds ����
 * @param  milliseconds Ҫ˯�ߵ�ʱ�䣬��λ������
 */
void ont_platform_sleep(int milliseconds);

struct ont_timeval{
	uint64_t  tv_sec;
	int tv_usec;
};

/*get time*/
int ont_gettimeofday(struct ont_timeval *val, int*zp);


/*set time*/
int ont_settimeofday(struct ont_timeval *val, int*zp);


# ifdef __cplusplus
}      /* extern "C" */
# endif

#endif /* ONT_INCLUDE_TIME_H_ */

