#ifndef MIPSASM_MIPS_H
#define MIPSASM_MIPS_H

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Mips {
public:
    enum class Format {
        R,
        I
    };

    enum class Parameter {
        RS,
        RT,
        RD,
        IMM16,
        SHIFT
    };

    struct Instruction {
        uint8_t opcode;
        uint8_t funct;
        Format format;
        vector<Parameter> parameters;
    };

    static unordered_map<string, Instruction> instructions;

    static unordered_map<string, uint8_t> registers;
};


#endif
