DROP database IF EXISTS `scott`;
CREATE database IF NOT EXISTS `scott` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;

USE `scott`;

DROP TABLE IF EXISTS `dept`;
CREATE TABLE `dept` (
  `deptno` int(2) unsigned zerofill NOT NULL COMMENT '部门编号',
  `dname` varchar(14) DEFAULT NULL COMMENT '部门名称',
  `loc` varchar(13) DEFAULT NULL COMMENT '部门所在地点'
);


DROP TABLE IF EXISTS `emp`;
CREATE TABLE `emp` (
  `empno` int(6) unsigned zerofill NOT NULL COMMENT '雇员编号',
  `ename` varchar(10) DEFAULT NULL COMMENT '雇员姓名',
  `job` varchar(9) DEFAULT NULL COMMENT '雇员职位',
  `mgr` int(4) unsigned zerofill DEFAULT NULL COMMENT '雇员领导编号',
  `hiredate` datetime DEFAULT NULL COMMENT '雇佣时间',
  `sal` decimal(7,2) DEFAULT NULL COMMENT '工资月薪',
  `comm` decimal(7,2) DEFAULT NULL COMMENT '奖金',
  `deptno` int(2) unsigned zerofill DEFAULT NULL COMMENT '部门编号'
);


DROP TABLE IF EXISTS `salgrade`;
CREATE TABLE `salgrade` (
  `grade` int(11) DEFAULT NULL COMMENT '等级',
  `losal` int(11) DEFAULT NULL COMMENT '此等级最低工资',
  `hisal` int(11) DEFAULT NULL COMMENT '此等级最高工资'
);


insert into dept (deptno, dname, loc)
values (10, 'ACCOUNTING', 'NEW YORK');
insert into dept (deptno, dname, loc)
values (20, 'RESEARCH', 'DALLAS');
insert into dept (deptno, dname, loc)
values (30, 'SALES', 'CHICAGO');
insert into dept (deptno, dname, loc)
values (40, 'OPERATIONS', 'BOSTON');

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7369, 'SMITH', 'CLERK', 7902, '1980-12-17', 800, null, 20);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7499, 'ALLEN', 'SALESMAN', 7698, '1981-02-20', 1600, 300, 30);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7521, 'WARD', 'SALESMAN', 7698, '1981-02-22', 1250, 500, 30);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7566, 'JONES', 'MANAGER', 7839, '1981-04-02', 2975, null, 20);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7654, 'MARTIN', 'SALESMAN', 7698, '1981-09-28', 1250, 1400, 30);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7698, 'BLAKE', 'MANAGER', 7839, '1981-05-01', 2850, null, 30);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7782, 'CLARK', 'MANAGER', 7839, '1981-06-09', 2450, null, 10);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7788, 'SCOTT', 'ANALYST', 7566, '1987-04-19', 3000, null, 20);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7839, 'KING', 'PRESIDENT', null, '1981-11-17', 5000, null, 10);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7844, 'TURNER', 'SALESMAN', 7698,'1981-09-08', 1500, 0, 30);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7876, 'ADAMS', 'CLERK', 7788, '1987-05-23', 1100, null, 20);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7900, 'JAMES', 'CLERK', 7698, '1981-12-03', 950, null, 30);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7902, 'FORD', 'ANALYST', 7566, '1981-12-03', 3000, null, 20);

insert into emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (7934, 'MILLER', 'CLERK', 7782, '1982-01-23', 1300, null, 10);

insert into salgrade (grade, losal, hisal) values (1, 700, 1200);
insert into salgrade (grade, losal, hisal) values (2, 1201, 1400);
insert into salgrade (grade, losal, hisal) values (3, 1401, 2000);
insert into salgrade (grade, losal, hisal) values (4, 2001, 3000);
insert into salgrade (grade, losal, hisal) values (5, 3001, 9999);
