#include "spitest.h"

//#include "Debug.h"
#define SPI_DEBUG 1

#define pr_debug printf
#define pr_err printf


static const char *device = "/dev/spidev0.0";
static uint8_t mode = 0; /* SPI通信使用全双工，设置CPOL＝0，CPHA＝0。 */
static uint8_t bits = 8; /* ８ｂiｔｓ读写，MSB first。*/
static uint32_t speed = 100 * 1000;/* 设置100K传输速度 */
static uint16_t delay = 0;
static int g_SPI_Fd = 0;


static void pabort(const char *s)
{
perror(s);
abort();
}


/**
* 功 能：同步数据传输
* 入口参数 ：
* TxBuf -> 发送数据首地址
* len -> 交换数据的长度
* 出口参数：
* RxBuf -> 接收数据缓冲区
* 返回值：0 成功
*/
int SPI_Transfer(const uint8_t *TxBuf, uint8_t *RxBuf, int len)
{
int ret;
int fd = g_SPI_Fd;


struct spi_ioc_transfer tr ={
.tx_buf = (unsigned long) TxBuf,
.rx_buf = (unsigned long) RxBuf,
.len =len,
.delay_usecs = delay,
};


ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
if (ret < 1)
pr_err("can't send spi message");
else
{
#if SPI_DEBUG
int i;
pr_debug("\nsend spi message Succeed");
pr_debug("\nSPI Send [Len:%d]: ", len);
for (i = 0; i < len; i++)
{
if (i % 8 == 0)
printf("\n\t");
printf("0x%02X ", TxBuf[i]);
}
printf("\n");


pr_debug("SPI Receive [len:%d]:", len);
for (i = 0; i < len; i++)
{
if (i % 8 == 0)
printf("\n\t");
printf("0x%02X ", RxBuf[i]);
}
printf("\n");
#endif
}
return ret;
}


/**
* 功 能：发送数据
* 入口参数 ：
* TxBuf -> 发送数据首地址
＊len -> 发送与长度
＊返回值：0 成功
*/
int SPI_Write(uint8_t *TxBuf, int len)
{
int ret;
int fd = g_SPI_Fd;


ret = write(fd, TxBuf, len);
if (ret < 0)
pr_err("SPI Write error\n");
else
{
#if SPI_DEBUG
int i;
pr_debug("\nSPI Write [Len:%d]: ", len);
for (i = 0; i < len; i++)
{
if (i % 8 == 0)
printf("\n\t");
printf("0x%02X ", TxBuf[i]);
}
printf("\n");


#endif
}


return ret;
}


/**
* 功 能：接收数据
* 出口参数：
* RxBuf -> 接收数据缓冲区
* rtn -> 接收到的长度
* 返回值：>=0 成功
*/
int SPI_Read(uint8_t *RxBuf, int len)
{
int ret;
int fd = g_SPI_Fd;
ret = read(fd, RxBuf, len);
if (ret < 0)
pr_err("SPI Read error\n");
else
{
#if SPI_DEBUG
int i;
pr_debug("SPI Read [len:%d]:", len);
for (i = 0; i < len; i++)
{
if (i % 8 == 0)
printf("\n\t");
printf("0x%02X ", RxBuf[i]);
}
printf("\n");
#endif
}


return ret;
}


/**
* 功 能：打开设备 并初始化设备
* 入口参数 ：
* 出口参数：
* 返回值：0 表示已打开 0XF1 表示SPI已打开 其它出错
*/
int SPI_Open(void)
{
int fd;
int ret = 0;


if (g_SPI_Fd != 0) /* 设备已打开 */
return 0xF1;


fd = open(device, O_RDWR);
if (fd < 0)
pabort("can't open device");
else
pr_debug("SPI - Open Succeed. Start Init SPI...\n");


g_SPI_Fd = fd;
/*
* spi mode
*/
ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
if (ret == -1)
pabort("can't set spi mode");


ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
if (ret == -1)
pabort("can't get spi mode");


/*
* bits per word
*/
ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
if (ret == -1)
pabort("can't set bits per word");


ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
if (ret == -1)
pabort("can't get bits per word");


/*
* max speed hz
*/
ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
if (ret == -1)
pabort("can't set max speed hz");


ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
if (ret == -1)
pabort("can't get max speed hz");


pr_debug("spi mode: %d\n", mode);
pr_debug("bits per word: %d\n", bits);
pr_debug("max speed: %d KHz (%d MHz)\n", speed / 1000, speed / 1000 / 1000);


return ret;
}


/**
* 功 能：关闭SPI模块
*/
int SPI_Close(void)
{
int fd = g_SPI_Fd;


if (fd == 0) /* SPI是否已经打开*/
return 0;
close(fd);
g_SPI_Fd = 0;


return 0;
}


/**
* 功 能：自发自收测试程序
* 接收到的数据与发送的数据如果不一样 ，则失败
* 说明：
* 在硬件上需要把输入与输出引脚短跑
*/
int SPI_LookBackTest(void)
{
int ret, i;
const int BufSize = 16;
uint8_t tx[BufSize], rx[BufSize];


bzero(rx, sizeof(rx));
for (i = 0; i < BufSize; i++)
tx[i] = i;


pr_debug("SPI - LookBack Mode Test...\n");
ret = SPI_Transfer(tx, rx, BufSize);
if (ret > 1)
{
ret = memcmp(tx, rx, BufSize);
if (ret != 0)
{
pr_err("LookBack Mode Test error\n");
//pabort("error");
}
else
pr_debug("SPI - LookBack Mode OK\n");
}

return ret;
}

int DoAT(){
    int ret,i;
    const int RetBufSz=258;
    uint8_t tx1[]="AT+CGLA=\"0,14,00010000020800\"";
    //uint8_t tx2[]="0,12,00020000010A";
    int bufsz1=sizeof(tx1)/sizeof(uint8_t);
    //int bufsz2=sizeof(tx2)/sizeof(uint8_t);
    uint8_t rx1[RetBufSz];
    //uint8_t rx2[RetBufSz]
    SPI_Write(tx1,bufsz1);
    SPI_Read(rx1,RetBufSz);
    return 0;
}

// 片选初始化
// ret 0: ok, -1: err
int initSelect(){
    uint8_t sendbuffer[256];
    uint8_t recvbuffer[256];
    // 1. 复位
    bzero(sendbuffer,256);
    bzero(recvbuffer,256);
    sendbuffer[0]=0x1f;
    SPI_Write(sendbuffer,3);   //send 1f0000
    SPI_Read(recvbuffer,1);
    if(recvbuffer[0]!=0x1f){
        return -1;
    }
    bzero(sendbuffer,256);
    bzero(recvbuffer,256);
    sendbuffer[0]=0x2f;
    SPI_Write(sendbuffer,3);   //send 2f0000
    SPI_Read(recvbuffer,3);
#if SPI_DEBUG
    for(int i=0;i<3;i++){
        pr_debug("%02x\t",recvbuffer[i]);
    }
    pr_debug("\n");
#endif
    bzero(sendbuffer,256);
    bzero(recvbuffer,256);
    sendbuffer[0]=0x01;
    SPI_Write(sendbuffer,1);   //send 01
    SPI_Read(recvbuffer,16);
#if SPI_DEBUG
    for(int i=0;i<16;i++){
        pr_debug("%02x\t",recvbuffer[i]);
    }
    pr_debug("\n");
#endif
    bzero(sendbuffer,256);
    bzero(recvbuffer,256);
    sendbuffer[0]=0x01;
    SPI_Write(sendbuffer,1);   //send 01
    SPI_Read(recvbuffer,6);
#if SPI_DEBUG
    for(int i=0;i<6;i++){
        pr_debug("%02x\t",recvbuffer[i]);
    }
    pr_debug("\n");
#endif

    // 2. APDU 的发送与返回
    // send APDU
    bzero(sendbuffer,256);
    bzero(recvbuffer,256);
    sendbuffer[0]=0x00;
    sendbuffer[0]=0x00;
    sendbuffer[0]=0x0C;
    SPI_Write(sendbuffer,3);   //send 00000C
    SPI_Read(recvbuffer,1);
#if SPI_DEBUG
    for(int i=0;i<1;i++){
        pr_debug("%02x\t",recvbuffer[i]);
    }//should be 0x00
    pr_debug("\n");
#endif
    bzero(sendbuffer,256);
    bzero(recvbuffer,256);
    sendbuffer[0]=0x00;
    sendbuffer[1]=0xA4;
    sendbuffer[2]=0x04;
    sendbuffer[3]=0x00;
    sendbuffer[4]=0x07;
    sendbuffer[5]=0xA0;
    sendbuffer[6]=0x00;
    sendbuffer[7]=0x00;
    sendbuffer[8]=0x00;
    sendbuffer[9]=0x03;
    sendbuffer[10]=0x00;
    sendbuffer[11]=0x00;
    SPI_Write(sendbuffer,12);   //send APDU
    SPI_Read(recvbuffer,1);
#if SPI_DEBUG
    for(int i=0;i<1;i++){
        pr_debug("%02x\t",recvbuffer[i]);
    }
    pr_debug("\n");
    // should be 0x01
#endif
    // recv APDU
    bzero(sendbuffer,256);
    bzero(recvbuffer,256);
    sendbuffer[0]=0x2f;
    sendbuffer[1]=0x00;
    sendbuffer[2]=0x00;
    SPI_Write(sendbuffer,3);   //send 2f0000
    SPI_Read(recvbuffer,3);
#if SPI_DEBUG
    for(int i=0;i<3;i++){
        pr_debug("%02x\t",recvbuffer[i]);
    }
    pr_debug("\n");
#endif
    bzero(sendbuffer,256);
    bzero(recvbuffer,256);
    sendbuffer[0]=0x01;
    SPI_Write(sendbuffer,1);   //send 01
    SPI_Read(recvbuffer,16);
#if SPI_DEBUG
    for(int i=0;i<16;i++){
        pr_debug("%02x\t",recvbuffer[i]);
    }
    pr_debug("\n");
#endif
    SPI_Write(sendbuffer,1);   //send 01
    SPI_Read(recvbuffer,1);
#if SPI_DEBUG
    for(int i=0;i<1;i++){
        pr_debug("%02x\t",recvbuffer[i]);
    }
    pr_debug("\n");
#endif

    return 0;
}

int main(){
    printf("%d:   spi_open return \n",SPI_Open());
    //printf("%d:   LookBackTest return \n",SPI_LookBackTest());
    DoAT();
    printf("%d:   spi_close return \n",SPI_Close());
    return 0;
}
