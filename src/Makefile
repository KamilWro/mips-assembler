# Kamil Breczko (280 990)

CXXFLAGS = -std=c++14 -Wall -Wextra

CXX = g++

main : main.o Parser.o Lexer.o Mips.o
	$(CXX) $(CXXFLAGS) -o mipsasm main.o Parser.o Lexer.o Mips.o

main.o : main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp -o  main.o

Lexer.o : Lexer.cpp Lexer.h
	$(CXX) -c $(CXXFLAGS) Lexer.cpp -o Lexer.o

Parser.o : Parser.cpp Parser.h
	$(CXX) -c $(CXXFLAGS) Parser.cpp -o  Parser.o

Mips.o : Mips.cpp Mips.h
	$(CXX) -c $(CXXFLAGS) Mips.cpp -o  Mips.o

clean:
	rm -rf *.o

distclean:
	rm -rf *.o mipsasm .*.swp