# IO.Swagger.Api.DefaultApi

All URIs are relative to *http://staging.node.skycoin.net*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AddressCount**](DefaultApi.md#addresscount) | **GET** /api/v1/addresscount | Returns the total number of unique address that have coins.
[**CoinSupply**](DefaultApi.md#coinsupply) | **GET** /api/v1/coinSupply | 
[**Csrf**](DefaultApi.md#csrf) | **GET** /api/v1/csrf | Creates a new CSRF token. Previous CSRF tokens are invalidated by this call.
[**DefaultConnections**](DefaultApi.md#defaultconnections) | **GET** /api/v1/network/defaultConnections | defaultConnectionsHandler returns the list of default hardcoded bootstrap addresses.\\n They are not necessarily connected to.
[**Health**](DefaultApi.md#health) | **GET** /api/v1/health | Returns node health data.
[**NetworkConnection**](DefaultApi.md#networkconnection) | **GET** /api/v1/network/connection | This endpoint returns a specific connection.
[**NetworkConnections**](DefaultApi.md#networkconnections) | **GET** /api/v1/network/connections | This endpoint returns all outgoings connections.
[**NetworkConnectionsDisconnect**](DefaultApi.md#networkconnectionsdisconnect) | **GET** /api/v1/network/connection/disconnect | 
[**NetworkConnectionsExchange**](DefaultApi.md#networkconnectionsexchange) | **GET** /api/v1/network/connections/exchange | 
[**NetworkConnectionsTrust**](DefaultApi.md#networkconnectionstrust) | **GET** /api/v1/network/connections/trust | trustConnectionsHandler returns all trusted connections.\\n They are not necessarily connected to. In the default configuration, these will be a subset of the default hardcoded bootstrap addresses.
[**ResendUnconfirmedTxns**](DefaultApi.md#resendunconfirmedtxns) | **POST** /api/v1/resendUnconfirmedTxns | 
[**VerifyAddress**](DefaultApi.md#verifyaddress) | **POST** /api/v2/address/verify | healthHandler returns node health data.
[**Version**](DefaultApi.md#version) | **GET** /api/v1/version | 
[**Wallet**](DefaultApi.md#wallet) | **GET** /api/v1/wallet | Returns a wallet by id.
[**WalletBalance**](DefaultApi.md#walletbalance) | **GET** /api/v1/wallet/balance | Returns the wallet&#39;s balance, both confirmed and predicted.  The predicted balance is the confirmed balance minus the pending spends.
[**WalletFolder**](DefaultApi.md#walletfolder) | **GET** /api/v1/wallets/folderName | 
[**WalletNewAddress**](DefaultApi.md#walletnewaddress) | **POST** /api/v1/wallet/newAddress | 
[**WalletNewSeed**](DefaultApi.md#walletnewseed) | **GET** /api/v1/wallet/newSeed | 
[**WalletSeed**](DefaultApi.md#walletseed) | **POST** /api/v1/wallet/seed | This endpoint only works for encrypted wallets. If the wallet is unencrypted, The seed will be not returned.
[**WalletUpdate**](DefaultApi.md#walletupdate) | **POST** /api/v1/wallet/update | Update the wallet.
[**Wallets**](DefaultApi.md#wallets) | **GET** /api/v1/wallets | 


<a name="addresscount"></a>
# **AddressCount**
> InlineResponse200 AddressCount ()

Returns the total number of unique address that have coins.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class AddressCountExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();

            try
            {
                // Returns the total number of unique address that have coins.
                InlineResponse200 result = apiInstance.AddressCount();
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.AddressCount: " + e.Message );
            }
        }
    }
}
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

<a name="coinsupply"></a>
# **CoinSupply**
> void CoinSupply ()



coinSupplyHandler returns coin distribution supply stats

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class CoinSupplyExample
    {
        public void main()
        {
            var apiInstance = new DefaultApi();

            try
            {
                apiInstance.CoinSupply();
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.CoinSupply: " + e.Message );
            }
        }
    }
}
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

<a name="csrf"></a>
# **Csrf**
> InlineResponse2001 Csrf ()

Creates a new CSRF token. Previous CSRF tokens are invalidated by this call.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class CsrfExample
    {
        public void main()
        {
            var apiInstance = new DefaultApi();

            try
            {
                // Creates a new CSRF token. Previous CSRF tokens are invalidated by this call.
                InlineResponse2001 result = apiInstance.Csrf();
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.Csrf: " + e.Message );
            }
        }
    }
}
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

<a name="defaultconnections"></a>
# **DefaultConnections**
> List<string> DefaultConnections ()

defaultConnectionsHandler returns the list of default hardcoded bootstrap addresses.\\n They are not necessarily connected to.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class DefaultConnectionsExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();

            try
            {
                // defaultConnectionsHandler returns the list of default hardcoded bootstrap addresses.\\n They are not necessarily connected to.
                List&lt;string&gt; result = apiInstance.DefaultConnections();
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.DefaultConnections: " + e.Message );
            }
        }
    }
}
```

### Parameters
This endpoint does not need any parameter.

### Return type

**List<string>**

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="health"></a>
# **Health**
> InlineResponse2002 Health ()

Returns node health data.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class HealthExample
    {
        public void main()
        {
            var apiInstance = new DefaultApi();

            try
            {
                // Returns node health data.
                InlineResponse2002 result = apiInstance.Health();
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.Health: " + e.Message );
            }
        }
    }
}
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

<a name="networkconnection"></a>
# **NetworkConnection**
> InlineResponse2003 NetworkConnection (string addr)

This endpoint returns a specific connection.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class NetworkConnectionExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();
            var addr = addr_example;  // string | Address port

            try
            {
                // This endpoint returns a specific connection.
                InlineResponse2003 result = apiInstance.NetworkConnection(addr);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.NetworkConnection: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **addr** | **string**| Address port | 

### Return type

[**InlineResponse2003**](InlineResponse2003.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="networkconnections"></a>
# **NetworkConnections**
> List<InlineResponse2003> NetworkConnections (string states = null, string direction = null)

This endpoint returns all outgoings connections.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class NetworkConnectionsExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();
            var states = states_example;  // string | Connection status. (optional) 
            var direction = direction_example;  // string | Direction of the connection. (optional) 

            try
            {
                // This endpoint returns all outgoings connections.
                List&lt;InlineResponse2003&gt; result = apiInstance.NetworkConnections(states, direction);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.NetworkConnections: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **states** | **string**| Connection status. | [optional] 
 **direction** | **string**| Direction of the connection. | [optional] 

### Return type

[**List<InlineResponse2003>**](InlineResponse2003.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="networkconnectionsdisconnect"></a>
# **NetworkConnectionsDisconnect**
> void NetworkConnectionsDisconnect (string id)



This endpoint disconnects a connection by ID or address

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class NetworkConnectionsDisconnectExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();
            var id = id_example;  // string | Address id.

            try
            {
                apiInstance.NetworkConnectionsDisconnect(id);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.NetworkConnectionsDisconnect: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string**| Address id. | 

### Return type

void (empty response body)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="networkconnectionsexchange"></a>
# **NetworkConnectionsExchange**
> List<string> NetworkConnectionsExchange ()



This endpoint returns all connections found through peer exchange

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class NetworkConnectionsExchangeExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();

            try
            {
                List&lt;string&gt; result = apiInstance.NetworkConnectionsExchange();
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.NetworkConnectionsExchange: " + e.Message );
            }
        }
    }
}
```

### Parameters
This endpoint does not need any parameter.

### Return type

**List<string>**

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="networkconnectionstrust"></a>
# **NetworkConnectionsTrust**
> List<string> NetworkConnectionsTrust ()

trustConnectionsHandler returns all trusted connections.\\n They are not necessarily connected to. In the default configuration, these will be a subset of the default hardcoded bootstrap addresses.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class NetworkConnectionsTrustExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();

            try
            {
                // trustConnectionsHandler returns all trusted connections.\\n They are not necessarily connected to. In the default configuration, these will be a subset of the default hardcoded bootstrap addresses.
                List&lt;string&gt; result = apiInstance.NetworkConnectionsTrust();
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.NetworkConnectionsTrust: " + e.Message );
            }
        }
    }
}
```

### Parameters
This endpoint does not need any parameter.

### Return type

**List<string>**

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="resendunconfirmedtxns"></a>
# **ResendUnconfirmedTxns**
> void ResendUnconfirmedTxns ()



Broadcasts all unconfirmed transactions from the unconfirmed transaction pool

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class ResendUnconfirmedTxnsExample
    {
        public void main()
        {
            var apiInstance = new DefaultApi();

            try
            {
                apiInstance.ResendUnconfirmedTxns();
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.ResendUnconfirmedTxns: " + e.Message );
            }
        }
    }
}
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

<a name="verifyaddress"></a>
# **VerifyAddress**
> InlineResponse2009 VerifyAddress (string address)

healthHandler returns node health data.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class VerifyAddressExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();
            var address = address_example;  // string | Address id.

            try
            {
                // healthHandler returns node health data.
                InlineResponse2009 result = apiInstance.VerifyAddress(address);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.VerifyAddress: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **address** | **string**| Address id. | 

### Return type

[**InlineResponse2009**](InlineResponse2009.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="version"></a>
# **Version**
> void Version ()



versionHandler returns the application version info

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class VersionExample
    {
        public void main()
        {
            var apiInstance = new DefaultApi();

            try
            {
                apiInstance.Version();
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.Version: " + e.Message );
            }
        }
    }
}
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

<a name="wallet"></a>
# **Wallet**
> WalletMeta Wallet (string id = null)

Returns a wallet by id.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class WalletExample
    {
        public void main()
        {
            var apiInstance = new DefaultApi();
            var id = id_example;  // string | tags to filter by (optional) 

            try
            {
                // Returns a wallet by id.
                WalletMeta result = apiInstance.Wallet(id);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.Wallet: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string**| tags to filter by | [optional] 

### Return type

[**WalletMeta**](WalletMeta.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="walletbalance"></a>
# **WalletBalance**
> InlineResponseDefault WalletBalance (string id)

Returns the wallet's balance, both confirmed and predicted.  The predicted balance is the confirmed balance minus the pending spends.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class WalletBalanceExample
    {
        public void main()
        {
            var apiInstance = new DefaultApi();
            var id = id_example;  // string | tags to filter by

            try
            {
                // Returns the wallet's balance, both confirmed and predicted.  The predicted balance is the confirmed balance minus the pending spends.
                InlineResponseDefault result = apiInstance.WalletBalance(id);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.WalletBalance: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string**| tags to filter by | 

### Return type

[**InlineResponseDefault**](InlineResponseDefault.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="walletfolder"></a>
# **WalletFolder**
> InlineResponse2008 WalletFolder (string addr)



Returns the wallet directory path

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class WalletFolderExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();
            var addr = addr_example;  // string | Address port

            try
            {
                InlineResponse2008 result = apiInstance.WalletFolder(addr);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.WalletFolder: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **addr** | **string**| Address port | 

### Return type

[**InlineResponse2008**](InlineResponse2008.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="walletnewaddress"></a>
# **WalletNewAddress**
> InlineResponse2004 WalletNewAddress (string id, string num = null, string password = null)



Generates new addresses

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class WalletNewAddressExample
    {
        public void main()
        {
            var apiInstance = new DefaultApi();
            var id = id_example;  // string | Wallet Id
            var num = num_example;  // string | The number you want to generate (optional) 
            var password = password_example;  // string | Wallet Password (optional) 

            try
            {
                InlineResponse2004 result = apiInstance.WalletNewAddress(id, num, password);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.WalletNewAddress: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string**| Wallet Id | 
 **num** | **string**| The number you want to generate | [optional] 
 **password** | **string**| Wallet Password | [optional] 

### Return type

[**InlineResponse2004**](InlineResponse2004.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="walletnewseed"></a>
# **WalletNewSeed**
> InlineResponse2005 WalletNewSeed (string entropy = null)



Returns the wallet directory path

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class WalletNewSeedExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();
            var entropy = entropy_example;  // string | Entropy bitSize. (optional) 

            try
            {
                InlineResponse2005 result = apiInstance.WalletNewSeed(entropy);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.WalletNewSeed: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **entropy** | **string**| Entropy bitSize. | [optional] 

### Return type

[**InlineResponse2005**](InlineResponse2005.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="walletseed"></a>
# **WalletSeed**
> InlineResponse2005 WalletSeed (string id, string password)

This endpoint only works for encrypted wallets. If the wallet is unencrypted, The seed will be not returned.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class WalletSeedExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();
            var id = id_example;  // string | Wallet Id.
            var password = password_example;  // string | Wallet password.

            try
            {
                // This endpoint only works for encrypted wallets. If the wallet is unencrypted, The seed will be not returned.
                InlineResponse2005 result = apiInstance.WalletSeed(id, password);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.WalletSeed: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string**| Wallet Id. | 
 **password** | **string**| Wallet password. | 

### Return type

[**InlineResponse2005**](InlineResponse2005.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="walletupdate"></a>
# **WalletUpdate**
> InlineResponse2006 WalletUpdate (string id, string label)

Update the wallet.

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class WalletUpdateExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();
            var id = id_example;  // string | Wallet Id.
            var label = label_example;  // string | The label the wallet will be updated to.

            try
            {
                // Update the wallet.
                InlineResponse2006 result = apiInstance.WalletUpdate(id, label);
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.WalletUpdate: " + e.Message );
            }
        }
    }
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string**| Wallet Id. | 
 **label** | **string**| The label the wallet will be updated to. | 

### Return type

[**InlineResponse2006**](InlineResponse2006.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

<a name="wallets"></a>
# **Wallets**
> List<InlineResponse2007> Wallets ()



Returns all loaded wallets

### Example
```csharp
using System;
using System.Diagnostics;
using IO.Swagger.Api;
using IO.Swagger.Client;
using IO.Swagger.Model;

namespace Example
{
    public class WalletsExample
    {
        public void main()
        {
            // Configure API key authorization: csrfAuth
            Configuration.Default.AddApiKey("csrf_Token", "YOUR_API_KEY");
            // Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
            // Configuration.Default.AddApiKeyPrefix("csrf_Token", "Bearer");

            var apiInstance = new DefaultApi();

            try
            {
                List&lt;InlineResponse2007&gt; result = apiInstance.Wallets();
                Debug.WriteLine(result);
            }
            catch (Exception e)
            {
                Debug.Print("Exception when calling DefaultApi.Wallets: " + e.Message );
            }
        }
    }
}
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**List<InlineResponse2007>**](InlineResponse2007.md)

### Authorization

[csrfAuth](../README.md#csrfAuth)

### HTTP request headers

 - **Content-Type**: application/json, application/xml
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

