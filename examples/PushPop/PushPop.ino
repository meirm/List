

#include "Arduino.h"
#include <List.h>

void setup()
{
	List<String> StringList;
	StringList.Push("a");
	StringList.Push("b");
	StringList.Push("c");
	Serial.begin(9600);
	//Iterate through list
	Serial.println("Count: "+String(StringList.Count()));
	while(!StringList.IsEmpty())
	{
	Serial.println(StringList.Pop());
	}
	/*Output:
		Count: 3
		c
		b
		a
	*/
	StringList.Clear();
	
}

void loop()
{
}
