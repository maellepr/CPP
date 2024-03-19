/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:40:51 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/19 11:13:17 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


/*************************** CONSTRUCTOR *************************/
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), 
_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	
	_displayTimestamp();
	_nbAccounts++;
	_totalAmount += _amount;
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
}

/*************************** DESTRUCTOR **************************/
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ";"
			  << "closed" << std::endl;
	return;
}

/************************* PUBLIC FUNCTIONS *********************/

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);	
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

/* 1ere fonction appelee et est appelee trois fois 
au cours du programme. Donne les infos generales des 
transactions */
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			<< "total:" << getTotalAmount() << ";"
			<< "deposits:" << getNbDeposits() << ";"
			<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

/* 2eme fonction appelee et est appelee trois fois
egalement. Donne les infos specifiques a chaque compte */
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "deposits:" << _nbDeposits << ";"
			<< "withdrawals:" << _nbWithdrawals << std::endl;
}

/* 3eme fonction appelee qui permet d'effectuer un depot
d'argent sur chacun des comptes */
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << "deposit:" << deposit << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_deposits:" << "1" << std::endl;
	return ;
}

/* 4eme fonction appelee qui permet de faire un retrait 
d'argent sur chacun des comptes */
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << this->_amount << ";"
			  << "withdrawal:";
	this->_amount -= withdrawal;
	if (checkAmount() < 0)
	{
		this->_amount += withdrawal;
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";";
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";"
			  << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

/************************ PRIVATE FUNCTIONS *******************/

void	Account::_displayTimestamp(void)
{
	std::time_t	current_time = std::time(0);
	std::tm *timeinfo = std::localtime(&current_time);

	std::cout << "[" 
	<< (timeinfo->tm_year + 1900)
	<< std::setw(2) << std::setfill('0') << (timeinfo->tm_mon + 1)
	<< std::setw(2) << std::setfill('0') << (timeinfo->tm_mday) << "_"
	<< std::setw(2) << std::setfill('0') << (timeinfo->tm_hour)
	<< std::setw(2) << std::setfill('0') << (timeinfo->tm_min)
	<< std::setw(2) << std::setfill('0') << (timeinfo->tm_sec) << "] ";
	return ;
}
