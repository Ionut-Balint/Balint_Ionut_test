CREATE TABLE [dbo].[agenda]
(
	[Id] INT NOT NULL PRIMARY KEY IDENTITY, 
    [nume] VARCHAR(50) NULL, 
    [data_nasterii] DATE NULL, 
    [domiciliu] VARCHAR(50) NULL, 
    [telefon] VARCHAR(50) NULL
)
