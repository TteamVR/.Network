/////////////////////////////////////////////////////////////////////
#ifndef LIST_H													   //
#define LIST_H													   //
/////////////////////////////////////////////////////////////////////



#include <stdlib.h>

#define NULLPTR 0

template <typename DataTemplate>
class List
{
private:
	
	struct DataTypeList
	{
		DataTemplate  data;
		DataTypeList *next;		
		
		DataTypeList(): data(0), next(NULLPTR){} 
		
	}*Last;
	
	
	unsigned __int64 ItemCounter;
	
public:
	List(): Last(NULLPTR), ItemCounter(0) {}
	
	DataTemplate operator[](int IndexItem);
	
	void push(DataTemplate data);
	DataTemplate pop();
	
	bool clear();
	bool empty();

	unsigned __int64 size();
};



/////////////////////////////////////////////////////////////
template <typename DataTemplate>					       //
DataTemplate List<DataTemplate>::operator[](int IndexItem) //
{
	DataTypeList *CopyLast = Last;
	
	for(__int64 counter = 0; counter < IndexItem; counter++)
		CopyLast = CopyLast -> next;
	
	return CopyLast -> data;
}



/////////////////////////////////////////////////////////////
template <typename DataTemplate>					       //
void List<DataTemplate>::push(DataTemplate data)  	       //
{
	DataTypeList *NewItem = (DataTypeList*)malloc(sizeof(DataTypeList));
	NewItem -> data = data;
	NewItem -> next = Last;
	Last = NewItem;
	
	ItemCounter++; 
}



/////////////////////////////////////////////////////////////
template <typename DataTemplate>					       //
DataTemplate List<DataTemplate>::pop() 				       //
{
	if(ItemCounter > 0)
	{
		DataTypeList *CopyLast = Last;
		DataTemplate data = Last -> data;
		
		Last = Last -> next;
		free(CopyLast);
		
		ItemCounter--;
		
		return data;
	}
}



/////////////////////////////////////////////////////////////
template <typename DataTemplate>					       //
bool List<DataTemplate>::clear() 					       //
{
	DataTypeList *CopyLast = NULLPTR;
	
	if(ItemCounter > 0)
	{	
		while(--ItemCounter > 0)
		{	
			CopyLast = Last;
			Last = Last -> next;
			free(CopyLast);
		}
		
		return true;
	}
	else return false;
}   



/////////////////////////////////////////////////////////////
template <typename DataTemplate>					       //
unsigned __int64 List<DataTemplate>::size()			       //
{
	return ItemCounter; 
}



/////////////////////////////////////////////////////////////
template <typename DataTemplate>					       //
bool List<DataTemplate>::empty() 					       //
{
	return !((bool)(ItemCounter)); 
}




/////////////////////////////////////////////////////////////////////
#endif															   //
/////////////////////////////////////////////////////////////////////















