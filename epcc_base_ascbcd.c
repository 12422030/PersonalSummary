/*******************#BEGIN#******************
 *�� �� ��: epcc_base_ascbcd
 *�� �� ��: ascbcdת��
 *������: ascbcdת��
 *��������: suitianmou
 *�� �� ��: 1.0.0
 *��������: 2017.09.09
********************#END#********************/
#include <stdio.h>
#include <string.h>
/*******************#epcc_base_ascbcd#******************
 *�� �� ��: epcc_base_ascbcd
 *��������: ����֧��ת��ascתΪbcd
 *��������: zyw
 *�� �� ��: 1.0.0
 *��������: 20110330
******************************************************/
void epcc_base_ascbcd(bcd_buf,ascii_buf,conv_len,type)
unsigned char *bcd_buf,*ascii_buf,type;
int           conv_len;
{
	int  cnt;
	char ch,ch1;

	if( conv_len&0x01 && type )
		ch1 = 0;
	else
		ch1 = 0x55;

	for(cnt=0; cnt<conv_len; ascii_buf++,cnt++) 
    {
		if(*ascii_buf>='a')
		   ch=*ascii_buf-'a'+10;
		else if(*ascii_buf>='A')
		   ch=*ascii_buf-'A'+10;
		else if(*ascii_buf>='0')
		   ch=*ascii_buf-'0';
		else
		   ch=0;

		if(ch1==0x55)
		   ch1=ch;
		else 
        {
	 	   *bcd_buf++ = (ch1<<4)|ch;
			ch1=0x55;
		}
	}

	if(ch1!=0x55)
       *bcd_buf=ch1<<4;

	return;
}

/*******************#epcc_base_bcdasc#******************
 *�� �� ��: epcc_base_bcdasc
 *��������: ����֧��ת��bcdתΪasc
 *��������: zyw
 *�� �� ��: 1.0.0
 *��������: 20110330
******************************************************/
void epcc_base_bcdasc(ascii_buf,bcd_buf,conv_len,type)
unsigned char *ascii_buf,*bcd_buf,type;
int           conv_len;
{
	int cnt;

	if( conv_len&0x01 && type )
    {
		cnt=1;
		conv_len++;
	}
	else
		cnt=0;

	for( ; cnt<conv_len; cnt++,ascii_buf++)
    {
   	    *ascii_buf=((cnt&0x01)?(*bcd_buf++&0x0f):(*bcd_buf>>4));
		*ascii_buf+=((*ascii_buf>9)?('A'-10):'0');
	}

	return;
}
/********************#epcc_base_des-END#********************/
