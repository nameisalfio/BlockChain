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

    //Blocco valido
    Block good = bChain[1];
    cout << "First block to check: " << endl;
    cout << good << endl;
    cout << (bChain._isValid(good) ? "Block valid" : "Block is not valid") << endl;

    //Blocco non valido
    Block bad(5, "Block bad Data", true);
    cout << "\nSecond block to check: " << endl;
    cout << bad << endl;
    cout << (bChain._isValid(bad) ? "Block valid" : "Block is not valid") << endl;
}
