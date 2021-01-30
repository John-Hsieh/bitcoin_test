#include "block.h"
#include "sha256.h"
#include "time.h"
#include <sstream>
block::block(uint32_t inputindex, const string& inputdata)
{
    blockindex = inputindex;
    blockdata = inputdata;
    blockrand = -1;
    blocktime = time(nullptr);
    if (inputindex == 0) first_time = blocktime;
}


string block::GetHash()
{
    return blockHash;
}

void block::MineBlock(uint32_t nDifficulty)
{
    char cstr[20];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
    string str(cstr);
    do
    {
    blockrand++;
    blockHash = hashcalc();
    } while (blockHash.substr(0, nDifficulty) != str);
    cout << "Block mined:" <<blockHash << endl;
}


inline string block:: hashcalc() const
{
    stringstream ss;
    ss << blockindex << blocktime << blockdata << blockrand << prevHash;
    return sha256(sha256(ss.str()));
}
void block::blockwriter()
{
ofstream outfile("blockinfo.txt", ios::app);
outfile <<"Index of block:"<<blockindex<<endl;
outfile << "Random num of block:" << blockrand << endl;
outfile << "Content of block:" << blockdata << endl;
outfile << "blockHash:" << blockHash << endl;
outfile << "PrevHash:" << prevHash << endl;
outfile << "time needed:" << blocktime - first_time << endl;
outfile << endl;
outfile.close();
}
