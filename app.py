from flask import Flask, render_template, request
import ctypes

app = Flask(__name__)

lib = ctypes.CDLL('./libvuln.so')
lib.check_input.argtypes = [ctypes.c_char_p]
lib.check_input.restype = ctypes.c_char_p

@app.route('/', methods=['GET', 'POST'])
def index():
    result = ""
    if request.method == 'POST':
        user_input = request.form['username']
        try:
            res = lib.check_input(user_input.encode('utf-8'))
            result = res.decode()
        except Exception:
            # If C code crashes, show a real error 500
            return "Internal Server Error", 500
    return render_template('index.html', result=result)

if __name__ == '__main__':
    app.run(host='0.0.0.0')
