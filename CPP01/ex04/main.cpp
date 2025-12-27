/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:39:06 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/27 09:28:29 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceString(const std::string& content, const std::string& s1, const std::string& s2)
{
    if (s1.empty())
        return content;
    
    std::string result;
    size_t pos = 0;
    size_t found = 0;
    
    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();

    }
    result += content.substr(pos);
    
    return result;
}

int main(int ac, char* av[])
{
    if (ac != 4)
    {
        std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return 1;
    }
    
    std::string content;
    std::string line;
    while (std::getline(infile, line))
    {
        content += line;
        if (!infile.eof())
            content += "\n";
    }
    infile.close();
    
    std::string result = replaceString(content, s1, s2);
    
    std::string outfilename = filename + ".replace";
    std::ofstream outfile(outfilename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: Cannot create output file " << outfilename << std::endl;
        return 1;
    }
    
    outfile << result;
    outfile.close();
    
    std::cout << "Replacement complete. Output saved to " << outfilename << std::endl;
    return 0;
}
