import unittest
import JSON_parser
import json


class JSONTestUnit(unittest.TestCase):

    def testJSONParser1(self):
        input_url = 'https://jsonplaceholder.typicode.com/todos'
        input_path_to_file = 'python/JSON_parser/output_true.json'
        self.assertTrue(testChecker(input_url, input_path_to_file))
    
    def testJSONParser2(self):
        input_url = 'https://jsonplaceholder.typicode.com/todos'
        input_path_to_file = 'python/JSON_parser/output_false.json'
        # isti kao output_true.json samo sto je u completed listi za "user_id" : 1
        # promijenjena zadnja recenica
        
        self.assertFalse(testChecker(input_url, input_path_to_file))

        
def testChecker(url, path_to_file):
    output_list = JSON_parser.jsonParser(url)
    ref_list = []

    with open(path_to_file,'r') as ref_file:
        ref_list = json.load(ref_file)
        ref_file.close()
        
    for i in range(len(ref_list)):
        id = ref_list[i]['user_id']

        for j in range(len(output_list)):
            if id == output_list[j].id:

                for k in ref_list[i]['completed_tasks']:
                    if k not in output_list[j].completed:
                        return False
                    
                for k in ref_list[i]['uncompleted_tasks']:
                    if k not in output_list[j].uncompleted:
                        return False
    return True


if __name__ == "__main__":
    unittest.main()
