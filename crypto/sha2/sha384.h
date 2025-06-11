#ifndef SHA2_384_H
#define SHA2_384_H

#include <cstdint>

class SHA384 {
private:
    uint64_t state[8];
    unsigned char buffer[128] = {0};
    uint64_t bytes{0};
public:
    static constexpr size_t outputLen = 48;
    SHA384();
    SHA384& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[outputLen]);
    SHA384& Reset();
    uint64_t Size() const { return bytes; }
};

#endif //SHA2_384_H
