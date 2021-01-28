#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("���Խ���xml�ļ�");
    return 0;
}
thObjectPtr getNodeSet(xmlDocPtr doc,const xmlChar *szXpath)
{

    xmlXPathContextPtr context;            //XPATH������ָ��
    xmlXPathObjectPtr result;              //XPATH����ָ�룬�����洢��ѯ���
    context = xmlXPathNewContext(doc);     //����һ��XPath������ָ��
    if (context == NULL)
    {  
        printf("context is NULL");
        return NULL;
    }
    result = xmlXPathEvalExpression(szXpath, context); //ѯXPath���ʽ���õ�һ����ѯ���
    xmlXPathFreeContext(context);                      //�ͷ�������ָ��
    if(result==NULL)
    {
        printf("xmlXPathEvalExpression return NULL");
        return NULL; 
    }
    if(xmlXPathNodeSetIsEmpty(result->nodesetval))    //����ѯ����Ƿ�Ϊ��
    {
        xmlXPathFreeObject(result);
        printf("nodeset is empty");
        return NULL;
    }
    return result;   
}

