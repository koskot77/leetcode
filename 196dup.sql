create table Person ( Id INTEGER, CONSTRAINT PKId PRIMARY KEY (id), email VARCHAR(256) );

Insert into Person (Id,email) values (2,'john@example.com') ;
Insert into Person (Id,email) values (3,'bob@example.com') ;
Insert into Person (Id,email) values (4,'john@example.com') ;

select MIN(Id), email from Person group by email;

delete from Person where Id not in (select * from (select MIN(Id) from Person group by email) tmp );
