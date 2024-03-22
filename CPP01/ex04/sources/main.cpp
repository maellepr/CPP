/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:54:32 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/22 16:47:13 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	openStream(std::ifstream *ifs, std::ofstream *ofs)
{
	if (!ifs->is_open())
	{
		std::cout << "Error opening the input file" << std::endl;
		return -1;
	}
	if (!ofs->is_open())
	{
		std::cout << "Error opening the output file" << std::endl;
		return -1;
	}
	return 0;
}

int	checkString(std::string s1, std::string s2)
{
	if (s1.empty())
	{
		std::cout << "La string a remplacer est nulle, entrez une string non nulle" << std::endl;
		return -1;
	}
	if (s2.empty())
	{
		std::cout << "La string qui remplace est nulle, entrer une string non nulle" << std::endl;
		return -1;
	}
	return 0;
}

int	replaceString(std::ifstream *ifs, std::ofstream *ofs, std::string s1, std::string s2)
{
	std::string	line;
	size_t		pos;
	size_t		i;
	
	pos = 0;
	while (std::getline(ifs, line))
	{
		i = 0;
		while (i < line.size())
		{
			pos = line.find(i);
			if (pos != std::string::npos)// si on a trouve une occurence
			{
				*ofs << line.substr(i, pos - i) << s2;// i = index de debut
				i = pos + s2.size();
			}
			else// sinon
			{
				*ofs << line.substr(i, line.size() - i);
				break ;
			}
		}
		if (!ifs->eof())
			*ofs << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "The program needs 3 arguments !" << std::endl;
		return -1;
	}
	std::string	inputFile = av[1];
	std::string	s1 = av[2];
	std::string s2 = av[3];
	
	std::ifstream ifs(inputFile);
	std::ofstream ofs("replaceFile");
	
	if (checkString(s1, s2))
		return -1;
	if (openStream(&ifs, &ofs))
		return -1;
	if (replaceString(&ifs, &ofs, s1, s2))
		return -1;

	ifs.close();
	ofs.close();
}