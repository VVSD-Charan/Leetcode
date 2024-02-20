# Write your MySQL query statement below

SELECT e.name,b.bonus
FROM Employee e LEFT JOIN Bonus as b ON e.empId = b.empId
WHERE b.bonus is NULL OR b.bonus < 1000; 