# Write your MySQL query statement below
WITH Dept_All AS (
    SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
    FROM Employee e
    LEFT JOIN Department d 
    ON e.departmentId = d.id
), Highest_salary AS (
    SELECT Department, Employee, Salary,
    RANK() OVER (PARTITION BY Department ORDER BY Salary DESC) as Ranking
    FROM Dept_All
)

SELECT Department, Employee, Salary 
FROM Highest_salary
WHERE Ranking = 1;