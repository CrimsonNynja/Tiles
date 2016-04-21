#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string getValueFromFile(std::string PropertyName, std::string FileDir);
void ChangeValue(std::string PropertyName, std::string value, std::string FileDir);
bool StringToBool(std::string str);