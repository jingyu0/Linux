drop database if exists `bit_index`;
create database if not exists `bit_index` default character set utf8;
use `bit_index`;

-- 构建一个8000000条记录的数据
-- 构建的海量表数据需要有差异性，所以使用存储过程来创建， 拷贝下面代码就可以了，暂时不用理解

-- 产生随机字符串
delimiter $$
create function rand_string(n INT)
returns varchar(255)
begin
declare chars_str varchar(100) default
'abcdefghijklmnopqrstuvwxyzABCDEFJHIJKLMNOPQRSTUVWXYZ';
declare return_str varchar(255) default '';
declare i int default 0;
while i < n do
set return_str =concat(return_str,substring(chars_str,floor(1+rand()*52),1));
set i = i + 1;
end while;
return return_str;
end $$
delimiter ;


-- 产生随机数字
delimiter $$
create function rand_num( )
returns int(5)
begin
declare i int default 0;
set i = floor(10+rand()*500);
return i;
end $$
delimiter ;

-- 创建存储过程，向雇员表添加海量数据
delimiter $$
create procedure insert_emp(in start int(10),in max_num int(10))
begin
declare i int default 0;
set autocommit = 0;
repeat
set i = i + 1;
insert into EMP values ((start+i)
,rand_string(6),'SALESMAN',0001,curdate(),2000,400,rand_num());
until i = max_num
end repeat;
commit;
end $$
delimiter ;

-- 雇员表
CREATE TABLE `EMP` (
  `empno` int(6) unsigned zerofill NOT NULL COMMENT '雇员编号',
  `ename` varchar(10) DEFAULT NULL COMMENT '雇员姓名',
  `job` varchar(9) DEFAULT NULL COMMENT '雇员职位',
  `mgr` int(4) unsigned zerofill DEFAULT NULL COMMENT '雇员领导编号',
  `hiredate` datetime DEFAULT NULL COMMENT '雇佣时间',
  `sal` decimal(7,2) DEFAULT NULL COMMENT '工资月薪',
  `comm` decimal(7,2) DEFAULT NULL COMMENT '奖金',
  `deptno` int(2) unsigned zerofill DEFAULT NULL COMMENT '部门编号'
);


-- 执行存储过程，添加8000000条记录
call insert_emp(100001, 8000000);














