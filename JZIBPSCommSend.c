/**
	 *LEVEL  �޸��ˡ��޸�����     �޸����� 
	 L0001  ��С��   20130506   �޸Ĵ��ǿ��������ط���
**/
#include "kernel/syspub.h"
#include "kernel/xipcmstc.h"
/** L0001 add  start **/
#include "jzibps/ibpspub.h"
/** L0001 add  start **/
int JZIBPSCommSend(TxipCMStc *xip)
{
    char fileName[31];
    char fullName[201];
    char sPkgHead[41];
    char sTmpStr[31];
    char replyMsg[51];
    char *xmlBuf = NULL;
    char command[101];
    FILE *fp = NULL;
    int  xmlBufLen = 0;
    int  y, m, d, hh, mm, ss;
    int  ret = 0;
/** L0001 add  start **/
	char fcode[11];
	char tcode[11];	
	char routeflag[9];	
	char accttp[13];	
/** L0001 add  start **/

    /*1.��Ӧ����ת��*/
    memset(sTmpStr, 0x00, sizeof(sTmpStr));
    ret = RsCodeLocalToTarget(Mxip_frid, Mxip_rc, sTmpStr, Mxip_rc);
    if (ret)
    {
       set_cm_data(TARGETRSPCODE, "PE3004"); /*��Ӧ����ת������ʱ��Ĭ�ϴ�����*/
    }
    else
    {
       set_cm_data(TARGETRSPCODE, sTmpStr); /*��Ӧ����ת���ɹ�ʱ��ת�������*/
    }

    get_cm_data(XIPREPLYMSG, replyMsg);
    if (replyMsg[0] == 0)
    {
       ret = GetRsCodeName(Mxip_rc, replyMsg);
       if (ret != 0)
       {
          sprintf(replyMsg, "[%s]δ�ҵ���Ӧ��Ϣ", Mxip_rc);
       }
    }
    set_cm_data(XIPREPLYMSG, replyMsg);

    /*2.��ȡ����ʱ��*/
    GetSysDateTime(&y, &m, &d, &hh, &mm, &ss);
    sprintf(sTmpStr, "%04d%02d%02d%02d%02d%02d", y, m, d, hh, mm, ss);
    set_cm_data("1609", sTmpStr);

    /*3.�鱨����*/
    if (Mxip_frtrbflag[0] == '2' || Mxip_frtrbflag[0] == '3')
    {
       if (strcmp(Mxip_rc, "0000") == 0)
       {
          get_cm_data(SENDFILENAME, fileName);
          strtrim(fileName);

          sprintf(fullName, "%s/%s", Mxip_sfpath, fileName);
          fp = fopen(fullName, "r");
          if (fp == NULL)
          {
             APPLOG("E", "Open File [%s] Err![%s]", fileName, strerror(errno));
             return -5;
          }
       }
    }

/** L0001 add  start **/
	memset(fcode, 0x00, sizeof(fcode));
	memset(tcode, 0x00, sizeof(tcode));
	memset(routeflag, 0x00, sizeof(routeflag));
	memset(accttp, 0x00, sizeof(accttp));
	
	strcpy(tcode, Mxip_frtc);
	get_cm_data("1610", routeflag);
	strtrim(routeflag);
	if (strlen(routeflag) && !strcmp(routeflag, "ROUTEGO"))
	{
		get_cm_data("1602", accttp);
		strtrim(accttp);		
		if (strcmp(accttp, "AT02")) {}
		else	/*���ǿ�*/
		{
		    ret = GetXipParmConv("IBPS_TRCODE", Mxip_frtc, 1, fcode, Mxip_rc);
		    if (ret != 0)	{}
		    else
		    {
		    	strtrim(fcode);
		    	memset(tcode, 0x00, sizeof(tcode));
		    	strcpy(tcode, fcode);		    	
		    }
		}
	}
	else { APPLOG("D", "��������") ; }
	ret = XmlCreateAndAttr(Mxip_frid, Mxip_frdcmode, tcode, Mxip_frfsign, NULL, fp, "B", NULL, &xmlBuf, &xmlBufLen, Mxip_rc);
/** L0001 add  end **/	   	

/** L0001 upd  start **/
	/**ret = XmlCreateAndAttr(Mxip_frid, Mxip_frdcmode, Mxip_frtc, Mxip_frfsign, NULL, fp, "B", NULL, &xmlBuf, &xmlBufLen, Mxip_rc);**/
/** L0001 upd  end **/	
    if (ret)
    {
       APPLOG("E", "CALL XmlCreateAndAttr Error=[%d]", ret);
       if (xmlBuf != NULL) free(xmlBuf);
       if (fp != NULL) fclose(fp);
       return -10;
    }

    xmlBuf[xmlBufLen] = 0;

APPLOG("D", "xmlBuf=[%s]", xmlBuf);

    /*4.�鱨��ͷ*/
    memset(sPkgHead, 0x00, sizeof(sPkgHead));

    /*�����峤��8λ*/
    sprintf(sPkgHead, "%08d", xmlBufLen+8);
   
    /*��������4λ*/
    strcpy(sPkgHead+8, "1410");

    /*������*/
    Mxip_frtc[4] = 0;
    sprintf(sPkgHead+12, "%s", Mxip_frtc);

    /*5.���ͱ���ͷ*/
    ret = TcpSend(Mxip_sockid, sPkgHead, 16, Mxip_frtmout);
    if (ret) 
    { 
       APPLOG("E", "TCPIP Send PackLen Failed![%d][%s]", ret, strerror(errno)); 
       free(xmlBuf);
       if (fp != NULL) fclose(fp);
       return -15; 
    }

    /*6.���ͱ�����*/
    ret = TcpSend(Mxip_sockid, xmlBuf, xmlBufLen, Mxip_frtmout);
    if (ret) 
    { 
       APPLOG("E", "TCPIP Send Pack Failed![%d][%s]", ret, strerror(errno)); 
       free(xmlBuf);
       if (fp != NULL) fclose(fp);
       return -20;  
    }
	if ( xmlBuf !=NULL)  
	{
		 free(xmlBuf); 
		 APPLOG("D", "�ر�xmlBuf");
	}
    if (fp != NULL) fclose(fp);

    /*������׳ɹ������Ƕ��˽������������˳�����ж���*/
    memset(command, 0x00, sizeof(command));
    memset(sTmpStr, 0x00, sizeof(sTmpStr));

    get_cm_data(TARGETRSPCODE, sTmpStr);

    if (strcmp(sTmpStr, "PE0000") == 0 && 
        (strcmp(Mxip_frtc, "9000") == 0 || strcmp(Mxip_frtc, "9100") == 0)
       )
    {
       /*����:�ϼ�����ID ����ID ���˽��� �������� ���˿�ʼ���� ������ֹ����*/
       sprintf(command, "JZIBPSChkServer %s %s %s %d %d %d 1>>%s/%s 2>>%s/%s &",
                         Mxip_frsid,
                         Mxip_frid,
                         Mxip_frtc,
                         g_chk_date,
                         g_chk_begdate,
                         g_chk_enddate, 
                         appLog.appLogPath,
                         appLog.appLogName,
                         appLog.appLogPath,
                         appLog.appLogName);
	  APPLOG("D", "����ִ��=[%s]", command);
       system(command);
    }

    return 0;

}

