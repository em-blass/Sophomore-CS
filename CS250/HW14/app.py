from flask import *
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager, UserMixin, login_user, logout_user, current_user, login_required

app = Flask(__name__, static_url_path='/static')
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
db = SQLAlchemy(app)

login_manager = LoginManager(app)
login_manager.init_app(app)

class User(UserMixin, db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(20), unique=True, nullable=False)
    password = db.Column(db.String(40), nullable=False)
    name = db.Column(db.String(40), nullable=False)
    age = db.Column(db.Integer)

app.config['SECRET_KEY'] = 'KEY'

@app.errorhandler(404)
def err404(err):
    return render_template('404.html', err=err)

@app.errorhandler(401)
def err401(err):
    return render_template('401.html', err=err)

@login_manager.user_loader
def load_user(uid):
    user = User.query.get(uid)
    return user

@app.route('/')
def home():
    if current_user.is_authenticated:
        return render_template('home.html', Logged=True)
    else:
        return render_template('home.html', Logged=False)

@app.route('/create', methods=['POST', 'GET'])
def create():
    if request.method == 'POST':
        name = request.form["name"]
        age = request.form["age"]
        username = request.form["username"]
        password = request.form["password"]

        user = User.query.filter_by(username=username).first()

        if user is not None:
            return render_template('create.html', errorMessage='ERROR: User already taken.', Logged=False)
        else:
            newEntry = User(name=name, age=age, username=username, password=password)
            db.session.add(newEntry)
            db.session.commit()
            login_user(newEntry)
            return redirect('/')

    else:
        return render_template('create.html', errorMessage='', Logged=False)

@app.route('/login', methods=['POST', 'GET'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        user = User.query.filter_by(username=username).first()

        if user is not None and user.password == password:
            login_user(user)
            return redirect('/')
        else:
            return render_template('login.html', errorMessage='ERROR: Invalid credentials.', Logged=False)
    else:
        return render_template('login.html', errorMessage='', Logged=False)

@app.route('/view_all')
@login_required
def viewAll():
    list = User.query.all()
    return render_template('viewAll.html', list=list, Logged=True)

@app.route('/update', methods=['POST', 'GET'])
@login_required
def update():
    if request.method == 'POST':
        oldPass = request.form["oldPass"]
        newPass = request.form["newPass"]

        if current_user.password == oldPass:
            current_user.password = newPass
            db.session.commit()
            return redirect('/')
        else:
            return render_template('update.html', errorMessage="ERROR: Current password invalid.", Logged=True)

    else:
        return render_template('update.html', errorMessage='', Logged=True)

@app.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect('/')

app.app_context().push()
if __name__ == "__main__":
    app.run()