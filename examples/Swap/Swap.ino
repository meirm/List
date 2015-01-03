#include "Arduino.h"
#include <List.h>

void setup()
{
           List<String> StringList;
        StringList.Push("h");
         StringList.Push("e");
          StringList.Push("o");
          StringList.Push("l");
          StringList.Push("l");
         StringList.Swap(2,4);

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
                a
                b
                c
        */
        StringList.Clear();
        ListEmpty = StringList.IsEmpty(); //true


}

void loop()
{
}

