import requests
import json


class ToDo(object):

    def __init__(self, id):
        self.id = id
        self.completed = []
        self.uncompleted = []

    def __repr__(self):
        return json.dumps(self.__dict__, indent=4, separators=(',',':'))


def jsonParser(url):
    #url = 'https://jsonplaceholder.typicode.com/todos'
    response = requests.get(url)
    response_json = response.json()

    user_dict = {}

    for i in range(len(response_json)):
        id = response_json[i]['userId']

        if id not in user_dict:
            user_dict[id] = ToDo(id)
        
        task = response_json[i]['title']

        if response_json[i]['completed'] == True:
            user_dict[id].completed.append(task)
        else:
            user_dict[id].uncompleted.append(task)
    
    return [x for x in user_dict.values()]