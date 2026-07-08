from cs50 import SQL
from flask import Flask, redirect, render_template, request

app = Flask(__name__)

db = SQL("sqlite:///registrants")

ANIMES = [
    "Land Of The Lustrous",
    "Your Name",
    "I Want to Eat Your Pancreas",
    "Liz And The Blue Bird"
]

@app.route("/")
def index():
    return render_template("index.html", animes=ANIMES)

# here we check if the value that the user inserted as their favourite anime is valid, that is, if it
# is not null and if it is in the list of constants ANIMES. We do this because users might change the
# value of the html of the page to be able to register an invalid anime.
@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    anime = request.form.get("Animes")

    # here we pass into the error page a message 
    if not name or not anime:
        return render_template("error.html", message="Missing name or anime")
    
    if anime not in ANIMES:
        return render_template("error.html", message="Invalid anime")
    
    db.execute("INSERT INTO registrants (name, anime) VALUES(?, ?)", name, anime)

    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)