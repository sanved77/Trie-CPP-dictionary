#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

/*
	Constructor initializes the root node for further use.	
*/
datad::datad(){
	
	anode *temp;
	
	root = (anode*)malloc(sizeof(anode));
	root->data = '.';
	root->meaning = false;
	root->pmdata = NULL;
	
	for(int i = 0; i < 26; i++){
		root->next[i] = NULL;
	}
}



/*
	Stores the entire word onto the tree.
*/
void datad::create(string abc){
	
	transform(abc.begin(), abc.end(), abc.begin(), ::tolower);
	
	anode *temp = NULL, *store = NULL, *ptr = NULL;
	mdata *data = NULL;
	
	ptr = root;
	
	for(int i = 0;i < abc.length(); i++){
		
		temp = checkIfThere(abc[i], ptr);
		
		if(temp){
			if(i == (abc.length() - 1)){
				data = getMeaningData(abc);
				ptr = temp;
				ptr->meaning = true;
				ptr->pmdata = data;
			}else{
				ptr = temp;
			}
		}else{
			store = (anode*)malloc(sizeof(anode));
			store->data = abc[i];
			if(i == (abc.length() - 1)){
				data = getMeaningData(abc);
				store->meaning = true;
				store->pmdata = data;
			}
			else{
				store->meaning = false;
				store->pmdata = NULL;
			}
			
			for(int j = 0; j < 26; j++){
				store->next[j] = NULL;
			}
			char a = abc[i] - 97;
			ptr->next[a] = store;
			ptr = store;
			
		}
		
	}
	
	cout<<"Entry added\n\n";
}



/*
	Checks if the node is already been made
*/
anode* datad::checkIfThere(char a, anode *node){

	a = a - 97;

	anode *temp = NULL;

	if(node->next[a]){
		temp = node->next[a];
	}
	
	return temp;
	
}



/*
	Takes the meaning of the word and then connects the node.
*/
mdata* datad::getMeaningData(string abc){
	
	mdata *data = NULL;
	data = (mdata*)malloc(sizeof(mdata));
	
	cout<<"Enter the meaning for the word - "<<abc<<"\n";
	cin>>data->meaning;
	return data;
}


/*
	Searches the nodes for the given word
*/
void datad::searchWord(string term){
	
	transform(term.begin(), term.end(), term.begin(), ::tolower);
	
	anode *temp = NULL, *ptr = NULL;
	mdata *data;
	
	ptr = root;
	
	for(int i = 0; i < term.length(); i++){
	
		temp = checkIfThere(term[i], ptr);
		if(temp){
			if(i == (term.length() - 1)){
				ptr = temp;
				data = ptr->pmdata;
				cout<<data->meaning<<endl;
			}else{
				ptr = temp;
			}
		}else{
			cout<<"Sorry, entry not found\n";
			break;
		}
		
	}
	
}


/*datad();
	create(string);
	anode *checkIfThere(char);
	anode *anodeMaker(char, bool);
mdata *mdataMaker();*/