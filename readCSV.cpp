#include <string>
#include <vector>
#include "property.h"
#include "readCSV.h"
#include "rapidcsv.h"

namespace rapidcsv
{
	template<>
	void Converter<int>::ToVal(const std::string& pStr, int& pVal) const
	{
		if (pStr == "")
			pVal = 0;
		else
			pVal = std::stoi(pStr);
	}
}


std::vector<Property> readCSV::CSVread(const std::string& filepath)
{
	std::vector<Property> properties;

	rapidcsv::Document csv(filepath);


	const auto& propertyTypeValue = csv.GetColumn<int>("DOR_UC");
	const auto& marketValue = csv.GetColumn<int>("JV");
	const auto& yearBuiltValue = csv.GetColumn<int>("ACT_YR_BLT");
	const auto& addressValue = csv.GetColumn<std::string>("PHY_ADDR1");
	const auto& cityValue = csv.GetColumn<std::string>("PHY_CITY");
	const auto& zipCodeValue = csv.GetColumn<int>("PHY_ZIPCD");


	size_t numRows = propertyTypeValue.size();

	std::vector<std::string> propertyType(numRows);
	std::vector<int> yearBuilt(numRows);
	std::vector<std::string> address(numRows);
	std::vector<std::string> city(numRows);
	std::vector<int> zipCode(numRows);


	for (size_t i = 0; i < numRows; i++)
	{
		if (propertyTypeValue[i] != 3 && propertyTypeValue[i] <= 9)
		{
			propertyType[i] = "Residential";
		}
		else if (propertyTypeValue[i] == 3)
		{
			propertyType[i] = "Apartment Complex";
		}
		else if (propertyTypeValue[i] >= 10 && propertyTypeValue[i] <= 39)
		{
			propertyType[i] = "Commercial";
		}
		else if (propertyTypeValue[i] >= 40 && propertyTypeValue[i] <= 49)
		{
			propertyType[i] = "Industrial";
		}
		else if (propertyTypeValue[i] >= 50 && propertyTypeValue[i] <= 69)
		{
			propertyType[i] = "Agricultural";
		}
		else if (propertyTypeValue[i] >= 70 && propertyTypeValue[i] <= 79)
		{
			propertyType[i] = "Institutional";
		}
		else if (propertyTypeValue[i] >= 80 && propertyTypeValue[i] <= 89)
		{
			propertyType[i] = "Governmental";
		}
		else
		{
			propertyType[i] = "Miscellaneous";
		}

		if (!addressValue[i].empty())
		{
			address[i] = addressValue[i];
		}
		else
		{
			address[i] = "N/A";
		}

		if (!cityValue[i].empty())
		{
			city[i] = cityValue[i];
		}
		else
		{
			city[i] = "N/A";
		}

		properties.push_back(Property(marketValue[i], zipCodeValue[i], yearBuiltValue[i], address[i], city[i], propertyType[i]));

	}

	return properties;
}
