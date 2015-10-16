#ifndef _PACKET_PACKET_H_
#define _PACKET_PACKET_H_

#include <vector>
#include <stdint.h>

namespace Packet
{
	class PacketBuilder
	{
	private:
		std::vector<uint8_t> buffer;

	public:
		template<typename T>
		void append(T value)
		{
			uint8_t* p = &value;
			for (size_t i = 0; i < sizeof(T); i++)
			{
				this->buffer.push_back((uint8_t)p[i]);
			}
		}

		void appendString(std::string value, size_t length)
		{
			for (size_t i = 0; i < length; i++)
			{
				this->buffer.push_back((uint8_t)value[i]);
			}
		}

		size_t getLength();
		uint8_t* getData();
	};
}

#endif