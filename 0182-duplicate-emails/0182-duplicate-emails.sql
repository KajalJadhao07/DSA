# Write your MySQL query statement below
-- select email
-- from Person
-- where email in (
--     select email 
--     from Person
--     group by email
--     having count(email) > 1
-- );

select email 
from Person
group by email
having count(email) > 1;