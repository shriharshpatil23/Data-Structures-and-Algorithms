# Write your MySQL query statement below
select a.id from Weather a,Weather b where a.temperature>b.temperature and a.recordDate=(b.recordDate + INTERVAL 1 DAY)