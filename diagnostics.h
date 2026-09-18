#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include <Arduino.h>
#include <string>
#include <map>

void translateFaultCode(std::string dtc) {
	std::map<std::string, std::string> faultDictionary = {
		{"P0300", "Random/Multiple Cylinder Misfire Detected - Check spark plugs."},
		{"P0100", "Mass Air Flow Sensor Malfunctioning."},
		{"P0420", "Catalyst System Efficiency Below Threshold."}
	};

	if (faultDictionary.find(dtc) != faultDictionary.end()) {
		Serial.print("ECU Code Captured: "); Serial.println(dtc.c_str());
		Serial.print("Plain-Language Alert: "); Serial.println(faultDictionary[dtc].c_str());
	} else {
		Serial.print("ECU Code Captured: "); Serial.print(dtc.c_str());
		Serial.println(" - Status: Unrecognized code.");
	}
}

#endif
