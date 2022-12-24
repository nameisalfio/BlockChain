#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include <vector>

class Blockchain 
{

public:

    Blockchain(bool _verboseIn = false) : _verbose(_verboseIn)
    {
        _vChain.emplace_back(Block(0, "Genesis Block", _verbose));
        _nDifficulty = 3;
    }

    void AddBlock(Block bNew)
    {
        bNew.sPrevHash = _GetLastBlock().sHash;
        bNew.MineBlock(_nDifficulty);
        _vChain.push_back(bNew);
    }

    friend ostream& operator<< (ostream& os, Blockchain& b)
    {
        os << "\nBlockchain:\n" << endl;
        for(auto i = (b._vChain).begin(); i != (b._vChain).end(); i++)
            os << *i << endl;
        return os;
    }

private:

    bool _verbose;
    int _nDifficulty;
    vector<Block> _vChain;  // vettore di Block

    Block _GetLastBlock() const {return _vChain.back();}

};

#endif 

