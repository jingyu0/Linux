-- 创建数据库
drop database if exists bit_student;
create database if not exists bit_student default character set utf8 collate utf8_general_ci;

-- 使用数据库
use bit_student;

-- 创建数据库表
drop table if exists student;
create table student (
	id int not null primary key auto_increment comment '编号',
	name varchar(20) not null default '' comment '姓名',
	chinese float(3,1) not null default 0.0 comment '语文成绩',
	english float(3,1) not null default 0.0 comment '英语成绩',
	math float(3,1) not null default 0.0 comment '数学成绩'
);

-- 插入数据
insert into student (name, chinese, english, math) values('李涛', 89,78, 90);
insert into student (name, chinese, english, math) values('唐僧', 67,98, 56);
insert into student (name, chinese, english, math) values('孙悟空', 87,78, 77);
insert into student (name, chinese, english, math) values('老妖婆', 88,98, 90);
insert into student (name, chinese, english, math) values('红孩儿', 82,84, 67);
insert into student (name, chinese, english, math) values('如来佛祖', 55,85, 45);
insert into student (name, chinese, english, math) values('菩萨', 75,65, 30);

-- 查询全部数据
select id ,name , chinese, english, math from student;