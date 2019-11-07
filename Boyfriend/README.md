智能语音对话AI 
===========================
插入链接
[技术博客](https://blog.csdn.net/qq_41906009/article/details/97384752)

环境依赖
* CentOS(64 位)、C/C++、vim、g++、make/makefile

软件简介
1. 使用C++编写一个智能AI对话和语音命令执行的语音管理工具 

2. 其中可执行命令支持配置 

***
项目演示

1. 程序启动之后，加载命令配置文件，启动本地录音工具，开始录音 

2. 程序准备识别, 将特定格式的录音推送到百度语音识别平台进行识别，返回识别完毕之后的文字信息

3. 对比识别之后的输入文本，辨别是命令还是普通对话信息 

4. 如果是命令，进入系统命令执行模块，执行完毕，看到执行结果，一次交互完成 

5. 如果是对话信息，推送给图灵机器人，图灵机器人会智能相应对话，得到图灵机器人响应的文本，调用百度语音合成，在本地合成语音，然后程序启动播放器，播放语音信息，完成对话信息 
支持语言退出  

准备部署工作
1. 注册图灵机器人

2. 使用百度语音识别

3. 准备需要的第三方库和sdk <font color=#FF0000 size=4>(因后续开发需要，需要先安装高版本cmake，gcc)</font>

   * <font color=#FFFF00 size=4> # scl enable devtoolset-7 bash</font>

 a. 下载百度C++语音识别SDK 
 
 b. 安装jsoncpp，要求：>1.6.2版本，0.x版本将不被支持

 c. 安装openssl (openssl轻易不要卸载)

 d. 安装libcurl（需要支持https）
 * 下载curl-7.64.1.tar.gz版本
 
4. 准备Centos 7录音和播放工具 
 * 使用arecord进行录音 
 
 * ``` # arecord -t wav -c 1 -r 16000 -d 5 -f S16_LE demo.wav ```
 * 安装第三方工具vlc/cvlc实现MP3文件播放

<br>
目录结构描述

##### 智能语音对话AI

├── Readme.md                 // help
<br>
├── build.sh                       //构建项目的shell脚本，简单实现
<br>
├── command.etc              //语音命令配置文件 
<br>
├── Boyfriend.cc                //AI 源文件调用
<br>
├──Boyfriend.hpp 　　　　//AI 核心代码 
<br>
├── Makefile                    //配置环境变量
<br>
├── speech                    　//百度语音识别SDK 
<br>
└── temp_file                    //保存临时语音文件目录
 
<br>
难点说明

* 使用jsoncpp  序列化与反序列化
插入链接：
[jsoncpp举例](https://github.com/jingyu0/Linux_project/tree/master/Boyfriend/test)





