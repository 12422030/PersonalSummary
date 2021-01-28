#include <stdio.h>
#include </app/user/liwei/test/parser.h>
#include </app/user/liwei/test/tree.h>
#include </app/user/liwei/test/xmlstring.h>
#include </app/user/liwei/test/xmlversion.h>
#include </app/user/liwei/test/xmlexports.h>

int main(int argc, char* argv[])
{
    xmlDocPtr doc;           /**��������ļ�ָ��**/
    xmlNodePtr curNode;      /**������ָ��**/
    xmlChar *szKey;          /**��ʱ�ַ�������**/
    char *szDocName;
    if (argc <= 1) {
        printf("Usage: %s docname", argv[0]);
        return(0);
    }
    szDocName = argv[1];
    doc = xmlReadFile(szDocName,"GB2312",XML_PARSE_RECOVER);
    /**�����ļ�**/
    /**�������ĵ��Ƿ�ɹ���������ɹ���libxml������ֹͣ������**/
    /**һ�����������ǲ��ʵ��ı��룬XML��׼�ĵ�������UTF-8��UTF-16�⻹�����������뱣��**/
    if (NULL == doc) {
        fprintf(stderr,"Document not parsed successfully.");
        return -1;
    }
    /**��ȡ���ڵ�**/
    curNode = xmlDocGetRootElement(doc);
    if (NULL == curNode) {
        fprintf(stderr,"empty document");
        xmlFreeDoc(doc);
        return -1;
    }
    /**ȷ�ϸ�Ԫ�������Ƿ����**/
    if (xmlStrcmp(curNode->name, BAD_CAST "root")) {
        fprintf(stderr,"document of the wrong type, root node != root");
        xmlFreeDoc(doc);
        return -1;
    }
    curNode = curNode->xmlChildrenNode;
    xmlNodePtr propNodePtr = curNode;
    while(curNode != NULL) {
        /**ȡ���ڵ��е�����**/
        if ((!xmlStrcmp(curNode->name, (const xmlChar *) "newNode1"))) {
            szKey = xmlNodeGetContent(curNode);
            printf("newNode1: %s\n", szKey);
            xmlFree(szKey);
        }
        /**���Ҵ�������attribute�Ľڵ�**/
        if (xmlHasProp(curNode,BAD_CAST "attribute")) {
            propNodePtr = curNode;
        }
        curNode = curNode->next;
    }

    /**��������**/
    xmlAttrPtr attrPtr = propNodePtr->properties;
    while (attrPtr != NULL) {
        if (!xmlStrcmp(attrPtr->name, BAD_CAST "attribute")) {
            xmlChar* szAttr = xmlGetProp(propNodePtr,BAD_CAST "attribute");
            printf("get attribute=%s\n", szAttr) ;
            xmlFree(szAttr);
        }
        attrPtr = attrPtr->next;
    }
    xmlFreeDoc(doc);
    return 0;
}
