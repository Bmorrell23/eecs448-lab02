/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	return m_size;
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

for (int k = 0; k < m_size; k++)//Search through whole list
{
	if(temp->getValue() == value)//If I found the value, report back to my return statement
	{
		isFound = true;
	}
	temp = temp->getNext();//Iterate through the rest of list
}
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
		Node<T>* lastNode = nullptr;
		Node<T>* secondintoLast = nullptr;
		bool isRemoved = false;

		secondintoLast = m_front;//Starting point at the front of the list
    lastNode = secondintoLast;

    if(!isEmpty())//List cannot be empty to removeBack
    {
        while(lastNode->getNext() != nullptr)//goes to back of list
        {
            lastNode = lastNode->getNext();
        }

        while(secondintoLast->getNext() != lastNode)//Iterates to node before last node
        {
            secondintoLast = secondintoLast->getNext();
        }

        delete lastNode;//lastNode will be pointing to nullptr already
        secondintoLast->setNext(nullptr);//secondintoLast becomes last node
        m_size--;//Decrease whole size of list
        isRemoved = true;
    }

    return(isRemoved);

}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
