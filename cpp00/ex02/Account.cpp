#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return Account::_nbAccounts;
}
int	Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
          << ";total:" << getTotalAmount()
          << ";deposits:" << getNbDeposits()
          << ";withdrawals:" << getNbWithdrawals()
          << std::endl;    
}

Account::Account (int deposit)
{
    _accountIndex = _nbAccounts;
    _amount = deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
          << ";amount:" << _amount
          << ";created"
          << std::endl; 
    _nbAccounts++;
}

Account::~Account ( void )
{ 
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
          << ";amount:" << _amount
          << ";closed"
          << std::endl; 
}


void	Account::makeDeposit( int deposit )
{   
    _amount += deposit;
    _nbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
          << ";p_amount:" << _amount - deposit
          << ";deposit:" << deposit
          << ";amount:" << _amount
          << ";nb_deposits:" << _nbDeposits
          << std::endl;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount
            << ";withdrawal:refused"
            << std::endl;
        return false;
    }
    else
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount + withdrawal
              << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;
        return true;
    }
    
}

int		Account::checkAmount( void ) const
{
    return _amount;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
          << ";amount:" << _amount
          << ";deposits:" << _nbDeposits
          << ";withdrawals:" << _nbWithdrawals
          << std::endl; 
}

void Account::_displayTimestamp( void )
{
    time_t current_time;
    char buffer[20];
    struct tm *calendar;

    time(&current_time);
    calendar = localtime(&current_time);
    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", calendar);
    std::cout << buffer << " ";
}