# libtpms - TPM 1.2 and TPM 2.0 software emulation library

This is a `build2` package for the
[`libtpms`](https://github.com/stefanberger/libtpms) C library. It
provides software emulation of a Trusted Platform Module (TPM 1.2 and TPM
2.0), built with the OpenSSL crypto backend.

**Windows (MSVC) support.** Upstream's `TPM_WINDOWS` code path for the TPM
2.0 sources has so far only been exercised against MinGW-w64, whose
GCC-based toolchain quietly supplies POSIX headers and GNU extensions
that real MSVC and clang in MSVC-compatibility mode lack. This package
fills the resulting gaps from the `buildfile` wherever possible
(feature-detected compat headers, per-target defines, DLL symbol
exporting), and only patches upstream sources (see the `*.patch` files
alongside them) where a `TPM_WINDOWS` branch upstream already started
was left incomplete or a GCC-only construct had no MSVC counterpart.


## Usage

To start using `libtpms` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libtpms ^0.10.2
```

Then import the library in your `buildfile`:

```
import libs = libtpms%lib{tpms}
```


## Importable targets

This package provides the following importable targets:

```
lib{tpms}
```

The library is declared in `<libtpms/tpm_library.h>`.


## Configuration variables

This package provides no configuration variables.
