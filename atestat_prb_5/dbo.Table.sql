CREATE TABLE [dbo].[elevi]
(
	[Id] INT NOT NULL PRIMARY KEY IDENTITY, 
    [cnp] VARCHAR(50) NULL, 
    [nume] VARCHAR(50) NULL, 
    [adresa] VARCHAR(50) NULL, 
    [diagnostic] VARCHAR(50) NULL, 
    [data] DATE NULL
)
