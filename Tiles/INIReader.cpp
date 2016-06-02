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
	std::string contents;
	std::vector<std::string> contentsFull;
	std::ifstream file(FileDir);
	
	if (file.is_open())
	{
		while (std::getline(file, contents))
		{
			contentsFull.push_back(contents);
		}
		for (unsigned i = 0; i < contentsFull.size(); i++)
		{
			if (strstr(contentsFull[i].c_str(), PropertyName.c_str()) != NULL)
			{
				contentsFull[i] = PropertyName + " = " + value;
			}
		}
	}
	file.close();


	std::ofstream file2(FileDir);
	for (auto x: contentsFull)
	{
		file2 << x << std::endl;
	}

	file2.close();
}

bool StringToBool(std::string str)
{
	if (str[0] == '1' || str == "true")
	{
		return true;
	}
	else
	{
		return false;
	}
}