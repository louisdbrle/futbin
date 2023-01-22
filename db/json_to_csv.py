import json
import csv

# Open the JSON file
with open("db/clean_player_db.json", 'r') as json_file:
    json_data = json.load(json_file)

# Open the CSV file
with open("db/clean_player_db.csv", 'w') as csv_file:
    csv_writer = csv.writer(csv_file)

    # Write the headers
    csv_writer.writerow(json_data[0].keys())

    # Write the data
    for row in json_data:
        csv_writer.writerow(row.values())
