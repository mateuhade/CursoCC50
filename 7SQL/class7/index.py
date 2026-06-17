# NOTE 6

# JOIN:
# Sometimes queries can sometimes become extremely long when we are dealin with many-to-many relationships,
# so we may resort to using the JOIN keyword, which can merge tables in a more succint way, for example:

#[here we get every title of a show that every person from the people table starred in]
#     sqlite3 > SELECT title FROM people 
#     ... > JOIN stars ON people.id = stars.person_id 
# [here we get every id of every person from the people table, and where that id is the same as the person_id 
# from the stars table, we merge those tables. For example, in the stars table we may have the id of a person 
# and the id of a show, saying which person is a star for which show. And on the people table we may have an 
# id for each person, a name and an age. By using this command, if a person id from the stars table is the 
# same as the id from the people table, we will create a table that has that same id, name, age and show id.]
#     ... > JOIN shows ON shows.id = stars.person_id 
# [now we have a table containing all the information the id of every show, and every show, how each of these 
# ids are connected and the values of each of these three tables
#     ... > WHERE name = 'John Doe';
# [and what all of this does is get the name of every show where John Doe was a star]

# ************************

# INDEXes:
# When running any commands in SQL up to now, we were running on constant time by always checking N items in
# every search or interaction. But in SQLite and most databases, we have the option to create indexes. Indexes
# are tree-based data structures that organize our data in B-Trees similar to Binary Treees we use when storing
# data in C or Python, except that they are graphically wider (a root will point to many nodes as opposed to
# only two like in Binary Trees) and so, shorter. Using this we can lower our run time to approximately O log(n).
#
# For example: 
# Lets say we have a very large database and searching for every title with John Doe as a star took about a
# second, in that case we could create indexes to every column that might be bottlenecking our search. Like this:
#     sqlite3 > CREATE INDEX show_index ON stars (show_id);
#     sqlite3 > CREATE INDEX person_index ON stars (person_id);
#     sqlite3 > CREATE INDEX name_index ON people (name);
# and just by running this one single time, we reduce significantly the run time of our database for the rest of
# its usage.