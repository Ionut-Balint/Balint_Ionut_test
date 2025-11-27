CREATE TABLE [dbo].[casa_schimb]
(
	[Id] INT NOT NULL PRIMARY KEY IDENTITY, 
    [nume] VARCHAR(50) NULL, 
    [tip_op] VARCHAR(50) NULL, 
    [tip_valuta] VARCHAR(50) NULL, 
    [curs] FLOAT NULL, 
    [suma_lei] FLOAT NULL
)
