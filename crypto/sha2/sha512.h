#ifndef SHA3_512_H
#define SHA3_512_H

#include <cstdint>

class SHA512 {
private:
    uint64_t state[8];
    unsigned char buffer[128] = {0};
    uint64_t bytes{0};
public:
    static constexpr size_t outputLen = 64;
    SHA512();
    SHA512& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[outputLen]);
    SHA512& Reset();
    uint64_t Size() const { return bytes; }
};

#endif //SHA2_512_H
