from flask import Flask, render_template

app = Flask(__name__)

GAMES = [
    {"name": "The Witness", "gameUrl": "https://store.steampowered.com/app/210970/The_Witness/", "reviewUrl": "https://www.gamespot.com/reviews/the-witness-review/1900-6416336/", "credits": "-Mike Mahardy (gamespot)", "review": "The Witness is one of the most challenging games I’ve ever played. During my playthrough, I experienced confusion, uncertainty, and mental exhaustion as I tried to understand this game’s intricacies. At times, I considered giving up. The Witness makes few attempts at handholding, opting instead to convey its mechanics in subtle, cryptic ways as you struggle to make sense of it all.", "image": "../static/images/games/theWitness.jpg"},
    {"name": "Z.A.T.O.", "gameUrl": "https://store.steampowered.com/app/4122860/ZATO__I_Love_the_World_and_Everything_In_It/", "reviewUrl": "https://backloggd.com/u/Jayke/review/3657596", "credits": "-Jayke (backloggd)", "review": "Z.A.T.O. is one of those experiences that really drags you in with it's endearing nature and unique narrator, just to batter you with wholesome tragedy, genuine devastation, and proto-existentialist concepts in a way that, if you meet it in turn, will emotionally devastate you in a way that you'll rarely experience.", "image": "../static/images/games/zato.jpg"},
    {"name": "DELTARUNE", "gameUrl": "https://store.steampowered.com/app/1671210/DELTARUNE/", "reviewUrl": "https://www.metacritic.com/game/deltarune", "credits": "-Cubed3 (metacritic)", "review": "Deltarune is a subversive epic that defies conventions and keeps the laughs coming every minute of its lengthy runtime. The most staggering aspect of it is that this isn't even its final form. Purchasing Deltarune chapters 1-4 is a ticket for the eventual chapters 5-7, which will expand the scope of the story and surely take things in an unpredictable direction if the conclusion of chapter 4 is anything to go by.", "image": "../static/images/games/deltarune.jpg"},
    {"name": "Hollow Knight: Silksong", "gameUrl": "https://store.steampowered.com/app/1030300/Hollow_Knight_Silksong/", "reviewUrl": "https://www.metacritic.com/game/hollow-knight-silksong/", "credits": "-Multiplayer.it (metacritic)", "review": "Hollow Knight: Silksong is, quite simply, a video game that shouldn’t exist. No publisher on Earth would ever fund the production of a colossal two-dimensional Metroidvania over the span of seven years, and no independent developer could realistically afford to turn such an immense ambition into reality. And yet, Hollow Knight: Silksong does exist, and it exists solely because a group of creators - deeply in love with their own work but above all blessed with extraordinary talent and the resources to make it shine - chose to invest seven years of their lives in the project.", "image": "../static/images/games/silksong.jpg"},
    {"name": "Enigma of Fear", "gameUrl": "https://store.steampowered.com/app/1507580/Enigma_of_Fear/", "reviewUrl": "https://www.metacritic.com/game/enigma-of-fear/", "credits": "-IGN Brasil (metacritic)", "review": "Enigma of Fear, although directly related to the expanded universe of the RPG Paranormal Order, stands on its own with eye-catching artwork, creative investigation mechanics and an engaging story augmented by evidence carefully placed in mysterious rooms.", "image": "../static/images/games/enigmaOfFear.jpg"}
]

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/coffee")
def coffee():
    return render_template("coffee.html")

@app.route("/lotl")
def lotl():
    return render_template("lotl.html")

@app.route("/games")
def games():
    return render_template("games.html", games=GAMES)
