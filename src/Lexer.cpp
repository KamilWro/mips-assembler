#include "Lexer.h"

Lexer::Token Lexer::lex(string line) {
    if (line.find('#') != string::npos)
        line = line.substr(0, line.find('#'));

    if (line.empty() || removeWhiteSpaces(line).empty())
        return {};

    ss.clear();
    ss << line;

    return readData();
}

Lexer::Token Lexer::readData() {
    Token result;
    ss >> result.name;
    result.parameters = extractParameters();
    return result;
}

queue<string> Lexer::extractParameters() {
    queue<string> parameters;
    string parameter;

    while (getline(ss, parameter, ',')) {
        parameters.push(removeWhiteSpaces(parameter));
    }

    return parameters;
}

string Lexer::removeWhiteSpaces(string data) {
    data.erase(remove_if(data.begin(), data.end(), [](unsigned char x) { return isspace(x); }), data.end());
    return data;
}