var isPrime = true;

do {
    var num = prompt('Enter a positive number: ');
} while (num <= 0)

if (num > 0) {   
    for (var i = 2; i < num; i++) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        document.write('<h1>', 'Factors of ', num, ': ', '</h1>');
        for(var i = 1; i <= num; i++) {
            if(num % i == 0) {
                document.write(i, '<br>');
            }
        }
        document.write('<br>', num, ' is a prime number.');
    } 
    
    else {
        document.write('<h1>', 'Factors of ', num, ': ', '</h1>');
        for(var i = 1; i <= num; i++) {
            if(num % i == 0) {
                document.write(i, '<br>');
            }
        }
        document.write('<br>', num, ' is not a prime number.');
    }
}