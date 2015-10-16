#ifndef _PACKET_PACKETBUFFER_H_
#define _PACKET_PACKETBUFFER_H_

#include <vector>
#include <stdint.h>

namespace Packet
{
	class PacketBuffer
	{
	private:
		std::vector<uint8_t> buffer;
		size_t position;

	public:
		PacketBuffer();
		~PacketBuffer();

		template<typename T>
		T getData()
		{
			T result;
			uint8_t *p = &buffer[position];
			std::copy(p, p + sizeof(T), (uint8_t*)&result);
			position += sizeof(T);
			return result;
		}

		std::string getString(size_t length);

		void appendPacket(char* packet, size_t packetLength);

		size_t data_available();
	};
}

#endif