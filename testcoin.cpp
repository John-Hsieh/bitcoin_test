#include <iostream>
#include <cstdint>
#include "blockchain.h"
#include "user.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include "time.h"
#include "sha256.h"
using namespace std;
int main()
{
    //parameters
    int usernum = 100;          //number of users
    int miningtime = 10000;     //how many time we want to mine
    int difficulty = 4;
    
    //testing part
    srand((int)time(0));
    blockchain samplechain = blockchain(difficulty);
    User users[usernum];
    int miner_id;
    for (int i = 0; i < miningtime; i++)
    {
        //we randomly determine a miner
        miner_id = rand() % usernum;
        //before adding block, make sure every user have the same copy of blockchain
        for (int j = 0; j < usernum; j++)
        {
            users[j].userBlockchain = samplechain;
        }
        
        printf("Mining block %d...\n", i);
        users[miner_id].userBlockchain.AddBlock(block(i, users[miner_id].batchTX()));
        samplechain = users[miner_id].userBlockchain;
        
        printf("Miner ID is %d...\n", miner_id);
     }
    system("pause");
    return 0;
}
