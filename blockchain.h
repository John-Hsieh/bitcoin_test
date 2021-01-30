#pragma once
#include"block.h"
#include<vector>//向量库
class blockchain
{
public:
    blockchain(unsigned int num);
    void AddBlock(block newblock);
    unsigned int difficulty;
    vector<block> blockhold;
    block _GetLastBlock() const;
};
