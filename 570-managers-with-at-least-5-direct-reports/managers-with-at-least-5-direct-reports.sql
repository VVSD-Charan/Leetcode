# Write your MySQL query statement below

SELECT e.name
FROM Employee e INNER JOIN Employee m on e.id = m.managerId
GROUP BY e.id  HAVING COUNT(e.id) >= 5;