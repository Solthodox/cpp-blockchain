#include "Block.h"
#include "sha256.h" // copy pasted from http://www.zedwood.com/article/cpp-sha256-function

// Initial setup
Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn) , _sData(sDataIn)
{
    _nNonce = -1;
    _tTime = time(nullptr);
}
// Hash getter
string Block::GetHash() {
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
    // create a string with (nDIfficulty) zeroes and "\0" in the end
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
    string str(cstr);

    // increase nonce while it doesn't match the string created
    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);

    // notify in console
    cout << "Block mined: " << _sHash << endl;
}


// inline keyword makes code more efficient
// hashes a string that contains : index, time, data, nonce and previous hash
inline string Block::_CalculateHash() const {
    stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;
    
    return sha256(ss.str());
}

Block::~Block()
{
    //dtor
}
