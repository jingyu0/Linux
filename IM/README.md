IM
===========================

###########环境依赖
CentOS(64 位)、C/C++、vim、g++、make/makefile
###########软件简介
1. 使用开源websocket框架mongoose编写网页版本的群聊即时通信工具 

2. 使用http+mongoose+session+mysql+jsoncpp的技术构成，完成IM工具 
***
###########部署步骤

1. 安装websocket框架mongoose 
####### mkdir IM 
####### cd IM 
####### mkdir IM

2. 接入mongoose框架头文件
####### cp 你下载的mongoose SDK路径/mongoose . -rf 

3. 后期接入mysql要使用
####### mkdir mysql_lib 

4. 构建IM项目框架
####### ls IM  mongoose  mysql_lib


###########目录结构描述

###### IM
├── Readme.md                   // help
├── build.sh 
├── IM_Server.hpp               //核心代码
├── main.cc                     //调用
├── Makefile                    //配置环境变量
├── Util.hpp                    //工具类
└── web                         //前端模板下载
 

###########C++编写mongoose基本框架
* 首先，设计基本框架
* 然后，先完成基本的聊天逻辑
* 在能够让我们访问数据库，访问我们之前所建立的表
* 最后，完成登录逻辑，这里还要涉及到对cookie和session的理解，我们在代码中体现



