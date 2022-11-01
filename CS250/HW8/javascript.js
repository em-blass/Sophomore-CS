const array1 = [
    'elephant.jpg', 'giraffe.jpg', 'hippo.jpg',
    'lion.jpg', 'monkey.jpg', 'zebra.jpg'];
    
let arr = [];
let imageArray = [];
let imageCount = [0, 0, 0, 0, 0, 0];
let fin = false;
let randomInt, checkMissed, checkMatch;

let card = [-1, -1];
let enabled = true;
let check = false;
let matched = 0;
let missed = 0;
let checkCard = [];

function setImage() {
    checkMatch = document.getElementById("matched");
    checkMissed = document.getElementById("missed");

    for (let i = 0; i < 12; i++) {
        arr[i] = document.getElementById(i);
        while (fin == false) {
            randomInt = Math.floor(Math.random() * 6);

            if (imageCount[randomInt] < 2) {
                imageArray[i] = array1[randomInt];
                imageCount[randomInt]++;
                fin = true;
            }
        }

        fin = false;
    }
}

function select(item) {
    let cardCheck = checkCard.includes(imageArray[card[0]]);

    if (enabled) {
        item.setAttribute('src', imageArray[item.id]);
    }

    if (card[0] === -1) {
        card[0] = item.id;
    } 
    
    else if (card[1] === -1 && card[0] !== item.id) {
        card[1] = item.id;
        enabled = false;
        check = true;
    }

    if (check) {
        if (imageArray[card[0]] === imageArray[card[1]] && !cardCheck) {
            matched += 1;
            checkMatch.textContent = "Matched | " + matched;
            checkCard.push(imageArray[card[0]]);
            card = [-1, -1];
            if (matched === 6)
                setTimeout(finished, 1000);
            enabled = true;
            check = false;
        } 
        
        else if (!cardCheck) {
            missed += 1;
            checkMissed.textContent = "Missed | " + missed;
            check = false;
            setTimeout(reset, 1000);
        }
    }
}

function finished() {
    if (checkCard.length === 6 && missed < matched) {
        setTimeout(alert("You Won!"), 200)
    }
    
    else {
        setTimeout(alert("LOSER!!!!"), 200)
    }
}

function reset() {
    let firstCard = checkCard.includes(imageArray[card[0]]);
    let secCard = checkCard.includes(imageArray[card[1]]);

    if (!firstCard) {
        arr[card[0]].src = "flipped.jpg";
    } else {
        arr[card[0]].src = imageArray[card[0]];
    }

    if (!secCard) {
        arr[card[1]].src = "flipped.jpg";
    }
    
    else {
        arr[card[1]].src = imageArray[card[1]];
    }

    card = [-1, -1]
    enabled = true;
}

window.onload = setImage;