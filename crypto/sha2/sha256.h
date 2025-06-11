#ifndef SHA2_256_H
#define SHA2_256_H

#include <cstdint>

class SHA256 {
private:
    uint32_t state[8];
    unsigned char buffer[64] = {0};
    uint64_t bytes{0};
public:
    static constexpr size_t outputLen = 32;
    SHA256();
    SHA256& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[outputLen]);
    SHA256& Reset();
};

#endif //SHA2_256_H
