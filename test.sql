show databases;--查看当前有哪些数据库

create database MyDB;--创建库名为 MyDB 的数据库

use MyDB;--使用MyDB数据库

--创建student表
create table student
(son int primary key auto_increment,sname varchar(5),
ssex char(5) not null default 'woman' check (ssex in('woman','man')),
sage int default 18,
classId int,constraint hxl 
check(sage>=16 and sage<=28));

desc student;--看student表结构
select * from student;--查看student表中数据

-- 创建course表
create table course(cno int primary key not null,
cname varchar(10) not null,
credit int,
constraint wyf check(credit>=1 and credit<=5)
);

desc course;--查看course表结构


--创建class表
create table class(classId int primary key not null,
className varchar(10),
unique(className));

desc class;--查看class表结构


-- 创建score表
create table score(son int not null,
cno int not null,、
degree int,
constraint wyf check(degree>=0 and degree<=100)
);

desc score;--查看表结构
