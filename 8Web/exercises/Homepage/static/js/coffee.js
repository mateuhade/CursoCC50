const coffeeFile = document.querySelector("#coffeeFile");
const coffeeSubmit = coffeeFile.querySelector("#coffeeSubmit");
const coffeeInput = coffeeFile.querySelector("#coffeeInput");
const coffeeStatus = coffeeFile.querySelector("#audioStatus")

coffeeSubmit.addEventListener("click", function() {
    const coffeeImage = coffeeFile.querySelector("#resultImage");
    const coffeeAudio = coffeeFile.querySelector("#resultAudio");
    let input = (coffeeInput.value).replace(/[^a-zA-Z]/g, "").toUpperCase()

    let image = "", audio = "";
    if (input.includes("AMERICANO")){
        audio = "/static/audios/Cafezinho-CyroMonteiro.mp3";
        coffeeAudio.setAttribute("src", audio);
        coffeeStatus.textContent = "Now Playing: Cafezinho - Cyro Monteiro"

        image = "/static/images/americano.jpg"
        coffeeImage.setAttribute("src", image);
    }
    else if (input.includes("MOCHA")){
        audio = "/static/audios/NonBreathOblige-PinocchioP.mp3";
        coffeeAudio.setAttribute("src", audio);
        coffeeStatus.textContent = "Now Playing: Non-Breath Oblige - PinocchioP"

        image = "/static/images/mocha.jpg"
        coffeeImage.setAttribute("src", image);
    }
    else if (input.includes("ESPRESSO")){
        audio = "/static/audios/IWantToBeCremated-ABuSe.mp3";
        coffeeAudio.setAttribute("src", audio);
        coffeeStatus.textContent = "Now Playing: I Want To Be Cremated - ABuSe"

        image = "/static/images/espresso.jpg"
        coffeeImage.setAttribute("src", image);
    }
    else {
        alert("No, it's not.");
    }
})

// pops up image based on the coffee Input Inputd by the user
function popImage(coffeeInput) {}