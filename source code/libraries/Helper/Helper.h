#ifndef _HELPER_H
#define _HELPER_H

#include "Arduino.h"

/// @author Rhalf Wendel D Caacbay <rhalfcaacbay@gmail.com>

// logo : byte arry 128x64 | 8192 pixels
class Helper {

     public:
          String toUtf8(float value);
          String toUtf8Currency(uint32_t value);
          String toUtf8Time(uint32_t value);
          String toUtf8Time2(uint32_t value);
          String toHexString(uint8_t * value, uint8_t length);

          String padding(String data, String character, uint8_t length);
          
          String debug(String tag, uint32_t value);

          uint32_t parseInt(String value);
     private:
          uint8_t _index = 0;
          char _buffer[20];
     
};


#endif // _HELPER_H
