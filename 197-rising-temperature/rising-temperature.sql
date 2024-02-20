# Write your MySQL query statement below

SELECT w1.id from Weather w1 , Weather w2 WHERE subdate(w1.recordDate,1) = w2.recordDate AND w1.temperature > w2.temperature