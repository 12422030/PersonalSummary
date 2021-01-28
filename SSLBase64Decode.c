/*******************************************************
* ��    ˾: ����ͬ�������Ƽ����޹�˾
* �� �� ��: SSLBase64Decode.c
* ������: BASE64��ת����ASC����
* �������:
*           in			��Ҫת����ASC������
*           inl			��Ҫת����ASC�����ݳ���
*           out			ת�����BASC64������
*           outl		ת�����BASC64�����ݳ���
			����out�����ĳ���=in�����ĳ���
* �������:
* �� �� ֵ:
			0		�ɹ�
			!0		ʧ��
* ��    ��: zyw
* ��������: 2011/2
* �� �� ��:
* �޸�����:
*******************************************************/

#include <stdio.h>
#include <string.h>
int SSLBase64Decode(char *in,int inl,char *out,int *outl)
{
		EVP_ENCODE_CTX	dctx;
		int		total=0,outlen=0,ret=0;

		EVP_DecodeInit(&dctx);

		outlen=0;
		ret=EVP_DecodeUpdate(&dctx,out,&outlen,in,inl);
		if(ret<0)
		{
			printf("Call EVP_DecodeUpdate ERROR");
			return -1;
		}
		total+=outlen;

		outlen=0;
		ret=EVP_DecodeFinal(&dctx,out,&outlen);
		total+=outlen;

		*outl=total;

		return 0;
}
