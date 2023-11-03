# Cxx-Buck2-Conan-Examples

A C++ example repository using Buck 2 with Conan (the C++ package manager) and scripts to generate a single `./compile_commands.json` file.

- [Installation](#installation)
- [Using this Example](#using-this-example)
  - [Available Targets](#available-targets)
  - [Buck 2 Files](#buck-2-files)
- [Converting an Existing or Generating a new C++ Project with Buck 2](#converting-an-existing-or-generating-a-new-c-project-with-buck-2)
- [Other Buck 2 C++ Examples](#other-buck-2-c-examples)
- [Buck 2 Examples for other Languages](#buck-2-examples-for-other-languages)
- [Contributions](#contributions)
- [License](#license)

## Installation

You need the following:

- Buck 2: [Buck2 Official Website](https://buck2.build/)
- Conan 1 [GitHub Releases - Conan 1.6](https://github.com/conan-io/conan/releases/tag/1.61.0). On MacOS with Homebrew: `brew install conan@1`. **Warning**: Conan 2 does not work.
- Python 3, Python 3.8 or newer.

Install Buck 2 like documented at [Buck 2 - Getting Started](https://buck2.build/docs/getting_started/).

## Using this Example

- Checkout the Buck 2 prelude containing the language rules: `git submodule update --init`
- Run `buck2 run //:conan-update` to build the Conan packages and add them to Buck 2. An updated file [./third-party/BUCK](./third-party/BUCK) should be generated.
- Now you should be able to build and run the example binary: `buck2 run //app:app`.
- To generate a `compile_commands.json` file (needed for the C++ LSPs), run `buck2 build //:compile_commands`.

### Available Targets

- `buck2 clean` - Deletes all generated files and Conan packages.
- `buck2 targets //...` - Lists all available targets, including all Conan packages.
- `buck2 build :exe` - A alias for `buck2 build //app:app`, builds the executable [./app/main.cpp](./app/main.cpp). Buck 2 configuration [./app/BUCK](./app/BUCK)
- `buck2 run :exe` - A alias for `buck2 run //app:app`, builds and runs the executable [./app/main.cpp](./app/main.cpp). Buck 2 configuration [./app/BUCK](./app/BUCK)
- `buck2 build :test` - A alias for `buck2 build test:test`, builds the tests in [./test/test_main.cpp](./test/test_main.cpp). Buck 2 configuration [./test/BUCK](./test/BUCK).
- `buck2 run :test` - A alias for `buck2 run test:test`, builds and runs the tests in [./test/test_main.cpp](./test/test_main.cpp). Buck 2 configuration [./test/BUCK](./test/BUCK).
- `buck2 build :lib` - A alias for `buck2 build //lib:library`, builds the library in [./lib/lib.cpp](./lib/lib.cpp). Buck 2 configuration [./lib/BUCK](./lib/BUCK)
- `buck2 run :conan-update` - Builds all Conan packages configured in [./conanfile.txt](./conanfile.txt). Buck 2 configuration in [./toolchains/BUCK](./toolchains/BUCK) and [./BUCK](./BUCK)
- `buck2 build :compile_commands` - Generates the file `./compile_commands.json`, needed for LSPs. The actual python scripts and Buck 2 configuration is located in [./concat_compile_cmds/](./concat_compile_cmds/), the list of targets to add to `./compile_commands.json` is located in the Buck 2 configuration file [./BUCK](./BUCK):

  ```python
  concat_compile_cmds(
    name="compile_commands",
    files=[
        "//app:app[full-compilation-database]",
        "//lib:library[full-compilation-database]",
        "//test:test[full-compilation-database]",
    ],
  )
  ```

### Buck 2 Files

- [./.buckroot](./.buckroot) - A empty file to mark the BUck 2 root. The root directory of all Buck 2 projects, not just a single one. Generated by `buck2 init`.
- [./.buckconfig](./.buckconfig) - The general Buck 2 configuration. Generated by `buck2 init`.
- [./BUCK](./BUCK) - Main Buck 2 configuration, holds the aliases, the Conan rules and the configuration for the generation of `./compile_commands.json`. You have to manually edit this.
- [./toolchains/BUCK](./toolchains/BUCK) - Configuration of the Buck 2 toolchains - Python, C++ and Conan. You have to manually edit this.
- [./concat_compile_cmds/](./concat_compile_cmds/) - Python script and Buck2 configuration to generate the file `./compile_commands.json`. Just copy that in your own project.
- [./third-party/BUCK](./third-party/BUCK) - Autogenerated by `buck2 run :conan-update`. Do not edit!
- [./lib/BUCK](./lib/BUCK) - The library's configuration. You have to manually create that.
- [./app/BUCK](./app/BUCK) - Configuration of the executable. You have to manually create that.
- [./test/BUCK](./test/BUCK) - Test configuration. You have to manually create that.

## Converting an Existing or Generating a new C++ Project with Buck 2

1. Initialize the project by running `buck2 init --git`
2. Generate a `./conanfile.txt` containing your dependencies.
3. Edit the files [./toolchains/BUCK](./toolchains/BUCK) and [./BUCK](./BUCK) to include the C++, Python and Conan toolchains.
4. Add sources and `BUCK` files. Like [./lib/BUCK](./lib/BUCK), [./app/BUCK](./app/BUCK) and [./test/BUCK](./test/BUCK).
5. Copy the directory [./concat_compile_cmds/](./concat_compile_cmds/) to your project and configure it in [./toolchains/BUCK](./toolchains/BUCK) and [./BUCK](./BUCK) to be able to generate a `./compile_commands.json` file in your root directory.
6. Run `buck2 run :conan-update` to install and configure the Conan packages for use with Buck 2. Generates the files [./third-party/BUCK](./third-party/BUCK) and [./conan.lock](./conan.lock).
7. Run `buck2 build :compile_commands` to generate the file `./compile_commands.json` for use with your LSP (like `clangd`).

## Other Buck 2 C++ Examples

- I have also written an example repository using vcpkg as package manager: [Cxx-Buck2-vcpkg-Examples](https://github.com/Release-Candidate/Cxx-Buck2-vcpkg-Examples)
- The official examples: [Facebook: Buck 2 C++ Examples](https://github.com/facebook/buck2/tree/main/examples/with_prelude/cpp)
- The official Conan examples: [Facebook: Buck 2 C++ Conan Examples](https://github.com/facebook/buck2/tree/main/examples/toolchains/conan_toolchain)
- Rust and C++ interop examples [Interop Between C++ and Rust](https://github.com/dtolnay/cxx)

## Buck 2 Examples for other Languages

I've also made examples for OCaml: [OCaml-Buck-2-Examples](https://github.com/Release-Candidate/OCaml-Buck-2-Examples).

## Contributions

If you want to add tips or tricks on using Buck 2, examples, a link to other examples, blog or forum posts, or found an error, please open an issue or pull request with your changes.

## License

These examples are licensed under the MIT license. See file [./LICENSE](./LICENSE)
