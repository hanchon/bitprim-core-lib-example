cmake_minimum_required(VERSION 3.7)
project(bitprim_core_lib_example
        VERSION 0.1
        LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)

# Set the BCH definition
add_definitions(-DBITPRIM_CURRENCY_BCH)

# Set the directories
INCLUDE_DIRECTORIES(./bitprim-core/include)
LINK_DIRECTORIES(./bitprim-core/lib)

# List of the libs needed by bitprim-core
set(CONAN_LIBS -pthread boost_exception boost_iostreams boost_locale boost_log boost_program_options boost_random boost_regex boost_timer boost_thread boost_chrono boost_date_time boost_atomic boost_filesystem boost_system boost_log_setup boost_unit_test_framework secp256k1 gmp icutu icui18n icutest icuio icuuc icudata dl ${CONAN_LIBS})

# Main program
set(SOURCE_FILES main.cpp define.hpp wallet_functions.hpp)
add_executable(bitprim_core_lib_example ${SOURCE_FILES} define.hpp wallet_functions.hpp)

# Link the libs
target_link_libraries(bitprim_core_lib_example PUBLIC bitprim-core ${CONAN_LIBS})

