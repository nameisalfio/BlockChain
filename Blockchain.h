#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"

class Blockchain 
{
public:

    Blockchain()
    {
        _vChain.emplace_back(Block(0, "Genesis Block"));
        _nDifficulty = 6;
    }

    void AddBlock(Block bNew)
    {
        bNew.sPrevHash = _GetLastBlock().sHash;
        bNew.MineBlock(_nDifficulty);
        _vChain.push_back(bNew);
    }

private:

    int _nDifficulty;
    vector<Block> _vChain;  // vettore di Block

    Block _GetLastBlock() const { return _vChain.back(); }
};

#endif 
