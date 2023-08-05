#pragma once
#include <string>
#include <vector>
#include "property.h"

class readCSV
{
public:
	std::vector<Property> CSVread(const std::string& filepath);
};
