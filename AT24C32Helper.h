// AT24C32Helper.h

#ifndef _AT24C32_HELPER_h
#define _AT24C32_HELPER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class AT24C32Helper
{
public:
	boolean begin();
	boolean begin(uint8 pinSDA, uint8 pinSCL);
	boolean begin(int eepromAddr);
	boolean begin(int eepromAddr, uint8 pinSDA, uint8 pinSCL);

	String ReadString(int addr);
	String ReadStringExact(int addr, int buff);
	void WriteString(int addr, String val, int maxLen, bool ExcludeTermination);
	void WriteString(int addr, String val, int maxLen);
	void WriteStringExact(int addr, String val, int maxLen);
	signed short ReadInt(int addr);
	void WriteInt(int addr, signed short value);
	long ReadLong(int addr);
	void WriteLong(int addr, long value);

private:
	void i2c_eeprom_write_byte(int deviceaddress, unsigned int eeaddress, byte data);
	void i2c_eeprom_write_page(int deviceaddress, unsigned int eeaddresspage, byte * data, byte length);
	byte i2c_eeprom_read_byte(int deviceaddress, unsigned int eeaddress);
	void i2c_eeprom_read_buffer(int deviceaddress, unsigned int eeaddress, byte * buffer, int length);
	int deviceAddr;
};

#endif

