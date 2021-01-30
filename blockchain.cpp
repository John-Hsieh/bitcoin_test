//
//  blockchain.cpp
//  blockchain
//
//  Created by john on 2021/1/28.
//

#include"blockchain.h"
blockchain::blockchain(unsigned int num)
{
    blockhold.push_back(block(0, "Genesis Block"));
    difficulty = num;
}
void blockchain::AddBlock(block newblock)
{
    newblock.prevHash = _GetLastBlock().GetHash();
    newblock.MineBlock(difficulty);
    blockhold.push_back(newblock);
    newblock.blockwriter();
}
block blockchain::_GetLastBlock() const
{
    return blockhold.back();
}
