9
------------------------------------------------------------------------------
SELECT F.departs
FROM Flights F
WHERE F.flno IN (( 	SELECT F0.flno
			FROM Flights F0
			WHERE F0.from = 'Madison' AND F0.to = 'New York'
					AND F0.arrives < '18.00')
			UNION
		       (SELECT F0.Flno
		        FROM Flights F0, Flights F1
			WHERE F0.from = 'Madison' AND F0.to <> 'New York'
			      AND F0.to = F1.from AND F1.to = 'New York'
			      AND F1.departs > F0.arrives
			      AND F1.arrives < '18:00')
		        UNION
		       (SELECT F0.flno
		        FROM Flights F0, Flights F1, Flights F2
			WHERE F0.from = 'Madison'
			      AND F0.to = F1.from
			      AND F1.to = F2.from
			      AND F2.to = 'New York'
			      AND F0.to <> 'New York'
			      AND F1.to <> 'New York'
			      AND F1.departs > F0.arrives
			      AND F2.departs > F1.arrives
			      AND F2.arrives < '18:00'))

10
---------------------------------------------------------------------------

SELECT Temp1.avg - Temp2.avg
FROM ( SELECT AVG (E.salary) AS avg
       FROM Employees E
       WHERE E.eid IN ( SELECT DISTINCT C.eid
       			FROM Certified C)) AS Temp1,
     ( SELECT AVG (E1.salary) AS avg
       FROM Employees E1) AS Temp2

11
----------------------------------------------------------------------------

SELECT E.ename, E.salary
FROM Employees E
WHERE E.eid NOT IN ( SELECT DISTINCT C.eid
		     FROM Certified C)
      AND E.salary > (SELECT AVG (E1.salary)
      		      FROM Employees E1
		      WHERE E1.eid IN ( SELECT DISTINCE C1.eid
		      			FROM Certified C1))

12
----------------------------------------------------------------------------

SELECT E.ename
FROM Employees E, Certified C, Aircraft A
WHERE C.eid = E.eid AND A.aid = C.aid
GROUP BY E.eid, E.ename
HAVING EVERY (A.crusingrange > 1000)

13
----------------------------------------------------------------------------

SELECT E.ename
FROM Employees E, Certified C, Aircraft A
WHERE C.eid = E.eid AND A.aid = C.aid
GROUP BY E.eid, E.ename
HAVING EVERY (A.crusingrange > 1000) AND COUNT (*) > 1

14
----------------------------------------------------------------------------

SELECT E.ename
FROM Employees E, Certified C, Aircraft A
WHERE C.eid = E.eid AND A.aid = C.aid
GROUP BY E.eid, E.ename
HAVING EVERY (A.crusingrange > 1000) AND ANY (A.aname LIKE 'Boeing%')

