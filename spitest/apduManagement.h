#ifndef APDU_MANAGEMENT_H
#define APDU_MANAGEMENT_H
 
extern char selectCmd[16];
extern char setRsaKeyLength[16];
extern char setPadding[16];

char *storeData(char dataToReceive[], int dataToReceiveLength);
char *sendData(char dataToSend[], int dataToSendLength);

#endif