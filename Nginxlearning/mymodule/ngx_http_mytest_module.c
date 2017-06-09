//Nginx hello world module written by C
//不希望模块对所有的HTTP请求起作用。
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>
static ngx_int_t ngx_http_mytest_handler(ngx_http_request_t *r);
static char *ngx_http_mytest(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
static ngx_command_t ngx_http_mytest_commands[]={
    {
        ngx_string("mytest"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_LOC_CONF|NGX_HTTP_LMT_CONF|NGX_CONF_NOARGS,
        ngx_http_mytest,
        NGX_HTTP_LOC_CONF_OFFSET,
        0,
        NULL
    },
    ngx_null_command
};


static char* ngx_http_mytest(ngx_conf_t *cf,ngx_command_t *cmd, void *conf){
    ngx_http_core_loc_conf_t *clcf;//找到mytest所属配置块
    clcf=ngx_http_conf_get_module_loc_conf(cf,ngx_http_core_module);
    //主机域名、URI与mytest所在配置快匹配时，将调用handler
    clcf->handler=ngx_http_mytest_handler;
    return NGX_CONF_OK;
}
static ngx_http_module_t ngx_http_mytest_module_ctx={
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

ngx_module_t ngx_http_mytest_module={
    NGX_MODULE_V1,
    &ngx_http_mytest_module_ctx,
    ngx_http_mytest_commands,
    NGX_HTTP_MODULE,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NGX_MODULE_V1_PADDING
};

static  ngx_int_t ngx_http_mytest_handler(ngx_http_request_t *r){
    //ez hello world test
    //必须是GET或者HEAD方法，否则返回405 Not Allowed
    if(!(r->method&(NGX_HTTP_GET|NGX_HTTP_HEAD))){
        return NGX_HTTP_NOT_ALLOWED;
    }
    //丢弃请求中的body
    ngx_int_t rc=ngx_http_discard_request_body(r);
    if(rc!=NGX_OK){
        return rc;
    }
    //设置返回的Content-Type, ngx_str_t 有一个很方便的初始化宏ngx_string，它可以把ngx_str_t 的data和len成员都设置好
    ngx_str_t type = ngx_string("text/plain");
    //返回的body内容
    ngx_str_t response = ngx_string("Hello World!");
    //设置返回状态码
    r->headers_out.status=NGX_HTTP_OK;
    //响应包是有body内容的，需要设置Content-Length长度
    r->headers_out.content_length_n=response.len;
    //设置Content-Type
    r->headers_out.content_type=type;

    //发送HTTP头部
    rc = ngx_http_send_header(r);
    if(rc==NGX_ERROR||rc>NGX_OK||r->header_only){
        return rc;
    }
	/*
    //构造ngx_buf_t 结构体准备发送body
    ngx_buf_t *b;
    b=ngx_create_temp_buf(r->pool,response.len);
    if(b==NULL){
        return NGX_HTTP_INTERNAL_SERVER_ERROR;
    }
	*/
    
    //如果要发送的是linux上的磁盘文件，则ngx_buf_t 的代码应该为
    ngx_buf_t *b;
    b=ngx_palloc(r->pool,sizeof(ngx_buf_t));

    u_char* filename = (u_char*)"~/Desktop/test/data";
    b->in_file=1;
    b->file=ngx_pcalloc(r->pool,sizeof(ngx_file_t));
    b->file->fd=ngx_open_file(filename,NGX_FILE_RDONLY|NGX_FILE_NONBLOCK,NGX_FILE_OPEN,0);
    //#define ngx_open_file(name,mode,create,access) open((const char *)name,mode|create,access)
    b->file->log=r->connection->log;
    b->file->name.data=filename;
    b->file->name.len=sizeof(filename)-1;
    if(b->file->fd<=0){
        return NGX_HTTP_NOT_FOUND;
    }
    if(ngx_file_info(filename,&b->file->info)==NGX_FILE_ERROR){
        return NGX_HTTP_INTERNAL_SERVER_ERROR;
    }
    r->headers_out.content_length_n = b->file->info.st.size;
    b->file_pos=0;
    b->file_last=b->file->info.st_size;
    /*
    //将hello world复制到ngx_buf_t指向的内存中
    ngx_memcpy(b->pos,response.data,response.len);
    //注意，一定要设置好last指针
    b->last=b->pos+response.len;
    //声明这是最后一块缓冲区
    b->last_buf=1;
	*/
    //构造发送时的ngx_chain_t结构体
    ngx_chain_t out;
    out.buf = b;
    out.next = NULL;
    
    //最后一步为发送body，发送结束后HTTP框架会调用 ngx_http_finalize_request 方法结束请求
    return ngx_http_output_filter(r,&out);
}
