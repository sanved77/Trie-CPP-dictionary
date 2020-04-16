#include <iostream>
#include <stdlib.h>
#include "linklist.h"
#include "linklist.cpp"

using namespace std;

int main(){
	
	system("cls");
	
	datad d1;
	
	string abc = "zaGdI";
	string ab2c = "ffaGdI";
	string def = "nag";
	string ghi = "nagesh";
	
	d1.create(abc);
	d1.create(def);
	d1.create(ghi);
	
	d1.searchWord(def);
	d1.searchWord(ab2c);
	d1.searchWord(ghi);
	
}