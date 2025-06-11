#ifndef BYTESWAP_H
#define BYTESWAP_H

#include <cstdint>

inline constexpr uint16_t internal_byteswap_16(uint16_t x) {
    return (x >> 8) | (x << 8);
}

inline constexpr uint32_t internal_byteswap_32(uint32_t x) {
    return (((x & 0xff000000U) >> 24) | ((x & 0x00ff0000U) >>  8) |
            ((x & 0x0000ff00U) <<  8) | ((x & 0x000000ffU) << 24));
}

inline constexpr uint64_t internal_byteswap_64(uint64_t x) {
    return (((x & 0xff00000000000000ull) >> 56)
          | ((x & 0x00ff000000000000ull) >> 40)
          | ((x & 0x0000ff0000000000ull) >> 24)
          | ((x & 0x000000ff00000000ull) >> 8)
          | ((x & 0x00000000ff000000ull) << 8)
          | ((x & 0x0000000000ff0000ull) << 24)
          | ((x & 0x000000000000ff00ull) << 40)
          | ((x & 0x00000000000000ffull) << 56));
}

#endif //BYTESWAP_H