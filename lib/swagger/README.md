# Skycoin Swagger

## Generate Client Server

- Requirements:
  - Java 7 o 9

``` sh
 java -jar swagger-codegen-cli.jar generate -i swagger.yml -l <language> -o <output-file>
```

## Instructions to generate client libraries

In order to generate a client library for a particular programming language, just run the following command from repository root folder:

```sh
$ openapi-generator generate -g <supported_Language> --additional-properties=prependFormOrBodyParameters=true -o /path/to/client -i ./lib/swagger/swagger.yml
```

For further details consult [OpenApi languague support matrix]( https://openapi-generator.tech/docs/generators)
