#pragma once
template <class T>
class TStack {
	T *arr;
	int size;
	int num; //текущее количество элементов в стеке
public:
	TStack(int _size = 10000) {
		if (_size <= 0) throw _size;
		size = _size;
		arr = new T[size];
		num = -1;
	}
	~TStack(){
		delete[] arr;
	}

	TStack(const TStack& st) {
		size = st.size;
		arr = new T[size];
		num = st.num;
		for (int i = 0; i <= num; i++) arr[i] = st.arr[i];
	}

	TStack& operator= (const TStack& st) {
		if (this != &st) {
			delete[] arr;
			size = st.size;
			arr = new T[size];
			num = st.num;
			for (int i = 0; i <= num; i++) arr[i] = st.arr[i];
		}
		return *this;
	}

	void Clear() {
		num = -1;
	}

	bool IsEmpty()const {
		if (num == -1) return true;
		return false;
	}

	bool IsFull()const {
		if (num == size - 1) return true;
		return false;
	}

	void Push(T el) {
		if (IsFull()) throw el;
		else {
			arr[num + 1] = el;
			num++;
		}
	}

	T Pop() {
		if (num == -1) throw num;
		num--;
		return arr[num + 1];
	}

	T Top() {
		if (num == -1) throw num;
		return arr[num];
	}
};