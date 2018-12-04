#ifndef ONT_INCLUDE_RTMP_RVOD_H_
#define ONT_INCLUDE_RTMP_RVOD_H_

# ifdef __cplusplus
extern "C" {
# endif

#define M_RTMP_CLIENTBUFLEN 4000



/**********************************/
/*Զ��¼��ط���ͣ                 */
/*ctx,    rtmp�ط�ָ��             */
/*paused, ��ͣ���߻ָ�����         */
/*ts, ��ͣ���߲���ʱ��ʱ���        */
/**********************************/
typedef void(*rtmp_pause_notify)(void* ctx, int paused, double ts);

/**********************************/
/*Զ��¼���϶���ָ��·��            */
/*cxt, rtmp�ط�ָ��                */
/*ts,  �϶�����Ҫ���ŵ�λ��        */
/**********************************/
typedef int(*rtmp_seek_notify)(void* ctx, double ts);

/**********************************/
/*֪ͨ�طſͻ��˲�����ɣ�ֹͣ����*/
/*cxt, rtmp�ط�ָ��                */
/**********************************/
typedef void(*rtmp_stop_notify)(void* ctx);


typedef struct _t_ont_rvod_callbacks
{
    rtmp_pause_notify               pause;
    rtmp_seek_notify                seek;
    rtmp_stop_notify                stop;
}t_ont_rvod_callbacks;

typedef struct _t_rtmp_vod_ctx
{
    void *rtmp;
    void *dev;
    void *user_data;
    int   status; /*0 created, 1 started, 2 stopeed*/
    t_ont_rvod_callbacks callback;
}t_rtmp_vod_ctx;


t_rtmp_vod_ctx *rtmp_rvod_createctx(void *dev, void *user_data, t_ont_rvod_callbacks *vodcb);
int rtmp_rvod_destoryctx(t_rtmp_vod_ctx* ctx);

int rtmp_rvod_start(t_rtmp_vod_ctx* ctx, const char *pushurl, int timeout);
int rtmp_rvod_stop(t_rtmp_vod_ctx* ctx);

int rtmp_rvod_send_videoeof(t_rtmp_vod_ctx* ctx);


# ifdef __cplusplus
}
# endif

#endif /*ONT_INCLUDE_RTMP_RVOD_H_*/
