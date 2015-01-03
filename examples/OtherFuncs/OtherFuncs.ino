

#include "Arduino.h"
#include <List.h>

void setup()
{
	List<String> StringList;
	StringList.Push("X");
	StringList.Replace(0,"a");
	StringList.Push("Z");
	StringList.Replace(1,"A");
	StringList.Push("c");
	StringList.Remove(2);
	StringList.Insert(2,"b");
	StringList.Replace(2,"C");
	StringList.Swap(0,2);
	Serial.begin(9600);
	//Iterate through list
	bool ListEmpty = StringList.IsEmpty(); //false
	Serial.println("Count: "+String(StringList.Count()));
	StringList.ToBegin();
	Serial.println(StringList.Shift());

	while(!StringList.IsEnd())
	{
		Serial.println(StringList.GetValue());
		StringList.Next();
	}
	/*Output:
		Count: 3
		c
		a
		A
	*/
	StringList.Clear();
	ListEmpty = StringList.IsEmpty(); //true
	
}

void loop()
{
}
