# Buffer Overflow Visual Lab

This project simulates a realistic buffer overflow vulnerability in a web application, combining a Flask frontend with a vulnerable C backend function. The objective is to detect the overflow by fuzzing and then exploit it to achieve remote code execution (RCE) for educational purposes.

---

## How it works

- Access the application via your browser (`http://localhost:5000/`) once the container is running.
- The web form posts the input to the backend, which passes it directly to a vulnerable C function (`check_input`).
- If the input exceeds the buffer, the application may crash or behave abnormally.
- A carefully crafted exploit can trigger the `secret_shell` function, spawning a shell in the container.

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

4. Run the fuzzer (optional):

    In a separate terminal (with the container running):

    ```bash
    pip install requests
    python fuzzer.py
    ```

    The fuzzer will help you detect which payloads cause a crash or abnormal behavior.

5. Exploitation:

    - Craft an exploit (manual or with tools like pwntools) to take control of program execution and spawn a shell.
    - Once you get a shell, run `whoami` and `cat flag.txt` inside the container to complete the lab.

---

## Files

- `app.py` – Flask web backend
- `vuln.c` – Vulnerable C code
- `templates/index.html` – HTML frontend
- `static/style.css` – CSS for the frontend
- `requirements.txt` – Python requirements
- `wordlist.txt` – Example payloads for fuzzing
- `fuzzer.py` – Automated fuzzing script
- `exploit.py` – (Placeholder) exploit script
- `flag.txt` – The flag to capture
- `Dockerfile` – Container configuration

---

## Disclaimer

This project is for educational use only. **Do NOT deploy in production.** It is intentionally vulnerable.

---

Good luck and happy hacking!
