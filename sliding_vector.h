#include <vector>
template<class T>
class SlidingVector {
	private:
		int principio_;
		int final_;
		int size_;
		std::vector<T> v_;
	public:
	SlidingVector();
	SlidingVector(int x, int y);
	~SlidingVector(){}
	int& size();
	T& operator[](int x);
	void push_back(T dato);
	void insert(T dato);
};