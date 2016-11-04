
// ------------------------------------------------------------------------
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// The author can be contacted by email at burf2000@gmail.com
//
// ------------------------------------------------------------------------

#include "BNSlib_HC05.h"

// This task continuously transmits sensor data.
task sendReceiveData
{
	int a = 0;
  string sendString;
  char returnData[100];

	while(true)
	{
		a +=1;
		stringFormat(sendString, "Test line %f", a);

		// Send Data
		bnsSerialSend(UART1, sendString);
		// send this to finish the line
		bnsSerialSend(UART1, "\n");

		// ReceiveData
		bnsSerialRead(UART1, returnData, 100, 100);
		writeDebugStreamLine(returnData);

		delay(100);
	}
}

task main()
{

	// This should match what the AT command set the baudrate to!
	setBaudRate(UART1, baudRate57600);
	startTask(sendReceiveData);

	while(true)
	{

	}
}
