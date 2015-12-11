/*
 * BankingSystem.cpp
 *
 * 7 July 2015
 * Mert Aytöre
 * 21400923
 * CS201-01 / Summer
 */

#include "BankingSystem.h"
#include <iostream>
#include <string>
using namespace std;

//constructor
BankingSystem::BankingSystem() {
	sizeBranch = 0, sizeCustomer = 0, sizeAccount = 0, totalAcc = 0;
}

//destructor
BankingSystem::~BankingSystem() {
	if(sizeCustomer != 0)
	{
		delete[] cId;
		delete[] cNames;
	}

	if(sizeBranch != 0)
	{
		delete[] bId;
		delete[] bNames;
	}
	//deleting accounts
	if(sizeAccount != 0)
	{
		for(int i = 0; i < sizeAccount; i++)
		{
			delete[] account[i];
		}
		delete[] account;
	}

}

//adding a branch to the banking system
void BankingSystem::addBranch( const int branchId, const string branchName ){
	if(sizeBranch == 0)
	{
		bId = new int[1];
		bId[0] = branchId;
		bNames = new string[1];
		bNames[0] = branchName;
		cout << "Branch " << bId[sizeBranch] << " has been added\n";
		sizeBranch++;
	}
	else
	{
		//If the branch id is already taken prints error
		for(int i = 0;i < sizeBranch; i++)
		{
			if(bId[i] == branchId)
			{
				cout<<"\nBranch "<< bId[i] << " already exists\n";
				return;
			}
		}
		sizeBranch++;
		int *tempId = new int[sizeBranch];
		string *tempNames = new string[sizeBranch];
		for(int i = 0; i < sizeBranch - 1; i++)
		{
			tempId[i] = bId[i];
			tempNames[i] = bNames[i];
		}
		tempId[sizeBranch - 1] = branchId;
		tempNames[sizeBranch - 1] = branchName;
		delete[] bId;
		delete[] bNames;
		bId = tempId;
		bNames = tempNames;
		cout<<"Branch "<< bId[sizeBranch - 1] << " has been added\n";
	}
}

//deleting a branch from the banking system
void BankingSystem::deleteBranch( const int branchId ){
	//Checks whether branchId is in the system or not
	int temp = -1;
	for(int i = 0; i < sizeBranch; i++){
		if(bId[i] == branchId)
			temp = i;
	}

	for(int i = 0; i < sizeAccount; i++){
		if(branchId == account[i][0]){
			//delete this account
			sizeAccount--;
			int temp2 = i;

			int** tempAccount = new int*[sizeAccount];

			for(int a = 0; a < temp2; a++)
			{
				tempAccount[a] = account[a];
			}

			delete[] account[temp2];

			for(int a = temp2; a < sizeAccount; a++)
			{
				tempAccount[a] = account[a + 1];
			}

			delete[] account;

			account = tempAccount;
			i--;
		}
	}

	//If there is not branchId in the system prints error
	if(temp == -1){
		cout<< "Branch " << branchId << " does not exist\n";
	}

	//If there is branchId in the system empties the branch location
	else{
		sizeBranch--;
		int *tempId = new int[sizeBranch];
		string *tempNames = new string[sizeBranch];
		for(int i = 0; i < temp; i++)
		{
			tempId[i] = bId[i];
			tempNames[i] = bNames[i];
		}

		for(int i = temp; i < sizeBranch; i++)
		{
			tempId[i] = bId[i + 1];
			tempNames[i] = bNames[i + 1];
		}
		delete[] bId;
		delete[] bNames;
		bId = tempId;
		bNames = tempNames;
		cout << "Branch " << branchId << " has been deleted\n";
	}
}

//adding a customer to the customer array
void BankingSystem::addCustomer( const int customerId, const string customerName ){
	if(sizeCustomer == 0){
		cId = new int[1];
		cId[0] = customerId;
		cNames = new string[1];
		cNames[0] = customerName;
		cout << "Customer " << cId[sizeCustomer] << " has been added\n";
		sizeCustomer++;
	}
	else{
		//If the customer id is already taken prints error
		for(int i = 0;i < sizeCustomer; i++)
		{
			if(cId[i] == customerId)
			{
				cout<<"\nCustomer "<< cId[i] << " already exists\n";
				return;
			}
		}
		sizeCustomer++;
		int *tempId = new int[sizeCustomer];
		string *tempNames = new string[sizeCustomer];
		for(int i = 0; i < sizeCustomer - 1; i++)
		{
			tempId[i] = cId[i];
			tempNames[i] = cNames[i];
		}
		tempId[sizeCustomer - 1] = customerId;
		tempNames[sizeCustomer - 1] = customerName;
		delete[] cId;
		delete[] cNames;
		cId = tempId;
		cNames = tempNames;
		cout<<"Customer "<< cId[sizeCustomer - 1]  << " has been added\n";
	}
}

//deleting customer from customer array
void BankingSystem::deleteCustomer( const int customerId ){
	//Checks whether customerId is in the system
	int temp = -1;
	for(int i = 0; i < sizeCustomer; i++){
		if(cId[i] == customerId)
			temp = i;
	}

	for(int i = 0; i < sizeAccount; i++){
		if(customerId == account[i][1]){
			//delete this account
			sizeAccount--;
			int temp2 = i;

			int** tempAccount = new int*[sizeAccount];

			for(int a = 0; a < temp2; a++)
			{
				tempAccount[a] = account[a];
			}

			delete[] account[temp2];

			for(int a = temp2; a < sizeAccount; a++)
			{
				tempAccount[a] = account[a + 1];
			}

			delete[] account;

			account = tempAccount;
			i--;
		}
	}
	//If there is not branchId in the system prints error
	if(temp == -1){
		cout<< "Customer " << customerId << " does not exist\n";
	}

	//If there is branchId in the system empties the branch location
	else{
		sizeCustomer--;
		int *tempId = new int[sizeCustomer];
		string *tempNames = new string[sizeCustomer];
		for(int i = 0; i < temp; i++)
		{
			tempId[i] = cId[i];
			tempNames[i] = cNames[i];
		}

		for(int i = temp; i < sizeCustomer; i++)
		{
			tempId[i] = cId[i + 1];
			tempNames[i] = cNames[i + 1];
		}
		delete[] cId;
		delete[] cNames;
		cId = tempId;
		cNames = tempNames;
		cout << "Customer " << customerId << " has been deleted\n";
	}
}

//adding an account to double pointer account
int BankingSystem::addAccount( const int branchId, const int customerId, const double amount ){
	//Checks if branch exists or not
	const int accFirst = 4;
	int count = 0;
	int temp = -1, teemp = -1, num = 0;

	//Checks if there is a customer in the location
	for(int i = 0; i < sizeCustomer;i++){
		if( cId[i] == customerId)
			teemp = i;
	}
	if(teemp == -1){
		cout << "Customer " << customerId <<" does not exist\n";
		return -1;
	}

	//branch check
	for(int i = 0; i < sizeBranch;i++){
		if( bId[i] == branchId)
			temp = i;
	}
	if(temp == -1){
		cout << "Branch " << branchId << " does not exist\n\n";
		return -1;
	}

	//If there is no account creates the dynamic arrays
	if( sizeAccount == 0){
		account = new int*[1];
		sizeAccount++;
		totalAcc++;
		int* tmp = new int[accFirst];

		tmp[0] = branchId;
		tmp[1] = customerId;
		tmp[2] = amount;
		tmp[3] = totalAcc;


		account[0] = tmp;
		cout << "Account " << totalAcc << " added for customer " << customerId << " at branch " << branchId<< "\n";
		return totalAcc;
	}

	//Tries to locate an empty spot in the array if there is not adds the reservation end of the array
	else
	{
		totalAcc++;
		sizeAccount++;
		int** tempAccount = new int*[sizeAccount];

		int* temp2=new int[accFirst];

		temp2[0] = branchId;
		temp2[1] = customerId;
		temp2[2] = amount;
		temp2[3] = totalAcc;

		for(int i = 0; i < sizeAccount - 1; i++)
		{
			tempAccount[i] = account[i];
		}

		tempAccount[sizeAccount - 1] = temp2;

		delete[] account;

		account = tempAccount;
		cout << "Account " << totalAcc << " added for customer " << customerId << " at branch " << branchId<< "\n";

		return totalAcc;

	}
}

//dynamically deleting an account
void BankingSystem::deleteAccount( const int accountId ){
	const int accFirst = 4;

	//Checks whether accountId is in the system
	int temp = -1;
	for(int i = 0; i < sizeAccount; i++){
		if(account[i][3] == accountId)
			temp = i;
	}
	//If there is not accountId in the system prints error
	if(temp == -1){
		cout<< "Account " << accountId << " does not exist\n";
	}
	//If there is accountId in the system empties the branch location
	else{
		sizeAccount--;

		int** tempAccount = new int*[sizeAccount];

		for(int i = 0; i < temp; i++)
		{
			tempAccount[i] = account[i];
		}

		delete[] account[temp];

		for(int i = temp; i < sizeAccount; i++)
		{
			tempAccount[i] = account[i + 1];

		}

		delete[] account;

		account = tempAccount;
		cout << "Account " << accountId << " has been deleted\n";
	}
}

//detailed output of the work done so far
void BankingSystem::showAllAccounts(){
	if(sizeBranch == 0)
	{
		return;
	}
	else{

		cout << "Account id\tBranch id\tBranch name\tCustomer id\tCustomer name\tBalance\n";
		int bIndex = 0;
		int cIndex = 0;

		for(int i = 0; i < sizeAccount; i++){
			for(int j = 0; j < sizeBranch; j++){
				if(bId[j] == account[i][0] ){
					bIndex = j;
					j = sizeAccount;
				}
			}
			//find customer name
			for(int j = 0; j < sizeCustomer; j++){
				if(cId[j] == account[i][1] ){
					cIndex = j;
					j = sizeAccount;
				}
			}
			cout << account[i][3] << "\t\t" << account[i][0] << "\t\t" << bNames[bIndex] <<
			"\t\t" <<account[i][1] << "\t\t" << cNames[cIndex]  << "\t\t" << account[i][2] << ".00\n";

		}
	}
}

//detailed output of branch
void BankingSystem::showBranch( const int branchId ){
	//If there is not branch in the system prints error
	if(sizeBranch == 0)
	{
		cout<<"Branch " << branchId << " does not exist\n";
		return;
	}
	//Searches in id array to find the given branch
	int check = -1;
	for(int i = 0; i < sizeBranch; i++)
		if(bId[i] == branchId)
			check = i;
	//If there is not the given branch id in the system prints error
	if(check == -1){
		cout<<"Branch " << branchId << " does not exist\n";
		return;
	}

	//Find number of accounts
	int count = 0;

	for(int i = 0; i < sizeAccount; i++){
		if(branchId == account[i][0]){
			count++;
		}
	}
	int cIndex = 0;
	cout << "\nBranch id: " << branchId << " Branch name: " << bNames[check] << "  Number of accounts: " << count << "\n";
	if (count > 0){
		cout << "Accounts at this branch:\n";
		cout << "Account id\tCustomer id\tCustomer name\tBalance\n";
		for(int i = 0; i < sizeAccount; i++){
			if(branchId == account[i][0] ){
				//find customer name
				for(int j = 0; j < sizeAccount; j++){
					if(cId[j] == account[i][1] ){
						cIndex = j;
						j = sizeAccount;
					}
				}
				cout << account[i][3] << "\t\t" << account[i][1] << "\t\t" << cNames[cIndex]  << "\t" << account[i][2] << ".00\n";
			}
		}
	}
}

//detailed output of customer
void BankingSystem::showCustomer( const int customerId ){
	if(sizeCustomer == 0){
		cout<<"Customer " << customerId << " does not exist\n";
		return;
	}

	int check = -1;
	for(int i=0; i < sizeCustomer;i++)
		if(cId[i] == customerId)
			check = i;
	//If there is not the given branch id in the system prints error
	if(check == -1){
		cout<<"Customer " << customerId << " does not exist\n";
		return;
	}

	//Find number of customers
	int count = 0;

	for(int i = 0; i < sizeAccount; i++){
		if(customerId == account[i][1]){
			count++;
		}
	}

	int bIndex = 0;
	cout<<"\nCustomer id: " << customerId << " Customer name: " << cNames[check] << "  Number of accounts: " << count << "\n";
	if(count > 0){
		cout << "Accounts of this customer:\n";
		cout << "Account id\tBranch id\tBranch name\tBalance\n";
		for(int i = 0; i < sizeAccount; i++){
			for(int j = 0; j < sizeAccount; j++){
				if(bId[j] == account[i][0] ){
					bIndex = j;
					j = sizeAccount;
				}
			}
			if(customerId == account[i][1] ){
				cout << account[i][3] << "\t\t" << account[i][0] << "\t\t" << bNames[bIndex] << "\t\t" << account[i][2] << ".00\n";
			}
		}
	}
}
