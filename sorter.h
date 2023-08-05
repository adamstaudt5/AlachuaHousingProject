#pragma once
#include <vector>
#include <string>
#include "property.h"

void merge(std::vector<Property>& properties, size_t left, size_t mid, size_t right);

void mergeSort(std::vector<Property>& properties, size_t left, size_t right);

void cityMerge(std::vector<Property>& properties, size_t left, size_t mid, size_t right);

void mergeSortCity(std::vector<Property>& properties, size_t left, size_t right);

void insertProperty(std::vector<Property>& properties, const Property& newProperty);

void deleteProperty(std::vector<Property>& properties, const Property& newProperty);