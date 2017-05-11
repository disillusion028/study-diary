使用源代码编译安装了pcre库、zlib库，完成了nginx 1.13.0版本的代码编译安装，还不明白如何运行，出现
nginx: [emerg] bind() to 0.0.0.0:80 failed (98: Address already in use)

另，了解了configure脚本检查某特性是否存在的方法：**configure脚本生成一个最简单的只包含main函数的C程序，该程序会包含相应的头文件。然后，通过检查是否可以编译通过来确认特性是否支持.**

学到了一个linux命令 
od <filename>    查看二进制文件
-tx1 选项表示将文件中的字节以十六进制的形式列出来，每组一个字节
-tc 选项表示将文件中的ASCII码以字符形式列出来
-Ax 选项要求以十六进制显示文件中的地址
还有个有相似功能的hexdump
这个东西太好用了，写程序的时候要注意/r/n 和/n的误扰。

学习了一下SSL/TLS协议运行的机制，感觉和《汽车信息系统密钥体系设计建议》里的SE TBOX Platform KMS这一套双向认证很像。
+ Figure 1.  Message flow for a full handshake:

      Client                                               Server

      ClientHello                  -------->
                                                      ServerHello
                                                     Certificate*
                                               ServerKeyExchange*
                                              CertificateRequest*
                                   <--------      ServerHelloDone
      Certificate*
      ClientKeyExchange
      CertificateVerify*
      [ChangeCipherSpec]
      Finished                     -------->
                                               [ChangeCipherSpec]
                                   <--------             Finished
      Application Data             <------->     Application Data
  
 
  <1>. client 发出请求， 请求主要包含以下信息：（clientHello）
 + 支持的协议版本，如 TLS1.0
 + 一个客户端生成的随机数
 + 支持的加密方法
 + 支持的压缩方法.

<2>. 服务器回应（ClientHello）
 + 确认使用的加密通信协议版本。（如果版本不一致则关闭加密通信）
 + 一个服务器生成的随机数
 + 确认使用的加密方法
 + ** 服务器证书 **
 + （如果服务器需要确认客户端身份，就会包含一项请求，要求客户端提供客户端证书).
 
<3>. 客户端回应
 + 验证证书（如果证书有问题就向访问者显示警告，由访问者选择是否继续通信）
 + 客户端从证书中取出公钥，向服务器发送下面三项信息
 （1）一个由服务器公钥加密的随机数
 （2）编码改变通知，表示随后的信息都用双方商定的加密方法和密钥发送。
 （3）客户端握手结束通知，表示客户端的握手阶段结束，这一段是前面发送所有内容的hash值，用来供服务器校验。
 （4）如果前一步服务器要求客户端证书，客户端会在这一步发送证书和相关信息。
 
<4>.服务器最后回应
 + 服务器收到客户端的第三个随机数之后，计算生成本次会话所用的"会话密钥"。然后向客户端最后发送下面的信息：
 （1）编码改变通知（同上）
 （2）服务器握手结束通知，表示服务器的握手阶段已经结束，这一项是前面发送的所有内容的hash值，以供客户端校验。