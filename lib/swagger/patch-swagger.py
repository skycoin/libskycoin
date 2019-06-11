import argparse
import json
import os
import yaml


def change_json(args):
    with open(args.file, "r") as jsonFile:
        data = json.load(jsonFile)

    if 'host' in data:
        data['host'] = args.node
    else:
        print('file not contains \'host\' field')
        return

    with open(args.file, "w") as jsonFile:
        json.dump(data, jsonFile)


def change_yaml(args):
    with open(args.file) as yamlFile:
        list_doc = yaml.load(yamlFile)

    # for fields in list_doc:
    if 'host' in list_doc:
        list_doc["host"] = args.node
    else:
        print('file not contains \'host\' field')
        return

    with open(args.file, "w") as yamlFile:
        yaml.dump(list_doc, yamlFile)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-n", "--node", help="Specific Node Address")
    parser.add_argument("-f", "--file", help="Swagger Specification")
    args = parser.parse_args()
    print(args)

    if args.node and args.file:
        if os.path.isfile(args.file):
            if args.file[len(args.file)-4:] == '.yml':
                print("Updating swagger specification in yaml")
                change_yaml(args)
            elif args.file[len(args.file)-5:] == '.json':
                print("Updating swagger specification in json")
                change_json(args)
            else:
                print('unknown file extension, use a .yml or .json file')
                print('example: \'./swagger.yml\'')

        else:
            print('set correct directory files')
    elif args.node:
        print('set a correct swagger spec')
    else:
        print('set a specific node address')


main()
