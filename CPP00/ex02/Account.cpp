/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:40:51 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/18 17:42:06 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;


/*************************** CONSTRUCTOR **********************/
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), 
_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	
	_displayTimestamp();
	_nbAccounts++;
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
}

/*************************** DESTRUCTOR ***********************/
Account::~Account(void)
{
	return;
}

/************************* PUBLIC FUNCTIONS ********************/

int	Account::getNbAccounts(void)
{
	return 1;
}

int	Account::getTotalAmount(void)
{
	return 1;	
}

int	Account::getNbDeposits(void)
{
	return 1;
}

int	Account::getNbWithdrawals(void)
{
	return 1;
}

/*********Premiere fonction appelee************/
void	Account::displayAccountsInfos(void)
{
	// _displayTimestamp();
}

void	Account::makeDeposit(int deposit)
{
	(void)deposit;
	return ;
}

bool Account::makeWithdrawal(int withdrawal)
{
	(void)withdrawal;
	return true;	
}

int	Account::checkAmount(void) const
{
	return 1;
}

void	Account::displayStatus(void) const
{
	// _displayTimestamp();
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