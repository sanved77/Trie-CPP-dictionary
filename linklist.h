#include <stdlib.h>

using namespace std;

typedef struct mdata
{
	char meaning[80];
}mdata;

typedef struct node
{
	char data;
	struct node *next[26];
	bool meaning;
	struct mdata *pmdata;
	
}anode;

class datad{
	
	anode *root;
	
	public:
	datad();
	void create(string);
	anode* checkIfThere(char, anode*);
	mdata* getMeaningData(string);
	void searchWord(string);
	/*anode *anodeMaker(char, bool);
	mdata *mdataMaker();*/
	
};

