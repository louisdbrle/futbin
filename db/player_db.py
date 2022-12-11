# extract db from api

import json
import requests
import pandas as pd


def get_db(url, token):
    headers = {'accept': 'application/json', 'X-Auth-Token': token}
    r = requests.get(url, headers=headers)
    data = json.loads(r.text)
    if r.status_code == 200:
        with open('db/player_db.json', 'w') as f:
            data = data["items"]
            for item in data:
                if item["position"] == "GK":
                    item["pace"] = item["goalkeeperAttributes"]["diving"]
                    item["shooting"] = item["goalkeeperAttributes"]["handling"]
                    item["passing"] = item["goalkeeperAttributes"]["kicking"]
                    item["dribbling"] = item["goalkeeperAttributes"]["positioning"]
                    item["defending"] = item["goalkeeperAttributes"]["reflexes"]

                del item["goalkeeperAttributes"]
                del item["physicalityAttributes"]
                del item["defendingAttributes"]
                del item["dribblingAttributes"]
                del item["passingAttributes"]
                del item["shootingAttributes"]
                del item["paceAttributes"]
                del item["ratingAverage"]
                del item["color"]
                del item["totalStatsInGame"]
                del item["totalStats"]
                del item["defenseWorkRate"]
                del item["attackWorkRate"]
                del item["foot"]
                del item["weakFoot"]
                del item["skillMoves"]
                del item["specialities"]
                del item["traits"]
                del item["rarity"]
                del item["club"]
                del item["league"]
                del item["age"]
                del item["birthDate"]
                del item["weight"]
                del item["height"]
                del item["name"]
                del item["lastName"]
                del item["firstName"]
                del item["futWizId"]
                del item["futBinId"]
                del item["resourceBaseId"]
                del item["resourceId"]
                del item["id"]

            for item in data:
                if item["commonName"] == "":
                    data.remove(item)

            json.dump(data, f)


def export_db(path_to_file):
    df = pd.read_json(path_to_file)
    df.to_csv('db/player_db.csv', index=False)


if __name__ == '__main__':
    url = 'https://futdb.app/api/players?page=1'
    token = "4dbfc4e6-4236-4999-9746-a655c40c0a29"
    get_db(url, token)
    export_db('db/player_db.json')
