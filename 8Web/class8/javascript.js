// NOTE 7

/*
// JavaScript is a programming language that has a syntax similar to C and Python
// It can be used to interact with html files and make the contents of a webpage vary

// here we use the keyword "let" to declare a variable, we don't have to specify its
// type though
let x = 5;
let y = 3;

// the ++ is back lesgooo
x++;
y--;

// the conditional syntax is the same as in C
if (x > y)
{}
else if (x < y)
{}
else
{}

// the looping syntax is very similar to C except for the let keyword
while (true)
{}

for (let i = 0; i < 3; i++)
{}
*/

///////////////////////////////// PAGE SCRIPT /////////////////////////////////////
// REFER TO js.html

function greet()
{
    /* This is a bit of a weird line, but the "document" keyword refers to all the files
    connected to the html webpage, the "querySelector(#name)" looks for a file that has
    the "name" ID in it, and the "value" gets the actual value that is stored in that ID*/
    let name = document.querySelector(#name).value
    alert("Hello,", name)
}