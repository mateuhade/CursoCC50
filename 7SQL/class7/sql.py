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
# [SELECT DISTINCT column FROM table], for example returns every unique value from column

# SQL also has clauses like these:
# WHERE (equivalent to an [if] statement)
# LIKE (returns data similar to a certain data)
# ORDER BY (order the data by a certain column)
# LIMIT (limits how many rows are returned)
# GROUP BY (group identical values)

# For example: [SELECT DISTINCT value FROM dataSet ORDER BY value LIMIT 10;] will return
# at most teh 10 first rows of the value column in sorted order

# By using % we can refer to [0 or more] characters in a string
# Another example:[SELECT value FROM dataSet WHERE value LIKE '%123%' ORDER BY value] will
# return any values that contain the string "123" (61236 for example) in them ordered by value

# and if we want to save our database we can use [.save fileName.db]