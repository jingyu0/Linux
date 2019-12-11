-- 创建数据库
drop database if exists bit_bao;
create database if not exists bit_bao default character set utf8 collate utf8_general_ci;

-- 使用数据库
use bit_bao;

-- 创建goods表
drop table if exists goods;
create table if not exists goods(
	goods_id int unsigned primary key auto_increment comment '商品编号',
	goods_name varchar(100) not null default '' comment '商品名称',
	unitprice decimal(10,2) not null default 0.0 comment '单价',
	category smallint not null default 0 comment '商品类别',
	provider varchar(100) not null default '' comment '供应商'
);

-- 创建customer
drop table if exists customer;
create table if not exists customer (
    customer_id int UNSIGNED primary key AUTO_INCREMENT comment '客户编号',
    name varchar(50) not null default '' comment '姓名',
    address varchar(100) not null default '' comment '地址',
    email varchar(60) not null unique comment '邮箱',
    sex enum('男', '女') not null default '男' comment '性别',
    card_id varchar(20) not null unique comment '身份证'
);

-- 创建purchase
drop table if exists purchase;
create table if not exists purchase (
    order_id varchar(30) not null primary key comment '购买订单编号',
    customer_id int UNSIGNED comment '客户编号',
    goods_id int UNSIGNED  comment '产品编号',
    nums int not null default 0 comment '购买数量',
    foreign key (customer_id) references customer (customer_id),
    foreign key (goods_id)    references goods (goods_id)
);


