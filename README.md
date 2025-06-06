# Buffer Overflow

This project provides a realistic, intentionally vulnerable backend written in C to demonstrate a classic stack-based buffer overflow vulnerability. The environment is designed for educational purposes, CTF training, and security research.

The application simulates a simple password manager where users are prompted to enter their username and password. Due to unsafe buffer handling in the backend, it is possible to exploit this vulnerability and trigger hidden functionality (such as spawning a shell or capturing a flag at `/flag.txt`). This hands-on scenario is inspired by real-world CTF challenges and legacy software bugs.

## How to Run

Make sure you have Docker installed on your system.

1. Clone this repository and navigate into the project directory:

   ```bash
   git clone https://github.com/yourusername/Buffer-Overflow.git
   cd Buffer-Overflow
   ```

2. Build the Docker image:

   ```bash
   docker build -t buffer-overflow-lab .
   ```

3. Run the Docker container:

   ```bash
   docker run --rm -it -p 8080:8080 buffer-overflow-lab
   ```

4. Open a new terminal window and connect to the application using netcat:

   ```bash
   nc localhost 8080
   ```

You will see a welcome banner and a prompt asking for a username and password. The login process is intentionally vulnerable and allows you to test exploitation techniques such as buffer overflow.

## Example Interaction

```
=== Welcome to Buffer Overflow Demo ===
This is a simple password manager.
For demo purposes, use the credentials: admin / admin123

Username:
```

## Project Structure

- `source.c`: Vulnerable C backend.
- `flag.txt`: The flag you need to capture.
- `index.html` and `styles.css`: Optional front-end visuals (not used by the backend, but included for reference).
- `Dockerfile`: Container build instructions.
- `README.md`: This file.

## Disclaimer

This project is intended for educational use only. **Do NOT deploy this application in production.** It contains intentional vulnerabilities designed for learning and demonstration.

Good luck and happy hacking!
