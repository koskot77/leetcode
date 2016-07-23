CREATE TABLE Scores (Id INTEGER, CONSTRAINT PKId PRIMARY KEY(Id), Score FLOAT) ;

INSERT INTO Scores (Id,Score) VALUES (1,3.50) ;
INSERT INTO Scores (Id,Score) VALUES (2,3.65) ;
INSERT INTO Scores (Id,Score) VALUES (3,4.0) ;
INSERT INTO Scores (Id,Score) VALUES (4,3.85) ;
INSERT INTO Scores (Id,Score) VALUES (5,4.00) ;
INSERT INTO Scores (Id,Score) VALUES (6,3.65) ;

SELECT s1.Score, COUNT(*) as Rank
FROM Scores s1, (SELECT DISTINCT Score from Scores) as s2
WHERE s1.Score <= s2.Score
GROUP BY s1.Id
ORDER BY -s1.Score ;
