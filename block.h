#pragma once
#include<cstdint>
#include<iostream>
#include <fstream>
using namespace std;
static time_t first_time = 0;


class block
{
public:
    string prevHash;
    block(unsigned int nIndexIn, const string& sDataIn);
    string GetHash();
    void MineBlock(unsigned int nDifficulty);
    void NoMineBlock();
    unsigned int blockindex;
    long long blockrand;
    string blockdata;
    string blockHash;
    time_t blocktime;
    string hashcalc() const;
    void blockwriter();
};
