# Write your MySQL query statement below
select eu.unique_id as unique_id, e.name as name FROM Employees AS e LEFT JOIN EmployeeUNI AS eu ON
e.id = eu.id;