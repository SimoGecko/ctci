--MINE
SELECT * FROM (
	SELECT MAX(Student.ID), AVG(Grade) AS avg_grade
	FROM Students INNER JOIN Grades
		ON Students.ID = Grades.StudentIS
		GROUP BY Students.ID
		ORDER BY avg_grade DESC
) T
LIMIT COUNT(T)/10

--SOLUTION
DECLARE @GPACutOff float;
SET @GPACutOff = (
	SELECT min(GPA) as 'GPAMin' FROM (
		SELECT TOP 10 PERCENT AVG(CourseEnrollment.Grade) AS GPA
		FROM CourseEnrollment
		GROUP BY CourseEnrollment.StudentID
		ORDER BY GPA desc) Grades
);

SELECT StudentName, GPA
FROM (
	SELECT AVG(CourseEnrollment.Grade) AS GPA, CourseEnrollment.StudentID
	FROM CourseEnrollment
	GROUP BY CourseEnrollment.StudentID
	HAVING AVG(CourseEnrollment.Grade) >= @GPACutOff
) Honors
INNER JOIN Students ON Honors.StudentID = Student.StudentID