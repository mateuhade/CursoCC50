const COFFEE_SONGS = [
    {"coffee": "mocha", "song": "Non-Breath Oblige - PinocchioP"},
    {"coffee": "americano", "song": "Cafezinho - Cyro Monteiro"},
    {"coffee": "espresso", "song": "I Want To Be Cremated - ABuSe"}
]

document.addEventListener("DOMContentLoaded", loadElements)

// Loads page elements and starts listening for "enter" key presses or for a press on the submit button,
// in which case it will call the RevealVibe() function passing necessary parameters
async function loadElements() {
    const coffeeAudio = await document.getElementById("resultAudio");
    const coffeeImage = await document.getElementById("resultImage");

    const coffeeSubmit = await document.getElementById("coffeeSubmit");
    const coffeeInput = await document.getElementById("coffeeInput");
    const coffeeStatus = await document.getElementById("audioStatus");
    
    const userAgent = navigator.userAgent.toLowerCase();

    coffeeAudio.volume = 0.15;
    if (userAgent.includes("mozilla")) {
        coffeeAudio.classList = "";
    }

    let input;
    coffeeSubmit.addEventListener("click", function() {
        input = (coffeeInput.value).replace(/[^a-zA-Z]/g, "").toLowerCase();
        revealVibe(coffeeImage, coffeeAudio, coffeeStatus, input)
    })

    coffeeInput.addEventListener("keydown", function() {
        input = (coffeeInput.value).replace(/[^a-zA-Z]/g, "").toLowerCase();
        if (event.key == "Enter") {
            revealVibe(coffeeImage, coffeeAudio, coffeeStatus, input)
        }
    })
}

// receives as parameters an image element, audio element and text element as well as a string in lower case 
// containing only letters serving as the user input. This function will compare the user input with every 
// value of a list of dictionaries with a "coffee" key. If at least one comparison returns true it will stop
// comparing and it will use the result to insert an image and song into the page
function revealVibe(image, audio, status, input) {
    let isValid = false;
    let imageTitle = "", audioTitle = "", songTitle = "";

    for (let i = 0; i < COFFEE_SONGS.length; i++) {
        if (input.includes(COFFEE_SONGS[i].coffee)) {
            imageTitle = COFFEE_SONGS[i].coffee;
            songTitle = COFFEE_SONGS[i].song;
            isValid = true;
            break;
        }
    }

    if (isValid) {
        audioTitle = songTitle.replaceAll(" ", "");

        status.textContent = `Now Playing: ${songTitle}`
        audio.setAttribute("src", `/static/audios/${audioTitle}.mp3`);
        image.setAttribute("src", `/static/images/coffee/${imageTitle}.jpg`);
    }
    else {
        alert("No, it's not.")
    }
}