// NOTE 8

function greet() {
    let name = document.querySelector(#name).value;
    alert("Hello, " + name);
}

function listen()
{}

document.addEventListener("DOMContentLoaded", function() {
    let input = document.querySelector('input');
    input.addEventListener('keyup', function(event) {
        let name = document.querySelector('#name');
        if (input.value) {
            name.innerHTML = `Hello, ${input.value}`
        }
        else {
            name.innerHTML = 'Hello, whoever you are'
        }
    })
})