# 1-Sessions are how we differ users, we can use them to store cookies of that user to remember
# their password so that they don't need to log in next time. They can also be used to track
# user tendencies, be it for relevant ads or maleficial purposes
from flask_session import Session
from flask import Flask, redirect, render_template, request, session

app = Flask(__name__)
# 2-necessary configurations for the Flask_session library according to its documentation
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
app.config["SECRET_KEY"] = "123"



@app.route("/")
def index():

    # 4-If the user doesn't have a name stored into their session, redirect them to /login
    if not session.get("name"):
        return redirect("/login")
    
    return render_template("index.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    if "name" not in session:
        session["name"] = []

    if request.method == "POST":
        # 3-Here we store the users name into their session and send them back to the homepage
        name = request.form.get("name")
        session["name"] = name
        return redirect("/")
    
    return render_template("login.html")

@app.route("/logout")
def logout():
    session["name"] = None
    return redirect("/login")