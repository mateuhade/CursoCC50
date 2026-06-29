addEventListener("DOMContentLoaded", function() {
    // Array containing the answers to every Trivia question
    let answers = [
        3,
        5,
        ["ROARINGKNIGHT", "RUDEUS", "PAPYRUS", "DESS", "DECEMBER", "THEROARINGKNIGHT"]
    ];

    checkMultipleChoiceAnswer(1, answers[0]);
    checkMultipleChoiceAnswer(2, answers[1]);
    checkFreeResponseAnswer(3, answers[2]);
})

/* ------------- MULTIPLE CHOICE QUESTIONS FUNCTIONS ------------*/
// Checks if the button clicked for question number questionIndex is the same
// button as the answer determined by the answerIndex
function checkMultipleChoiceAnswer(questionIndex, answerIndex) {
    let questionTag = `#question${questionIndex}`;
    let question = document.querySelector(questionTag);
    let answer = question.querySelector(`button:nth-child(${answerIndex})`);

    let isAnswered = false;
    let buttons = question.querySelectorAll(`button`);
    buttons.forEach(function(button) {
        button.addEventListener("click", function() {
            // checks if the user clicked the right option or if he already
            // answered the question
            let isCorrect = false;
            if (button == answer && !isAnswered) {
                alert("Correct Answer!");
                isCorrect = true;
                isAnswered = true;
            }
            else if (!isAnswered) {
                alert("Wrong Answer.");
                isCorrect = false;
                isAnswered = true;
            }
            question.classList.add("answered");

            questionAnswerReveal(question, answer, isCorrect);
        })
    })
}

// Reveals the correct answer for the question by changing the button answer
// color to green or yellow depending if the answer is correct, and the other
// buttons to red
function questionAnswerReveal(question, answer, isCorrect) {
    question.querySelectorAll(`button`).forEach(function(b) {
        b.style.backgroundColor = "#ffb5b5";
    })
    if (isCorrect) {
        answer.style.backgroundColor = "#a8ff8a";
    }
    else {
        answer.style.backgroundColor = "#ffff8a"
    }
}

/* ------------- FREE RESPONSE QUESTIONS FUNCTIONS ------------*/
// Checks if the answer typed by the user in question number questioIndex is in
// an array of correct answers
function checkFreeResponseAnswer(questionIndex, answers) {
    let questionTag = `#question${questionIndex}`;
    let question = document.querySelector(questionTag);
    let submitButton = question.querySelector(`button`);

    let isAnswered = false;
    submitButton.addEventListener("click", function() {
        let input = question.querySelector(`input`).value;
        let cleanUserInput = input.replace(/[^a-zA-Z]/g, "").toUpperCase();

        if (answers.includes(cleanUserInput) && !isAnswered) {
            alert("Correct Answer!");
            question.classList.add("answered");
            submitButton.style.backgroundColor = "#a8ff8a";
        }
        else if (!cleanUserInput && !isAnswered) {
        }
        else if (!isAnswered){
            alert("Wrong Answer.");
            question.classList.add("answered")
            submitButton.style.backgroundColor = "#ffb5b5";
        }
        isAnswered = true;
    })
}
