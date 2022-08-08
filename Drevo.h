#pragma once
#include <iostream>
#include <cstring>
#include <conio.h>
#include <iomanip>
#include<mutex>
#include<thread> 

using namespace std;

template <class T>
class Drevo
{
public:
	template <typename U>
	struct Tree
	{
		Tree* left;
		Tree* right;
		U inf;
	};
	Drevo();
	Drevo(const Drevo& t);
	Drevo(Drevo&& t);
	~Drevo();
private:
	Tree<T>* root;
	Tree<T>* head;
	mutable mutex mtx;
	Tree<T>* add_tr(T i, Tree<T>* t);
	void deletet(Tree<T>* t, T i);
	void add_tree(Tree<T>* i);
	void clear(Tree<T>* t);
	void inorder(Tree<T>* t) const noexcept;
public:

	void add(T i);
	Drevo find_subtree(T i) const noexcept;
	/*
	{
		if (root == nullptr)
			return nullptr;
		else if (i < root->inf)
			return find(root->left, i);
		else if (i > root->inf)
			return find(root->right, i);
		else
			return root;
	}*/
	void addtree(const Drevo& s);
	Drevo operator<< (T i);
	void const print();
	void addtread(T i) noexcept;
	bool find(T i) const noexcept;
	Tree<T>* del(T i);
	/*
	{
		const lock_guard<mutex> guard(mtx);
		head = nullptr;
		deletet(root, i);
		root = head;
		head = nullptr;
		return root;
	}*/
};

template <class T>
Drevo<T>::Drevo()
{
	root = nullptr;
	head = nullptr;
}

template <class T>
Drevo<T>::Drevo(const Drevo& t)
{
	//root = t.root;
	root = add_tr(1, t.root);
}

template <class T>
Drevo<T>::Drevo(Drevo&& t)
{
	root = t.root;
	t.root = nullptr;
}

template <class T>
Drevo<T>::~Drevo() {
	clear(root);
	//delete root;
}

template <class T>
Drevo<T> Drevo<T>::operator<<(T i)
{
	const lock_guard<mutex> guard(mtx);
	root = add_tr(i, root);
	return *this;
}

template < class T>
void const Drevo<T>::print()
{
	try
	{
		if (root == nullptr)
			throw(1);
		inorder(root);
		cout << endl;
	}
	catch (int err)
	{
		if (err == 1)
			cout << "Empty" << endl;
	}
}

template < class T>
Drevo<T>::Tree<T>* Drevo<T>::add_tr(T i, Drevo<T>::Tree<T>* t)
{
	if (t == nullptr)
	{
		t = new Drevo::Tree<T>;
		t->inf = i;
		t->left = t->right = nullptr;

	}
	else if (i < t->inf)
	{
		t->left = add_tr(i, t->left);
	}
	else if (i > t->inf)
	{
		t->right = add_tr(i, t->right);
	}
	head = root;
	return t;
}

template < class T>
void  Drevo<T>::addtread(T i) noexcept
{
	lock_guard<mutex> guard(mtx);
	root = add_tr(i, root);
}

template < class T>
bool Drevo<T>::find(T i) const noexcept
{
	return (find(root, i) != nullptr);
}

template < class T>
Drevo<T> Drevo<T>::find_subtree(T i) const noexcept
{
	if (root == nullptr)
		return nullptr;
	else if (i < root->inf)
		return find(root->left, i);
	else if (i > root->inf)
		return find(root->right, i);
	else
		return root;
}

template < class T>
Drevo<T>::Tree<T>* Drevo<T>::del(T i)
{
	const lock_guard<mutex> guard(mtx);
	head = nullptr;
	deletet(root, i);
	root = head;
	head = nullptr;
	return root;
}

template < class T>
void Drevo<T>::clear(Drevo::Tree<T>* t)
{
	const lock_guard<mutex> guard(mtx);
	if (t == nullptr) return;
	clear(t->left);
	clear(t->right);
	delete t;
}

template < class T>
void Drevo<T>::add_tree(Drevo::Tree<T>* i)
{
	if (i == NULL) return;
	add_tree(i->left);
	root = add_tr(i->inf, root);
	add_tree(i->right);
	root = add_tr(i->inf, root);
	head = root;
}

template < class T>
void Drevo<T>::deletet(Drevo::Tree<T>* t, T i)
{
	if (t == NULL) return;
	deletet(t->left, i);
	if (i != t->inf) head = add_tr(t->inf, head);
	deletet(t->right, i);
}

template < class T>
void Drevo<T>::add(T i)
{
	root = add_tr(i, root);
}

template < class T>
void Drevo<T>::inorder(Drevo::Tree<T>* t) const noexcept
{
	if (t == NULL) return;
	inorder(t->left);
	cout << t->inf << " ";
	inorder(t->right);
}

template < class T>
void Drevo<T>::addtree(const Drevo& s)
{
	Tree<T>* i = s.root;
	const lock_guard<mutex> guard(mtx);
	add_tree(i);
}