from flask import Flask, render_template, request

app = Flask(__name__)


#request.args.get get args via url like ?name=David
#name will subtitude {{ name }} in html file
@app.route("/")
def index():
    return render_template("index.html", name=request.args.get("name", "world"), lname="cyl")
