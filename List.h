
/*
  List.h - Linked List (single chain)
  Created by Birk Blechschmidt, 16 August 2013
  Released into the public domain.
  Extended by Meir Michanie, 3 January 2014
*/
#ifndef List_h
#define List_h


template <class T> class ListElement
{
	public:
		ListElement(T Element)
		{
			Content = Element;
			NextElement = NULL;
		}
		~ListElement()
		{
			//delete NextElement;
			
		}
		T Content;
		ListElement<T> *NextElement;
		
};

template <class T> class List
{
  public:
	~List()
	{
		Clear();
		delete FirstElement;
		delete LastElement;
		delete CurrentElement;
	}
	List()
	{
		FirstElement = NULL;
		CurrentElement = NULL;
		LastElement = NULL;
		Length = 0;
	}
	void Clear()
	{
		ToBegin();
		delete CurrentElement;
		FirstElement = NULL;
		CurrentElement = NULL;
		LastElement = NULL;
		Length = 0;
	}
	void unShift(T Element)
	{
		
		if(Length ==0){
			FirstElement = new ListElement<T>(Element);
			LastElement = FirstElement;
			CurrentElement = FirstElement;
			
		}else{
			ListElement<T> *tempElement = FirstElement;
			FirstElement= new ListElement<T>(Element);
			FirstElement->NextElement=tempElement;
		}
		Length++;
			
	}
	T getPos(int n)
	{
		if ((Length==0) || (n > Length -1)) return NULL;
		int c=0;
		ToBegin();
		while(c++ < n){
			CurrentElement=CurrentElement->NextElement;
		}
		
		return CurrentElement->Content;
		}
	T Shift()
	{
		if(Length ==0){
			
			return NULL;
		}else {
			ToBegin();
			T ToBeRemoved=CurrentElement->Content;
			CurrentElement=CurrentElement->NextElement ;
			delete FirstElement;
			FirstElement=CurrentElement;
			Length--;
			if (Length==0) LastElement=NULL;
			return ToBeRemoved;
		}
	}
	T Pop()
	{
		/*  Implement Pop */
		if(Length ==0){
			return NULL;
		}else {
			ToBegin();
			T ToBeRemoved=LastElement->Content;
			ListElement<T> *TempElement=LastElement;
			
			while(CurrentElement->NextElement!=LastElement){
				CurrentElement=CurrentElement->NextElement;
			}
			LastElement=CurrentElement;
			CurrentElement->NextElement=NULL;
			delete TempElement;
			Length--;
			return ToBeRemoved;
		}
	}
	void Push(T Element)
	{
		if(LastElement)
		{
			LastElement->NextElement = new ListElement<T>(Element);
			LastElement = LastElement->NextElement;
		}
		else
		{
			FirstElement = new ListElement<T>(Element);
			LastElement = FirstElement;
			CurrentElement = FirstElement;
		}
		Length++;
	}
	T Remove(int pos){
		if (pos < 0) pos =Length + pos;
		if ((Length -1 < pos)||(pos <0)) return NULL;
		if (pos==0){
			return Shift();
		}
		if (pos == Length - 1) return Pop();
		int c=0;
		ToBegin();
		while(c++ < pos -1){
			CurrentElement=CurrentElement->NextElement;
		}
		ListElement<T> *tempElement=CurrentElement->NextElement;
		CurrentElement->NextElement=tempElement->NextElement;
		T ToBeRemoved=tempElement->Content;
		delete tempElement;
		Length--;
		return ToBeRemoved;
	}
	void Swap(int p, int n){
		T SwapElement1= getPos(p);
		Replace(p,getPos(n));
		Replace(n,SwapElement1);
	}
	bool Replace(int pos, T Element){
		if (pos < 0) pos =Length + pos;
		if ((pos > Length -1 )||(pos <0)) return false;
		Remove(pos);
		return Insert(pos,Element);
	}
	bool Insert(int pos,T Element)
	{
		if (pos < 0) pos =Length + pos;
		if ((Length < pos)||(pos <0)) return false;
		if (pos == Length) {
			Push(Element);
			return true;
		}
		if (pos==0){
			unShift(Element);
			return true;
		}
		int c=0;
		ToBegin();
		while(c++ < pos -1){
			CurrentElement=CurrentElement->NextElement;
		}
		ListElement<T> *tempElement =	new ListElement<T>(Element);
		tempElement->NextElement=CurrentElement->NextElement;
		CurrentElement->NextElement=tempElement;
		Length++;
		return true;
	}
	
	bool IsEnd()
	{
		if(CurrentElement)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	bool IsEmpty()
	{
		return FirstElement == NULL;
	}

	unsigned long Count()
	{
		return Length;
	}
	void ToBegin()
	{
		CurrentElement = FirstElement;
	}
	void Next()
	{
		if(CurrentElement)
		{
			CurrentElement = CurrentElement->NextElement;
		}
	}
	T GetValue()
	{
		return CurrentElement->Content;
	}
  private:
	  unsigned long Length;
	  ListElement<T> *FirstElement;
	  ListElement<T> *LastElement;
	  ListElement<T> *CurrentElement;
};

#endif
