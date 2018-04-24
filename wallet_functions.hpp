//
// Created by hanchon.
//

#ifndef BITPRIM_CORE_LIB_EXAMPLE_WALLET_FUNCTIONS_HPP
#define BITPRIM_CORE_LIB_EXAMPLE_WALLET_FUNCTIONS_HPP

#include "define.hpp"
#include <bitcoin/bitcoin/multi_crypto_support.hpp>
#include <bitcoin/bitcoin/wallet/ec_private.hpp>
#include <bitcoin/bitcoin/wallet/hd_private.hpp>
#include <bitcoin/bitcoin/wallet/payment_address.hpp>

// The seed must be base 16 encoded and at least 32 char long.
libbitcoin::ec_secret generate_priv_key(std::string const &seed_data) {
  // This function generates a private key using the seed_data string.

  // Bound parameters.
  libbitcoin::data_chunk seed;
  if (!libbitcoin::decode_base16(seed, seed_data)) {
    // Seed is not base16
    return {};
  }

  if (seed.size() < minimum_seed_size) {
    // Short seed
    return {};
  }

  const libbitcoin::wallet::hd_private key(seed);
  libbitcoin::ec_secret secret(key.secret());

  if (secret == libbitcoin::null_hash) {
    // New invalid key
    return {};
  }

  return secret;
}

libbitcoin::wallet::ec_public
priv_key_to_public(libbitcoin::ec_secret const &priv_key,
                   bool compress = false) {
  // This function generates a public key using a private key. The public key
  // can be compressed or uncompressed.

  libbitcoin::ec_compressed point;
  libbitcoin::secret_to_public(point, priv_key);
  return libbitcoin::wallet::ec_public(point, compress);
}

libbitcoin::wallet::payment_address
pub_key_to_addr(libbitcoin::wallet::ec_public const &pub_key,
                bool mainnet = true) {
  // This function generates a payment address using the public key. The payment
  // address can be for mainnet or testnet.
  // The payment_address knows how to encode itself as cashAddr
  // (encoded_cashaddr()) and legacy(encoded())

  uint8_t version;
  if (mainnet) {
    version = libbitcoin::wallet::payment_address::mainnet_p2kh; // mainnet_p2sh
                                                                 // can also be
                                                                 // used
  } else {
    version = libbitcoin::wallet::payment_address::testnet_p2kh; // testnet_p2sh
                                                                 // can also be
                                                                 // used
  }
  return libbitcoin::wallet::payment_address(pub_key, version);
}

std::string priv_key_to_wif(libbitcoin::ec_secret const &priv_key,
                            bool mainnet = true, bool compress = false) {
  // Encode a private key to WIF

  uint8_t wif_version = 128;
  if (!mainnet) {
    wif_version = 239;
  }
  // Payment address version is unused in this scenario.
  const uint8_t payment_version = 0;
  // ec_private requires a composite version.
  const auto version =
      libbitcoin::wallet::ec_private::to_version(payment_version, wif_version);

  libbitcoin::wallet::ec_private wif(priv_key, version, compress);

  return wif.encoded();
}

// Creates a payment_address using a cashAddr string
libbitcoin::wallet::payment_address
cashAddr_to_payment_address(std::string const &address, bool mainnet = true) {
  // Encode a private key to WIF

  libbitcoin::set_cashaddr_prefix("bitcoincash");
  if (!mainnet) {
    libbitcoin::set_cashaddr_prefix("bchtest");
  }
  const libbitcoin::wallet::payment_address new_address(address);
  return new_address;
}

#endif // BITPRIM_CORE_LIB_EXAMPLE_WALLET_FUNCTIONS_HPP
