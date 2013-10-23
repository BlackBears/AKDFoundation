#include "bitops.h"

#include <stdio.h>

#pragma mark - Circular shift

inline unsigned int rotl(unsigned int value, int shift) {
    return (value << shift) | (value >> (sizeof(value) * 8 - shift));
}

inline unsigned int rotr(unsigned int value, int shift) {
    return (value >> shift) | (value << (sizeof(value) * 8 - shift));
}

inline uint32_t rotl32(uint32_t value, int shift)
{
    return rotl(value, shift);
}

inline uint32_t rotr32(uint32_t value, int shift)
{
    return rotr(value, shift);
}

inline uint8_t rotl8(uint8_t value, int shift)
{
    return (value << shift) | (value >> (sizeof(value) * 8 - shift));
}

inline uint8_t rotr8(uint8_t value, int shift)
{
    return (value >> shift) | (value << (sizeof(value) * 8 - shift));
}

inline void sbi(int *value, uint8_t bit)
{
    *value |= (1 << bit);
}

inline int cbi(int value, uint8_t bit)
{
    return value & ~(1 << bit);
}

inline bool signs_opposite32(int32_t x, int32_t y)
{
    return ((x ^ y) < 0);
}

inline bool signs_opposite64(int64_t x, int64_t y)
{
    return ((x ^ y) < 0);
}

inline int32_t min32(int32_t x, int32_t y)
{
    return y ^ ((x ^ y) & -(x < y));
}

inline int64_t min64(int64_t x, int64_t y)
{
    return y ^ ((x ^ y) & -(x < y));
}

inline int32_t max32(int32_t x, int32_t y)
{
    return x ^ ((x ^ y) & -(x < y));
}

inline int64_t max64(int64_t x, int64_t y)
{
    return x ^ ((x ^ y) & -(x < y));
}

inline bool is2power32(uint32_t v)
{
    return v && !(v & (v - 1));
}

inline bool is2power64(uint64_t v)
{
    return v && !(v & (v - 1));
}

inline bool haszero32(uint32_t v)
{
    return ~((((v & 0x7F7F7F7F) + 0x7F7F7F7F) | v) | 0x7F7F7F7F);
}

inline uint32_t round2pwr32(uint32_t v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

inline uint64_t round2pwr64(uint64_t v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v |= v >> 32;
    v++;
    return v;
}

inline uint32_t bitcount32(uint32_t v)
{
    uint32_t c;
    for( c = 0; v; c++ )
        v &= v-1;
    return c;
}