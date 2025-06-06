# Buffer Overflow Visual Lab

This project simulates a realistic buffer overflow vulnerability in a web application, combining a Flask frontend with a vulnerable C backend function. The objective is to detect the overflow by fuzzing, identify the payload that triggers a crash (error 500), and then "exploit" it to simulate remote code execution (RCE) and capture a flag — just like in a real-world CTF or bug bounty scenario.

---

## How it works

- Access the application via your browser (`http://localhost:5000/`) once the container is running.
- The web form posts the input to the backend, which passes it directly to a vulnerable C function (`check_input`).
- Using the provided `fuzzer.py` and `wordlist.txt`, you will discover which input payload causes the application to crash (i.e., returns HTTP 500 Internal Server Error).
- The browser **never** reveals the flag or shell — only a crash.
- With the correct payload, use `exploit.py` to simulate the RCE: the script will recognize the crash and show you the contents of `flag.txt` as if you had gained a shell.
- **After each crash, you must restart the Docker container to continue testing or exploiting!**

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

    > If port 5000 is busy, you can use another, e.g. `-p 5001:5000` and access the lab at [http://localhost:5001/](http://localhost:5001/)

3. Access the lab in your browser:

    - Go to [http://localhost:5000/](http://localhost:5000/) or your chosen port.

4. Run the fuzzer:

    In a separate terminal (with the container running):

    ```bash
    pip install requests
    python fuzzer.py
    ```

    The fuzzer will show which payload (from `wordlist.txt`) crashes the server (status code 500).

5. Exploitation:

    - Use `exploit.py` to send the discovered crash payload.
    - The script will simulate the effect of a successful exploit by revealing the flag.

6. **IMPORTANT:**  
   After every crash (error 500), **restart the Docker container** before running more fuzzing or exploiting.

---

## Files

- `app.py` – Flask web backend
- `vuln.c` – Vulnerable C code (crashes on overflow payload)
- `templates/index.html` – HTML frontend
- `static/style.css` – CSS for the frontend
- `requirements.txt` – Python requirements
- `wordlist.txt` – Example payloads for fuzzing
- `fuzzer.py` – Automated fuzzing script (shows which payload causes crash)
- `exploit.py` – Automated exploit that simulates RCE and reveals the flag upon crash detection
- `flag.txt` – The flag to capture
- `Dockerfile` – Container configuration

---

## Disclaimer

This project is for educational use only. **Do NOT deploy in production.** It is intentionally vulnerable.

---

Good luck and happy hacking!
