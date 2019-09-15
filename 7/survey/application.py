import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    name=request.form.get("name")
    house=request.form.get("house")
    position=request.form.get("position")
    if not name or not house or not position:
        print("error")
        return render_template("error.html")
    with open("survey.csv","a") as file:
        csvWrite=csv.DictWriter(file,fieldnames=["name","house","position"])
        csvWrite.writerow({"name":name,"house":house,"position":position})
    return get_sheet()


@app.route("/sheet", methods=["GET"])
def get_sheet():
    tableContent=[]
    with open("survey.csv","r") as file:
        csReader=csv.DictReader(file,fieldnames=["name","house","position"])
        for row in csReader:
            newrow=[row['name'],row['house'],row['position']]
            tableContent.append(newrow)

    return render_template("sheet.html",tableContent=tableContent)
    return render_template("error.html", message="TODO")
