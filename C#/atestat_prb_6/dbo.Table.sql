CREATE TABLE [dbo].[camping]
(
	[Id] INT NOT NULL PRIMARY KEY IDENTITY, 
    [numar_camping] INT NULL, 
    [tip_camping] VARCHAR(50) NULL, 
    [data] DATE NULL, 
    [numar_nopti] INT NULL, 
    [nume_titular] VARCHAR(50) NULL
)
