# Bitprim-core lib example
This is an example on how to use bitprim-core as a cpp lib. 

Note: this example is using linux as OS. To use bitprim-core as a windows lib the conanfile.txt needs to be modified to copy the `.dll` instead of the `.so` files.

# Example:

This example is a small program that uses bitprim-core lib to create some wallets.

The `wallet_functions.hpp` file has all the calls (to the bitprim-core lib) that are need in order to creates private keys, public keys and wallets.

The `main.cpp` uses the wallet functions to create a wallet for testnet and mainnet, encoded in legacy format and cashAddr.

```
./bitprim_core_lib_example
Private key:                  b89d02a452a142f241d622f806aa1098e1afc3a007097f00966f9a8c900648e8
Mainnet wallet (WIF):         5KDbHFeEBqmBeQDsBfXB4A4Y9v8SjuBvuMthoq8bWMvXDHPqvYg
Testnet wallet (WIF):         92zDrzTmn4qKcTj9p1R5vkcVoaV9u4j8FJketTV6r6fZzFnZoUv
Public key:                   04278f7bfee4ef625f85279c3a01d57c22e2877a902128b2df85071f9d6c95b290f094f5bd1bff5880d09cc231c774d71ac22d3ab9bdd9dda2e75017b52d893367
Wallet Address (Mainnet):     17DHrHvtmMRs9ciersFCPNhvJtryd5NWbT
Wallet cashAddress (Mainnet): bitcoincash:qpzz8n7jp6847yyx8t33matrgcsdx6c0cvmtevrfgz
Wallet Address (Testnet):     mmjF9M1saNs7vjCGaSDaDHvFAtTgUNtfrJ
Wallet cashAddress (Testnet): bchtest:qpzz8n7jp6847yyx8t33matrgcsdx6c0cvleatp707
```

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
