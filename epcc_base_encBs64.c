/*******************#BEGIN#******************
 *�� �� ��: epcc_base_encBs64
 *�� �� ��: ����base64
 *������: ����base64
 *��������: heqy
 *�� �� ��: 1.0.0
 *��������: 20161021
********************#END#********************/
/*******************#epcc_base_encBs64-BEGIN#******************
 *�� �� ��: epcc_base_encBs64
 *�� �� ��: ����base64
 *��������: 
 *��������: heqy
 *�� �� ��: 1.0.0
 *��������: 20161021
 *�� �� ��: 
 *            ����         ������ʽ
 *�������: 
 *           ���ݱ���      ����/���      ˵��
 *�޸���ʷ: 
 *  ����    ����       �汾��    ���ԭ��:
 ******************************************************/
#include "kernel/syspub.h"
#include "kernel/xipcmstc.h"

int epcc_base_encBs64(char *bindata,int datalen, char *base64)
{

    int len=0;

    SSLBase64Encode(bindata, datalen, base64,&len) ;

    /*ȥ�����һλ\n */
    if( base64[len-1] == '\n')
    {
        base64[len-1] = 0x00;
        len -= 1;
    }

    return 0;
}

/********************#epcc_base_encBs64-END#********************/
