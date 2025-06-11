#ifndef KECCAKF_H
#define KECCAKF_H

#include <bit>
#include <cstdint>

inline void KeccakF(uint64_t (&state)[25]) {
    static constexpr uint64_t RNDC[24] = {
        0x0000000000000001, 0x0000000000008082, 0x800000000000808a, 0x8000000080008000,
        0x000000000000808b, 0x0000000080000001, 0x8000000080008081, 0x8000000000008009,
        0x000000000000008a, 0x0000000000000088, 0x0000000080008009, 0x000000008000000a,
        0x000000008000808b, 0x800000000000008b, 0x8000000000008089, 0x8000000000008003,
        0x8000000000008002, 0x8000000000000080, 0x000000000000800a, 0x800000008000000a,
        0x8000000080008081, 0x8000000000008080, 0x0000000080000001, 0x8000000080008008
    };
    static constexpr int ROUNDS = 24;

    for (int round = 0; round < ROUNDS; ++round) {
        uint64_t bc0, bc1, bc2, bc3, bc4, t;

        // Theta
        bc0 = state[0] ^ state[5] ^ state[10] ^ state[15] ^ state[20];
        bc1 = state[1] ^ state[6] ^ state[11] ^ state[16] ^ state[21];
        bc2 = state[2] ^ state[7] ^ state[12] ^ state[17] ^ state[22];
        bc3 = state[3] ^ state[8] ^ state[13] ^ state[18] ^ state[23];
        bc4 = state[4] ^ state[9] ^ state[14] ^ state[19] ^ state[24];
        t = bc4 ^ std::rotl(bc1, 1); state[0] ^= t; state[5] ^= t; state[10] ^= t; state[15] ^= t; state[20] ^= t;
        t = bc0 ^ std::rotl(bc2, 1); state[1] ^= t; state[6] ^= t; state[11] ^= t; state[16] ^= t; state[21] ^= t;
        t = bc1 ^ std::rotl(bc3, 1); state[2] ^= t; state[7] ^= t; state[12] ^= t; state[17] ^= t; state[22] ^= t;
        t = bc2 ^ std::rotl(bc4, 1); state[3] ^= t; state[8] ^= t; state[13] ^= t; state[18] ^= t; state[23] ^= t;
        t = bc3 ^ std::rotl(bc0, 1); state[4] ^= t; state[9] ^= t; state[14] ^= t; state[19] ^= t; state[24] ^= t;

        // Rho Pi
        t = state[1];
        bc0 = state[10]; state[10] = std::rotl(t, 1); t = bc0;
        bc0 = state[7]; state[7] = std::rotl(t, 3); t = bc0;
        bc0 = state[11]; state[11] = std::rotl(t, 6); t = bc0;
        bc0 = state[17]; state[17] = std::rotl(t, 10); t = bc0;
        bc0 = state[18]; state[18] = std::rotl(t, 15); t = bc0;
        bc0 = state[3]; state[3] = std::rotl(t, 21); t = bc0;
        bc0 = state[5]; state[5] = std::rotl(t, 28); t = bc0;
        bc0 = state[16]; state[16] = std::rotl(t, 36); t = bc0;
        bc0 = state[8]; state[8] = std::rotl(t, 45); t = bc0;
        bc0 = state[21]; state[21] = std::rotl(t, 55); t = bc0;
        bc0 = state[24]; state[24] = std::rotl(t, 2); t = bc0;
        bc0 = state[4]; state[4] = std::rotl(t, 14); t = bc0;
        bc0 = state[15]; state[15] = std::rotl(t, 27); t = bc0;
        bc0 = state[23]; state[23] = std::rotl(t, 41); t = bc0;
        bc0 = state[19]; state[19] = std::rotl(t, 56); t = bc0;
        bc0 = state[13]; state[13] = std::rotl(t, 8); t = bc0;
        bc0 = state[12]; state[12] = std::rotl(t, 25); t = bc0;
        bc0 = state[2]; state[2] = std::rotl(t, 43); t = bc0;
        bc0 = state[20]; state[20] = std::rotl(t, 62); t = bc0;
        bc0 = state[14]; state[14] = std::rotl(t, 18); t = bc0;
        bc0 = state[22]; state[22] = std::rotl(t, 39); t = bc0;
        bc0 = state[9]; state[9] = std::rotl(t, 61); t = bc0;
        bc0 = state[6]; state[6] = std::rotl(t, 20); t = bc0;
        state[1] = std::rotl(t, 44);

        // Chi Iota
        bc0 = state[0]; bc1 = state[1]; bc2 = state[2]; bc3 = state[3]; bc4 = state[4];
        state[0] = bc0 ^ (~bc1 & bc2) ^ RNDC[round];
        state[1] = bc1 ^ (~bc2 & bc3);
        state[2] = bc2 ^ (~bc3 & bc4);
        state[3] = bc3 ^ (~bc4 & bc0);
        state[4] = bc4 ^ (~bc0 & bc1);
        bc0 = state[5]; bc1 = state[6]; bc2 = state[7]; bc3 = state[8]; bc4 = state[9];
        state[5] = bc0 ^ (~bc1 & bc2);
        state[6] = bc1 ^ (~bc2 & bc3);
        state[7] = bc2 ^ (~bc3 & bc4);
        state[8] = bc3 ^ (~bc4 & bc0);
        state[9] = bc4 ^ (~bc0 & bc1);
        bc0 = state[10]; bc1 = state[11]; bc2 = state[12]; bc3 = state[13]; bc4 = state[14];
        state[10] = bc0 ^ (~bc1 & bc2);
        state[11] = bc1 ^ (~bc2 & bc3);
        state[12] = bc2 ^ (~bc3 & bc4);
        state[13] = bc3 ^ (~bc4 & bc0);
        state[14] = bc4 ^ (~bc0 & bc1);
        bc0 = state[15]; bc1 = state[16]; bc2 = state[17]; bc3 = state[18]; bc4 = state[19];
        state[15] = bc0 ^ (~bc1 & bc2);
        state[16] = bc1 ^ (~bc2 & bc3);
        state[17] = bc2 ^ (~bc3 & bc4);
        state[18] = bc3 ^ (~bc4 & bc0);
        state[19] = bc4 ^ (~bc0 & bc1);
        bc0 = state[20]; bc1 = state[21]; bc2 = state[22]; bc3 = state[23]; bc4 = state[24];
        state[20] = bc0 ^ (~bc1 & bc2);
        state[21] = bc1 ^ (~bc2 & bc3);
        state[22] = bc2 ^ (~bc3 & bc4);
        state[23] = bc3 ^ (~bc4 & bc0);
        state[24] = bc4 ^ (~bc0 & bc1);
    }
}

#endif //KECCAKF_H

