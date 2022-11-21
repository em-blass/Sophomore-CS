from flask import *
app = Flask(__name__, static_url_path='/static')

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/isPrime/<foo>')
def back(foo):
    return render_template('index.html')

@app.route('/isPrime/app/<foo>')
def isPrime(foo):
    if int(foo) == 1 or int(foo) == 2 or int(foo) == 3:
        return "<link rel='stylesheet' href='/static/stylesheet.css'> \n <h1>" + \
            foo + " is prime!</h1> \n <a href='http://127.0.0.1:5000/isPrime/" + foo + "'>BACK</a>"

    if int(foo) % 2 == 0 or int(foo) < 2:
        return "<link rel='stylesheet' href='/static/stylesheet.css'> \n <h1>" + \
            foo + " is NOT Prime.</h1> \n <a href='http://127.0.0.1:5000/isPrime/" + foo + "'>BACK</a>"

    for n in range(3, int(int(foo) ** 1 / 2) + 1, 2):
        if int(foo) % n == 0:
            return "<link rel='stylesheet' href='/static/stylesheet.css'> \n <h1>" + \
                foo + " is NOT prime.</h1> \n <a href='http://127.0.0.1:5000/isPrime/" + foo + "'>BACK</a>"

    return "<link rel='stylesheet' href='/static/stylesheet.css'> \n <h1> " + \
        foo + " is prime!</h1> \n <a href='http://127.0.0.1:5000/isPrime/" + foo + "'>BACK</a>"

if __name__ == "__main__":
    app.run()