from flask import Flask, render_template, request
import ctypes

app = Flask(__name__)

# Load the C shared library
lib = ctypes.CDLL('./libvuln.so')
lib.check_input.argtypes = [ctypes.c_char_p]
lib.check_input.restype = None

@app.route('/', methods=['GET', 'POST'])
def index():
    result = ""
    if request.method == 'POST':
        user_input = request.form['username']
        try:
            # Pass the user input to the vulnerable C function
            lib.check_input(user_input.encode('utf-8'))
            result = "Login processed (no errors detected)."
        except Exception:
            # If the C code crashes, this will likely never be reached,
            # but kept here for completeness
            result = "Application error."
    return render_template('index.html', result=result)

if __name__ == '__main__':
    app.run(host='0.0.0.0')
