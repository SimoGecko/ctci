-- create tables

CREATE TABLE Apartments (
	AptID 			INTEGER PRIMARY KEY,
	UnitNumber 		VARCHAR(10),
	BuildingID 		INTEGER --FOREIGN KEY REFERENCES Buildings.BuildingID
);

CREATE TABLE Buildings (
	BuildingID 		INTEGER PRIMARY KEY,
	ComplexID 		INTEGER, --FOREIGN KEY REFERENCES Complexes.ComplexID,
	BuildingName 	VARCHAR(100),
	Address 		VARCHAR(100),
);

CREATE TABLE Complexes (
	ComplexID 		INTEGER PRIMARY KEY,
	ComplexName 	VARCHAR(100)
);

CREATE TABLE Tenants (
	TenantID 		INTEGER PRIMARY KEY,
	TenantName 		VARCHAR(100)
);

CREATE TABLE AptTenants (
	TenantID		INTEGER PRIMARY KEY,
	AptID 			INTEGER PRIMARY KEY
);

CREATE TABLE Requests (
	RequestID		INTEGER PRIMARY KEY,
	Status			VARCHAR(100),
	AptID 			INTEGER, --FOREIGN KEY REFERENCES Apartments.AptID,
	Description		VARCHAR(500),
);




-- populate tables

INSERT INTO Apartments (AptID, UnitNumber, BuildingID)
VALUES
	(1, "30", 1),


