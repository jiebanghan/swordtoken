// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2019 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <primitives/block.h>
#include <logging.h>
#include <hash.h>
#include <tinyformat.h>

//#include "crypto/sph_keccak.h"
#include "streams.h"
using namespace std;

/*
uint256 CBlockHeader::GetHash() const
{
    return SerializeHash(*this);
} */

uint256 CBlockHeader::GetHash() const
{
    /*if (nTime < 0x57100000)  // 2016 Apr 14 20:39:28 UTC
    {
        std::cout<<"common hash"<<endl;
        return SerializeHash(*this);
    }*/
        
    //std::cout<<"enter GetX13PoWHash"<<endl;
    LogPrintf("enter GetX13PoWHash\n");
	return HashX13sm3(BEGIN(nVersion), END(nNonce));
}
uint256 CBlockHeader::GetX13PoWHash() const
{
    if (nTime < 0x57100000)  // 2016 Apr 14 20:39:28 UTC
        return SerializeHash(*this);
    std::cout<<"enter GetX13PoWHash"<<endl;
	return HashX13sm3(BEGIN(nVersion), END(nNonce));
}
std::string CBlock::ToString() const
{
    std::stringstream s;
    s << strprintf("CBlock(hash=%s, ver=0x%08x, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u, vtx=%u)\n",
        GetHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashMerkleRoot.ToString(),
        nTime, nBits, nNonce,
        vtx.size());
    for (const auto& tx : vtx) {
        s << "  " << tx->ToString() << "\n";
    }
    return s.str();
}
