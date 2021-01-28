#include<string.h>
#include<stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
int main()
{
    xmlDocPtr doc;
    xmlNodePtr curNode;
    xmlNodePtr node1;
    xmlNodePtr node2;
    xmlNodePtr node3;
    xmlNodePtr node4;
    xmlNodePtr node5;
    xmlNodePtr node6;
    xmlNodePtr node7;
    xmlNodePtr node8;
    xmlChar *szKey;

    xmlKeepBlanksDefault(0);

    doc = xmlReadFile("/app/files/epccb/chkfile/20181224/HZ_B201812240008_B201812240008.xml/", "GBK",XML_PARSE_RECOVER);
    if( NULL == doc)
    {
        APPLOG("E","��ȡ���ڵ����!!!![%s]", strerror(errno));
        strcpy(Mxip_rc, "EP01");
        return -5;
    }
    curNode =  xmlDocGetRootElement(doc); //ȷ���ļ���Ԫ��root
    if( NULL == curNode)
    {
        APPLOG("E","��ȡ���ڵ����!!!![%s]", strerror(errno));
        strcpy(Mxip_rc, "EP01");
        return -5;
    }
    APPLOG("D","curNode-[%s]", curNode->name);

    /**1.PyerInf**/
    node1 = curNode->xmlChildrenNode;
    curNode=node1->xmlChildrenNode;
    szKey=xmlNodeGetContent(curNode);  
    if(szKey!=NULL)                 /**PyerAcctIssrId**/
    {
        APPLOG("D","curNode-[%s][%s]", curNode->name, szKey);
        xmlFree(szKey);
    }

    xmlFreeDoc(doc);
    return 0;
}
