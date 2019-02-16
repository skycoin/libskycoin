
[](https://user-images.githubusercontent.com/26845312/32426705-d95cb988-c281-11e7-9463-a3fce8076a72.png)

# Skycoin C library

[![Build Status](https://travis-ci.org/skycoin/libskycoin.svg)](https://travis-ci.org/skycoin/libskycoin)

Skycoin C library (a.k.a `libskycoin`) exports the Skycoin API to DApps using the C programming language.
It is also the foundation to build client libraries for other programming languages.

## Links

* [skycoin.net](https://www.skycoin.net)
* [Skycoin Blog](https://www.skycoin.net/blog)
* [Skycoin Docs](https://www.skycoin.net/docs)
* [Skycoin Blockchain Explorer](https://explorer.skycoin.net)
* [Skycoin Development Telegram Channel](https://t.me/skycoindev)
* [Skycoin Github Wiki](https://github.com/skycoin/skycoin/wiki)

## Subprojects

The Skycoin C library is made of the following components

- `lib/cgo`     : C wrappers for the Skycoin core API
- `lib/swagger` : Swagger specifications for generating REST API clients
- `lib/swig`    : SWIG interfaces to generate wrappers around the Skycoin core API for other programming languages

Consult respective `README` files for further details.

## C Wrapper for Skycoin Api

The C wrapper for Skycoin Api is made with swagger specifications, and generated automatically with open api.

The C wrapper is in `lib/Clients/cClient`.

## Generate Clients for other Languages with Swagger Spec

You can generate multiple clients for Skycoin Api from swagger spec.
You need install openapi:

``` sh
    $ npm install swagger2openapi -g
```

To Generate a Client from swagger spec, just type:

``` sh
    $ make generate-c-client
```
This command generate a C client in `lib/Clients` with name `cClient<current git commit at specified branch>`

To generate a wrapper for many other languages, just type:

```sh
    $ openapi-generator generate -g <supported_Language> --additional-properties=prependFormOrBodyParameters=true -o /path/to/client -i ./lib/swagger/swagger.yml
```

For further details in this [Open Api Valid Languagues]( https://openapi-generator.tech/docs/generators)