//
// Created by hanchon.
//

#ifndef BITPRIM_CORE_LIB_EXAMPLE_DEFINE_HPP
#define BITPRIM_CORE_LIB_EXAMPLE_DEFINE_HPP

#include <bitcoin/bitcoin/constants.hpp>
/**
 * The minimum safe length of a seed in bits (multiple of 8).
 */
const size_t minimum_seed_bits = 128;

/**
 * The minimum safe length of a seed in bytes (16).
 */
const size_t minimum_seed_size = minimum_seed_bits / libbitcoin::byte_bits;


#endif //BITPRIM_CORE_LIB_EXAMPLE_DEFINE_HPP
