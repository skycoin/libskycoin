# SwaggerClient::DefaultApi

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
> InlineResponse200 address_count

Returns the total number of unique address that have coins.

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

begin
  #Returns the total number of unique address that have coins.
  result = api_instance.address_count
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->address_count: #{e}"
end
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



# **coin_supply**
> coin_supply



coinSupplyHandler returns coin distribution supply stats

### Example
```ruby
# load the gem
require 'swagger_client'

api_instance = SwaggerClient::DefaultApi.new

begin
  api_instance.coin_supply
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->coin_supply: #{e}"
end
```

### Parameters
This endpoint does not need any parameter.

### Return type

nil (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **csrf**
> InlineResponse2001 csrf

Creates a new CSRF token. Previous CSRF tokens are invalidated by this call.

### Example
```ruby
# load the gem
require 'swagger_client'

api_instance = SwaggerClient::DefaultApi.new

begin
  #Creates a new CSRF token. Previous CSRF tokens are invalidated by this call.
  result = api_instance.csrf
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->csrf: #{e}"
end
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



# **default_connections**
> Array&lt;String&gt; default_connections

defaultConnectionsHandler returns the list of default hardcoded bootstrap addresses.\\n They are not necessarily connected to.

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

begin
  #defaultConnectionsHandler returns the list of default hardcoded bootstrap addresses.\\n They are not necessarily connected to.
  result = api_instance.default_connections
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->default_connections: #{e}"
end
```

### Parameters
This endpoint does not need any parameter.

### Return type

**Array&lt;String&gt;**

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **health**
> InlineResponse2002 health

Returns node health data.

### Example
```ruby
# load the gem
require 'swagger_client'

api_instance = SwaggerClient::DefaultApi.new

begin
  #Returns node health data.
  result = api_instance.health
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->health: #{e}"
end
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



# **network_connection**
> InlineResponse2003 network_connection(addr)

This endpoint returns a specific connection.

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

addr = "addr_example" # String | Address port


begin
  #This endpoint returns a specific connection.
  result = api_instance.network_connection(addr)
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->network_connection: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **addr** | **String**| Address port | 

### Return type

[**InlineResponse2003**](InlineResponse2003.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **network_connections**
> Array&lt;InlineResponse2003&gt; network_connections(opts)

This endpoint returns all outgoings connections.

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

opts = { 
  states: "states_example", # String | Connection status.
  direction: "direction_example" # String | Direction of the connection.
}

begin
  #This endpoint returns all outgoings connections.
  result = api_instance.network_connections(opts)
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->network_connections: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **states** | **String**| Connection status. | [optional] 
 **direction** | **String**| Direction of the connection. | [optional] 

### Return type

[**Array&lt;InlineResponse2003&gt;**](InlineResponse2003.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **network_connections_disconnect**
> network_connections_disconnect(id)



This endpoint disconnects a connection by ID or address

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

id = "id_example" # String | Address id.


begin
  api_instance.network_connections_disconnect(id)
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->network_connections_disconnect: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **String**| Address id. | 

### Return type

nil (empty response body)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **network_connections_exchange**
> Array&lt;String&gt; network_connections_exchange



This endpoint returns all connections found through peer exchange

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

begin
  result = api_instance.network_connections_exchange
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->network_connections_exchange: #{e}"
end
```

### Parameters
This endpoint does not need any parameter.

### Return type

**Array&lt;String&gt;**

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **network_connections_trust**
> Array&lt;String&gt; network_connections_trust

trustConnectionsHandler returns all trusted connections.\\n They are not necessarily connected to. In the default configuration, these will be a subset of the default hardcoded bootstrap addresses.

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

begin
  #trustConnectionsHandler returns all trusted connections.\\n They are not necessarily connected to. In the default configuration, these will be a subset of the default hardcoded bootstrap addresses.
  result = api_instance.network_connections_trust
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->network_connections_trust: #{e}"
end
```

### Parameters
This endpoint does not need any parameter.

### Return type

**Array&lt;String&gt;**

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **resend_unconfirmed_txns**
> resend_unconfirmed_txns



Broadcasts all unconfirmed transactions from the unconfirmed transaction pool

### Example
```ruby
# load the gem
require 'swagger_client'

api_instance = SwaggerClient::DefaultApi.new

begin
  api_instance.resend_unconfirmed_txns
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->resend_unconfirmed_txns: #{e}"
end
```

### Parameters
This endpoint does not need any parameter.

### Return type

nil (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json



# **verify_address**
> InlineResponse2009 verify_address(address)

healthHandler returns node health data.

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

address = "address_example" # String | Address id.


begin
  #healthHandler returns node health data.
  result = api_instance.verify_address(address)
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->verify_address: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **address** | **String**| Address id. | 

### Return type

[**InlineResponse2009**](InlineResponse2009.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **version**
> version



versionHandler returns the application version info

### Example
```ruby
# load the gem
require 'swagger_client'

api_instance = SwaggerClient::DefaultApi.new

begin
  api_instance.version
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->version: #{e}"
end
```

### Parameters
This endpoint does not need any parameter.

### Return type

nil (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **wallet**
> WalletMeta wallet(opts)

Returns a wallet by id.

### Example
```ruby
# load the gem
require 'swagger_client'

api_instance = SwaggerClient::DefaultApi.new

opts = { 
  id: "id_example" # String | tags to filter by
}

begin
  #Returns a wallet by id.
  result = api_instance.wallet(opts)
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->wallet: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **String**| tags to filter by | [optional] 

### Return type

[**WalletMeta**](WalletMeta.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **wallet_balance**
> InlineResponseDefault wallet_balance(id)

Returns the wallet's balance, both confirmed and predicted.  The predicted balance is the confirmed balance minus the pending spends.

### Example
```ruby
# load the gem
require 'swagger_client'

api_instance = SwaggerClient::DefaultApi.new

id = "id_example" # String | tags to filter by


begin
  #Returns the wallet's balance, both confirmed and predicted.  The predicted balance is the confirmed balance minus the pending spends.
  result = api_instance.wallet_balance(id)
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->wallet_balance: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **String**| tags to filter by | 

### Return type

[**InlineResponseDefault**](InlineResponseDefault.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **wallet_folder**
> InlineResponse2008 wallet_folder(addr)



Returns the wallet directory path

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

addr = "addr_example" # String | Address port


begin
  result = api_instance.wallet_folder(addr)
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->wallet_folder: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **addr** | **String**| Address port | 

### Return type

[**InlineResponse2008**](InlineResponse2008.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **wallet_new_address**
> InlineResponse2004 wallet_new_address(id, opts)



Generates new addresses

### Example
```ruby
# load the gem
require 'swagger_client'

api_instance = SwaggerClient::DefaultApi.new

id = "id_example" # String | Wallet Id

opts = { 
  num: "num_example", # String | The number you want to generate
  password: "password_example" # String | Wallet Password
}

begin
  result = api_instance.wallet_new_address(id, opts)
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->wallet_new_address: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **String**| Wallet Id | 
 **num** | **String**| The number you want to generate | [optional] 
 **password** | **String**| Wallet Password | [optional] 

### Return type

[**InlineResponse2004**](InlineResponse2004.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **wallet_new_seed**
> InlineResponse2005 wallet_new_seed(opts)



Returns the wallet directory path

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

opts = { 
  entropy: "entropy_example" # String | Entropy bitSize.
}

begin
  result = api_instance.wallet_new_seed(opts)
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->wallet_new_seed: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **entropy** | **String**| Entropy bitSize. | [optional] 

### Return type

[**InlineResponse2005**](InlineResponse2005.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **wallet_seed**
> InlineResponse2005 wallet_seed(id, password)

This endpoint only works for encrypted wallets. If the wallet is unencrypted, The seed will be not returned.

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

id = "id_example" # String | Wallet Id.

password = "password_example" # String | Wallet password.


begin
  #This endpoint only works for encrypted wallets. If the wallet is unencrypted, The seed will be not returned.
  result = api_instance.wallet_seed(id, password)
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->wallet_seed: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **String**| Wallet Id. | 
 **password** | **String**| Wallet password. | 

### Return type

[**InlineResponse2005**](InlineResponse2005.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **wallet_update**
> InlineResponse2006 wallet_update(id, label)

Update the wallet.

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

id = "id_example" # String | Wallet Id.

label = "label_example" # String | The label the wallet will be updated to.


begin
  #Update the wallet.
  result = api_instance.wallet_update(id, label)
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->wallet_update: #{e}"
end
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **String**| Wallet Id. | 
 **label** | **String**| The label the wallet will be updated to. | 

### Return type

[**InlineResponse2006**](InlineResponse2006.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



# **wallets**
> Array&lt;InlineResponse2007&gt; wallets



Returns all loaded wallets

### Example
```ruby
# load the gem
require 'swagger_client'
# setup authorization
SwaggerClient.configure do |config|
  # Configure API key authorization: csrfAuth
  config.api_key['csrf_Token'] = 'YOUR API KEY'
  # Uncomment the following line to set a prefix for the API key, e.g. 'Bearer' (defaults to nil)
  #config.api_key_prefix['csrf_Token'] = 'Bearer'
end

api_instance = SwaggerClient::DefaultApi.new

begin
  result = api_instance.wallets
  p result
rescue SwaggerClient::ApiError => e
  puts "Exception when calling DefaultApi->wallets: #{e}"
end
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**Array&lt;InlineResponse2007&gt;**](InlineResponse2007.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json



