#include <stdio.h>
#include <stdlib.h>
#include "apduManagement.h"

#define DATA_PACKAGE_MAX_SIZE 254

char selectCmd[] = {0x00, 0xA4, 0x04, 0x00, 0x06, 0x11, 0x22, 0x33, 0x44, 0x55, 0x22, 0x00};
char setRsaKeyLength[] = {0x00, 0x01, 0x00, 0x00, 0x02, 0x08, 0x00, 0x00};
char setPadding[] = {0x00, 0x02, 0x00, 0x00, 0x01, 0x0A, 0x00};

int bufLength; //全局变量，每次发送数据的长度

int receiveDataLength; //全局变量，收到的数据总长度
char receiveData[1024];
//char *receiveData = (char *)malloc(receiveDataLength); // 全局变量，收到的总数据

char *storeData(char dataToReceive[], int dataToReceiveLength)
{
  int i;
	int index = 0;
	int offset = index * DATA_PACKAGE_MAX_SIZE;
	if(dataToReceiveLength <= DATA_PACKAGE_MAX_SIZE)
	{
		for(i = offset; i < dataToReceiveLength; i++)
		{
			receiveData[i] = dataToReceive[i];
		}
		index++;
	}
	return receiveData;
}

char *sendData(char dataToSend[], int dataToSendLength)
{
	int p1 = dataToSend[2];
	int p2 = dataToSend[3];
	int numOfDataPackage = (((dataToSendLength % DATA_PACKAGE_MAX_SIZE) == 0)?
	                                     (dataToSendLength / DATA_PACKAGE_MAX_SIZE):(dataToSendLength / DATA_PACKAGE_MAX_SIZE + 1));
	if((int)p1 < numOfDataPackage)
	{
		int i;
		int offset = (int) (p1 * DATA_PACKAGE_MAX_SIZE);
	  int remainingLength = (int) (dataToSendLength - offset);
	  bufLength = (remainingLength > DATA_PACKAGE_MAX_SIZE) ? DATA_PACKAGE_MAX_SIZE : remainingLength;
	  char *buffer = (char *)malloc(bufLength);
    //char buffer[bufLength];
		for(i = offset; i < bufLength; i++)
		{
			buffer[i] = dataToSend[i];
		}
    //printf("%d",buffer[0]);
    for(i = 0;i<8;i++)
    {
      printf("0x%x\t", buffer[i]);
    }
	  return buffer;   //返回每次发送的数据
	}
	else
	{
	  printf("Wrong P1 or P2!");
		return NULL;
  }
}
