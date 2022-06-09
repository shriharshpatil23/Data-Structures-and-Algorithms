SELECT Name as Customers from Customers
WHERE Id NOT IN (SELECT CustomerId from Orders);