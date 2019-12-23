#pragma once
template <class T>
struct TNode {
	T val;
	TNode* pNext;
};
template <class T>
class TStack{
	TNode<T> *pFirst;
public:
	TStack(int a = 0);
	~TStack();
	TStack(const TStack<T>& st);
	TStack<T>& operator=(const TStack<T>& st);
	bool IsEmpty()const;
	bool IsFull()const;
	void Push(const T& a);
	T Pop();
	T Top();
	void Clear();
};


template <class T>
TStack<T>::TStack(int a) {
	pFirst = NULL;
}

template <class T>
TStack<T>::~TStack(){
	TNode<T>* p = pFirst;
	while (pFirst != NULL){
		pFirst = pFirst->pNext;
		delete p;
		p = pFirst;
	}
}

template <class T>
TStack<T>::TStack(const TStack<T>& st){
	TNode<T>* p = st.pFirst;
	if (!p){
		pFirst = p;
	}
	while (p){
		Push(p->val);
		p = p->pNext;
	}
	delete p;
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& st){
	if (this != &st){
		if (!IsEmpty())
			Clear();
		else{
			TNode<T>* p = st.pFirst;
			if (!p)
				pFirst = p;
			while (p){
				Push(p->val);
				p = p->pNext;
			}
			delete p;
		}
	}
	return *this;
}

template <class T>
bool TStack<T>::IsEmpty()const {
	return !pFirst;
}

template <class T>//???????????
bool TStack<T>::IsFull()const {
	TNode<T>* p;
	p = new TNode<T>;
	if (p == NULL)
	{
		return 1;
	}
	else
	{
		delete p;
		return 0;
	}
}

template <class T>
void TStack<T>::Push(const T& a) {
	if (IsFull())
		throw -1;
	else{
		TNode<T>* p = new TNode<T>;
		p->pNext = pFirst;
		p->val = a;
		pFirst = p;
	}
}

template <class T>
T TStack<T>::Pop() {
	if (IsEmpty()){
		throw -1;
	}
	else{
		T res = pFirst->val;
		TNode<T>* p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
		return res;
	}
}

template <class T>
T TStack<T>::Top() {
	if (IsEmpty())
		throw -1;
	else
		return pFirst->val;
}

template <class T>
void TStack<T>::Clear() {
	TNode<T>* p = pFirst;
	while (pFirst){
		pFirst = pFirst->pNext;
		delete p;
		p = pFirst;
	}
}

