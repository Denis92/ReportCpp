#ifndef _MYVEC_
#define _MYVEC_

template<class _Type>
class vector
{
private:
	_Type *vec;
	int sz;

public:
	vector<_Type>();
	int resize(int);
	int size(){return sz;}
	_Type & operator[](int i);
	_Type & operator[](int i)const;
	~vector<_Type>();
};

template<class _Type>
vector<_Type> :: vector<_Type>()
{
	sz = 0;
	vec = NULL;
}

template<class _Type>
vector<_Type> :: ~vector<_Type>()
{
	delete [] vec;
}

template<class _Type>
int vector<_Type> :: resize(int s)
{
	_Type *tmp;
	int i;
	tmp = new (_Type[s]);
	for(i = 0; (i < s) && (i < sz); i++)
		tmp[i] = vec[i];
	vec = tmp;
	sz = s;
	return sz;
}

template<class _Type>
_Type & vector<_Type>::operator[](int i)
{
	if(i >= (sz - 1))
		resize(i + 1);
	return vec[i];
}

template<class _Type>
 _Type & vector<_Type>::operator[](int i)const
{
	return vec[i];
}

 #endif