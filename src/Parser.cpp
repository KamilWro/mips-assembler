#include "Parser.h"

string Parser::parse(Lexer::Token token) {
    Mips::Instruction instruction = mapToInstruction(token.name);
    uint8_t rs = 0, rt = 0, rd = 0, shift = 0;
    uint16_t imm = 0;
    queue<string> parameters = token.parameters;

    for (Mips::Parameter expectedParameter: instruction.parameters) {
        string parameter = popNextParameter(parameters);
        switch (expectedParameter) {
            case Mips::Parameter::SHIFT:
                shift = (uint8_t) mapToNumber(parameter, 0, 31);
                break;

            case Mips::Parameter::IMM16:
                imm = (uint16_t) mapToNumber(parameter, INT16_MIN, INT16_MAX);
                break;

            case Mips::Parameter::RT:
                rt = mapToRegisterCode(parameter);
                break;

            case Mips::Parameter::RD:
                rd = mapToRegisterCode(parameter);
                break;

            case Mips::Parameter::RS:
                rs = mapToRegisterCode(parameter);
                break;
        }
    }

    if (!parameters.empty())
        throw runtime_error("too many parameters");

    if (instruction.format == Mips::Format::I)
        return convertToIFormat(instruction.opcode, rs, rt, imm);

    return convertToRFormat(rs, rt, rd, shift, instruction.funct);
}

string Parser::popNextParameter(queue<string> &parameters) {
    if (parameters.empty())
        throw runtime_error("too few parameters");

    string parameter = parameters.front();
    parameters.pop();
    return parameter;
}

Mips::Instruction Parser::mapToInstruction(string instructionName) {
    if (Mips::instructions.find(instructionName) == Mips::instructions.end())
        throw runtime_error("command not found");

    return Mips::instructions[instructionName];
}


uint8_t Parser::mapToRegisterCode(string reg) {
    if (Mips::registers.find(reg) == Mips::registers.end())
        throw runtime_error("register was expected");

    return Mips::registers[reg];
}

uint32_t Parser::mapToNumber(string num, int32_t min, int32_t max) {
    char *sufix;
    long number = strtol(num.c_str(), &sufix, 0);
    if (sufix == num || *sufix != '\0')
        throw invalid_argument("number was expected");
    if (number > INT16_MAX || number < INT16_MIN)
        throw out_of_range("parameter should be in the range from " + to_string(min) + " to " + to_string(max));

    return (uint32_t) number;
}

string Parser::convertToRFormat(uint8_t rs, uint8_t rt, uint8_t rd, uint8_t shift, uint8_t funct) {
    uint32_t binaryCode = 0;
    binaryCode = rs << 21 | rt << 16 | rd << 11 | shift << 6 | funct;
    return convertToHex(binaryCode);
}

string Parser::convertToIFormat(uint8_t opcode, uint8_t rs, uint8_t rt, uint16_t imm) {
    uint32_t binaryCode = 0;
    binaryCode = opcode << 26 | rs << 21 | rt << 16 | imm;
    return convertToHex(binaryCode);
}

string Parser::convertToHex(uint32_t binaryCode) {
    ostringstream oss;
    oss << internal << setfill('0');
    oss << hex << setw(8) << binaryCode;
    return oss.str();
}