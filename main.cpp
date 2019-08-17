#include "Binary_tree.h"
#include "iostream"

int main()
{
	try{

		Binary_tree<int> tree;

		tree.add_element(5);
		tree.add_element(2);		
		tree.add_element(3);
		tree.add_element(1);
		tree.add_element(8);
		tree.add_element(9);

		if(tree.search(9)){
	
			std::cout << "Found it! :)\n";
		}
		else{
			std::cout << "Didn't find it! :( \n";

		}

    }catch(const char *e){

    	std::cout << e << "\n";
    }

	return 0;
}	