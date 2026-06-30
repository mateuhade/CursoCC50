'''NOTE 1
Flask is a Framework, that is, a way to simplify simple back-end tasks. For example, instead of using
the scanf() function in C and having to deal with cleaning the buffer, just simply using get_string().

The basic convention for creating projects using Flask is to name the files and folders the following way:
app.py           (the actual code we are going to write with flask)
requirements.txt (the libraries and dependencies we are going to use)
static/          (contains static files like png's, jpg's, css, js, etc.)
templates/       (contains HTML files)

Frameworks, specially Flask, usually follow some design patterns like the following MVC:
Model ()   (What technique, software or service we are using with the program's data, like SQL, CSV, etc.)          Updates    -> V
View  ()   (Visual files that the user can see, like HTML and CSS)                                                  Seen By    -> (user)
.                                                                                                       (user)        Uses     -> C   
Controller (The files that control our program, like C, py, js, or any files that only the programmer cares about) Manipulates -> M
'''