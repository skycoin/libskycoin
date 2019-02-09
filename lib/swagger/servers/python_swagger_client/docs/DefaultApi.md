# swagger_client.DefaultApi

All URIs are relative to *http://staging.node.skycoin.net*

Method | HTTP request | Description
------------- | ------------- | -------------
[**address_count**](DefaultApi.md#address_count) | **GET** /api/v1/addresscount | Returns the total number of unique address that have coins.
[**coin_supply**](DefaultApi.md#coin_supply) | **GET** /api/v1/coinSupply | 
[**csrf**](DefaultApi.md#csrf) | **GET** /api/v1/csrf | Creates a new CSRF token. Previous CSRF tokens are invalidated by this call.
[**default_connections**](DefaultApi.md#default_connections) | **GET** /api/v1/network/defaultConnections | defaultConnectionsHandler returns the list of default hardcoded bootstrap addresses.\\n They are not necessarily connected to.
[**health**](DefaultApi.md#health) | **GET** /api/v1/health | Returns node health data.
[**network_connection**](DefaultApi.md#network_connection) | **GET** /api/v1/network/connection | This endpoint returns a specific connection.
[**network_connections**](DefaultApi.md#network_connections) | **GET** /api/v1/network/connections | This endpoint returns all outgoings connections.
[**network_connections_disconnect**](DefaultApi.md#network_connections_disconnect) | **GET** /api/v1/network/connection/disconnect | 
[**network_connections_exchange**](DefaultApi.md#network_connections_exchange) | **GET** /api/v1/network/connections/exchange | 
[**network_connections_trust**](DefaultApi.md#network_connections_trust) | **GET** /api/v1/network/connections/trust | trustConnectionsHandler returns all trusted connections.\\n They are not necessarily connected to. In the default configuration, these will be a subset of the default hardcoded bootstrap addresses.
[**resend_unconfirmed_txns**](DefaultApi.md#resend_unconfirmed_txns) | **POST** /api/v1/resendUnconfirmedTxns | 
[**verify_address**](DefaultApi.md#verify_address) | **POST** /api/v2/address/verify | healthHandler returns node health data.
[**version**](DefaultApi.md#version) | **GET** /api/v1/version | 
[**wallet**](DefaultApi.md#wallet) | **GET** /api/v1/wallet | Returns a wallet by id.
[**wallet_balance**](DefaultApi.md#wallet_balance) | **GET** /api/v1/wallet/balance | Returns the wallet&#39;s balance, both confirmed and predicted.  The predicted balance is the confirmed balance minus the pending spends.
[**wallet_folder**](DefaultApi.md#wallet_folder) | **GET** /api/v1/wallets/folderName | 
[**wallet_new_address**](DefaultApi.md#wallet_new_address) | **POST** /api/v1/wallet/newAddress | 
[**wallet_new_seed**](DefaultApi.md#wallet_new_seed) | **GET** /api/v1/wallet/newSeed | 
[**wallet_seed**](DefaultApi.md#wallet_seed) | **POST** /api/v1/wallet/seed | This endpoint only works for encrypted wallets. If the wallet is unencrypted, The seed will be not returned.
[**wallet_update**](DefaultApi.md#wallet_update) | **POST** /api/v1/wallet/update | Update the wallet.
[**wallets**](DefaultApi.md#wallets) | **GET** /api/v1/wallets | 


# **address_count**
> InlineResponse200 address_count()

Returns the total number of unique address that have coins.

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))

try:
    # Returns the total number of unique address that have coins.
    api_response = api_instance.address_count()
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->address_count: %s\n" % e)
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**InlineResponse200**](InlineResponse200.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **coin_supply**
> coin_supply()



coinSupplyHandler returns coin distribution supply stats

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.DefaultApi()

try:
    api_instance.coin_supply()
except ApiException as e:
    print("Exception when calling DefaultApi->coin_supply: %s\n" % e)
```

### Parameters
This endpoint does not need any parameter.

### Return type

void (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **csrf**
> InlineResponse2001 csrf()

Creates a new CSRF token. Previous CSRF tokens are invalidated by this call.

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.DefaultApi()

try:
    # Creates a new CSRF token. Previous CSRF tokens are invalidated by this call.
    api_response = api_instance.csrf()
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->csrf: %s\n" % e)
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**InlineResponse2001**](InlineResponse2001.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **default_connections**
> list[str] default_connections()

defaultConnectionsHandler returns the list of default hardcoded bootstrap addresses.\\n They are not necessarily connected to.

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))

try:
    # defaultConnectionsHandler returns the list of default hardcoded bootstrap addresses.\\n They are not necessarily connected to.
    api_response = api_instance.default_connections()
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->default_connections: %s\n" % e)
```

### Parameters
This endpoint does not need any parameter.

### Return type

**list[str]**

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **health**
> InlineResponse2002 health()

Returns node health data.

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.DefaultApi()

try:
    # Returns node health data.
    api_response = api_instance.health()
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->health: %s\n" % e)
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**InlineResponse2002**](InlineResponse2002.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **network_connection**
> InlineResponse2003 network_connection(addr)

This endpoint returns a specific connection.

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))
addr = 'addr_example' # str | Address port

try:
    # This endpoint returns a specific connection.
    api_response = api_instance.network_connection(addr)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->network_connection: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **addr** | **str**| Address port | 

### Return type

[**InlineResponse2003**](InlineResponse2003.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **network_connections**
> list[InlineResponse2003] network_connections(states=states, direction=direction)

This endpoint returns all outgoings connections.

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))
states = 'states_example' # str | Connection status. (optional)
direction = 'direction_example' # str | Direction of the connection. (optional)

try:
    # This endpoint returns all outgoings connections.
    api_response = api_instance.network_connections(states=states, direction=direction)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->network_connections: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **states** | **str**| Connection status. | [optional] 
 **direction** | **str**| Direction of the connection. | [optional] 

### Return type

[**list[InlineResponse2003]**](InlineResponse2003.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **network_connections_disconnect**
> network_connections_disconnect(id)



This endpoint disconnects a connection by ID or address

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))
id = 'id_example' # str | Address id.

try:
    api_instance.network_connections_disconnect(id)
except ApiException as e:
    print("Exception when calling DefaultApi->network_connections_disconnect: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **str**| Address id. | 

### Return type

void (empty response body)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **network_connections_exchange**
> list[str] network_connections_exchange()



This endpoint returns all connections found through peer exchange

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))

try:
    api_response = api_instance.network_connections_exchange()
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->network_connections_exchange: %s\n" % e)
```

### Parameters
This endpoint does not need any parameter.

### Return type

**list[str]**

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **network_connections_trust**
> list[str] network_connections_trust()

trustConnectionsHandler returns all trusted connections.\\n They are not necessarily connected to. In the default configuration, these will be a subset of the default hardcoded bootstrap addresses.

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))

try:
    # trustConnectionsHandler returns all trusted connections.\\n They are not necessarily connected to. In the default configuration, these will be a subset of the default hardcoded bootstrap addresses.
    api_response = api_instance.network_connections_trust()
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->network_connections_trust: %s\n" % e)
```

### Parameters
This endpoint does not need any parameter.

### Return type

**list[str]**

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **resend_unconfirmed_txns**
> resend_unconfirmed_txns()



Broadcasts all unconfirmed transactions from the unconfirmed transaction pool

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.DefaultApi()

try:
    api_instance.resend_unconfirmed_txns()
except ApiException as e:
    print("Exception when calling DefaultApi->resend_unconfirmed_txns: %s\n" % e)
```

### Parameters
This endpoint does not need any parameter.

### Return type

void (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **verify_address**
> InlineResponse2009 verify_address(address)

healthHandler returns node health data.

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))
address = 'address_example' # str | Address id.

try:
    # healthHandler returns node health data.
    api_response = api_instance.verify_address(address)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->verify_address: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **address** | **str**| Address id. | 

### Return type

[**InlineResponse2009**](InlineResponse2009.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **version**
> version()



versionHandler returns the application version info

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.DefaultApi()

try:
    api_instance.version()
except ApiException as e:
    print("Exception when calling DefaultApi->version: %s\n" % e)
```

### Parameters
This endpoint does not need any parameter.

### Return type

void (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **wallet**
> WalletMeta wallet(id=id)

Returns a wallet by id.

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.DefaultApi()
id = 'id_example' # str | tags to filter by (optional)

try:
    # Returns a wallet by id.
    api_response = api_instance.wallet(id=id)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->wallet: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **str**| tags to filter by | [optional] 

### Return type

[**WalletMeta**](WalletMeta.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **wallet_balance**
> InlineResponseDefault wallet_balance(id)

Returns the wallet's balance, both confirmed and predicted.  The predicted balance is the confirmed balance minus the pending spends.

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.DefaultApi()
id = 'id_example' # str | tags to filter by

try:
    # Returns the wallet's balance, both confirmed and predicted.  The predicted balance is the confirmed balance minus the pending spends.
    api_response = api_instance.wallet_balance(id)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->wallet_balance: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **str**| tags to filter by | 

### Return type

[**InlineResponseDefault**](InlineResponseDefault.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **wallet_folder**
> InlineResponse2008 wallet_folder(addr)



Returns the wallet directory path

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))
addr = 'addr_example' # str | Address port

try:
    api_response = api_instance.wallet_folder(addr)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->wallet_folder: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **addr** | **str**| Address port | 

### Return type

[**InlineResponse2008**](InlineResponse2008.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **wallet_new_address**
> InlineResponse2004 wallet_new_address(id, num=num, password=password)



Generates new addresses

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# create an instance of the API class
api_instance = swagger_client.DefaultApi()
id = 'id_example' # str | Wallet Id
num = 'num_example' # str | The number you want to generate (optional)
password = 'password_example' # str | Wallet Password (optional)

try:
    api_response = api_instance.wallet_new_address(id, num=num, password=password)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->wallet_new_address: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **str**| Wallet Id | 
 **num** | **str**| The number you want to generate | [optional] 
 **password** | **str**| Wallet Password | [optional] 

### Return type

[**InlineResponse2004**](InlineResponse2004.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **wallet_new_seed**
> InlineResponse2005 wallet_new_seed(entropy=entropy)



Returns the wallet directory path

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))
entropy = 'entropy_example' # str | Entropy bitSize. (optional)

try:
    api_response = api_instance.wallet_new_seed(entropy=entropy)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->wallet_new_seed: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **entropy** | **str**| Entropy bitSize. | [optional] 

### Return type

[**InlineResponse2005**](InlineResponse2005.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **wallet_seed**
> InlineResponse2005 wallet_seed(id, password)

This endpoint only works for encrypted wallets. If the wallet is unencrypted, The seed will be not returned.

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))
id = 'id_example' # str | Wallet Id.
password = 'password_example' # str | Wallet password.

try:
    # This endpoint only works for encrypted wallets. If the wallet is unencrypted, The seed will be not returned.
    api_response = api_instance.wallet_seed(id, password)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->wallet_seed: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **str**| Wallet Id. | 
 **password** | **str**| Wallet password. | 

### Return type

[**InlineResponse2005**](InlineResponse2005.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **wallet_update**
> InlineResponse2006 wallet_update(id, label)

Update the wallet.

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))
id = 'id_example' # str | Wallet Id.
label = 'label_example' # str | The label the wallet will be updated to.

try:
    # Update the wallet.
    api_response = api_instance.wallet_update(id, label)
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->wallet_update: %s\n" % e)
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **str**| Wallet Id. | 
 **label** | **str**| The label the wallet will be updated to. | 

### Return type

[**InlineResponse2006**](InlineResponse2006.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **wallets**
> list[InlineResponse2007] wallets()



Returns all loaded wallets

### Example
```python
from __future__ import print_function
import time
import swagger_client
from swagger_client.rest import ApiException
from pprint import pprint

# Configure API key authorization: csrfAuth
configuration = swagger_client.Configuration()
configuration.api_key['csrf_Token'] = 'YOUR_API_KEY'
# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['csrf_Token'] = 'Bearer'

# create an instance of the API class
api_instance = swagger_client.DefaultApi(swagger_client.ApiClient(configuration))

try:
    api_response = api_instance.wallets()
    pprint(api_response)
except ApiException as e:
    print("Exception when calling DefaultApi->wallets: %s\n" % e)
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**list[InlineResponse2007]**](InlineResponse2007.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

