# Write your MySQL query statement below
select p.firstName , p.lastName , a.city , a.state from
person p left join address a ON
p.personId = a.personId