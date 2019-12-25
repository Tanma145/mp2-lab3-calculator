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
	TStack(int a = 1);
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

template <class T>
void TStack<T>::Push(const T& a) {
	TNode<T>* p = new TNode<T>;
	p->pNext = pFirst;
	p->val = a;
	pFirst = p;
}

template <class T>
T TStack<T>::Pop() {
	if (pFirst) {
		T res = pFirst->val;
		TNode<T>* p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
		return res;
	}
	else throw - 1;
}

template <class T>
T TStack<T>::Top() {
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

