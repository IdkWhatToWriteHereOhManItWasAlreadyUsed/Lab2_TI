#ifndef KEY_H
#define KEY_H

#include <cstdint>
#include <vector>

const std::vector<int> polynomial = { 30, 16, 15, 1 };

std::vector<uint8_t> generateKey(const std::vector<uint8_t>& key, int length);

uint8_t getNewBit(std::vector<uint8_t>& key, const std::vector<int>& polynomial);

void leftShift(std::vector<uint8_t>& key);

std::vector<uint8_t> generateKey( const std::vector<uint8_t>& key, const std::vector<int>& polynomial, int length);

std::vector<uint8_t> generateKeyAppending(const std::vector<uint8_t>& initialKey,  const std::vector<int>& polynomial,  int outputLength);
#endif 