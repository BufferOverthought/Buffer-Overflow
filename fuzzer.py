import requests

url = "http://localhost:5000/"
with open("wordlist.txt") as f:
    for line in f:
        payload = line.strip()
        try:
            r = requests.post(url, data={"username": payload}, timeout=2)
            if r.status_code != 200 or "Login processed" not in r.text:
                print(f"[!] Possible crash or abnormal behavior! Payload: {payload}\nStatus: {r.status_code}\nResponse: {r.text}")
            else:
                print(f"Tested: {payload}")
        except Exception as e:
            print(f"[!] No response / crash detected! Payload: {payload} Exception: {e}")
