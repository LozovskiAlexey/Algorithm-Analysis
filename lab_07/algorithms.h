#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

using  shift_t = std::vector<size_t>;

int standart(std::string str, std::string substr);
int kmp(std::string str, std::string substr); // Кнут-Моррис-Пратт
int bm(std::string str, std::string substr); // Бойер-Мурр

std::map<char, size_t> get_shift(const std::string &substr);
shift_t get_shift(const std::string &substr, const size_t &size);

#endif // ALGORITHMS_H
