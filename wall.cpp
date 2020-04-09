#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

struct firewallIDs
{
	int ID, port;
	char source_IP[16], destination_IP[16], date[10];
	bool block;

};
int main()
{
	int i = 0, j = 0, h = 0, flag=0,bandera = 0,temp = 0;
	int showdata;
	int bubblearray[100] = {0}, n, c, d, swap;
	char ch;
	string inputdata="";
	char *pointerDataSelect,*pointerReference,*pointerPort2int,*pointerReplaceAux;
	char PortString2Int[5];
	char SourceIPStacker[16];
	 
	
	
	struct firewallIDs data[100] = {0};
	
	cout << "Insert Data? [y/n]: ";
	while (i <= 100 &&  (ch=getchar()) == 'y' )
	{
		cout << "What's the ID number: ";
		cin >> data[i].ID;
		fflush(stdin);
		cout << "Port  IP_Source  IP_Destination  Date  Blocked \n";
		getline(cin, inputdata);
		fflush(stdin);
		pointerDataSelect = &inputdata[0];
		pointerReference = pointerDataSelect;

		while(*pointerDataSelect)
		{
			if(*pointerDataSelect == ' ')
			{
				pointerDataSelect++;
				break;
			}
			pointerDataSelect++;
		}
		
		pointerPort2int = PortString2Int;
		while(pointerDataSelect != pointerReference)
		{
			*pointerPort2int = *pointerReference;
			pointerReference++;
			pointerPort2int++;
		}
		data[i].port = atoi(PortString2Int);
		//cout << data[i].port;
		
	
		while(*pointerDataSelect)
		{
			if(*pointerDataSelect == ' ')
			{
				pointerDataSelect++;
				break;
			}
			pointerDataSelect++;
		}
		pointerReplaceAux = &data[i].source_IP[0];
		while(pointerDataSelect != pointerReference)
		{
			*pointerReplaceAux = *pointerReference;
			pointerReplaceAux++;
			pointerReference++;
		}
		//cout << data[i].source_IP;
		
		while(*pointerDataSelect)
		{
			if(*pointerDataSelect == ' ')
			{
				pointerDataSelect++;
				break;
			}
			pointerDataSelect++;
		}
		pointerReplaceAux = &data[i].destination_IP[0];
		while(pointerDataSelect != pointerReference)
		{
			*pointerReplaceAux = *pointerReference;
			pointerReplaceAux++;
			pointerReference++;
		}
		//cout << data[i].destination_IP;
		
		while(*pointerDataSelect)
		{
			if(*pointerDataSelect == ' ')
			{
				pointerDataSelect++;
				break;
			}
			pointerDataSelect++;
		}
		pointerReplaceAux = &data[i].date[0];
		while(pointerDataSelect != pointerReference)
		{
			*pointerReplaceAux = *pointerReference;
			pointerReplaceAux++;
			pointerReference++;
		}
		//cout << data[i].date;
		
		while(*pointerDataSelect)
		{
			if(*pointerDataSelect == '\0')
			{
				break;
			}
			pointerDataSelect++;
		}
			
		pointerReplaceAux = PortString2Int;
		while(pointerDataSelect != pointerReference)
		{
			*pointerReplaceAux = *pointerReference;
			pointerReplaceAux++;
			pointerReference++;
		}
		cout << PortString2Int[0];
		if(PortString2Int[0] == 'y' && PortString2Int[1] == 'e' && PortString2Int[2] == 's')
		{
			data[i].block = 1;
		}
		else if(PortString2Int[0] == 'n' && PortString2Int[1] == 'o')
		{
			data[i].block = 0;
		}
		
		i++;
		cout << "Continue? [y/n]: ";
	}
	struct firewallIDs outdata[100];
	// writting
	ofstream output_file("IPFirewall.data", ios::binary); //creates a binary output file names IPfirwall
	output_file.write((char*)&data, sizeof(data));        //this line writes to already created output file information on data
	output_file.close();                                  //closes file after written.

	//reading
	ifstream input_file("IPFirewall.data", ios::binary);
	input_file.read((char*)&outdata,sizeof(outdata));
	while(bandera == 0)
	{
		cout << "Enter 0 to read'em all or enter ID to read such information";
		cin >> showdata;
		if (showdata==0)
		{
			j = 0;
			while (j <= i)
			{
				bubblearray[j] = outdata[j].ID;
				j++;
			}
			
			 for(d=0; d<(i-1); d++)
				{
					for(j=0; j<(i-d-1); j++)
					{
						if(bubblearray[j]>bubblearray[j+1])
						{
							temp=bubblearray[j];
							bubblearray[j]=bubblearray[j+1];
							bubblearray[j+1]=temp;
						}
					}
				}
			  //cout << bubblearray[0];
			  j = 0;
			  
			while (j < i)
			{
				h = 0;
				while (h <= 100)
				{
					if (outdata[h].ID == bubblearray[j])
					{
						cout << "Id:  " << outdata[h].ID << '\n';
						cout << "Source IP:  " << outdata[h].source_IP << '\n';
						cout << "Destination IP: " << outdata[h].destination_IP << '\n';
						cout << "Port: " << outdata[h].port << '\n';
						cout << "Date: " << outdata[h].date << '\n';
						if(outdata[h].block == 1)
						{
							cout << "Blocked: True \n";
						}
						else
						{
							cout << "Blocked: False \n";
						}
						
					}
					h++;
				}
				j++;
			}
		}
		else  
		{	
			h = 0;
			while (h <= 100)
			{
				if (outdata[h].ID == showdata)
				{
					cout << "Id:  " << outdata[h].ID << '\n';
					cout << "Source IP:  " << outdata[h].source_IP << '\n';
					cout << "Destination IP: " << outdata[h].destination_IP << '\n';
					cout << "Port: " << outdata[h].port << '\n';
					cout << "Date: " << outdata[h].date << '\n';
					if(outdata[h].block == 1)
					{
						cout << "Blocked: True \n";
					}
					else
					{
						cout << "Blocked: False \n";
					}
					flag = 1;
					bandera = 1;
				}
				h++;
			}
			if (flag == 0)
			{
				cout << "No result, try another ID";
			}
		}
	}
	return 0;
}