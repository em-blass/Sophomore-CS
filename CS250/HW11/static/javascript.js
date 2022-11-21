var result = document.getElementById('result');

window.onload = function() {
    var foo = 1;
    
    result.innerHTML = "IS " + foo + " PRIME?";
    result.href = "http://127.0.0.1:5000/isPrime/app/" + foo;
}

function slider(foo) {
    result.innerHTML = "IS " + foo + " PRIME?";
    result.href = "http://127.0.0.1:5000/isPrime/app/" + foo;
}
