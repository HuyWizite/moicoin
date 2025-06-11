#ifndef ENDIAN_H
#define ENDIAN_H

#include <bit>

#include "byteswap.h"

inline constexpr uint16_t htobe16_internal(uint16_t host_16bits)
{
    if constexpr (std::endian::native == std::endian::little) return internal_byteswap_16(host_16bits);
        else return host_16bits;
}
inline constexpr uint16_t htole16_internal(uint16_t host_16bits)
{
    if constexpr (std::endian::native == std::endian::big) return internal_byteswap_16(host_16bits);
        else return host_16bits;
}
inline constexpr uint16_t be16toh_internal(uint16_t big_endian_16bits)
{
    if constexpr (std::endian::native == std::endian::little) return internal_byteswap_16(big_endian_16bits);
        else return big_endian_16bits;
}
inline constexpr uint16_t le16toh_internal(uint16_t little_endian_16bits)
{
    if constexpr (std::endian::native == std::endian::big) return internal_byteswap_16(little_endian_16bits);
        else return little_endian_16bits;
}
inline constexpr uint32_t htobe32_internal(uint32_t host_32bits)
{
    if constexpr (std::endian::native == std::endian::little) return internal_byteswap_32(host_32bits);
        else return host_32bits;
}
inline constexpr uint32_t htole32_internal(uint32_t host_32bits)
{
    if constexpr (std::endian::native == std::endian::big) return internal_byteswap_32(host_32bits);
        else return host_32bits;
}
inline constexpr uint32_t be32toh_internal(uint32_t big_endian_32bits)
{
    if constexpr (std::endian::native == std::endian::little) return internal_byteswap_32(big_endian_32bits);
        else return big_endian_32bits;
}
inline constexpr uint32_t le32toh_internal(uint32_t little_endian_32bits)
{
    if constexpr (std::endian::native == std::endian::big) return internal_byteswap_32(little_endian_32bits);
        else return little_endian_32bits;
}
inline constexpr uint64_t htobe64_internal(uint64_t host_64bits)
{
    if constexpr (std::endian::native == std::endian::little) return internal_byteswap_64(host_64bits);
        else return host_64bits;
}
inline constexpr uint64_t htole64_internal(uint64_t host_64bits)
{
    if constexpr (std::endian::native == std::endian::big) return internal_byteswap_64(host_64bits);
        else return host_64bits;
}
inline constexpr uint64_t be64toh_internal(uint64_t big_endian_64bits)
{
    if constexpr (std::endian::native == std::endian::little) return internal_byteswap_64(big_endian_64bits);
        else return big_endian_64bits;
}
inline constexpr uint64_t le64toh_internal(uint64_t little_endian_64bits)
{
    if constexpr (std::endian::native == std::endian::big) return internal_byteswap_64(little_endian_64bits);
        else return little_endian_64bits;
}

#endif //ENDIAN_H
