#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "blockchain.h"
#include "sha256.h"
using namespace std;
class User
{
public:
    blockchain userBlockchain = blockchain(4);
    string batchTX();//打包交易
};
