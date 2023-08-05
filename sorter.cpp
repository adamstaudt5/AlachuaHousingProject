#include <vector>
#include <string>
#include "property.h"

void merge(std::vector<Property>& properties, size_t left, size_t mid, size_t right)
{
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    std::vector<Property> leftSplit(n1);
    std::vector<Property> rightSplit(n2);

    for (size_t i = 0; i < n1; i++)
    {
        leftSplit[i] = properties[left + i];
    }
    for (size_t j = 0; j < n2; j++)
    {
        rightSplit[j] = properties[mid + 1 + j];
    }

    size_t i = 0;
    size_t j = 0;
    size_t k = left;

    while (i < n1 && j < n2) 
    {
        if (leftSplit[i].getMarketValue() <= rightSplit[j].getMarketValue()) 
        {
            properties[k] = leftSplit[i];
            i++;
        }
        else 
        {
            properties[k] = rightSplit[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        properties[k] = leftSplit[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        properties[k] = rightSplit[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Property>& properties, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;
		mergeSort(properties, left, mid);
		mergeSort(properties, mid + 1, right);

		
		merge(properties, left, mid, right);
	}
}

void cityMerge(std::vector<Property>& properties, size_t left, size_t mid, size_t right)
{
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    std::vector<Property> leftSplit(n1);
    std::vector<Property> rightSplit(n2);

    for (size_t i = 0; i < n1; i++)
    {
        leftSplit[i] = properties[left + i];
    }
    for (size_t j = 0; j < n2; j++)
    {
        rightSplit[j] = properties[mid + 1 + j];
    }

    size_t i = 0;
    size_t j = 0;
    size_t k = left;

    while (i < n1 && j < n2)
    {

        if (leftSplit[i].getCity() <= rightSplit[j].getCity())
        {
            properties[k] = leftSplit[i];
            i++;
        }
        else
        {
            properties[k] = rightSplit[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        properties[k] = leftSplit[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        properties[k] = rightSplit[j];
        j++;
        k++;
    }
}

void mergeSortCity(std::vector<Property>& properties, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = left + (right - left) / 2;
        mergeSortCity(properties, left, mid);
        mergeSortCity(properties, mid + 1, right);

        cityMerge(properties, left, mid, right);
    }
}

void insertProperty(std::vector<Property>& properties, const Property& newProperty)
{
    if (properties.empty() || newProperty.getMarketValue() >= properties.back().getMarketValue())
    {
        properties.push_back(newProperty);
        return;
    }

    auto it = std::lower_bound(properties.begin(), properties.end(), newProperty,
        [](const Property& a, const Property& b) {
            return a.getMarketValue() < b.getMarketValue();
        });

    properties.insert(it, newProperty);
}

void deleteProperty(std::vector<Property>& properties, const Property& newProperty)
{
    auto it = std::lower_bound(properties.begin(), properties.end(), newProperty,
        [](const Property& a, const Property& b) { return a.getMarketValue() < b.getMarketValue(); });

    if (it != properties.end() && *it == newProperty)
    {
        properties.erase(it);
    }
}
