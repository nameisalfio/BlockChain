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
        _nDifficulty = 4;
    }

    void AddBlock(Block bNew)
    {
        bNew.sPrevHash = _GetLastBlock().sHash;
        bNew.MineBlock(_nDifficulty);
        _vChain.push_back(bNew);
    }

    Block _GetLastBlock() const {return _vChain.back();}

    bool _isValid(Block _toCheck)
    {
        for(auto i = _vChain.begin(); i != _vChain.end(); i++)
        {
            if(_toCheck.sHash == (*i).sHash)
                return true;
        }
        return false;
    }

    friend ostream& operator<< (ostream& os, Blockchain& b)
    {
        os << "\nBlockchain:\n" << endl;
        for(auto i = (b._vChain).begin(); i != (b._vChain).end(); i++)
            os << *i << endl;
        return os << endl;
    }

    Block operator[] (int i){return _vChain.at(i);}

private:

    vector<Block> _vChain;  // vettore di Block
    int _nDifficulty;
    bool _verbose;

};

#endif 

