#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <iostream>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain
{
    public:
        Blockchain();
        void addBlock(Block bNew);

    private:
        uint32_t _nDifficulty;
        vector<Block> _vChain;

        Block _GetLastBlock() const;
};

#endif // BLOCKCHAIN_H
