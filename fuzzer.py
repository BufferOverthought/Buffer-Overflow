import requests

url = "http://localhost:5000/"
with open("wordlist.txt") as f:
    for line in f:
        payload = line.strip()
        r = requests.post(url, data={"username": payload})
        if "Simulated shell" in r.text:
            print(f"[!] Potential exploit found! Payload: {payload}\nResponse:\n{r.text}")
        else:
            print(f"Tested: {payload}")
