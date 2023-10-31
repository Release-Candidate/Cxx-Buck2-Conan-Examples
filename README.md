# Cxx-Buck2-Examples

A C++ example repository using Buck 2 with Conan (the C++ package manager).

## Setup

- Checkout the Buck 2 prelude containing the language rules: `git submodule update --init`
- Run `buck2 run //:conan-update` to build the Conan packages and add them to Buck 2. A file [./third-party/BUCK](./third-party/BUCK) should be generated.
- Now you should be able to build and run the example binary: `buck2 run //app:app`
