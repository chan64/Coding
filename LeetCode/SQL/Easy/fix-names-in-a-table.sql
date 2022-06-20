-- Prepare data
Create table If Not Exists Users (user_id int, name varchar(40));
Truncate table Users;
insert into Users (user_id, name) values ('1', 'aLice');
insert into Users (user_id, name) values ('2', 'bOB');

-- fix the names so that only the first character is uppercase and the rest are lowercase.
update Users set name = CONCAT(UPPER(SUBSTRING(name,1,1)),LOWER(SUBSTRING(name,2)));

-- Solution
Select user_id, CONCAT(UPPER(SUBSTRING(name,1,1)),LOWER(SUBSTRING(name,2))) as name from Users order by user_id;
