/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:54:32 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 09:56:40 by mapoirie         ###   ########.fr       */
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
		std::cout << "La string qui doit etre remplacee est nulle, entrez une string non nulle" << std::endl;
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
	while (std::getline(*ifs, line))//tant qu'il y a des lignes, on lit ligne apres ligne
	{
		i = 0;
		if (ifs->fail())
			return -1;
		while (i < line.size())//on va lire char par char, tant qu'il y en a 
		{
			pos = line.find(s1, i);//cherche l'occurence s1 a partir de l'index i
			if (pos != std::string::npos)// si on a trouve une occurence
			{
				*ofs << line.substr(i, pos - i) << s2;// on ecrit dans le outfile
				i = pos + s1.size();// on avance l'index de la taille de s1 pour passer a la suite dans le infile
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
	return 0;
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
	
	std::ifstream ifs(inputFile.c_str());
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