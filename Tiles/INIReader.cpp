#include "INIReader.h"

std::string getValueFromFile(std::string PropertyName, std::string FileDir)
{
	std::string contents;
	std::string returnval, returnval2;
	bool bDummy = false;
	std::ifstream INI(FileDir);
	
	if (INI.is_open())
	{
		while (std::getline(INI, contents))
		{
			if (strstr(contents.c_str(), PropertyName.c_str()) != NULL)
			{
				for (int i = 0; i < contents.size(); i ++)
				{
					returnval.push_back(contents[i]);
				}
			}
		}
		INI.close();
	}
	else
	{
		std::cout << "cannot open file" << std::endl;
	}

	for (int i = 0; i < returnval.size(); i ++)
	{
		if (i != 0 && i != 1 && returnval[i - 2] == '=')
		{
			bDummy = true;
		}
		if (bDummy == true)
		{
			returnval2.push_back(returnval[i]);
		}
	}

	return returnval2;
}

void ChangeValue(std::string PropertyName, std::string value, std::string FileDir)
{
	
}

bool StringToBool(std::string str)
{
	if (str == "true" || str[0] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}