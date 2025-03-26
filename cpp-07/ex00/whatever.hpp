#pragma once

template<typename V>
void swap(V& a, V& b)
{
	V tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<typename V>
V min(V& a, V& b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename V>
const V& min(const V& a, const V& b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename V>
V& max(V& a, V& b)
{
	if (a > b)
		return (a);
	return (b);
}

template<typename V>
const V& max(const V& a, const V& b)
{
	if (a > b)
		return (a);
	return (b);
}