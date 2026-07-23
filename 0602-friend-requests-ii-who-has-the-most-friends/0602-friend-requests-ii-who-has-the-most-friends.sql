# Write your MySQL query statement below
with friends as (
    select requester_id as id
    from RequestAccepted

    union all

    select accepter_id as id
    from RequestAccepted
),
friend_count as (
    select id, count(*) as num
    from friends
    group by id
)

select id , num 
from friend_count
order by num desc
limit 1;