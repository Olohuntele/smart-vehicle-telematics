
#include <Arduino.h>
#include "security.h"
#include "diagnostics.h"

void setup() {
	Serial.begin(115200);
	delay(1000);
	Serial.println("Initializing Smart Vehicle Security & Diagnostic Hub...");
	setupSecurityPin();
}

void loop() {
	Serial.println("\n[Scanning ECU & Security Status...]");

	// Simulate catching a fault code from the vehicle
	translateFaultCode("P0300");

	// Simulate security trigger check
	checkRemoteCommand("IMOB_ACTIVATE");

	delay(10000); // Pause for 10 seconds
}
