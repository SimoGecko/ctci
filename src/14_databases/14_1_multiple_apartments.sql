-- MINE
SELECT MAX(TenantName), COUNT(AptID) AS num_apartments
FROM Tenants INNER JOIN AptTenants
			 ON Tenants.TenantID = AptTenants.TenantID
WHERE num_apartments >= 2
GROUP BY TenantID


-- SOLUTION


SELECT TenantName
FROM Tenants INNER JOIN (
	SELECT TenantID
	FROM AptTenants
	GROUP BY TenantID
	HAVING count(*) > 1
) C
ON Tenants.TenantID = C.TenantID