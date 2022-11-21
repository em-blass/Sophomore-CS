from flask import *
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__, static_url_path='/static')
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///cars.db'
db = SQLAlchemy(app)

class Cars(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    year = db.Column(db.Integer)
    make = db.Column(db.String(100))
    model = db.Column(db.String(100))
    price = db.Column(db.String(100))

@app.route('/')
def home():
    return render_template('home.html')

@app.route('/create', methods=['POST', 'GET'])
def create():
    if request.method == 'POST':
        year = request.form["year"]
        brand = request.form["brand"]
        model = request.form["model"]
        price = request.form["price"]

        _entry = Cars(year=year, make=brand, model=model, price=price)

        db.session.add(_entry)
        db.session.commit()

        return redirect('read')
    else:
        return render_template('create.html')

@app.route('/read')
def read():
    list = Cars.query.all()
    return render_template('read.html', list=list)

@app.route('/update/<id>', methods=['POST', 'GET'])
def update(id):
    target = Cars.query.filter_by(id=id).first()
    if request.method == 'POST':
        target.year = request.form['year']
        target.make = request.form['brand']
        target.model = request.form['model']
        target.price = request.form['price']

        db.session.commit()

        return redirect('/read')
    else:
        return render_template('update.html', year=target.year, brand=target.make, model=target.model, price=target.price, id=id)

@app.route('/delete/<id>')
def delete(id):
    target = Cars.query.filter_by(id=id).first()
    db.session.delete(target)
    db.session.commit()
    return redirect('/read')

@app.errorhandler(404)
def err404(err):
    return render_template('404.html', err=err)

app.app_context().push()

if __name__ == "__main__":
    app.run()