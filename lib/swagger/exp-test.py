# exp-test.py
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.DefaultApi()

try:
    # Get list of exposure types
    api_response = api_instance.version()
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->exposures_get: %s\n" % e)
 
