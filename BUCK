load(
    "@prelude//toolchains/conan:defs.bzl",
    "conan_generate",
    "conan_lock",
    "conan_update",
    "lock_generate",
)
load("//concat_compile_cmds:defs.bzl", "concat_compile_cmds")


conan_lock(
    name = "lock",
    conanfile = "conanfile.txt",
    visibility = ["//third-party:"],
)

lock_generate(
    name = "lock-generate",
    lockfile = ":lock",
)

# TODO[AH] Prevent double build of packages.
#   This rule builds or fetches all transitive dependencies defined by the
#   conanfile in order to generate the import targets. These packages will
#   later be built or fetched again one-by-one again as their corresponding
#   conan_package targets. Avoid this double building. Mark this target manual,
#   or don't tie the generation to it's default output.
conan_generate(
    name = "conan-generate",
    conanfile = "conanfile.txt",
    lockfile = ":lock",
)

conan_update(
    name = "conan-update",
    conan_generate = ":conan-generate",
    conanfile = "conanfile.txt",
    lock_generate = ":lock-generate",
    lockfile = ":lock",
    lockfile_name = "conan.lock",
    targets_name = "third-party/BUCK",
)


concat_compile_cmds(
    name="compile_commands",
    files=[
        "//app:app[full-compilation-database]",
        "//lib:library[full-compilation-database]",
    ],
)
