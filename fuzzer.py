import requests

url = "http://localhost:5001/" 
with open("wordlist.txt") as f:
    for line in f:
        payload = line.strip()
        try:
            r = requests.post(url, data={"username": payload}, timeout=2)
            if r.status_code == 500:
                print(f"[!] CRASH! Payload: {payload} | Status: {r.status_code}")
            else:
                print(f"Tested: {payload} | Status: {r.status_code}")
        except Exception as e:
            print(f"[!] Exception or No response for Payload: {payload} | Error: {e}")
