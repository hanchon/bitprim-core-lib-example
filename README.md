# Bitprim-core lib example
This is an example on how to use bitprim-core as a cpp lib. 

Note: this example is using linux as OS. To use bitprim-core as a windows lib the conanfile.txt needs to be modified to copy the `.dll` instead of the `.so` files.

# Requirements for the example:

* A C++11 compiler, currently minimum [GCC 4.8.0](https://gcc.gnu.org/projects/cxx0x.html) or Clang based on [LLVM 3.5](http://llvm.org/releases/3.5.0/docs/ReleaseNotes.html).
* [CMake](https://cmake.org/) minimum 3.7
* [Conan](https://conan.io/) minimum 1.2.3. [Conan installation guide](http://docs.conan.io/en/latest/installation.html) (Conan itself requires Python, Pip and CMake)

# Build and run the example:
```
git clone https://github.com/hanchon/bitprim-core-lib-example
cd bitprim-core-lib-example
mkdir bitprim-core
cd bitprim-core
conan install ..
cd ..
mkdir build
cd build
cmake ..
make -j2
./bitprim_core_lib_example
```

Note: the example works if the bitprim-core lib is download in bitcore-core-lib-example/bitprim-core. If the bitprim-core lib is downloaded in another location, the CMakeLists.txt must be updated using the new location.

# Use bitprim-core on others projects:
Download Bitprim-core and all it's dependencies using conan install and the `conanfile.txt`.

If the libs are already built for your architecture conan will download the already built lib, if not it'll download the source code and built it locally.

When the conan install is called, Conan will download `Boost`, `GMP`, `ICU`, `secp256k1` and `Bitprim-core`. This libs will not be installed in your PC, they'll stay in the conan sandbox.


In your project include the path to the include and lib folders and link the libs to the main program.