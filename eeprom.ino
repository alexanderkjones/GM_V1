#ifndef _timeandvalue
#define _timeandvalue
struct TimeAndValue
{
	sint32 Time;
	sint32 Value;
};
#endif // !_timeandvalue

//////////////////////////////////////////////
//				EEPROM Storage
//	ADDR	LEN		DESCRIPTION

//	0		1		WiFi client auto-connect
String eepromAutoConnect() { return eeprom.ReadStringExact(0, 1); }
void eepromAutoConnect(String val) { eeprom.WriteStringExact(0, val, 1); }
//	1		32+1	Remote SSID
String eepromSsid() { return eeprom.ReadString(1); }
void eepromSsid(String Ssid) { eeprom.WriteString(1, Ssid, 33); }
//	34		64+1	Remote password
String eepromPass() { return eeprom.ReadString(34); }
void eepromPass(String Pass) { eeprom.WriteString(34, Pass, 65); }
//	99		4		Last Remote AP connection
sint32 eepromLastApConnectTime() { return eeprom.ReadInt32(99); }
void eepromLastApConnectTime(sint32 UnixTime) { eeprom.WriteInt32(99, UnixTime); }
//	103		2		Last Remote AP RSSI
sint16 eepromLastApRssi() { return eeprom.ReadInt16(103); }
void eepromLastApRssi(sint16 Rssi) { eeprom.WriteInt16(103, Rssi); }
//	105		2		SetPoint0 * 100
sint16 eepromSetPoint0() { return eeprom.ReadInt16(105); }
void eepromSetPoint0(sint16 Weight) { eeprom.WriteInt16(105, Weight); }
//	107		2		SetPoint1 * 100
sint16 eepromSetPoint1() { return eeprom.ReadInt16(107); }
void eepromSetPoint1(sint16 Weight) { eeprom.WriteInt16(107, Weight); }
//	109		4		HX711 Zero Calibration
sint32 eepromZeroCal() { return eeprom.ReadInt32(109); }
void eepromZeroCal(sint32 ZeroCalVal) { eeprom.WriteInt32(109, ZeroCalVal); }
//	113		4		HZ711 Scale Factor
sint32 eepromScaleFactor() { return eeprom.ReadInt32(113); }
void eepromScaleFactor(sint32 ScaleFactor) { eeprom.WriteInt32(113, ScaleFactor); }
//	117

//	1020	2		Data sample Read pointer
sint16 eepromReadPointer() { return eeprom.ReadInt16(1020); }
void eepromReadPointer(sint16 PacketIndex) { eeprom.WriteInt16(1020, PacketIndex); }
//	1022	2		Data sample Write pointer
sint16 eepromWritePointer() { return eeprom.ReadInt16(1022); }
void eepromWritePointer(sint16 PacketIndex) { eeprom.WriteInt16(1022, PacketIndex); }
//	1024	3072	384 Data samples; 4 byte timestamp, 4 byte value
TimeAndValue eepromDataSample(uint16 PacketIndex)
{
	return{ eeprom.ReadInt32(1024 + (PacketIndex * 8)), eeprom.ReadInt32(1024 + (PacketIndex * 8) + 4) };
}
void eepromDataSample(uint16 PacketIndex, TimeAndValue Data)
{
	eeprom.WriteInt32(1024 + (PacketIndex * 8), Data.Time);
	eeprom.WriteInt32(1024 + (PacketIndex * 8) + 4, Data.Value);
}
//////////////////////////////////////////////

