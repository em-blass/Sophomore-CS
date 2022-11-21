function nasaAPI() {
    var pickDate = document.querySelector('input[type="date"]');

    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if(this.readyState === 4 && this.status === 200) {
            var obj = JSON.parse(this.responseText);

            document.getElementById('title').innerText = obj.title;
            document.getElementById('image').src = obj.url;
            document.getElementById('desc').innerText = obj.explanation;
        }
    };

    xhttp.open("GET", "https://api.nasa.gov/planetary/apod?api_key=qsnwMthSc0RMmDFjqNuqmZB42UECqHTKIUFWNhM2&date=" + pickDate.value, true);
    xhttp.send();
}