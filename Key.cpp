#include <vector>
#include <cstdint>
#include "Key.h"

/*
std::vector<uint8_t> generateKey(std::vector<uint8_t>& key, int length) {
   // return generateKey(key, polynomial, length);
    return generateKeyAppending(key, polynomial, length);
}

/// ���������� ������

uint8_t calculateFeedbackBit(const std::vector<uint8_t>& reg, const std::vector<int>& polynomial) 
{
    uint8_t feedback = 0;
    for (int tap : polynomial) {
        if (tap > reg.size())
            continue;
        feedback ^= reg[reg.size() - tap];
    }
    return feedback;
}

void shiftLeft(std::vector<uint8_t>& reg)
{
    uint8_t feedbackBit = calculateFeedbackBit(reg, polynomial);
    for (int i = 0; i < reg.size() - 1; ++i)
    {
        reg[i] = reg[i + 1];
    }
    reg[reg.size() - 1] = feedbackBit;
}

std::vector<uint8_t> generateKeyAppending(std::vector<uint8_t>& initialKey,  const std::vector<int>& polynomial, int outputLength) {
    std::vector<uint8_t> generatedKey(outputLength);

    for (int i = 0; i < outputLength; ++i) {
        generatedKey[i] = initialKey[0];
        shiftLeft(initialKey);
    }

    return generatedKey;
}*/



std::vector<uint8_t> generateKey(const std::vector<uint8_t>& key, int length) {
    // return generateKey(key, polynomial, length);
    return generateKeyAppending(key, polynomial, length);
}


/// ���������������� ������

uint8_t calculateFeedbackBit(const std::vector<uint8_t>& reg, const std::vector<int>& polynomial, int step) {
    uint8_t feedback = 0;
    for (int tap : polynomial) {
        if (tap + step > reg.size())
            continue;
        feedback ^= reg[30 - tap + step];
    }
    return feedback;
}

std::vector<uint8_t> generateKeyAppending(const std::vector<uint8_t>& initialKey, const std::vector<int>& polynomial, int outputLength) {
    std::vector<uint8_t> generatedKey(outputLength);

    for (int i = 0; i < initialKey.size(); ++i)
        generatedKey[i] = initialKey[i];

    for (int i = initialKey.size(); i < outputLength; ++i) {
        generatedKey[i] = calculateFeedbackBit(generatedKey, polynomial, i - 30);
    }

    return generatedKey;
}