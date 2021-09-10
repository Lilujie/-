https://leetcode-cn.com/problems/duplicate-emails/
# Write your MySQL query statement below
#select distinct(p1.Email) from Person p1, Person p2 where p1.Email = p2.Email And p1.Id != p2.Id;
select Email from Person group by Email having count(Email) > 1;