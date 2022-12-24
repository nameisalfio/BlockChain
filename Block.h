#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <sstream>
#include <ctime>
#include "sha256.h" //Hash function SHA-256

using namespace std;

class Block 
{

public:
    string sHash;   //hash of the current block 
    string sPrevHash;   //link to previous block
    bool verbose;

    Block(int nIndexIn, const string &sDataIn, bool verbose = false) : _nIndex(nIndexIn), _sData(sDataIn), verbose(verbose)
    {
        _nNonce = 0;
        _tTime = time(nullptr);
        sHash = _CalculateHash();
    }

    void MineBlock(int nDifficulty)    
    {
        char cstr[nDifficulty + 1];
        for (int i = 0; i < nDifficulty; i++)  
            cstr[i] = '0';
        cstr[nDifficulty] = '\0'; 
        string str(cstr);   //cstr becomes a standar string

        do
        {
            _nNonce++;
            sHash = _CalculateHash();
        }
        while (sHash.substr(0, nDifficulty) != str);

        cout << "Block mined: " << sHash << endl;
    }

    friend ostream& operator << (ostream& os, Block& b)
    {
        if(!b.verbose)
            return os << "Hash: " << b.sHash << endl;
        os << "Index: " << b._nIndex << endl;
        os << "Data: " << b._sData << endl;
        os << "nNonce: " << b._nNonce << endl;
        os << "Previous: " << (b.sPrevHash != "" ? b.sPrevHash : "NULL") << endl;
        return os << "Hash: " << b.sHash << endl;
    }

private:
    int _nIndex;
    int _nNonce;
    string _sData;
    time_t _tTime;

    string _CalculateHash() const;  // inline function

};

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << sPrevHash << _tTime << _sData << _nNonce;
    return sha256(ss.str());
}

#endif 
