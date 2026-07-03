const coffeeFile = document.querySelector("body");
const coffeeSubmit = coffeeFile.querySelector("#coffeeSubmit");
const coffeeInput = coffeeFile.querySelector("#coffeeInput");
const coffeeStatus = coffeeFile.querySelector("#audioStatus")

coffeeSubmit.addEventListener("click", function() {
    const coffeeImage = coffeeFile.querySelector("#resultImage");
    const coffeeAudio = coffeeFile.querySelector("#resultAudio");
    let input = (coffeeInput.value).replace(/[^a-zA-Z]/g, "").toUpperCase()
    revealVibe(coffeeImage, coffeeAudio, input)
})

// pops up image and song based on the coffee Input sent by the user
function revealVibe(coffeeImage, coffeeAudio, input) {
    let isValid = true;
    let image = "", audio = "";
    if (input.includes("AMERICANO")){
        coffeeStatus.textContent = "Now Playing: Cafezinho - Cyro Monteiro"
        audio = "/static/audios/Cafezinho-CyroMonteiro.mp3";
        image = "/static/images/americano.jpg"
    }
    else if (input.includes("MOCHA")){
        coffeeStatus.textContent = "Now Playing: Non-Breath Oblige - PinocchioP"
        audio = "/static/audios/NonBreathOblige-PinocchioP.mp3";
        image = "/static/images/mocha.jpg"
    }
    else if (input.includes("ESPRESSO")){
        coffeeStatus.textContent = "Now Playing: I Want To Be Cremated - ABuSe"
        audio = "/static/audios/IWantToBeCremated-ABuSe.mp3";
        image = "/static/images/espresso.jpg"
    }
    else {
        alert("No, it's not.");
        isValid = false;
    }

    if (isValid) {
        coffeeAudio.setAttribute("src", audio);
        coffeeImage.setAttribute("src", image);
    }
}