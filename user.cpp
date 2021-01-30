#include"user.h"
string User::batchTX()
{
    ifstream file("test.txt");
    string temp[300];
    int i = 0;
    if (!file.is_open())
    {
        cout << "Trading data fail to load" << endl;
    }
    while (getline(file, temp[i++]))
    {
        getline(file, temp[i++]);
    }
    for (int i = 0; i < 300; i++)
    {
        stringstream ss;
        ss << temp[0] << temp[i];       //we save the result from prev operation
        temp[0] = sha256(ss.str());     //temp[0] = hash code of previous implementation
    }
    file.close();
    return temp[0];
}
