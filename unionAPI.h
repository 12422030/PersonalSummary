#ifndef _UNIONAPI_H_
#define _UNIONAPI_H_

#define LEN_OF_UNIONMSG 8192

// ������Ϣ
typedef struct
{
        char                    id[32+1];               // out,���ױ�ʶ,8λ����+8λ�̺߳�+8λ˳���
        unsigned long           useTime;                //��ʱ
        char                    responseCode[6+1];      // out,��Ӧ��
        char                    responseRemark[128+1];  // out,��Ӧ����
        unsigned int		lenOfLog;               // out,��־��С
        char                    log[20480+1];           // out,��־
        char                    serviceCode[5];        // ������� added 2015-06-16
	int			writeLog_flag;		// Ϊ1ʱÿ�ʶ�д����Ϊ0ʱ���壬������UnionSetAPILogEndд�����嵽��־�ļ���
}TUnionTransInfo;
typedef TUnionTransInfo		*PUnionTransInfo;

/*
����:  	�ͷ�API�������Դ���ڽ����˳�ʱ����
����: 	
	��

����ֵ: >=0 �ɹ�
	<0 ������
*/
int UnionAPIFree();

/*
API��ʼ
���ܣ�
	������������룬������־���棬����API�����ļ�����ʼ���������Ӧbuf��
������
	serviceCode[in]         ������
	userInfo[in]            �û��Զ�����Ϣ��Ϊ��ʱapi�Զ����ɣ����鴫�뽻����ˮ��
	sysID[in]               �ⲿϵͳID��Ϊ��ʱ��ʹ�������ļ��е�sysID
	appID[in]               Ӧ��ϵͳID��Ϊ��ʱ��ʹ�������ļ��е�appID
���أ�
	=0      �ɹ�
	<0      ʧ��
*/
int UnionAPI_start(const char *serviceCode, const char *userInfo, const char *sysID, const char *appID);

/*
API�������
���ܣ�
	����API���񣬲��������е���־��д����־�ļ��С�
*/
int UnionAPI_end();

/*
����API������
���ܣ�
	����API���������������ֵΪ�ַ�����
������
	fieldName[in]		����������
	fieldValue[in]		�������ֵ
	fieldLen[in]		�������ֵ����
���أ�
	=0	�ɹ�
	<0	ʧ��
*/
int UnionAPI_setString(const char *fieldName, const char *fieldValue, int fieldLen);

/*
����API������
���ܣ�
	����API���������������ֵΪ������
������
	fieldName[in]		����������
	fieldValue[in]		�������ֵ
���أ�
	=0	�ɹ�
	<0	ʧ��
*/
int UnionAPI_setInteger(const char *fieldName, int fieldValue);

/*
��ȡAPI��Ӧ��
���ܣ�
	��ȡAPI����Ӧ����Ӧ���ֵΪ�ַ�����
������
	fieldName[in]		��Ӧ������
	fieldValue[in]		��Ӧ���ֵ
	size[in]		����Ĵ�С
���أ�
	>=0	��Ӧ���ֵ����
	<0	ʧ��
*/
int UnionAPI_getString(const char *fieldName, char *fieldValue, int size);

/*
��ȡAPI��Ӧ��
���ܣ�
	��ȡAPI����Ӧ����Ӧ���ֵΪ������
������
	fieldName[in]		��Ӧ������
	fieldValue[in]		��Ӧ���ֵ
���أ�
	=0	�ɹ�
	<0	ʧ��
*/
int UnionAPI_getInteger(const char *fieldName, int *fieldValue);

/*
���������ĵ�ƽ̨����������Ӧ����
���ܣ�
	����API�����ĵ�ƽ̨����������Ӧ����
	�����̨���ش����벻Ϊ000000����ú������غ�̨��Ӧ�����롣
����ֵ��
	>=0	�ɹ�
	<0	ʧ��
*/
int UnionAPI_send();

/*
��ȡ���һ�η��񱨴�Ĵ���˵��
���ܣ�
	��ȡ���һ�η��񱨴�Ĵ���˵����������˵�����ȳ��������Сsizeʱ����ȡ�����С�Ĵ���˵����
	errRemark[out]		���մ���˵���Ļ���
	size[in]		���մ���˵���Ļ����С
����ֵ��
	>=0	�ɹ�
	<0	ʧ��
*/
int UnionAPI_getLastErrRemark(char *errRemark, int size);

/*
��������ĵ�������
���ܣ�
	��������ĵ�������
	buf[out]	���������ĵĻ���
	size[in]	���������ĵĻ����С
����ֵ��
	>=0	�ɹ�
	<0	ʧ��
*/
int UnionAPI_printRequest(char *buf, int size);

/*
�����Ӧ���ĵ�������
���ܣ�
	�����Ӧ���ĵ�������
	buf[out]	������Ӧ���ĵĻ���
	size[in]	������Ӧ���ĵĻ����С
����ֵ��
	>=0	�ɹ�
	<0	ʧ��
*/
int UnionAPI_printResponse(char *buf, int size);

/*
��ȡ���һ�η�����Ӧ��userInfo��������ˮ�ţ�
���ܣ�
	��ȡ���һ�η�����Ӧ��userInfo��������ˮ�ţ�
	userInfo[out]		���ս���userInfo��Ϣ�Ļ���
	size[in]		���ս���userInfo��Ϣ�Ļ����С
����ֵ��
	>=0     �ɹ���������ˮ���ַ�������
	<0      ʧ��
*/
int UnionAPI_getUserInfo(char *userInfo, int size);

/*
����SSL��������Ϊ��������
���ܣ�
	plainText[in]		SSL�������룬ԭʼ�ַ���
	cryptogram[out]		�������룬��չ��16�����ַ���
����ֵ��
	>=0	�ɹ�
	<0	ʧ��
*/
int UnionAPI_encSSLPasswd(const char *plainText, char *cryptogram);

#endif 
