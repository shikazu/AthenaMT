#ifndef _PACKET_PACKETBUFFER_H_
#define _PACKET_PACKETBUFFER_H_

#include <vector>
#include <stdint.h>
#include <queue>

namespace Packet
{
	class PacketBuffer
	{
	private:
		std::queue<uint8_t> buffer;

	public:
		PacketBuffer();
		~PacketBuffer();

		template<typename T>
		T getData()
		{
			T result;
			uint8_t *data = new uint8_t[sizeof(T)];
			for (size_t i = 0; i < sizeof(T); i++)
			{
				data[i] = this->buffer.front();
				this->buffer.pop();
			}
			std::copy(data, data + sizeof(T), (uint8_t*)&result);
			delete data;
			return result;
		}

		std::string getString(size_t length);

		void appendPacket(char* packet, size_t packetLength);

		size_t data_available();
	};
}

#endif