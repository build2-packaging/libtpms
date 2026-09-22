# build2-libtpms - <SUMMARY>

This is a `build2` package repository for [`build2-libtpms`](https://<UPSTREAM-URL>),
a <SUMMARY-OF-FUNCTIONALITY>.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`build2-libtpms` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](<PACKAGE>/PACKAGE-README.md) file.

The development setup for `build2-libtpms` uses the standard `bdep`-based workflow.
For example:

```
git clone .../build2-libtpms.git
cd build2-libtpms

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
