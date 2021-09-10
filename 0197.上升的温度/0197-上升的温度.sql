https://leetcode-cn.com/problems/rising-temperature/
# Write your MySQL query statement below
select w2.id from Weather w1,Weather w2  where w2.temperature > w1.temperature and DATEDIFF(w2.RecordDate, w1.RecordDate) = 1;
