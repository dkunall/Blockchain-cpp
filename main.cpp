//jeetu
#include <iostream>
#include <ctime>
#include <vector>
#include "TransactionData.h"
#include "Block.h"
#include "Blockchain.h"
using namespace std;

int main()
{
    // Start Blockchain
    Blockchain awesomeCoin;
    
    // Data for first block
    time_t data1Time;
    TransactionData data1(1.5, "kanha", "radha", time(&data1Time));
    awesomeCoin.addBlock(data1);
    
    time_t data2Time;
    TransactionData data2(0.2233, "rama", "sita", time(&data2Time));
    awesomeCoin.addBlock(data2);
    
    //what's in the blockchain!
    awesomeCoin.printChain();
    
    //valid
    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());
    
    // ----
    Block *hackBlock = awesomeCoin.getLatestBlock();
    hackBlock->data.amount = 10000; 
    hackBlock->data.receiverKey = "ganesh";

    //look at data
    awesomeCoin.printChain();

    //not valid
    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());
    
    return 0;
}
