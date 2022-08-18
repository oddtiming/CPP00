#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

Account::Account( int initial_deposit ) :
	_accountIndex( _nbAccounts ),
	_nbDeposits( 0 ),
	_nbWithdrawals( 0 ) {

	_displayTimestamp();

	// Correct for negative numbers
	if (initial_deposit < 0)
		initial_deposit = 0;
	this->_amount = initial_deposit;
	this->_totalAmount += _amount;
	
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;

	this->_nbAccounts++;
	return ;
}

Account::~Account( void ) {

	this->_nbAccounts--;
	return ;
}

void	Account::makeDeposit( int deposit ) {
	
	_displayTimestamp();

	// Negative deposits are treated as null
	if (deposit < 0) {
		deposit = 0;
	}

	// Start output
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit" << deposit << ";";


	// Update class attributes
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits += 1;
	this->_nbDeposits += 1;

	// Finish output
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;

	return ;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	
	_displayTimestamp();

	// Negative deposits are treated as null
	if (withdrawal < 0) {
		withdrawal = 0;
	}

	// Start output
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";

	// Verify validity of param `deposit'
	if (withdrawal > _amount)
		std::cout << "refused";
		return false;
	}

	// Update class attributes
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals += 1;
	this->_nbWithdrawals += 1;

	// Finish output
	std::cout << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;

	return true;
	
}


/**
 *		This function is never used, so we are left to
 *		make an educated guess on its role. 
 *		Its return type, and the fact that it has a different terminology
 * 		from `displayStatus' leads me to believe it is simplistic in output,
 * 		and returns the current Account's amount
 */
int		Account::checkAmount( void ) const {
	
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";

	return _amount;
}

void	Account::displayStatus( void ) const {
	
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << deposit << ";";
	std::cout << "withdrawals:" << withdrawal << ";";
}


/***************************************************************/
/*            Non-member attributes and functions              */
/***************************************************************/

void	displayAccountsInfos( void ) {

	_displayTimestamp();

	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;

}

void	_displayTimestamp( void ) {

    std::time_t	time	= std::time(0);   			// 0 means now

	// std::tm is a struct holding time separated in instances
    std::tm*	now		= std::localtime(&time);
	
    std::cout << "["
		<< (now->tm_year + 1900)
        << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
        << std::setw(2) << std::setfill('0') << now->tm_mday
		<< "_"
		<< std::setw(2) << std::setfill('0') << now->tm_hour
		<< std::setw(2) << std::setfill('0') << now->tm_min
		<< std::setw(2) << std::setfill('0') << now->tm_sec
        << "] ";
}

int	getNbAccounts( void ) { return Account::_nbAccounts; }
int	getTotalAmount( void ) { return Account::_totalAmount; }
int	getNbDeposits( void ) { return Account::_nbDeposits; }
int	getNbWithdrawals( void ) { return Account::_nbWithdrawals; }

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
