#ifndef SECURITY_H
#define SECURITY_H

#include <Arduino.h>
#include <string>

const int RELAY_PIN = 23; // Digital pin for fuel pump relay

void setupSecurityPin() {
	pinMode(RELAY_PIN, OUTPUT);
	digitalWrite(RELAY_PIN, HIGH); // Default: Engine/Fuel pump powered ON
}

void checkRemoteCommand(std::string command) {
	if (command == "IMOB_ACTIVATE") {
		Serial.println("ALERT: Remote immobilization triggered!");
		digitalWrite(RELAY_PIN, LOW); // Cut relay power
		Serial.println("ACTION: Relay tripped. Fuel pump disconnected.");
	} else if (command == "IMOB_DEACTIVATE") {
		Serial.println("ACTION: Security disarmed. Vehicle power restored.");
		digitalWrite(RELAY_PIN, HIGH); // Restore relay power
	} else {
		Serial.println("Status: Monitoring active.");
	}
}

#endif
