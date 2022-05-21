create database leetcode;
show databases;

-- Prepare data
Create table If Not Exists Products (product_id int, low_fats ENUM('Y', 'N'), recyclable ENUM('Y','N'));
Truncate table Products;
insert into Products (product_id, low_fats, recyclable) values ('0', 'Y', 'N');
insert into Products (product_id, low_fats, recyclable) values ('1', 'Y', 'Y');
insert into Products (product_id, low_fats, recyclable) values ('2', 'N', 'Y');
insert into Products (product_id, low_fats, recyclable) values ('3', 'Y', 'Y');
insert into Products (product_id, low_fats, recyclable) values ('4', 'N', 'N');

-- Solution
select product_id from Products where low_fats='Y' and recyclable='Y';

-- Percentage of products that are either low_fats or recyclable
SELECT ROUND(AVG(CASE WHEN low_fats = 'Y' OR recyclable = 'Y' THEN 1 ELSE 0 END),2) AS PERCENTAGE from Products;