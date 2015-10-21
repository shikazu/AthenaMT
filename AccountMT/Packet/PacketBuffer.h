#ifndef _PACKET_PACKETBUFFER_H_
#define _PACKET_PACKETBUFFER_H_

#include <vector>
#include <cstring>
#include <stdint.h>

namespace Packet
{
	class PacketBuffer
	{
	private:
		std::vector<char> buffer;
		uint32_t position;

	public:
		PacketBuffer()
		{
			position = 0;
		}

		template<typename T>
		void append(T value)
		{
			unsigned int len = sizeof(value);

			char data[len];
			memcpy(data, &value, len);

			for (unsigned int i = 0; i < len; i++)
			{
				buffer.push_back(data[i]);
			}
		}

		void appendBuffer(char *buffer, size_t length)
		{
			for (size_t i = 0; i < length; i++)
			{
				this->buffer.push_back(buffer[i]);
			}
		}

		size_t dataAvailable()
		{
			return (this->buffer.size() - position);
		}

		template<typename T>
		T getData()
		{
			T value;
			unsigned int len = sizeof(T);
			char *data = new char[sizeof(T)];

			for (unsigned int i = 0; i < len; i++)
			{
				data[i] = buffer[position++];
			}

			memcpy(&value, data, len);
			delete data;

			return value;
		}

		std::string getString(size_t length)
		{
			std::string value;
			bool terminated = false;

			for (size_t i = 0; i < length; i++)
			{
				char temp_val = this->getData<char>();

				if (temp_val == 0)
				{
					terminated = true;
				}

				if (!terminated)
				{
					value.push_back(temp_val);
				}
			}

			return value;
		}

		size_t getLength()
		{
			return buffer.size();
		}

		void clear()
		{
			this->buffer.clear();
			position = 0;
		}
	};
}
#endif // _BINARYBUFFER_HPP_