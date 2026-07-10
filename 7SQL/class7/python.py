#NOTE 5

# Many-to-many relationships:
# Many to many relationships exist when we need one table to be refered to by multiple tables, for
# example, a table called show may have multiple genres, so instead of creating multiple tables with
# the same genre and but a different show_ID, we may create one table for each genre and give it a,
# ID. Then, if we want to refer to the shows table, we cound create a LINK TABLE called show_genre,
# which will contain a show_id and a genre_id, replacing a table that has many repeated genres with
# a smaller table contaning just the exact amount of genres that there are, and creating a new table
# which serves the only purpose to connect two or more tables, making our database cleaner and more
# readable.

# Python:
# We have a few to treat foreign keys, but for now we will use python to do it. Let's say we are
# using the CS50 library, most libraries are similar but we'll use this one for convenience, in this
# case to connect the shows table with the genres table and correspondingly the show_genre table, we
# may use a script similar to this:

# here we make sure that a table called shows.db exists
open("shows.db", "w").close()
# here we tell the library which database we will intereact with (sqlite:/// prefix is mandatory)
from cs50 import SQL
db = SQL("sqlite:///shows.db")
db.execute("CREATE TABLE shows (id INTEGER, title TEXT, PRIMARY KEY(id))")
db.execute("CREATE TABLE genres (id INTEGER, genre TEXT, PRIMARY KEY(id))")
db.execute("CREATE TABLE show_genre (show_id INTEGER, genre_id INTEGER, FOREIGN KEY(show_id), " \
"FOREIGN KEY(genre_id))") # link table

# here we will suppose that we already have titles and genres stored as variables
title = ""
genre = ""

# usually when we insert into a table and the table has an integer column, libraries will return
# the integer that was inserted, so we can store that as a variable
show_id = db.execute("INSERT INTO shows (title) VALUES(?)", title)
genre_id = db.execute("INSERT INTO genres (genre) VALUES(?)", genre)
db.execute("INSERT INTO show_genre (show_id, genre_id) VALUES(?, ?)", show_id, genre_id)

# So, now that we have a table connecting both tables, we can view all of the values using the ids
# and nested queries (commands/queries inside commands/queries)
db.execute("SELECT title FROM shows WHERE id IN (SELECT show_id FROM show_genre WHERE genre_id " \
"= (SELECT id FROM genres WHERE genre = 'Musical'))")
# working from inside-out, this previous command will return first the id from the genre called
# "Musical", then it will use this id as the genre_id in the show_genre table, to find every
# show_id that has that specific genre_id, essentially finding every show that is a musical. And
# at last, it use the show_ids that it finds to read from the shows table every title corresponding
# to each show_id
