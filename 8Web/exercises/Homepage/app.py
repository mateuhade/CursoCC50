from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/coffee")
def coffee():
    return render_template("coffee.html")

@app.route("/lotl", methods=["POST"])
def lotl():
    return render_template("lotl.html")

@app.route("/games", methods=["POST"])
def games():
    return render_template("games.html")