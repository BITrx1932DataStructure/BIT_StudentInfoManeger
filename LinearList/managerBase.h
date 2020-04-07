#pragma once

template<typename T>
class ManagerBase
{
public:
	void insert(const T& value);
	void query();
};