# nginx 简单http模块编写与调用模块
根据书上的介绍，首先要编写一个config文件，来定义模块名称、代码文件名称信息。configure脚本执行的过程中和config文件配合起来把定制的第三方模块加入Nginx。

config

    ngx_addon_name=ngx_http_mytest_module
    HTTP_MODULES="$HTTP_MODULES ngx_http_mytest_module"
    NGX_ADDON_SRCS="$NGX_ADDON_SRCS $ngx_addon_dir/ngx_http_mytest_module.c"
在写完config文件之后，接下来对nginx代码文件夹中的 nginx.conf 文件进行修改，以添加mytest配置项。
在http配置块下的server配置块下添加location配置块，并且在该location配置块下添加mytest配置项。
```
	location =/test{
    	mytest;
    }
```
接着，把config文件中添加的模块文件写完，就可以开始命令行配置和编译了。

在configure时添加自定义模块的路径：
> ./configure --add-module=/mymodules/mytest

其中，路径 /mydules/mytest 对应了config文件中的ngx_addon_dir变量。现在configure程序便知道了我们定义的模块的绝对路径。
then make and make install.