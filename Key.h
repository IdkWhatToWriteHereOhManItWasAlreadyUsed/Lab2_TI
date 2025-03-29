#ifndef KEY_H
#define KEY_H

#include <cstdint>
#include <vector>

const std::vector<int> polynomial = { 30, 16, 15, 1 };

std::vector<uint8_t> generateKey( std::vector<uint8_t>& key, int length);

uint8_t calculateFeedbackBit(std::vector<uint8_t>& reg, const std::vector<int>& polynomial);

void shiftLeft(std::vector<uint8_t>& reg);

std::vector<uint8_t> generateKeyAppending(std::vector<uint8_t>& initialKey, const std::vector<int>& polynomial, int outputLength);

#endif //KEY_H