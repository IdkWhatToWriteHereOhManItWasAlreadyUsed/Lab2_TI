#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <vector>
#include <cstdint> 
#include <stdexcept>

class Encryptor {
public:

    std::vector<uint8_t> plainText;

    std::vector<uint8_t> cipherText;

    void encrypt(const std::vector<uint8_t>& key) {
        if (key.size() < plainText.size()) {
            throw std::out_of_range("Key is shorter than plain text");
        }

        cipherText.resize(plainText.size());
        for (size_t i = 0; i < cipherText.size(); ++i) {
            cipherText[i] = key[i] ^ plainText[i];
        }
    }
};

#endif 