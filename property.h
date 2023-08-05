#pragma once
#include <string>

class Property
{
    int marketValue;
    int zipCode;
    int yearBuilt;
    std::string address;
    std::string city;
    std::string propertyType;

public:
    Property()
        : marketValue(0), zipCode(0), yearBuilt(0), address(""), city(""), propertyType("") {}

    Property(int MARKETVALUE, int ZIPCODE, int YEARBUILT, std::string ADDRESS, std::string CITY, std::string PROPERTYTYPE)
        : marketValue(MARKETVALUE), zipCode(ZIPCODE), yearBuilt(YEARBUILT), address(ADDRESS), city(CITY), propertyType(PROPERTYTYPE) {};

    bool operator==(const Property& other) const;

    int getMarketValue() const;

    void setMarketValue(int newMarketValue);

    int getZipCode() const;

    void setZipCode(int newZipCode);

    int getYearBuilt() const;

    void setYearBuilt(int newYearBuilt);

    std::string getAddress() const;

    void setAddress(const std::string& newAddress);

    std::string getCity() const;

    void setCity(const std::string& newCity);

    std::string getPropertyType() const;

    void setPropertyType(const std::string& newPropertyType);
};
