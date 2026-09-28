# libtpms - TPM 1.2 and TPM 2.0 software emulation library

This is a `build2` package repository for
[`libtpms`](https://github.com/stefanberger/libtpms), a software emulation
of a Trusted Platform Module (TPM 1.2 and TPM 2.0).

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`libtpms` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libtpms/PACKAGE-README.md) file.

The development setup for `libtpms` uses the standard `bdep`-based workflow.
For example:

```
git clone .../libtpms.git
cd libtpms

bdep init -C @gcc cc config.c=gcc
bdep update
bdep test
```
