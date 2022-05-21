-- Prepare data
Create table If Not Exists Customers (id int, name varchar(255));
Create table If Not Exists Orders (id int, customerId int);
Truncate table Customers;
insert into Customers (id, name) values ('1', 'Joe');
insert into Customers (id, name) values ('2', 'Henry');
insert into Customers (id, name) values ('3', 'Sam');
insert into Customers (id, name) values ('4', 'Max');
Truncate table Orders;
insert into Orders (id, customerId) values ('1', '3');
insert into Orders (id, customerId) values ('2', '1');

-- Report all customers who never order anything
-- Solution 1
select name as Customers from Customers where id not in (select customerid from Orders);

-- Solution 2
select name as Customers from Customers left join Orders on Customers.id = Orders.customerid where Orders.customerid is NULL;

-- Solution 3
select name as Customers from Customers c where not exists(select 1 from Orders o where c.id = o.customerid)