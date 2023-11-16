/******************************************************************************************************
 * Pragma
 ******************************************************************************************************/

#pragma once

/******************************************************************************************************
 * Include
 ******************************************************************************************************/

#include <cstdint>
#include "Eclectic/Source/Crc/CrcConfiguration.h"
#include "Eclectic/Source/Crc/CrcUtility.h"
#include <format>
#include <string>
#include <vector>

/******************************************************************************************************
 * Namespace
 ******************************************************************************************************/

namespace Eclectic
{
    /******************************************************************************************************
     * Class
     ******************************************************************************************************/

    /*** CRC8 ***/
    class Crc8
    {
        private:
            /* Variable */
            std::vector<std::uint8_t> lookupTable;

        public:
            /* Constructor */
            Crc8(const Crc8Configuration& Configuration);

            /* Method */
            std::uint8_t calculate(const std::vector<std::uint8_t> Data) const;
            std::uint8_t calculate(const std::uint8_t Data, std::uint8_t crc, const bool Last) const;
            void generateLookupTable();
            std::string toString() const;

            /* Variable */
            const Crc8Configuration Configuration;
    };

    /*** CRC16 ***/
    class Crc16
    {
        private:
            /* Variable */
            std::vector<std::uint16_t> lookupTable;

        public:
            /* Constructor */
            Crc16(const Crc16Configuration& Configuration);

            /* Method */
            std::uint16_t calculate(const std::vector<std::uint8_t> Data) const;
            std::uint16_t calculate(const std::uint8_t Data, std::uint16_t crc, const bool First, const bool Last) const;
            void generateLookupTable();
            std::string toString() const;

            /* Variable */
            const Crc16Configuration Configuration;
    };

    /*** CRC32 ***/
    class Crc32
    {
        private:
            /* Variable */
            std::vector<std::uint32_t> lookupTable;

        public:
            /* Constructor */
            Crc32(const Crc32Configuration& Configuration);

            /* Method */
            std::uint32_t calculate(const std::vector<std::uint8_t> Data) const;
            std::uint32_t calculate(const std::uint8_t Data, std::uint32_t crc, const bool First, const bool Last) const;
            void generateLookupTable();
            std::string toString() const;

            /* Variable */
            const Crc32Configuration Configuration;
    };
}
