# extract db from api

import json
import requests
import pandas as pd


def get_db(url, token):
    headers = {"accept": "application/json", "X-Auth-Token": token}
    r = requests.get(url, headers=headers)
    data = json.loads(r.text)
    if r.status_code == 200:
        return data["items"]


if __name__ == "__main__":
    qualified = ["Netherlands", "United States", "Argentina",
                 "Australia", "Japan", "Croatia", "Brazil", "Korea Republic", "England", "Senegal", "France", "Poland", "Morocco", "Spain", "Portugal", "Switzerland"]

    url = "https://futdb.app/api/nations?page="
    token = "4dbfc4e6-4236-4999-9746-a655c40c0a29"

    nations = []
    for i in range(1, 9):
        nations += get_db(url+str(i), token)

    nations = [nation for nation in nations if nation["name"] in qualified]

    with open("db/nation_db.json", 'w') as f:
        json.dump(nations, f)
