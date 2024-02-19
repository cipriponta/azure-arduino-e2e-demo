import json
from flask import Flask, request, Response, session, render_template

app = Flask(__name__)
app.secret_key="SECRET_KEY"

global led_state
led_state = "OFF"

@app.route("/")
def main_page():
    global led_state
    print(led_state)
    return render_template('index.html', led_state=led_state)

@app.route("/get", methods=['GET'])
def get_method():
    global led_state
    print(led_state)
    return led_state

@app.route("/post", methods=['POST'])
def post_method():
    global led_state
    led_state = request.data.decode("utf-8")
    return Response(status=204)

