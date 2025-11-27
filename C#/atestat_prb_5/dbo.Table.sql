CREATE TABLE [dbo].[pacientii]
(
	[Id] INT NOT NULL PRIMARY KEY IDENTITY, 
    [CNP] VARCHAR(50) NULL, 
    [nume] VARCHAR(50) NULL, 
    [adresa] VARCHAR(50) NULL, 
    [diagnostic] VARCHAR(50) NULL, 
    [data] DATE NULL
)
