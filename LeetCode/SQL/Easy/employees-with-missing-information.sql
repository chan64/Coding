-- Prepare data
Create table If Not Exists Employees_1 (employee_id int, name varchar(30));
Create table If Not Exists Salaries (employee_id int, salary int);
Truncate table Employees_1;
insert into Employees_1 (employee_id, name) values ('2', 'Crew');
insert into Employees_1 (employee_id, name) values ('4', 'Haven');
insert into Employees_1 (employee_id, name) values ('5', 'Kristian');
Truncate table Salaries;
insert into Salaries (employee_id, salary) values ('5', '76071');
insert into Salaries (employee_id, salary) values ('1', '22517');
insert into Salaries (employee_id, salary) values ('4', '63539');

-- to report the IDs of all the employees with missing information
select result.employee_id from (select employee_id from Salaries where employee_id not in (select employee_id from Employees_1)
UNION
select employee_id from Employees_1 where employee_id not in (select employee_id from Salaries)) result
order by result.employee_id ASC;

select employee_id from Salaries where employee_id not in (select employee_id from Employees_1)
UNION
select employee_id from Employees_1 where employee_id not in (select employee_id from Salaries)
order by 1 ASC;