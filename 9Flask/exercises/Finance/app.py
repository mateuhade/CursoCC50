import os
import datetime

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return apology("TODO")

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Search for symbol specified by user
        symbolSearch = lookup(request.form.get("symbol"))
        if not symbolSearch:
            apology("invalid symbol", 403)
        
        # Get number of shares to buy via user input
        try:
            shares = int(request.form.get("shares"))
        except:
            apology("invalid number of shares", 403)

        # Check for valid user input in shares field
        if not shares or shares < 1:
            apology("invalid number of shares", 403)

        sharePrice = symbolSearch["price"]
        finalPrice = sharePrice * shares
        userBalance = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

        # Check if user has enough money for the purchase
        if userBalance < finalPrice:
            apology("insuficient funds", 403)
        
        # Update user balance based on current purchase
        userID = db.execute("UPDATE users SET cash = ? WHERE id = ?", (userBalance - finalPrice), session["user_id"])
        
        # Store transaction in database
        currentTime = datetime.datetime.now()
        transactionID = db.execute("INSERT INTO transactions (cost, time) VALUES(?, ?)", finalPrice, currentTime)
        db.execute("INSERT INTO user_transaction (user_id, transaction_id) VALUES(?, ?)", userID, transactionID)

        # Redirect user to Homepage
        flash("Purchase made successfuly!", "success")
        return redirect("/")
    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        flash("Logged in successfuly!", "success")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    flash("Logged out!", "success")
    return redirect("/")

@app.route("/quote")
@login_required
def quote():
    print(session["user_id"])
    return render_template("quote.html")

@app.route("/quoted", methods=["GET", "POST"])
@login_required
def quoted():
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Looks for the symbol specified by the user, returning price, symbol and company
        symbolSearch = lookup(request.form.get("symbol"))

        # Check for valid symbol
        if not symbolSearch:
            return apology("invalid symbol", 403)
        
        companyName = symbolSearch["name"]
        price = symbolSearch["price"]
        symbol = symbolSearch["symbol"]

        return render_template("quoted.html", companyName=companyName, price=price, symbol=symbol)
    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return redirect("/quote")

@app.route("/register", methods=["GET", "POST"])
def register():
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("passwordConfirmation")
        hashedPassword = generate_password_hash(password)

        # Ensure username was submitted
        if not username:
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not password or not confirmation:
            return apology("must provide password", 403)

        # Ensure passwords submitted were the same
        elif password != confirmation:
            return apology("passwords don't match", 403)

        # Check if username is already in use
        try: 
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hashedPassword)
        except:
            return apology("username is already in use", 403)
        
        # Log in user and remember their ID
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        flash("Registered successfuly!", "success")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
