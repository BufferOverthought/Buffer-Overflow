# Buffer Overflow Visual Lab

This project simulates a realistic buffer overflow vulnerability in a web application, combining a Flask frontend with a vulnerable C backend function. The objective is to detect the overflow by fuzzing and then exploit it to achieve remote code execution (RCE) for educational purposes.

---

## How it works

- Access the application via your browser (`http://localhost:5000/`) once the container is running.
- The web form posts the input to the backend, which passes it directly to a vulnerable C function (`check_input`).
- Using the provided `fuzzer.py` and `wordlist.txt`, you will discover which input payload triggers abnormal behavior—a simulated crash or a simulated shell.
- A carefully crafted exploit (e.g., using the payload revealed by the fuzzer) will simulate an RCE, returning the result of commands like `whoami` and `cat flag.txt` as if you had gained a shell.

---

## How to run

1. Build the Docker image:

    ```bash
    docker build -t buffer-overflow-lab .
    ```

2. Run the Docker container:

    ```bash
    docker run --rm -it -p 5000:5000 buffer-overflow-lab
    ```

3. Access the lab in your browser:

    - Go to [http://localhost:5000/](http://localhost:5000/)

4. Run the fuzzer:

    In a separate terminal (with the container running):

    ```bash
    pip install requests
    python fuzzer.py
    ```

    The fuzzer will help you detect which payload causes the simulated overflow and “shell.”

5. Exploitation:

    - Use `exploit.py` to send the correct payload and capture the simulated shell output, including the contents of `flag.txt`.

---

## Files

- `app.py` – Flask web backend
- `vuln.c` – Vulnerable C code (returns a shell simulation with flag on overflow)
- `templates/index.html` – HTML frontend
- `static/style.css` – CSS for the frontend
- `requirements.txt` – Python requirements
- `wordlist.txt` – Example payloads for fuzzing
- `fuzzer.py` – Automated fuzzing script
- `exploit.py` – Automated exploit to simulate RCE and reveal the flag
- `flag.txt` – The flag to capture
- `Dockerfile` – Container configuration

---

## Disclaimer

This project is for educational use only. **Do NOT deploy in production.** It is intentionally vulnerable.

---

Good luck and happy hacking!
