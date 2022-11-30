#include "Blockchain.h"

// add genesis block to chain
Blockchain::Blockchain(){
    _vChain.emplace_back(Block(0, "Genesis Block"));
}

// function to push a new block to the chain

void Blockchain::addBlock(Block bNew){
    // get hash of latest block
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const{
    return _vChain.back();
}