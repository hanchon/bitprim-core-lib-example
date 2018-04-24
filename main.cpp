#include "wallet_functions.hpp"
#include <iostream>

int main() {
  // The seed must be base 16 encoded and at least 32 char long.
  std::string priv_key_seed = "aaeb587496cc54912bbcef874fa9a61c";

  // Creates a private key using the seed.
  auto priv_key = generate_priv_key(priv_key_seed);
  std::cout << "Private key:                   "
            << libbitcoin::encode_base16(priv_key) << std::endl
            << std::endl;

  // Private key in WIF for mainnet
  bool mainnet = true;
  std::cout << "Mainnet wallet (WIF):          "
            << priv_key_to_wif(priv_key, mainnet) << std::endl
            << std::endl;

  // Private key in WIF for testnet
  mainnet = false;
  std::cout << "Testnet wallet (WIF):          "
            << priv_key_to_wif(priv_key, mainnet) << std::endl
            << std::endl;

  // Creates a public key using the private key.
  auto pub_key = priv_key_to_public(priv_key);
  // pub_key.enconded() can be used to get the string
  std::cout << "Public key:                    " << pub_key << std::endl
            << std::endl;

  // Creates a mainnet wallet using the public key.
  mainnet = true;
  auto wallet = pub_key_to_addr(pub_key, mainnet);
  std::cout << "Wallet Address (Mainnet):      " << wallet.encoded()
            << std::endl;
  std::cout << "Wallet cashAddress (Mainnet):  " << wallet.encoded_cashaddr()
            << std::endl
            << std::endl;

  // Creates a payment_address using a cashAddr string

  std::string mainnet_address = wallet.encoded_cashaddr();
  wallet = cashAddr_to_payment_address(mainnet_address, mainnet);
  std::cout << "Wallet Address (Imported):     " << wallet.encoded()
            << std::endl;
  std::cout << "Wallet cashAddress (Imported): " << wallet.encoded_cashaddr()
            << std::endl
            << std::endl;

  // Creates a tesnet wallet using the public key.
  mainnet = false;
  wallet = pub_key_to_addr(pub_key, mainnet);
  std::cout << "Wallet Address (Testnet):      " << wallet.encoded()
            << std::endl;
  std::cout << "Wallet cashAddress (Testnet):  " << wallet.encoded_cashaddr()
            << std::endl
            << std::endl;

  // Creates a payment_address using a cashAddr string
  std::string testnet_address = wallet.encoded_cashaddr();
  wallet = cashAddr_to_payment_address(testnet_address, mainnet);
  std::cout << "Wallet Address (Imported):     " << wallet.encoded()
            << std::endl;
  std::cout << "Wallet cashAddress (Imported): " << wallet.encoded_cashaddr()
            << std::endl
            << std::endl;

  return 0;
}