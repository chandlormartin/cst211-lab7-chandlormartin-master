#ifndef BSNODE_H
#define BSNODE_H

template<typename T>
class BSNode
{
public:
	//Constructors
	BSNode() = default;
	BSNode(T val);

	//Getters
	T getData() const;
	BSNode<T>* getLeft() const;
	BSNode<T>* getRight() const;

	//Setters
	void setData(const T& val);
	void setLeft(BSNode<T>* newnode);
	void setRight(BSNode<T>* newnode);

	//Operator Overloads
	BSNode& operator =(const BSNode<T>& rhs);

private:
	T			Data{ T() };
	BSNode<T>* Left{ nullptr };
	BSNode<T>* Right{ nullptr };
};
#endif

//Constructors----------------------------------------------------
//----------------------------------------------------------------
template<typename T>
BSNode<T>::BSNode<T>(T val)
{
	Left	= nullptr;
	Right	= nullptr;
	Data	= val;			//set data to val
}

//Getters---------------------------------------------------------
//----------------------------------------------------------------
template<typename T>
T BSNode<T>::getData() const
{
	if (this != nullptr)
		return Data;		//if this is not nullptr, return data
	else
		return T();			//if this is nullptr, return default value for type T
}

template<typename T>
BSNode<T>* BSNode<T>::getLeft() const
{
	return Left;		//if this is not nullptr, return Left pointer
}

template<typename T>
BSNode<T>* BSNode<T>::getRight() const
{
	return Right;		//if this is not nullptr, return Right pointer
}

//Setters----------------------------------------------------
//----------------------------------------------------------------
template<typename T>
void BSNode<T>::setData(const T& val)
{
	Data = val;			//set data to val
}

template<typename T>
void BSNode<T>::setLeft(BSNode<T>* newnode)
{
	if (this != nullptr)	//if this is not nullptr, set Left pointer to new node
		Left = newnode;
	else					//if nullptr, set Left to nullptr
		Left = nullptr;
}

template<typename T>
void BSNode<T>::setRight(BSNode<T>* newnode)
{
	if (this != nullptr)	//if this is not nullptr, set Right pointer to new node
		Right = newnode;
	else					//if nullptr, set Right to nullptr
		Right = nullptr;
}

//Operator Overloads----------------------------------------------------
//----------------------------------------------------------------
template<typename T>
BSNode<T>& BSNode<T>::operator =(const BSNode<T>& rhs)
{
	setData(rhs.Data);		//set this data to rhs' Data
	setLeft(rhs.Left);		//set this Left pointer to rhs' Left pointer
	setRight(rhs.Right);	//set this right pointer to rhs' Right pointer
}