#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include "property.h"
#include "readCSV.h"
#include "sorter.h"

int main()
{
	readCSV read;
	std::string const path = "NAL11F202201.csv";

	auto start = std::chrono::high_resolution_clock::now();
	std::vector<Property> properties = read.CSVread(path);
	auto end = std::chrono::high_resolution_clock::now();
	auto fileReadTime = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

	std::cout << properties.size() << " properties extracted from file in " << fileReadTime << " seconds." << std::endl;


	/*********************************************************************************/
	/*                   Comparing Merge Sort vs Standard Sort                       */
	/*                                For City                                       */
	/*********************************************************************************/

	start = std::chrono::high_resolution_clock::now(); // Starts timer
	mergeSortCity(properties, 0, properties.size() - 1);
	end = std::chrono::high_resolution_clock::now(); // Ends timer
	auto mergeSortCityTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Finds time taken
	std::cout << "Merge Sort by City Time: " << mergeSortCityTime << " milliseconds." << std::endl;

	std::vector<Property> stdSortProperties = properties;

	start = std::chrono::high_resolution_clock::now(); // Starts timer
	std::sort(stdSortProperties.begin(), stdSortProperties.end(), [](const Property& a, const Property& b)
		{
			return a.getCity() < b.getCity();
		});
	end = std::chrono::high_resolution_clock::now(); // Ends timer
	auto stdSortCityTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Finds time taken
	std::cout << "Standard Sort by City Time: " << stdSortCityTime << " milliseconds." << std::endl;


	/*********************************************************************************/
	/*                   Comparing Merge Sort vs Standard Sort                       */
	/*                              For Market Value                                 */
	/*********************************************************************************/
	
	start = std::chrono::high_resolution_clock::now(); // Starts timer
	mergeSort(properties, 0, properties.size() - 1);
	end = std::chrono::high_resolution_clock::now(); // Ends timer
	auto mergeSortTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Finds time taken
	std::cout << "Merge Sort by Market Value Time: " << mergeSortTime << " milliseconds." << std::endl;

	start = std::chrono::high_resolution_clock::now(); // Starts timer
	std::sort(stdSortProperties.begin(), stdSortProperties.end(), [](const Property& a, const Property& b)
		{
			return a.getMarketValue() < b.getMarketValue();
		});
	end = std::chrono::high_resolution_clock::now(); // Ends timer
	auto stdSortTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Finds time taken
	std::cout << "Standard Sort by Market Value Time: " << stdSortTime << " milliseconds." << std::endl;
	

	/*********************************************************************************/
	/*             Comparing Lower_Bound Insertion vs Standard Insertion             */
	/*                                                                               */
	/*********************************************************************************/

	std::vector<Property> customProperties = properties; // Vector that will be used to store Lower_Bound Insert
	std::vector<Property> standardProperties = stdSortProperties; // Vector that will be used to store the Standard Insert

	Property newProperty(150000, 111111, 2000, "123 Street", "Gainesville", "Residential"); // Property that will be inserted in the vector

	start = std::chrono::high_resolution_clock::now(); // Starts timer
	insertProperty(customProperties, newProperty);
	end = std::chrono::high_resolution_clock::now(); // Ends timer
	auto customInsertTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Finds time taken
	std::cout << "Custom Insert Time: " << customInsertTime << " milliseconds." << std::endl;

	start = std::chrono::high_resolution_clock::now(); // Starts timer
	standardProperties.push_back(newProperty);
	std::sort(standardProperties.begin(), standardProperties.end(), [](const Property& a, const Property& b)
		{
			return a.getMarketValue() < b.getMarketValue();
		});
	end = std::chrono::high_resolution_clock::now(); // Ends timer
	auto stdInsertTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Finds time taken
	std::cout << "Standard Insert Time: " << stdInsertTime << " milliseconds." << std::endl;


	/*********************************************************************************/
	/*             Comparing Lower_Bound Deletion vs Standard Deletion               */
	/*                                                                               */
	/*********************************************************************************/

	start = std::chrono::high_resolution_clock::now(); // Starts timer
	deleteProperty(customProperties, newProperty); // Searches for and deletes the Property that was just added in customProperties vector
	end = std::chrono::high_resolution_clock::now(); // Ends timer
	auto customDeleteTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Finds time taken
	std::cout << "Custom Delete Time: " << customDeleteTime << " milliseconds." << std::endl;

	start = std::chrono::high_resolution_clock::now(); // Starts timer
	auto it = std::remove(standardProperties.begin(), standardProperties.end(), newProperty);
	standardProperties.resize(std::distance(standardProperties.begin(), it));
	end = std::chrono::high_resolution_clock::now(); // Ends timer
	auto stdDeleteTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Finds time taken
	std::cout << "Standard Delete Time: " << stdDeleteTime << " milliseconds." << std::endl;

	/*
	for (const auto& it : properties)
	{
		std::cout << "Property Type: " << it.getPropertyType() << std::endl;
		std::cout << "Value: " << it.getMarketValue() << std::endl;
		std::cout << "Year: " << it.getYearBuilt() << std::endl;
		std::cout << "Address: " << it.getAddress() << std::endl;
		std::cout << "City: " << it.getCity() << std::endl;
		std::cout << "ZIP: " << it.getZipCode() << std::endl;
		std::cout << "------------------" << std::endl;
	}
	*/

	return 0;
}