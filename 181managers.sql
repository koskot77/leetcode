CREATE TABLE Employee (Id INTEGER, CONSTRAINT PKId PRIMARY KEY(Id), Name VARCHAR(256) NOT NULL, Salary INTEGER NOT NULL, ManagerId INTEGER, CONSTRAINT FKMId FOREIGN KEY(ManagerId) REFERENCES Employee(Id));

Insert into Employee (Id,Name,Salary,ManagerId) values (3,'Sam',60000,NULL) ;
Insert into Employee (Id,Name,Salary,ManagerId) values (4,'Max',90000,NULL) ;
Insert into Employee (Id,Name,Salary,ManagerId) values (1,'Joe',70000,3) ;
Insert into Employee (Id,Name,Salary,ManagerId) values (2,'Henry',80000,4) ;

select e1.Name as Employee from Employee e1, Employee e2 where e1.ManagerId = e2.Id and e1.Salary > e2.Salary ;

