#ifndef MIPSASM_PARSER_H
#define MIPSASM_PARSER_H

#include <cstdint>
#include <string>
#include <iomanip>
#include "Lexer.h"
#include "Mips.h"

using namespace std;

class Parser {
public:
    string parse(Lexer::Token token);

    string convertToHex(uint32_t binaryCode);

private:
    string convertToRFormat(uint8_t rs, uint8_t rt, uint8_t rd, uint8_t shift, uint8_t funct);

    string convertToIFormat(uint8_t opcode, uint8_t rs, uint8_t rt, uint16_t imm);

    uint8_t mapToRegisterCode(string reg);

    uint32_t mapToNumber(string num, int32_t min, int32_t max);

    Mips::Instruction mapToInstruction(string instructionName);

    string popNextParameter(queue<string> &parameters);
};

#endif
