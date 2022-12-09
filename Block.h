#ifndef BLOCK_H
#define BLOCK_H

#include "sha256.h"

class Block 
{

public:
    string sHash;
    string sPrevHash;

    Block(int nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
    {
        _nNonce = 0;
        _tTime = time(nullptr);
        sHash = _CalculateHash();
    }

    void MineBlock(int nDifficulty)    
    {
        char cstr[nDifficulty + 1];
        for (int i = 0; i < nDifficulty; ++i)  
            cstr[i] = '0';
        cstr[nDifficulty] = '\0'; 

        string str(cstr);   //cstr diventa una stringa standard

        do
        {
            _nNonce++;
            sHash = _CalculateHash();
        }
        while (sHash.substr(0, nDifficulty) != str);

        cout << "Block mined: " << sHash << endl;
    }

private:
    int _nIndex;
    int _nNonce;
    string _sData;
    time_t _tTime;

    string _CalculateHash() const;  // inline function

};


// L'utilizzo di funzioni inline rende il programma più veloce perché elimina il sovraccarico associato alle chiamate di funzione

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << sPrevHash << _tTime << _sData << _nNonce;
    return sha256(ss.str());
}

#endif 
