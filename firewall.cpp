#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

typedef struct sIPString
{
	int id;
	char sourceIP[10];
	char destinationIP[10];
	int port;
    char dateV[10];
	bool blocked;
}sIPString_t;

int main()
{
    sIPString_t firewallIP[100];  
    
    firewallIP[0].id = 1;
	strcpy(firewallIP[0].sourceIP, "192.168.0.1");
	strcpy(firewallIP[0].destinationIP, "192.168.1.1");
    firewallIP[0].port = 80;
	strcpy(firewallIP[0].dateV, "2/12/2015");
	firewallIP[0].blocked = true;


    // Serializing struct to student.data
    ofstream output_file("IPFirewall.data", ios::binary);
    output_file.write((char*)&firewallIP, sizeof(firewallIP));
    output_file.close();

    // Reading from it
    ifstream input_file("IPFirewall.data", ios::binary);
    sIPString master[3];
    input_file.read((char*)&master, sizeof(master));         

    for (size_t idx = 0; idx < 3; idx++)
    {
        // If you wanted to search for specific records, 
        // you should do it here! if (idx == 2) ...

        cout << "Id : " << master[idx].id << endl;
        cout << "Source IP: " << master[idx].sourceIP << endl;
        cout << "Destination IP: " << master[idx].destinationIP << endl;
        cout << "Port: " << master[idx].port << endl;
		cout << "Date: " << master[idx].dateV << endl;
		cout << "Blocked: " << master[idx].blocked << endl;
       
    }

    return 0;
}