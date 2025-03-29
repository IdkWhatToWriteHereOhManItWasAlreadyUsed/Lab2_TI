#include <vector>
#include <cstdint>
#include "Key.h"

uint8_t getNewBit(std::vector<uint8_t>& key, const std::vector<int>& polynomial)
{
    uint8_t firstBit = 0;
    for (size_t i = 0; i < polynomial.size(); i++) {
        firstBit ^= key[key.size() - polynomial[i]];
    }
    return firstBit;
}

void leftShift(std::vector<uint8_t>& key)
{
    for (size_t i = 0; i < key.size() - 1; i++)
    {
        key[i] = key[i + 1];
    }
}

std::vector<uint8_t> generateKey(const std::vector<uint8_t>& key, int length) {
    return generateKey(key, polynomial, length);
}

std::vector<uint8_t> generateKey(const std::vector<uint8_t>& key, const std::vector<int>& polynomial, int length) {
    std::vector<uint8_t> generatedKey(length);
    std::vector<uint8_t> temp = key;

    for (int i = 0; i < length; i++) {
        generatedKey[i] = temp[0];

        uint8_t firstBit = getNewBit(temp, polynomial);
        leftShift(temp);
        temp[temp.size() - 1] = firstBit;
    }

    return generatedKey;
}