create table Employee (Id INTEGER, CONSTRAINT PKId Primary Key(Id), Name VARCHAR(256), Salary FLOAT, DepartmentId INTEGER );
Insert into Employee (Id,Name,Salary,DepartmentId) values (1,'Joe',70000,1) ;
Insert into Employee (Id,Name,Salary,DepartmentId) values (2,'Henry',80000,2) ;
Insert into Employee (Id,Name,Salary,DepartmentId) values (3,'Sam',60000,2) ;
Insert into Employee (Id,Name,Salary,DepartmentId) values (4,'Max',90000,1) ;

create table Department (Id INTEGER, CONSTRAINT PKId Primary Key(Id), Name VARCHAR(256) );
Insert into Department (Id,Name) values (1,'IT');
Insert into Department (Id,Name) values (2,'Sales');


select d.Name as Department, e1.Name as Employee, e1.Salary from Employee e1, Employee e2, Department d where e1.Salary > e2.Salary and e1.DepartmentId = e2.DepartmentId and e1.DepartmentId = d.Id;

{"headers": {"Employee": ["Id"
"Name"
"Salary"
"DepartmentId"]
"Department": ["Id"
"Name"]}
"rows": {"Employee": [[1
"Joe"
60000
1]
[4
"Max"
60000
1]]
"Department": [[1
"IT"]]}}

Output: {"headers": ["Department", "Employee", "Salary"], "values": [["IT", "Joe", 60000], ["IT", "Max", 60000], ["IT", "Joe", 60000], ["IT", "Max", 60000]]}

Expected: {"headers": ["Department", "Employee", "Salary"], "values": [["IT", "Joe", 60000], ["IT", "Max", 60000]]}


select DepartmentId, MIN(Salary) from Employee group by DepartmentId ;

SELECT
    d.Name as Department, e1.Name as Employee, e1.Salary
FROM
    Employee e1
INNER JOIN
    (
        SELECT
            DepartmentId, MAX(Salary) as MaxSalary
        FROM
            Employee
        GROUP BY
            DepartmentId
    ) AS e2
    ON  e2.MaxSalary    = e1.Salary
    AND e2.DepartmentId = e1.DepartmentId,
    Department d
    WHERE
        e1.DepartmentId = d.Id
;

select DepartmentId, Salary from Employee ORDER BY -Salary LIMIT 1 ;


