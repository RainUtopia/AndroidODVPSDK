#ifndef ONT_INCLUDE_PROTOCOL_H_
#define ONT_INCLUDE_PROTOCOL_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct t_message_header_tag
{
	char     flag;
	uint32_t msg_length;
	uint16_t msg_type;
	uint32_t msg_id;
}t_message_header;

typedef struct t_message_register_tag
{
	uint64_t pid;
	uint8_t  regcode_size;
	char*    regcode;
	uint8_t  deviceid_size;
	char*    deviceid;
}t_message_register;


typedef struct t_message_addchannel_tag
{
	uint32_t chnid;
	uint8_t  title_length;
	char*    title;
	uint8_t  desc_length;
	char*    desc;
}t_message_addchannel;

typedef struct t_message_picture_tag
{
	uint32_t  chnid;           //通道ID
	uint8_t   picture_type;    //图片类型  1 PNG 2 JPG
	uint16_t  name_length;     //图片名字长度
	char*     name;            //图片名字
	uint32_t  picture_length;  //图片长度
	char*     picture;         //图片
}t_message_picture;

typedef struct t_message_pre_picture_tag
{
    uint32_t chnid; // ͨ��ID
    uint8_t  type;  // ͼƬ���� 1 PNG; 2 JPG
    uint32_t size;  // ͼƬ��С
    const char *   pic;   // ͼƬ����
}t_message_pre_picture;

#define MSG_FLAG_VERSION 0x01

#define MSG_TYPE_REQ_PUBKEY                     0x0001
#define MSG_TYPE_REQ_PUBKEY_RESP                0x8001
#define MSG_TYPE_PLATFORM_REQ_PUBKEY            0x0002
#define MSG_TYPE_PLATFORM_REQ_PUBKEY_RESPONSE   0x8002
#define MSG_TYPE_DEVICE_REGISTER                0x0003
#define MSG_TYPE_DEVICE_REGISTER_RESP           0x8003
#define MSG_TYPE_AUTH                           0x0004
#define MSG_TYPE_AUTH_RESP                      0x8004
#define MSG_TYPE_KEEPALIVE                      0x0005
#define MSG_TYPE_KEEPALIVE_RESP                 0x8005

#define MSG_TYPE_QUERY_CHANNELLIST              0x0006
#define MSG_TYPE_QUERY_CHANNELLIST_RESP         0x8006
#define MSG_TYPE_ADD_CHANNEL                    0x0007
#define MSG_TYPE_ADD_CHANNEL_RESP               0x0007
#define MSG_TYPE_DEL_CHANNEL                    0x0008
#define MSG_TYPE_DEL_CHANNEL_RESP               0x8008

#define MSG_TYPE_LIVE_START                     0x0009
#define MSG_TYPE_LIVE_START_RESP                0x8009

#define MSG_TYPE_RVOD_START                     0x000A
#define MSG_TYPE_RVOD_START_RESP                0x800A

#define MSG_TYPE_PLATFORM_CMD                   0x000B
#define MSG_TYPE_PLATFORM_CMD_RESP              0x800B
 
#define MSG_TYPE_USERDEFINED_CMD                0x000C
#define MSG_TYPE_USERDEFINED_CMD_RESP           0x800C

#define MSG_TYPE_CONNECT_VERIFY                 0x000D
#define MSG_TYPE_CONNECT_VERIFY_RESP            0x800D


#define MSG_TYPE_UPLOAD_PICTURE                 0x0011
#define MSG_TYPE_UPLOAD_PICTURE_RESP            0x8011

#define MSG_TYPE_UPLOAD_PIC_PREVIEW             0x0012
#define MSG_TYPE_UPLOAD_PIC_PREVIEW_RESP        0x8012

#define MSG_TYPE_KEEP_CONNECT					0x0013
#define MSG_TYPE_USERDEFINED_ACTIVATED_CMD		0x0014

#define MSG_TYPE_REQ_PUSH_STREAM				0x0015
#define MSG_TYPE_REQ_PUSH_STREAM_RESP			0x8015


#define MSG_TYPE_DEVICE_UPLOAD_DATA             0x000E

#define MSG_TYPE_CHANNEL_RECORD_STATUS          0x000F
#define MSG_TYPE_CHANNEL_RECORD_RESP            0x800F

#define MSG_TYPE_GET_SYSTIME                    0x0010
#define MSG_TYPE_GET_SYSTIME_RESP               0x8010


#define ONT_PROTOCOL_DEFAULT_SIZE               65536
#define ONT_PROTOCOL_COMM_HEADER_LENGTH         10
#define ONT_PROTOCOL_COMM_PLAIN_HEADER          4


int ont_device_msg_snd_response(ont_device_t *dev, uint16_t msgtype, char *msg, size_t length, uint32_t ms);

int ont_device_msg_sendmsg(ont_device_t *dev, uint16_t type, const char *data, size_t length, uint8_t wait_resp,
	char *resp, size_t *resp_length, uint32_t ms);

int ont_device_msg_register(ont_device_t *dev, t_message_register *reg);

int ont_device_msg_addchannel(ont_device_t *dev, t_message_addchannel *chn);

int ont_device_msg_rcv(ont_device_t *dev, char **msg_out/*message out, not including header*/, t_message_header *header, uint32_t ms);

int ont_device_msg_callback(ont_device_t *dev, char *msg, size_t length, t_message_header *header);

int ont_device_msg_upload_picture(ont_device_t *dev, t_message_picture *pic);

int ont_device_msg_upload_preview_picture(ont_device_t *dev, t_message_pre_picture *pic);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ONT_INCLUDE_PROTOCOL_H_ */
