#include <iostream> 
using namespace std;
#include "ticketmachine.h"

int main(void)
{
	TicketMachine tm;
	tm.insertMoney(100);
	tm.showBalance();
	return 0;
}
