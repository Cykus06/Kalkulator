#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "dzialania.cpp"

void dopelnienie(int temp, std::string& str);
std::string dodawanie(std::string a, std::string b);
void mnowl(const int N, std::string a, std::string b, std::vector<std::string>& dodatki);
std::string mnozenie(std::string a, std::string b);
bool mniejsze(std::string a, std::string b);
std::string dzielenie(std::string a, std::string b);
std::string silnia(std::string a);