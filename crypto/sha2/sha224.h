#ifndef SHA2_224_H
#define SHA2_224_H

#include <cstdint>

class SHA224 {
private:
    uint32_t state[8];
    unsigned char buffer[64] = {0};
    uint64_t bytes{0};
public:
    static constexpr size_t outputLen = 28;
    SHA224();
    SHA224& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[outputLen]);
    SHA224& Reset();
};

#endif //SHA2_224_H
