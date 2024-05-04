# libcanvas - A C++ library

The `libcanvas` C++ library provides <SUMMARY-OF-FUNCTIONALITY>.


## Usage

To start using `libcanvas` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libcanvas ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libcanvas%lib{<TARGET>}
```


## Importable targets

This package provides the following importable targets:

```
lib{<TARGET>}
```

<DESCRIPTION-OF-IMPORTABLE-TARGETS>


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libcanvas.<VARIABLE> ?= false
```

<DESCRIPTION-OF-CONFIG-VARIABLES>
