/*
 * main.cpp
 *
 *  Created on: 24 Tem 2015
 *      Author: User
 */
#include <iostream>
#include <stdio.h>
using namespace std;

#include "BankingSystem.h"

int main(){

        BankingSystem B;
        BankingSystem B1;



        B.addBranch(1111,"B1_B1");
        B.addBranch(1112,"B1_B2");
        B.addBranch(1113,"B1_B3");
        B.addBranch(1114,"B1_B4");
        B.addBranch(1115,"B1_B5");
        B.addBranch(1116,"B1_B6");
        B.addBranch(1117,"B1_B7");
        B.addBranch(1118,"B1_B8");
        B.addBranch(1115,"B1_B9"); // not allowed
        B.addBranch(1112,"B1_B10"); // not allowed


        printf("%s\n","*******************************************" );

        B.deleteBranch(1135);//doesnt't exist
        B.deleteBranch(1111);// ok
        B.deleteBranch(1114);// ok
        B.deleteBranch(1118); // delete normally
        B.deleteBranch(1114); // doesn't exist
        B.deleteBranch(1111); // doesn't exixt
        printf("%s\n","*******************************************" );
        B.showBranch(1112);
        printf("%s\n","*******************************************" );

        /******************************************************/
        B1.addAccount(1115,2111,100.00); // no customer


        B.addCustomer(2111,"C1_B1");
        B.addCustomer(2112,"C2_B1");
        B.addCustomer(2113,"C3_B1");
        B.addCustomer(2114,"C4_B1");
        B.addCustomer(2115,"C5_B1");

        B1.addCustomer(2111,"C2_B2");
        B1.addCustomer(2112,"C1_B2");
        B1.addCustomer(2113,"C2_B2");
        B1.addCustomer(2114,"C1_B2");
        B1.addCustomer(2116,"C2_B2");

        B.addCustomer(2116,"C6_B1"); // should add normally
        B.addCustomer(2112,"C7_B1"); // customer already exist
        B.deleteCustomer(2115); // should delete from B
        B1.deleteCustomer(2114); // should delete from B1

        printf("%s\n","*******************************************" );

        B.showCustomer(2112);
        B.showCustomer(2114); // should appear
        B1.showCustomer(2115); // shouldn't appear
        printf("%s\n","*******************************************" );

        int account1 = B.addAccount(1111,2111,100.00); // no branch
        int account2 = B.addAccount(1111,2112,100.00); // no branch
        int account3 = B.addAccount(1112,2111,100.00); // ok
        int account4 = B.addAccount(1112,2112,100.00); //ok

        int account5 = B.addAccount(1113,2111,100.00);

        int account6 = B.addAccount(1114,2112,100.00); // no branch
        int account7 = B.addAccount(1114,2111,100.00); // no branch
        int account9 = B.addAccount(1115,2112,100.00);
        int account10 = B.addAccount(1116,2113,100.00);
        int account11 = B.addAccount(1117,2113,100.00);
        int account12 = B.addAccount(1118,2113,100.00);
        int account13 = B.addAccount(1117,2114,100.00);

        B.showAllAccounts();

        B.deleteBranch(1117);
        B.showAllAccounts();

        B.deleteCustomer(2111);

        B.showAllAccounts();

        B.deleteAccount(account13); // invalid
        B.deleteAccount(account11); // invalid
        B.deleteAccount(account3); // invalid

        int account14 = B1.addAccount(1114,2112,100.00); // no branch
        int account15 = B1.addAccount(1114,2111,100.00); // no branch
        int account161 = B1.addAccount(1115,2112,100.00); // no branch

        printf("%s\n","*******************************************" );

        B.showAllAccounts();

        printf("%s\n","*******************************************" );

        B1.showAllAccounts();

        printf("%s\n","*******************************************" );

        B1.deleteBranch(1114);

        B1.deleteAccount(account2); // depends on the ID of account 2
        B1.deleteAccount(account9); // ok
        B1.deleteAccount(account9); // does not exist


        B1.deleteAccount(account10); // branch does not exist



        printf("%s\n","*******************************************" );

        B1.showAllAccounts();

        printf("%s\n","*******************************************" );

        B.showAllAccounts();

        return 0;
}



