#NOTE 3
# Firstly we'll install sqlite3, a language that is used mostly in databases of mobile apps
# Then we can import an existing database in another flatfile format, like .csv, by typing
# in the terminal [.mode [fileFormat]] to set the type of the file we'll import, and then
# using [.import [fileName.fileFormat] [newFileName]]. And finally we can use [.schema],
# that automatically creates a table

# SQL (Said like "Sequel") means Structured Query Language, it is a language to interact
# with databases, in database languages we have 4 basic operations to interact with the 
# files/tables:
# C - CREATE  (INSERT)
# R - READ    (SELECT)
# U - UPDATE
# D - DELETE
# ...

# An use example of this is typing in the terminal 
# # This creates a table
# [[CREATE  TABLE [tableName] ([columnName] [columnDataType], ...)] 

# # This reads certain columns of a table
# [SELECT column, column FROM table]

# # By using the * operator we can also refer to everything in the table
# [SELECT * FROM table]

# And in SQL we also have functions similar to the ones we have in excel, for example:
# AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER, etc.
# [SELECT DISTINCT column FROM table]