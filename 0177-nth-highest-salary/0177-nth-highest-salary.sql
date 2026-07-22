CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
    select salary 
    from (
        select salary, 
        dense_rank() over( order by salary desc) as rankg
        from Employee
    ) as ranked
    where rankg = N
    limit 1 
  );
END