// https://leetcode-cn.com/problems/department-top-three-salaries/
# Write your MySQL query statement below
select  
    d.Name as Department,
    e1.Name as Employee,
    Salary     
from Employee e1,Department d
where e1.DepartmentId=d.Id AND
     3 > (SELECT
            COUNT(DISTINCT e2.Salary)
        FROM
            Employee e2
        WHERE
            e2.Salary > e1.Salary
                AND e1.DepartmentId = e2.DepartmentId
        );