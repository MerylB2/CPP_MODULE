/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:36:40 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/03/25 14:52:15 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "colors.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{}

static int pseudoLiterals(const std::string &input)
{
    if (input == "nan" || input == "nanf")
    {
        std::cout << GOLD << "char:   " << REDD << "impossible" << RST << std::endl;
        std::cout << GOLD << "int:    " << REDD << "impossible" << RST << std::endl;
        std::cout << GOLD << "float:  " << LIME << "nanf"       << RST << std::endl;
        std::cout << GOLD << "double: " << LIME << "nan"        << RST << std::endl;
        return 1;
    }
    else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
    {
        std::cout << GOLD << "char:   " << REDD << "impossible" << RST << std::endl;
        std::cout << GOLD << "int:    " << REDD << "impossible" << RST << std::endl;
        std::cout << GOLD << "float:  " << LIME << "+inff"      << RST << std::endl;
        std::cout << GOLD << "double: " << LIME << "+inf"       << RST << std::endl;
        return 1;
    }
    else if (input == "-inf" || input == "-inff")
    {
        std::cout << GOLD << "char:   " << REDD << "impossible" << RST << std::endl;
        std::cout << GOLD << "int:    " << REDD << "impossible" << RST << std::endl;
        std::cout << GOLD << "float:  " << LIME << "-inff"      << RST << std::endl;
        std::cout << GOLD << "double: " << LIME << "-inf"       << RST << std::endl;
        return 1;
    }
    return 0;
}

static int isChar(const std::string &input)
{
    if (input.length() == 1 && !isdigit(input[0]))
    {
        char c = input[0];
        std::cout << GOLD << "char:   " << LIME << "'" << c << "'" << RST << std::endl;
        std::cout << GOLD << "int:    " << LIME << static_cast<int>(c) << RST << std::endl;
        std::cout << GOLD << "float:  " << LIME << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << RST << std::endl;
        std::cout << GOLD << "double: " << LIME << std::fixed << std::setprecision(1) << static_cast<double>(c) << RST << std::endl;
        return 1;
    }
    return 0;
}

static int isInt(const std::string &input)
{
    char *end;
    long l = strtol(input.c_str(), &end, 10); // strtol is used (base 10) to convert string to long and check for errors; in case of overflow, it sets errno and returns LONG_MAX or LONG_MIN, which we check against INT_MAX and INT_MIN
    if (*end != '\0' || l < INT_MIN || l > INT_MAX)
        return 0;

    int i = static_cast<int>(l); // We can safely cast to int since we've already checked the range
    char c = static_cast<char>(i); // We can safely cast to char since we'll check if it's displayable before printing

    if (isprint(c))
        std::cout << GOLD << "char:   " << LIME << "'" << c << "'" << RST << std::endl;
    else
        std::cout << GOLD << "char:   " << REDD << "Non displayable" << RST << std::endl;
    std::cout << GOLD << "int:    " << LIME << i << RST << std::endl;
    std::cout << GOLD << "float:  " << LIME << std::fixed << std::setprecision(1) << static_cast<float>(i)  << "f" << RST << std::endl;
    std::cout << GOLD << "double: " << LIME << std::fixed << std::setprecision(1) << static_cast<double>(i) << RST << std::endl;
    return 1;
}

static int isFloat(const std::string &input)
{
    char *end;
    float f = strtof(input.c_str(), &end);
    if (*end != 'f' || *(end + 1) != '\0')
        return 0;

    double d = static_cast<double>(f);

    if (f >= 32.0f && f <= 126.0f)
        std::cout << GOLD << "char:   " << LIME << "'" << static_cast<char>(f) << "'" << RST << std::endl;
    else if (f >= 0.0f && f <= 127.0f)
        std::cout << GOLD << "char:   " << REDD << "Non displayable" << RST << std::endl;
    else
        std::cout << GOLD << "char:   " << REDD << "impossible" << RST << std::endl;
    if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX))
        std::cout << GOLD << "int:    " << LIME << static_cast<int>(f) << RST << std::endl;
    else
        std::cout << GOLD << "int:    " << REDD << "impossible" << RST << std::endl;
    std::cout << GOLD << "float:  " << LIME << std::fixed << std::setprecision(1) << f << "f" << RST << std::endl;
    std::cout << GOLD << "double: " << LIME << std::fixed << std::setprecision(1) << d << RST << std::endl;
    return 1;
}

static int isDouble(const std::string &input)
{
    char *end;
    double d = strtod(input.c_str(), &end); // strtod is used to convert string to double and check for errors;
    if (*end != '\0' || input.find('.') == std::string::npos)
        return 0;

    float f = static_cast<float>(d);

    if (d >= 32.0 && d <= 126.0)
        std::cout << GOLD << "char:   " << LIME << "'" << static_cast<char>(d) << "'" << RST << std::endl;
    else if (d >= 0.0 && d <= 127.0)
        std::cout << GOLD << "char:   " << REDD << "Non displayable" << RST << std::endl;
    else
        std::cout << GOLD << "char:   " << REDD << "impossible" << RST << std::endl;
    if (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX))
        std::cout << GOLD << "int:    " << LIME << static_cast<int>(d) << RST << std::endl;
    else
        std::cout << GOLD << "int:    " << REDD << "impossible" << RST << std::endl;
    std::cout << GOLD << "float:  " << LIME << std::fixed << std::setprecision(1) << f << "f" << RST << std::endl;
    std::cout << GOLD << "double: " << LIME << std::fixed << std::setprecision(1) << d << RST << std::endl;
    return 1;
}

void ScalarConverter::convert(const std::string &input)
{
    if (pseudoLiterals(input))
        return;
    if (isChar(input))
        return;
    if (isInt(input))
        return;
    if (isFloat(input))
        return;
    if (isDouble(input))
        return;
    std::cout << GOLD << "char:   " << REDD << "impossible" << RST << std::endl;
    std::cout << GOLD << "int:    " << REDD << "impossible" << RST << std::endl;
    std::cout << GOLD << "float:  " << REDD << "impossible" << RST << std::endl;
    std::cout << GOLD << "double: " << REDD << "impossible" << RST << std::endl;
}
