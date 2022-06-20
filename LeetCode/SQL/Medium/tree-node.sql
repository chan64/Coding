-- Prepare data
Create table If Not Exists Tree (id int, p_id int);
Truncate table Tree;
insert into Tree (id, p_id) values ('1', null);
insert into Tree (id, p_id) values ('2', '1');
insert into Tree (id, p_id) values ('3', '1');
insert into Tree (id, p_id) values ('4', '2');
insert into Tree (id, p_id) values ('5', '2');

-- to report the type of each node in the tree
-- Solution
select id, case 
WHEN p_id is null THEN 'Root'
when (select count(id) from Tree t1 where t1.p_id=t.id)=0 THEN 'Leaf'
when (select count(p_id) from Tree t1 where t.p_id=t1.p_id)>0 THEN 'Inner' 
end as Type
from Tree t
order by id asc;

-- Solution 1
select distinct t1.id, (
    case 
    when t1.p_id is null then 'Root'
    when t1.p_id is not null and t2.id is not null then 'Inner'
    when t1.p_id is not null and t2.id is null then 'Leaf'
    END  
) as Type
 from Tree t1 left join Tree t2 on t1.id = t2.p_id
 order by t1.id asc;