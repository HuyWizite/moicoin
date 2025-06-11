#ifndef SHA3_256_H
#define SHA3_256_H

#include <cstdint>
#include <span>

class SHA3_256 {
private:
    uint64_t state[25] = {0};
    unsigned char buffer[8];
    unsigned buffer_size = 0;
    unsigned pos = 0;

    static constexpr unsigned rate_bits = 1600 - 256 * 2;
    static constexpr unsigned rate_buffers = rate_bits / (8 * sizeof(buffer));
    static_assert(rate_bits % (8 * sizeof(buffer)) == 0, "Rate must be a multiple of 8 bytes");
public:
    static constexpr size_t outputLen = 32;
    SHA3_256() = default;
    SHA3_256& Write(std::span<const unsigned char> data);
    SHA3_256& Finalize(std::span<unsigned char> hash);
    SHA3_256& Reset();
};

#endif //SHA3_256_H
