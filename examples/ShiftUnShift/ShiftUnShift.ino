

#include "Arduino.h"
#include <List.h>

void setup()
{
	List<String> StringList;
	StringList.unShift("c");
	StringList.unShift("b");
	StringList.unShift("a");
	Serial.begin(9600);
	bool ListEmpty = StringList.IsEmpty(); //false
	Serial.println("Count: "+String(StringList.Count()));
	while(!StringList.IsEmpty())
	{
		Serial.println(StringList.Shift());
	}
	/*Output:
		Count: 3
		a
		b
		c
	*/
	StringList.Clear();
	
}

void loop()
{
}
