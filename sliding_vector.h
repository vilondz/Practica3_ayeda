#include <vector>
#include <cmath>
template<class T>
class SlidingVector {
	private:
		int principio_;
		int final_;
		std::vector<T> v_;
	public:
	SlidingVector(){}
	SlidingVector(int x, int y, T dato);
	SlidingVector(int x, int y);
	~SlidingVector(){}
	std::pair<int,int> get_indices(void){return std::make_pair(principio_, final_)}
	void resize(int size);
	int size();
	T& operator[](int x);
	void push_back(T dato);
	void insert(T dato);
};


template <class T>
SlidingVector<T>::SlidingVector(int x, int y, T dato){
	principio_ = x;
	final_ = y;
	v_.resize(y - x + 1);
	for(auto aux: v_){
		aux = dato;
	}
}

template <class T>
SlidingVector<T>::SlidingVector(int x, int y){
	principio_ = x;
	final_ = y;
	v_.resize(y - x + 1);
}

template <class T>
int SlidingVector<T>::size(){return v_.size();}

//añadir incidencia con try catch
template <class T>
T& SlidingVector<T>::operator[](int x){
	return v_[x - principio_];
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

template <class T>
void SlidingVector<T>::resize(int size){
	v_.resize(size);
}