# extract db from api

import json
import requests
import pandas as pd


def get_db(url, token):
    headers = {'accept': 'application/json', 'X-Auth-Token': token}
    r = requests.get(url, headers=headers)
    data = json.loads(r.text)
    out = []
    if r.status_code == 200:
        with open('db/nation_db.json', 'r') as f:
            nations = json.load(f)

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
            del item["lastName"]
            del item["firstName"]
            del item["futWizId"]
            del item["futBinId"]
            del item["resourceBaseId"]
            del item["resourceId"]

            for nation in nations:
                if item["nation"] == nation["id"]:
                    item["nation"] = nation["name"]

            if type(item["nation"]) == str and item["commonName"] != "":
                out.append(item)

    return out


if __name__ == '__main__':
    url = 'https://futdb.app/api/players?page='
    token = "a61b1f6f-35b6-4615-9636-07e9864ec647"
    players = []

    # for i in range(1, 850):
    #    players += get_db(url + str(i), token)

    with open('db/players.csv', 'r') as f:
        df = pd.read_csv(f)
        names = list(df.columns)

    with open('db/player_db.json', 'r') as f:
        players = json.load(f)

    clean = []

    for player in players:
        if player["name"] in names:
            clean.append(player)
        elif player["commonName"] in names:
            clean.append(player)

    # with open('db/player_db.json', 'w') as f:
    #     json.dump(players, f)

    with open('db/clean_player_db.json', 'w') as f:
        json.dump(clean, f)
