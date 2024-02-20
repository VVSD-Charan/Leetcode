# Write your MySQL query statement below
SELECT p.project_id , IFNULL(ROUND(sum(e.experience_years)/count(p.project_id),2),0) AS average_years
FROM Project p LEFT JOIN Employee e ON p.employee_id = e.employee_id WHERE e.experience_years IS NOT NULL
GROUP BY p.project_id