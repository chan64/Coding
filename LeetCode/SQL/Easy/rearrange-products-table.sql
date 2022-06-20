-- Prepare data
Create table If Not Exists Products_1 (product_id int, store1 int, store2 int, store3 int);
Truncate table Products_1;
insert into Products_1 (product_id, store1, store2, store3) values ('0', '95', '100', '105');
insert into Products_1 (product_id, store1, store2, store3) values ('1', '70', NULL, '80');

-- to rearrange the Products table so that each row has (product_id, store, price)
select * from (select product_id, 'store1' as store, (select store1 from Products_1 p where p.store1=p1.store1 and p.store1 is not null) price from Products_1 p1
union 
select product_id, 'store2' as store, (select store2 from Products_1 p where p.store2=p1.store2 and p.store2 is not null) price from Products_1 p1
union 
select product_id, 'store3' as store, (select store3 from Products_1 p where p.store3=p1.store3 and p.store3 is not null) price from Products_1 p1) Products
where Products.price is not null 
order by Products.product_id asc;

-- Solution
SELECT product_id, 'store1' AS store, store1 AS price FROM Products_1 WHERE store1 IS NOT NULL
UNION 
SELECT product_id, 'store2' AS store, store2 AS price FROM Products_1 WHERE store2 IS NOT NULL
UNION 
SELECT product_id, 'store3' AS store, store3 AS price FROM Products_1 WHERE store3 IS NOT NULL
ORDER BY 1,2 ASC;

select product_id, store, price 
from Products_1
UNPIVOT
(
    price
	FOR store in (store1,store2,store3)
)
as t;
