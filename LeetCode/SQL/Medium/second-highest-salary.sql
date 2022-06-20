-- Prepare data
Create table If Not Exists Employee (id int, salary int);
Truncate table Employee;
insert into Employee (id, salary) values ('1', '100');
insert into Employee (id, salary) values ('2', '200');
insert into Employee (id, salary) values ('3', '300');

-- to report the second highest salary from the Employee table
select if(salary, salary, null) as SecondHighestSalary
from
    ( select id,
             salary,
             rank() over (
                          order by salary desc) as 'sal_rank'
     from Employee 
    ) emp_sal
where emp_sal.sal_rank = 2;

-- Solution 
select max(salary) as SecondHighestSalary from Employee where salary< (select max(salary) from Employee);