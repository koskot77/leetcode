create table Customers (Id INTEGER, CONSTRAINT PKId PRIMARY KEY(Id), Name VARCHAR(256));

INSERT INTO Customers (Id,Name) VALUES (1,'Joe') ;
INSERT INTO Customers (Id,Name) VALUES (2,'Henry') ;
INSERT INTO Customers (Id,Name) VALUES (3,'Sam') ;
INSERT INTO Customers (Id,Name) VALUES (4,'Max') ;

CREATE TABLE Orders (Id INTEGER, CONSTRAINT PKId PRIMARY KEY(Id), CustomerId INTEGER NOT NULL);

INSERT INTO Orders (Id,CustomerId) VALUES (1,3);
INSERT INTO Orders (Id,CustomerId) VALUES (2,1);

select c.Name as Customers from Customers c LEFT JOIN Orders o ON c.Id = o.CustomerId WHERE o.Id IS NULL ;

