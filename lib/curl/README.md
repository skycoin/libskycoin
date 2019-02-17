
# Skycoin C REST client library

[![Build Status](https://travis-ci.org/skycoin/libskycoin.svg)](https://travis-ci.org/skycoin/libskycoin)
[![GoDoc](https://godoc.org/github.com/skycoin/libskycoin?status.svg)](https://godoc.org/github.com/skycoin/libskycoin)
[![Go Report Card](https://goreportcard.com/badge/github.com/skycoin/libskycoin)](https://goreportcard.com/report/github.com/skycoin/libskycoin)

Skycoin C REST client library (a.k.a. libskycoin-curl) provides access to Skycoin REST API
functions for implementing third-party applications.

This API is generated from [OpenAPI v3](https://github.com/OAI/OpenAPI-Specification/blob/master/versions/3.0.0.md) specifications with [openapi-generator](https://github.com/OpenAPITools/openapi-generator). The library has [libcurl](https://curl.haxx.se/libcurl/c/) as its only dependency.

## Source code generation

In order to generate liskycoin-curl from swagger spec, install `swagger2openapi` as follows

``` sh
    $ npm install swagger2openapi -g
```

To Generate a Client from swagger spec, just type:

``` sh
    $ make swagger-client
```
This command will generate a C client in `lib/curl/cClient`.

