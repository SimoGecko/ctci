-- MINE
UPDATE Requests
SET Status = "Closed"
INNER JOIN Apartments
	ON Apartments.AptID = Requests.AptID
WHERE BuildingID = 11


-- SOLUTION
UPDATE Requests
SET Status = 'Closed'
WHERE AptID IN (
	SELECT AptID
	FROM Apartments
	WHERE BuildingID = 11
)