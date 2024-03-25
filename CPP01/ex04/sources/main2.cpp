/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:40:37 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/25 08:55:17 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	replace(std::ifstream *ifs, std::ofstream *ofs, std::string s1, std::string s2)
{
	std::string	line;
	size_t		pos;
	size_t		i;
	
	pos = 0;
	if (s1.empty() || s2.empty())
	{
		std::cout << "One of the string is null" << std::endl;
		return -1;
	}
	while (std::getline(*ifs, line))
	{	
		if (ifs->fail())
			return -1;
		i = 0;
		while (i < line.size())
		{
			pos = line.find(s1, i);// trouve l'occurence a partir de i, renvoie l'index du debut ou l'occurence apparait
			if (pos != std::string::npos)//verification qu'on a bien trouve la str a remplacer
			{
				*ofs << line.substr(i, pos - i) << s2;
				i = pos + s1.size();
			}
			else//si on a pas trouve la str a remplacer
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

int main (int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong arguments !" << std::endl;
		return 1;
	}
	std::string		infile = av[1];
	std::string		outfile;
	std::string		s1 = av[2];//a remplacer
	std::string		s2 = av[3];//qui remplace

	std::ifstream	ifs(infile.c_str());//c.str()
	ifs.is_open();//ajouter protection 
	std::ofstream	ofs(infile.append("_replace").c_str());//c.str()
	ofs.is_open();//ajouter protection
	replace(&ifs, &ofs, s1, s2);
	ifs.close();
	ofs.close();
}