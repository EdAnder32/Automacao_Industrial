from flask import Flask, render_template, jsonify, request
import serial

app = Flask(__name__)
arduino = serial.Serial('COM27', 9600, timeout=1)

@app.route("/")
def botao():
    return render_template("index.html")

@app.route("/toggle_led", methods=['POST'])
def toggle_led():
    command = request.get_data().decode('utf-8')
    arduino.write(command.encode())
    return jsonify({'status': 'success', 'command': command})

if __name__ == "__main__":
    app.run()
