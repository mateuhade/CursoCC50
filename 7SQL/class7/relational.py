# NOTE 4

# If we have a data set that contains many repeated values we can use the function GROUP BY [value]
# to show only one instance of that value instead of repeating them, and if we want to know how
# many times a value is repeated we can use COUNT([value])

# Now, if we want to insert data into a table, we can use INSERT INTO [table] ([name of column to 
# insert into], [name of column to insert into], ...) VALUES([value to be inserted], ...)
# ex: INSERT INTO dataSet (small, value) VALUES(test, 1);
# And if we want to update the value of something in our table we can simply use the UPDATE function
# ex: UPDATE dataSet SET value = 2 WHERE small = 'test'
# And if we want to delete a value:
# ex: DELETE FROM dataSet WHERE small = 'this'

# ***************************************

# Standard SQL data types:
# TEXT     ('cool text') [text]
# INTEGER  (12 123 1234) [numbers]
# NUMBERIC (02/04/2008) [data that contains numbers but isn't used like numbers]
# REAL     (0.123) [floating point numbers]
# BLOB     (0 1 0 1) [binary object, zeros and ones, true or false] 

# Constraints:
# NOT NULL [specifies that the value in the column cannot be empty]
# UNIQUE [specifies that the value in the column must not appear again if it appeared once before]

# Keys:
# Let's say we have two tables, the table "show", which contains the title of a show and the show ID,
# and the table "genres", which contains the genres of a show, and an ID identical to the ID from the
# show table, refering to that spefic show. Let's call theses ID's "ID" and "show_ID" by convention.
# In this context, the show_ID is the FOREIGN KEY of the database, since it refers to a table that is
# not itself. And so, the ID is the PRIMARY KEY of the database, since it is refered to by others and
# only refers to its own table.
# Example: CREATE TABLE shows (id INTEGER, title TEXT, PRIMARY KEY(id))
# Example: CREATE TABLE genres (show_id INTEGER, genre TEXT, FOREIGN KEY(show_id))

