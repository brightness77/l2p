#pragma once



template <typename T1>

class smallMao{


public:

	int storage_;
	const int& refTest1;


public:
	smallMao(int i, const int& r) : storage_(i), refTest1(r) {};


	int getStorage();
	int getRef();


};


class smallMao2 {

public:
	int storage_;

public:
	smallMao2(int i);

};






