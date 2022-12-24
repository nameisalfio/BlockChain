#include "Blockchain.h"

int main()
{
    Blockchain bChain = Blockchain(true);

    cout << "Mining block 1..." << endl;
    bChain.AddBlock(Block(1, "Block 1 Data", true));

    cout << "Mining block 2..." << endl;
    bChain.AddBlock(Block(2, "Block 2 Data", true));

    cout << "Mining block 3..." << endl;
    bChain.AddBlock(Block(3, "Block 3 Data", true)); 

    cout << bChain << endl;

}
