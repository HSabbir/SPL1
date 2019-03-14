#include<bits/stdc++.h>
#include <iostream>
#include <fstream>

 using namespace std;

 int main (void)
{
	ifstream iFile;
	iFile.open("sample.pdf");
	if(iFile.is_open())
	{
		ofstream oFile;
		oFile.open("pdf1.doc");
		if(oFile.is_open())
		{
			char cr;
			iFile.get(cr);
			while(!iFile.eof())
			{
				//oFile << cr;
				if(cr=='(')
				{
					while(cr!=')')
					{
						if(cr=='(') cr=cr;


 						else oFile << cr;


 						iFile.get(cr);

 					}
				}
			    iFile.get(cr);
			
			}
			oFile.close();
		}
		else
		{
			cout << "Cannot Open Output File" << endl;
		}
		iFile.close();
	}
	else
	{
		cout << "Cannot Open Input File" << endl;
	}

 	
 	return 0;
}
