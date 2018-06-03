#include <iostream>
#include <iomanip>
#include "Lexer.h"
#include "Parser.h"

string proccessLine(const string &line, uint32_t &address, Lexer &lexer, Parser &parser);

using namespace std;

int main() {
    string line;
    uint32_t address = 0;
    Lexer lexer;
    Parser parser;

    try {
        cout << ".text" << endl;
        while (getline(cin, line)) {
            cout << proccessLine(line, address, lexer, parser) << endl;
        }
    } catch (const exception &e) {
        cerr << "The conversion was unsuccessful: " << e.what() << endl;
        return -1;
    }

    return 0;
}

string proccessLine(const string &line, uint32_t &address, Lexer &lexer, Parser &parser) {
    Lexer::Token token = lexer.lex(line);

    if (token.name.empty() && token.parameters.empty())
        return line;

    string binaryAddress = parser.convertToHex(address);
    string binaryCode = parser.parse(token);
    address += binaryCode.length() / 2;

    return binaryAddress + " " + binaryCode + " " + line;
}