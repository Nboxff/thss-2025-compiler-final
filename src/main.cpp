#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "SysYLexer.h"
#include "SysYParser.h"
#include "SysYParserBaseVisitor.h"

using namespace antlr4;

int main(int argc, const char *argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: ./compiler <input-file> <output-file>"
              << std::endl;
    return 1;
  }

  std::ifstream stream;
  stream.open(argv[1]);
  if (!stream.is_open()) {
      std::cerr << "Failed to open input file: " << argv[1] << std::endl;
      return 1;
  }

  ANTLRInputStream input(stream);
  SysYLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  SysYParser parser(&tokens);

  tree::ParseTree *tree = parser.compUnit();

  if (parser.getNumberOfSyntaxErrors() > 0) {
      std::cerr << "Syntax error detected." << std::endl;
      return 1;
  }

  std::cout << "Parsed successfully!" << std::endl;

  // TODO: IR Generation

  return 0;
}