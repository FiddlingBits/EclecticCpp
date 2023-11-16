/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <cstdint>
#include <format>
#include <string>

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace Eclectic
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** CRC8 Configuration ***/
    class Crc8Configuration
    {
        public:
            /* Enumeration */
            enum class Algorithm
            {
                CRC_8,
                CRC_8_CDMA2000,
                CRC_8_DARC,
                CRC_8_DVB_S2,
                CRC_8_EBU,
                CRC_8_I_CODE,
                CRC_8_ITU,
                CRC_8_MAXIM,
                CRC_8_ROHC,
                CRC_8_WCDMA
            };

            /* Constructor */
            Crc8Configuration(const std::string Name, const std::uint8_t Check, const std::uint8_t Polynomial, const std::uint8_t Initial, const bool Reflect, const std::uint8_t XOrOut);

            /* Method */
            static Crc8Configuration get(const Algorithm A);
            std::string toString() const;

            /* Variable */
            std::string name;
            std::uint8_t check;
            std::uint8_t polynomial;
            std::uint8_t initial;
            bool reflect;
            std::uint8_t xOrOut;
    };

    /*** CRC16 Configuration ***/
    class Crc16Configuration
    {
        public:
            /* Enumeration */
            enum class Algorithm
            {
                CRC_16_ARC,
                CRC_16_AUG_CCITT,
                CRC_16_BUYPASS,
                CRC_16_CCITT_FALSE,
                CRC_16_CDMA2000,
                CRC_16_DDS_110,
                CRC_16_DECT_R,
                CRC_16_DECT_X,
                CRC_16_DNP,
                CRC_16_EN_13757,
                CRC_16_GENIBUS,
                CRC_16_KERMIT,
                CRC_16_MAXIM,
                CRC_16_MCRF4XX,
                CRC_16_MODBUS,
                CRC_16_RIELLO,
                CRC_16_T10_DIF,
                CRC_16_TELEDISK,
                CRC_16_TMS37157,
                CRC_16_USB,
                CRC_16_X_25,
                CRC_16_XMODEM,
                CRC_A
            };

            /* Constructor */
            Crc16Configuration(const std::string Name, const std::uint16_t Check, const std::uint16_t Polynomial, const std::uint16_t Initial, const bool Reflect, const std::uint16_t XOrOut);

            /* Method */
            static Crc16Configuration get(const Algorithm A);
            std::string toString() const;

            /* Variable */
            std::string name;
            std::uint16_t check;
            std::uint16_t polynomial;
            std::uint16_t initial;
            bool reflect;
            std::uint16_t xOrOut;
    };

    /*** CRC32 Configuration ***/
    class Crc32Configuration
    {
        public:
            /* Enumeration */
            enum class Algorithm
            {
                CRC_32,
                CRC_32_BZIP2,
                CRC_32_JAMCRC,
                CRC_32_MPEG_2,
                CRC_32_POSIX,
                CRC_32_SATA,
                CRC_32_XFER,
                CRC_32C,
                CRC_32D,
                CRC_32Q
            };

            /* Constructor */
            Crc32Configuration(const std::string Name, const std::uint32_t Check, const std::uint32_t Polynomial, const std::uint32_t Initial, const bool Reflect, const std::uint32_t XOrOut);

            /* Method */
            static Crc32Configuration get(const Algorithm A);
            std::string toString() const;

            /* Variable */
            std::string name;
            std::uint32_t check;
            std::uint32_t polynomial;
            std::uint32_t initial;
            bool reflect;
            std::uint32_t xOrOut;
    };
}
