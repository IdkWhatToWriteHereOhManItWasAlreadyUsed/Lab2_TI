#include <vector>
#include <cstdint>
#include "Key.h"

uint8_t getNewBit(std::vector<uint8_t>& key, const std::vector<int>& polynomial)
{
    uint8_t firstBit = 0;
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
   // return generateKey(key, polynomial, length);
    return generateKeyAppending(key, polynomial, length);
}

std::vector<uint8_t> generateKey(const std::vector<uint8_t>& key, const std::vector<int>& polynomial, int length) {
    std::vector<uint8_t> generatedKey(length);
    return generatedKey;
}

/// корректная версия

uint8_t calculateFeedbackBit(const std::vector<uint8_t>& reg, const std::vector<int>& polynomial, int step) {
    uint8_t feedback = 0;
    for (int tap : polynomial) {
        if (tap + step > reg.size())
            continue;
        feedback ^= reg[30 - tap + step];
    }
    return feedback;
}

std::vector<uint8_t> generateKeyAppending(const std::vector<uint8_t>& initialKey,  const std::vector<int>& polynomial, int outputLength) {
    std::vector<uint8_t> generatedKey(outputLength);

    for (int i = 0; i < initialKey.size(); ++i)
        generatedKey[i] = initialKey[i];

    for (int i = initialKey.size(); i < outputLength; ++i) {
        generatedKey[i] = calculateFeedbackBit(generatedKey, polynomial, i - 30);
    }

    return generatedKey;
}