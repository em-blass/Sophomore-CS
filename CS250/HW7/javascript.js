var array = ['elephant.jpg', 'elephant.jpg', 'giraffe.jpg', 'giraffe.jpg', 'lion.jpg', 'lion.jpg', 
                'monkey.jpg', 'monkey.jpg', 'hippo.jpg', 'hippo.jpg', 'zebra.jpg', 'zebra.jpg'];

function table(array) {
    document.write('<table>');
    let incr = 0;
    
    for (let r = 0; r < 3; r++) {
        document.write('<tr>');
            document.write('<td>' + '<img src="' + array[incr] + '" alt="">' + '</td>');
            incr += 1;

            document.write('<td>' + '<img src="' + array[incr] + '" alt="">' + '</td>');
            incr += 1;

            document.write('<td>' + '<img src="' + array[incr] + '" alt="">' + '</td>');
            incr += 1;

            document.write('<td>' + '<img src="' + array[incr] + '" alt="">' + '</td>');
            incr += 1;

        document.write('</td>');
    }
}

function randomize(array) {
    let currentIndex = array.length,  randomIndex;

    while (currentIndex != 0) {
        randomIndex = Math.floor(Math.random() * currentIndex);
        currentIndex--;

        [array[currentIndex], array[randomIndex]] = 
        [array[randomIndex], array[currentIndex]];
    }

    return array;
}  

let randomArray = randomize(array);
table(randomArray);