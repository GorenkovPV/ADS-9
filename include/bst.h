// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::string word = "";
  char lower = 'a' - 'A';
  std::ifstream file(filename);
  if (!file) {
    std::cout << "Error!" << std::endl;
    return tree;
  }
  while (!file.eof()) {
    char symbol = file.get();
    if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) {
      if (symbol >= 'A' && symbol <= 'Z')
        symbol += lower;
      word += symbol;
    } else if (word != "") {
      tree.add(word);
      word = "";
    }
  }
  file.close();
  return tree;
}
