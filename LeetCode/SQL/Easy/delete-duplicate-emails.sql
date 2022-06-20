-- Prepare data
Create table If Not Exists Person (Id int, Email varchar(255));
Truncate table Person;
insert into Person (id, email) values ('1', 'john@example.com');
insert into Person (id, email) values ('2', 'bob@example.com');
insert into Person (id, email) values ('3', 'john@example.com');

-- Write an SQL query to delete all the duplicate emails, keeping only one unique email with the smallest id. Note that you are supposed to write a DELETE statement and not a SELECT one.
-- Solution 
with person_set as
    (select id,
            email,
            rank() over (partition by email
                         order by id asc) as email_rank
     from Person)
delete
from person_set
where email_rank > 1;

-- Solution 1
delete from Person where id not in( 
    select t.id from (
        select min(id) as id from Person group by email
    ) t
)