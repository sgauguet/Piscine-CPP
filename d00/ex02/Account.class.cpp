#include "Account.class.hpp"
#include <iostream>
#include <ctime>

Account::Account(int initial_deposit ) {
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++ ;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" ;
	std::cout << "amount:" << this->_amount << ";" ;
	std::cout << "created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" ;
	std::cout << "amount:" << this->_amount << ";" ;
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" ;
	std::cout << "total:" << getTotalAmount() << ";" ;
	std::cout << "deposits:"  << getNbDeposits() << ";" ;
	std::cout << "withdrawals:"  << getNbWithdrawals() << std::endl ;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" ;
	std::cout << "p_amount:" << this->_amount << ";" ;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits++ ;
	Account::_totalAmount += deposit;
	std::cout << "deposit:" << deposit  << ";" ;
	std::cout << "amount:" << this->_amount << ";" ;
	std::cout << "deposits:" << this->_nbDeposits << std::endl ;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" ;
	std::cout << "p_amount:" << this->_amount << ";" ;
	this->_amount -= withdrawal;
	if (!checkAmount()) {
		this->_amount += withdrawal;
		std::cout << "withdrawal:refused" << std::endl ;
		return false;
	}
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals++ ;
	Account::_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";" ;
	std::cout << "amount:" << this->_amount << ";" ;
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl ;
	return true;
}

int		Account::checkAmount( void ) const {
	if (this->_amount < 0)
		return 0;
	return 1;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" ;
	std::cout << "amount:" << this->_amount << ";" ;
	std::cout << "deposits:" << this->_nbDeposits << ";" ;
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl ;
	return;
}

void	Account::_displayTimestamp( void ) {
	time_t rawtime;
	struct tm * timeinfo;
 	char buffer [20];
 	time (&rawtime);
 	timeinfo = localtime (&rawtime);
 	strftime (buffer, 20,"%Y%m%d_%H%M%S",timeinfo);
 	std::cout << "[" << buffer << "] " ;
}

int Account::_nbAccounts = 0; 

int Account::_totalAmount = 0; 

int Account::_totalNbDeposits = 0; 

int Account::_totalNbWithdrawals = 0;

Account::Account( void ) {

}