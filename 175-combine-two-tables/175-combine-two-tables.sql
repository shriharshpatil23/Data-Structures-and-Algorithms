# Write your MySQL query statement below
select Person.firstName , Person.lastName , Address.city , Address.state 
from Person left outer join Address 
ON Person.personId = Address.personId