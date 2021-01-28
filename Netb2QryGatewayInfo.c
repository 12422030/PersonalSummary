/*******************#BEGIN#******************
 *�� �� ��: Netb2QryGatewayInfo
 *�� �� ��: ��ѯԭ������Ϣ
 *������: ��ѯԭ������Ϣ
 *��������: liwei
 *�� �� ��: 1.0.0
 *��������: 20190304
 ********************#END#********************/
/********************************************
 *�� �� ��: Netb2QryGatewayInfo
 *�� �� ��: ɨ�赱2����δ��ִ����Ϣ,���з��� 
 *��������: 
 *��������: liwei
 *�� �� ��: 1.0.0
 *��������: 20190304
 *�� �� ��: 
 *            ����         ������ʽ
 *�������: 
 *           ���ݱ���      ����/���      ˵��
 *�޸���ʷ: 
 *  ����      ����       �汾��    ���ԭ��:
 ******************************************************/
#include "kernel/syspub.h"
#include "kernel/xipcmstc.h"
#include "epcc/epccpub.h"
#include "epcc/tabincl/epcc_gateway_c.h"

int Netb2QryGatewayInfo(TxipCMStc *xip)
{
    int ret = 0;
    char orderid[61];

    struct epcc_gateway_c epcc_gateway;

    memset(orderid,0x00,sizeof(orderid));
    memset(&epcc_gateway,0x00,sizeof(epcc_gateway));

    get_zd_data("0820",orderid);
    APPLOG("D","----[%s]----",orderid);

    ret=Epcc_gateway_Sel(Mxip_rc,&epcc_gateway,"orderid='%s'",orderid);
    if(ret)
    {
        APPLOG("E","Call Epcc_gateway_Sel Err[%d]",ret);
        Epcc_gateway_Clo_Sel();
        return -1;
    }
    set_zd_data("0580",epcc_gateway.payerlssid);
    set_zd_data("0230",epcc_gateway.cbflg);
    set_zd_data("0240",epcc_gateway.lmtp);
    set_zd_data("0220",epcc_gateway.payeractp);
    set_zd_data("101A",epcc_gateway.payertxtrmtp);
    set_zd_data("106J",epcc_gateway.payertxtrmno);

    set_zd_data("0700",epcc_gateway.rp_flag);
    
    set_zd_data("0590",epcc_gateway.payeelssid);
    set_zd_data("100B",epcc_gateway.payeeactp);
    set_zd_data("0320",epcc_gateway.payeeacno);
    set_zd_data("0260",epcc_gateway.payeeacname);
    set_zd_data("1014",epcc_gateway.payeecityno);
    set_zd_data("1143",epcc_gateway.payeetxtrmtp);
    set_zd_data("106N",epcc_gateway.payeetxtrmno);
    
    set_zd_data("0600",epcc_gateway.instglssid);
    set_zd_data("0330",epcc_gateway.instgacno);
    set_zd_data("0270",epcc_gateway.instgacname);
    
    set_zd_data("106G",epcc_gateway.epcc_trace);
    set_zd_data("102A",epcc_gateway.epcc_time);
    set_zd_double("0400",epcc_gateway.tx_amt);
    set_zd_data("0640",epcc_gateway.txctgy);
    set_zd_data("1144",epcc_gateway.bzitype);

    set_zd_data("0820",epcc_gateway.orderid);
    set_zd_data("1510",epcc_gateway.orderdesc);
    set_zd_data("0620",epcc_gateway.orderexp);
    set_zd_data("0730",epcc_gateway.pltfrmnm);
    set_zd_data("0960",epcc_gateway.clbckurl);
    
    set_zd_data("0800","");
    set_zd_data("0630",epcc_gateway.chnltp);
    set_zd_data("0950",epcc_gateway.txdevid);

    strcpy(Mxip_rc, "0000");
    return 0;
}
