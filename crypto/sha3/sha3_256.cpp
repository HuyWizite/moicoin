#include "sha3_256.h"
#include "keccakf.h"
#include "../common.h"

#include <algorithm>
#include <cassert>


SHA3_256& SHA3_256::Write(std::span<const unsigned char> data) {
    if (buffer_size && data.size() >= sizeof(buffer) - buffer_size) {
        // Fill the buffer and process it.
        std::ranges::copy(data.begin(), data.begin() + (sizeof(buffer) - buffer_size), buffer + buffer_size);
        data = data.subspan(sizeof(buffer) - buffer_size);
        state[pos++] ^= ReadLE64(buffer);
        buffer_size = 0;
        if (pos == rate_buffers) {
            KeccakF(state);
            pos = 0;
        }
    }
    while (data.size() >= sizeof(buffer)) {
        // Process chunks directly from the buffer.
        state[pos++] ^= ReadLE64(data.data());
        data = data.subspan(8);
        if (pos == rate_buffers) {
            KeccakF(state);
            pos = 0;
        }
    }
    if (data.size()) {
        // Keep the remainder in the buffer.
        std::ranges::copy(data.begin(), data.end(), buffer + buffer_size);
        buffer_size += data.size();
    }
    return *this;
}

SHA3_256& SHA3_256::Finalize(std::span<unsigned char> hash) {
    assert(hash.size() == outputLen);
    std::ranges::fill(buffer + buffer_size, buffer + sizeof(buffer), 0);
    buffer[buffer_size] ^= 0x06;
    state[pos] ^= ReadLE64(buffer);
    state[rate_buffers - 1] ^= 0x8000000000000000;
    KeccakF(state);
    for (unsigned i = 0; i < 4; ++i) {
        WriteLE64(hash.data() + 8 * i, state[i]);
    }
    return *this;
}

SHA3_256& SHA3_256::Reset() {
    buffer_size = 0;
    pos = 0;
    std::ranges::fill(std::begin(state), std::end(state), 0);
    return *this;
}
