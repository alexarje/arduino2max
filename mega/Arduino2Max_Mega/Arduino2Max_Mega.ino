 /*  
 *  Arduino2Max
 *  Send pin values from Arduino to MAX/MSP
 *
 *  Updated by: Joe Sanford (josephsanford@gmail.com)
 *  Last updated: 3/26/15
 *  
 *  Original by Daniel Jolliffe
 *  Based on a sketch and patch by Thomas Ouellet Fredericks  tof.danslchamp.org
 *  
 */


int x = 0;                              // a place to hold pin values
int ledpin = 13;

void setup()
{
  Serial.begin(115200);               // 115200 is the default Arduino Bluetooth speed
  digitalWrite(13,HIGH);              ///startup blink
  delay(600);
  digitalWrite(13,LOW);
  pinMode(13,INPUT);
}



void loop()
{ 

if (Serial.available() > 0){         // Check serial buffer for characters
        
    if (Serial.read() == 'r') {       // If an 'r' is received then read the pins
    
for (int pin= 0; pin<=15; pin++){      // Read and send analog pins 0-15
    x = analogRead(pin);
    sendValue (x);
    }



for (int pin= 22; pin<=53; pin++){     // Read and send digital pins 22-53 (leaving
    x = digitalRead(pin);              // comm and PWM pins available)
    sendValue (x);
    }
  
    Serial.println();                 // Send a carriage returnt to mark end of pin data. 
    delay (5);                        // add a delay to prevent crashing/overloading of the serial port
  
  }

 }
}

void sendValue (int x){              // function to send the pin value followed by a "space". 
 Serial.print(x);
 Serial.write(32); 
}



