-- MINE

SELECT BuildingName, ISNULL(num_open_requests, 0) AS Open_requests
FROM Buildings LEFT JOIN (
	SELECT BuildingID, COUNT(*) AS num_open_requests
	FROM Apartments INNER JOIN Requests
		ON Apartments.AptID = Requests.AptID
	WHERE Status LIKE "Open"
	GROUP BY BuildingID
) T
ON Buildings.BuildingID = T.BuildingID


-- SOLUTION

SELECT BuildingName, ISNULL(Count, 0) as 'Count'
FROM Buildings
LEFT JOIN (
	SELECT Apartments.BuildingID, count(*) as 'Count'
	FROM Requests INNER JOIN Apartments
		ON Requests.AptID = Apartments.AptID
	WHERE Requests.Status = 'Open'
	GROUP BY Apartments.BuildingID
) ReqCounts
ON ReqCounts.BuildingID = Buildings.BuildingID