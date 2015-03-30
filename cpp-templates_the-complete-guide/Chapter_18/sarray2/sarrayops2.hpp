//addition of two SArrays
template <typename T>
SArray<T> operator+(SArray<T> const &a, SArray<T> const &b)
{
	SArray<T> result(a.size());
	for(size_t k=0; k<a.size(); ++k)
	{
		result[k] = a[k]+b[k];
	}
	return result;
}

//multiplication of two SArrays
template <typename T>
SArray<T> operator*(SArray<T> const &a, SArray<T> const &b)
{
	SArray<T> result(a.size());
	for(size_t k=0; k<a.size(); ++k)
	{
		result[k] = a[k]*b[k];
	}
	return result;
}

//multiplication of scalar and SArray
template <typename T>
SArray<T> operator*(T const &s, SArray<T> const &a)
{
	SArray<T> result(a.size());
	for(size_t k=0; k<a.size(); k++)
	{
		result[k] = s*a[k];
	}
	return result;
}

//additive assignment of SArray
template <class T>
SArray<T>& SArray<T>::operator+=(SArray<T> const &b)
{
	for(size_t k=0; k<size(); ++k)
	{
		(*this)[k] += b[k];
	}

	return *this;
}

//multiplicative assignment of SArray
template <class T>
SArray<T>& SArray<T>::operator*=(SArray<T> const &b)
{
	for(size_t k=0; k<size(); ++k)
	{
		(*this)[k] *= b[k];
	}

	return *this;
}

//multiplicative assignment of scalar
template <class T>
SArray<T>& SArray<T>::operator*=(T const &s)
{
	for(size_t k=0; k<size(); ++k)
	{
		(*this)[k] *= s;
	}

	return *this;
}
