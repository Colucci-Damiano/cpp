
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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

void	Account::displayAccountsInfos(void)
{
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

Account::Account(int initialDeposit)
{
	this->_accountIndex = Account::getNbAccounts();
	this->_amount = initialDeposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	std::cout << "index:";
	std::cout << this->_accountIndex << ";";
	std::cout << "amount:";
	std::cout << this->_amount << ";";
	std::cout << "created"; 
	std::cout << std::endl;

	Account::_nbAccounts += 1;
	Account::_totalAmount += initialDeposit;
}

Account::~Account(void)
{
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	pAmount;
	
	pAmount = this->checkAmount();
	this->_amount += deposit;
	this->_nbDeposits += 1;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << pAmount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	bool	valid;
	int		pAmount;

	valid = true;
	pAmount = this->checkAmount();
	if (pAmount < withdrawal)
		valid = false;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount" << pAmount << ";";
	if (valid)
	{
		this->_nbWithdrawals += 1;
		this->_amount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->checkAmount() << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
	}
	else
	{
		std::cout << "withdrawal:refused";
	}
	std::cout << std::endl;
	return (valid);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}