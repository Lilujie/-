https://leetcode-cn.com/problems/department-highest-salary/
# Write your MySQL query statement below
select  
    Department.Name as Department,
    Employee.Name as Employee,
    Salary     
from Employee ,Department 
where Employee.DepartmentId=Department.Id AND
     (Employee.DepartmentId , Salary) IN
    (   SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
	)
;
-- SELECT
--     Department.name AS 'Department',
--     Employee.name AS 'Employee',
--     Salary
-- FROM
--     Employee
--         JOIN
--     Department ON Employee.DepartmentId = Department.Id
-- WHERE
--     (Employee.DepartmentId , Salary) IN
--     (   SELECT
--             DepartmentId, MAX(Salary)
--         FROM
--             Employee
--         GROUP BY DepartmentId
-- 	)
-- ;
