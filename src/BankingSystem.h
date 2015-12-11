/*
 * BankingSystem.h
 *
 *  Created on: Jul 24, 2015
 *      Author: mertaytore
 */
#include <iostream>
#include <string>
using namespace std;
#ifndef BANKINGSYSTEM_H_
#define BANKINGSYSTEM_H_

class BankingSystem {
public:
	BankingSystem();
	~BankingSystem();

	void addBranch( const int branchId, const string branchName );
	void deleteBranch( const int branchId );

	void addCustomer( const int customerId, const string customerName );
	void deleteCustomer( const int customerId );

	int addAccount( const int branchId, const int customerId, const double amount );
	void deleteAccount( const int accountId );

	void showAllAccounts();
	void showBranch( const int branchId );
	void showCustomer( const int customerId );
private:
	//these hold the sizes of the id arrays
	int sizeBranch, sizeCustomer, sizeAccount;

	//to hold the account ids
	int totalAcc;

	//these hold branch, customer and account ids.
	int *bId, *cId;

	//a 2D array for accounts
	int **account;

	//string array for branch names and customer names
	string *bNames, *cNames;
};

#endif /* BANKINGSYSTEM_H_ */
