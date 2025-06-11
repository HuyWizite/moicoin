#ifndef SHA1_H
#define SHA1_H

#include <cstdint>

class SHA1 {
private:
    uint32_t state[5];
    unsigned char buffer[64] = {0};
    uint64_t bytes{0};
public:
    static constexpr size_t outputLen = 20;
    SHA1();
    SHA1& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[outputLen]);
    SHA1& Reset();
};



#endif //SHA1_H
