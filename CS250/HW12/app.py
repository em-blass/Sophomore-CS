from flask import *
app = Flask(__name__, static_url_path='/static')

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/factors', methods=['POST', 'GET'])
def factors():
    numArray = []
    if request.method == "POST":
        number = request.form['numInput']
        for i in range(1, int(number) + 1):
            if int(number) % i == 0:
                numArray.append(i)

        return render_template('factors.html', numArray=numArray)

    if request.method == "GET":
        return render_template('factors.html')

@app.route('/wordCount', methods=['POST', 'GET'])
def wordcount():
    if request.method == "POST":
        wordArray = {}
        strInput = request.form["strInput"]

        for word in strInput.split():
            wordArray[word] = 0
        for word in strInput.split():
            wordArray[word] += 1

        return render_template('wordCount.html', wordArray=wordArray)

    if request.method == "GET":
        return render_template('wordCount.html')

@app.errorhandler(404)
def err404(err):
    return render_template('404.html', err=err)

app.run()