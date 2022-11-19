#include "maos.h"


// CONSTRUCTOR


/*
template <typename T1>
smallMao<T1>::smallMao(int i, int& r) : storage_(i) , refTest1(r) {

}

*/


smallMao2::smallMao2(int i) : storage_(i) {};






// FUNCTION

template <typename T1>
int smallMao<T1>::getStorage() {
	return storage_;
}




template <typename T1>
int smallMao<T1>::getRef() {
	return refTest1;
}








