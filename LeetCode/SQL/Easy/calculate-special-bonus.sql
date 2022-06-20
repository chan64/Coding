-- Prepare data
Create table If Not Exists Employees (employee_id int, name varchar(30), salary int);
Truncate table Employees;
insert into Employees (employee_id, name, salary) values ('2', 'Meir', '3000');
insert into Employees (employee_id, name, salary) values ('3', 'Michael', '3800');
insert into Employees (employee_id, name, salary) values ('7', 'Addilyn', '7400');
insert into Employees (employee_id, name, salary) values ('8', 'Juan', '6100');
insert into Employees (employee_id, name, salary) values ('9', 'Kannon', '7700');

-- SQL query to calculate the bonus of each employee. The bonus of an employee is 100% of their salary if the ID of the employee is an odd number and the employee name does not start with the character 'M'. The bonus of an employee is 0 otherwise.
select employee_id, 
case 
    when (employee_id%2)<>0 and substring(name,1,1)<>'M' then salary 
    else 0
end as bonus
from Employees;

-- Solution 2
select employee_id,if((employee_id%2)<>0 and substring(name,1,1)<>'M',salary,0) as bonus
from Employees;