#ifndef _ONT_PLATFORM_PERSISTENCE_H_
#define _ONT_PLATFORM_PERSISTENCE_H_

# ifdef __cplusplus
extern "C" {
# endif


/**
 * �־û������豸״̬����
 * @param status ָ���豸״̬���ݿ�
 * @param size �豸״̬���ݿ��ֽ���
 * @return ����ɹ�����ONT_ERR_OK
 * @remark �洢�豸״̬�Ĺ����У�Ҫ��ֹ�洢�����ݱ�д��
 */
int ont_platform_save_device_status(const char *status, size_t size);
/**
 * �����豸״̬����
 * @param status ָ�����ڱ����豸״̬���ݵ��ڴ�
 * @param size ���ص��豸״̬���ֽ���
 * @return ���سɹ�����ONT_ERR_OK
 */
int ont_platform_load_device_status(char *status, size_t size);



#ifdef __cplusplus
} /* extern "C" */
#endif



#endif /* ONT_PLATFORM_PERSISTENCE_SUPPORT */



