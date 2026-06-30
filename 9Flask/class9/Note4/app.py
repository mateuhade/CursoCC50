from flask import Flask, render_template, request

app = Flask(__name__)

ANIMES = [
    "Land Of The Lustrous",
    "Your Name",
    "I Want to Eat Your Pancreas",
    "Liz And The Blue Bird"
]

@app.route("/")
def index():
    return render_template("index.html", animes=ANIMES)

@app.route("/register", methods=["POST"])
def register():
    if not request.form.get("name") or request.form.get("Animes") not in ANIMES:
        return render_template("failure.html")
    return render_template("success.html")