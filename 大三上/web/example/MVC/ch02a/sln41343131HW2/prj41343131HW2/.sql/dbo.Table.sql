CREATE TABLE [dbo].[user]                              -- must use "users" instead
(
	[fId] INT NOT NULL IDENTITY(1,1) PRIMARY KEY,
    [fAccount] NVARCHAR(50) NOT NULL,-- UNIQUE,
    [fPassword] NVARCHAR(20) NOT NULL,      -- must using hash and >64
    [fEmail] NVARCHAR(30) NULL,                     -- must using >=100
    [fDate] DATE NOT NULL
)
