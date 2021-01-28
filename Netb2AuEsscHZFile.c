/*******************#BEGIN#******************
 *�� �� ��: epccAuEsscHZFile
 *�� �� ��: ���ܺͽ�ѹ�����ļ�
 *������: ���ܺͽ�ѹ�����ļ�
 *��������: suitm
 *�� �� ��: 1.0.0
 *��������: 20170906
 ********************#END#********************/
/*******************#epccAuEsscHZFile-BEGIN#******************
 *�� �� ��: epccAuEsscHZFile
 *�� �� ��: ���ܺͽ�ѹ�����ļ�
 *��������: ���ܺͽ�ѹ�����ļ�
 *��������: suitm
 *�� �� ��: 1.0.0
 *��������: 20170906
 *�� �� ��: 
 *            ����         ������ʽ
 *�������: 
 *           ���ݱ���      ����/���      ˵��
 *             P0250           I         �ļ���
 *�޸���ʷ: 
 *  ����    ����       �汾��    ���ԭ��:
 ******************************************************/
#include <libgen.h>
#include "epcc/epccpub.h"
#include "kernel/syspub.h"
#include "kernel/xipcmstc.h"
#include "kernel/xipbsipub.h"

char*EncodeAllConv(char*convFunc,char*inBuf,int inLen);
int Netb2AuEsscHZFile(TxipCMStc *xip)
{

    int ret = 0;
    char filename[256]={0};
    char filepath[512]={0};
    int  bcdlen=0;
    int  conlen=0;
    char decBuf[256]={0};
    char keyValue[65]={0};
    char keyType[10]={0};
    char conType[10]={0};
    char *conValu=NULL;
    unsigned char bcdBuf[1024];
    char ascBuf[1024];
    FILE *fpr=NULL; 
    FILE *fpw=NULL; 
    char name[256]={0}; 
    char path[512]={0};
    char inbuffer[4096];
    char outbuffer[4096];
    int hour=0;
    int minute=0;
    int second=0;
    long date=0;

    memset(bcdBuf,0x00,sizeof(bcdBuf));
    memset(ascBuf,0x00,sizeof(ascBuf));
    memset(inbuffer,0x00,sizeof(inbuffer));
    memset(outbuffer,0x00,sizeof(outbuffer));

    get_zd_data("1202", filename);
    get_zd_long("0770", &date);

    GetSysTime(&hour, &minute, &second);
    sprintf(name,"%ld%02d%02d%02d",date,hour,minute,second);
    set_zd_data("1035",name);
    sprintf(path,"%s/%s",Mxip_rfpath,name);

    snprintf(filepath,sizeof(filepath),"%s/%s",Mxip_rfpath,filename);
    APPLOG("D","[%s][%s]",filepath,path);

    fpr=fopen(filepath,"r");
    if(fpr==NULL)
    {
        fclose(fpr);
        APPLOG("E","�ļ���Ϊ��[%s]",filepath);
        strcpy(Mxip_rc, "EP01");
        return -1;
    }
    fpw=fopen(path,"w");
    if(fpw==NULL)
    {
        APPLOG("D","��д�ļ�ʧ��!");
        return -2;
    }

    fgets(inbuffer,4096,fpr);

    epcc_base_decBs64(inbuffer,bcdBuf,&bcdlen);
    epcc_base_bcdasc(ascBuf,bcdBuf,bcdlen*2,0);


    strcpy(keyType,"R");
    strcpy(keyValue,"3AAE296371E6A8514C2A42AC40038AED26A221E15DEB3FC010FD7B6DB8A68D3F");
    /**����������д�������,���6.14.4�½�**/
    ret=EpccEsscLmkDeData(keyValue,keyType,ascBuf,decBuf,&conlen);
    if(ret)
    {   
        APPLOG("D","����ʧ��[%s]",ascBuf);
        return -5;
    }
    strcpy(conType,"UToG1");
    conValu=EncodeAllConv(conType,decBuf,strlen(decBuf));
    strcpy(outbuffer,conValu);
    APPLOG("D","���ܺ�����:[%s]",outbuffer);

    fprintf(fpw,"%s",outbuffer);

    fclose(fpw);
    fclose(fpr);

    set_zd_data("1035",name);
    set_zd_data(SENDFILENAME,name);
    set_zd_data(BATCHFILEFLAG,"1");

    strcpy(Mxip_rc,"0000");    
    return 0;
}
