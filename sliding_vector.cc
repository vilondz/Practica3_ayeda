#include "sliding_vector.h"
#include <cmath>
template <class T>
SlidingVector<T>::SlidingVector(){}

template <class T>
SlidingVector<T>::SlidingVector(int x, int y){
	principio_ = x;
	final_ = y;
	size_ = x - y + 1;
	v_.resize(size_);
}

template <class T>
int& SlidingVector<T>::size(){return size_;}

//añadir incidencia con try catch
template <class T>
T& SlidingVector<T>::operator[](int x){
	if(x < 0){
		return v_[x + fabs(principio_)];
	}
	else{
		return v_[x - final_];
	}
}

template <class T>
void SlidingVector<T>::push_back(T dato){
	final_+=1;
	v_.push_back(dato);
}

template <class T>
void SlidingVector<T>::insert(T dato){
	principio_ -= 1;
	v_.insert(v_.begin(), dato);
}
