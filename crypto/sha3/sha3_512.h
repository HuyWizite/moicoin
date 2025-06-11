#ifndef SHA3_512_H
#define SHA3_512_H

#include <cstdint>
#include <span>

class SHA3_512 {
private:
    uint64_t state[25] = {0};
    unsigned char buffer[8];
    unsigned buffer_size = 0;
    unsigned pos = 0;

    static constexpr unsigned rate_bits = 1600 - 512 * 2;
    static constexpr unsigned rate_buffers = rate_bits / (8 * sizeof(buffer));
    static_assert(rate_bits % (8 * sizeof(buffer)) == 0, "Rate must be a multiple of 8 bytes");
public:
    static constexpr size_t outputLen = 64;
    SHA3_512() = default;
    SHA3_512& Write(std::span<const unsigned char> data);
    SHA3_512& Finalize(std::span<unsigned char> hash);
    SHA3_512& Reset();
};

#endif //SHA3_512_H
