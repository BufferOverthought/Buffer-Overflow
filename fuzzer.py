import requests

# ANSI color codes
RED    = "\033[91m"
GREEN  = "\033[92m"
YELLOW = "\033[93m"
CYAN   = "\033[96m"
RESET  = "\033[0m"
BOLD   = "\033[1m"

url = "http://localhost:5001/"
with open("wordlist.txt") as f:
    for line in f:
        payload = line.strip()
        try:
            r = requests.post(url, data={"username": payload}, timeout=2)
            if r.status_code == 500:
                print(f"{BOLD}{RED}[!] CRASH!{RESET} Payload: {YELLOW}{payload}{RESET} | Status: {RED}{r.status_code}{RESET}")
                break  # Stop on first crash (optional)
            else:
                print(f"{CYAN}Tested:{RESET} {payload} | Status: {GREEN}{r.status_code}{RESET}")
        except Exception as e:
            print(f"{BOLD}{RED}[!] Exception or No response{RESET} for Payload: {YELLOW}{payload}{RESET} | Error: {e}")
