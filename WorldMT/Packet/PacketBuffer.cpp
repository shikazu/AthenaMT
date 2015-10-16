#include "PacketBuffer.h"

using namespace Packet;

PacketBuffer::PacketBuffer()
{
	position = 0;
}

PacketBuffer::~PacketBuffer()
{

}

std::string PacketBuffer::getString(size_t length)
{
	std::string temp;
	if (data_available() >= length)
	{
		for (size_t i = 0; i < length; i++)
		{
			char tmp = getData<char>();
			if (tmp != 0)
			{
				temp.push_back(tmp);
			}
			else
			{
				position += (length - i - 1);
				return temp;
			}
		}
		return temp;
	}
	return temp;
}

void PacketBuffer::appendPacket(char* packet, size_t packetLength)
{
	for (size_t i = 0; i < packetLength; i++)
	{
		this->buffer.push_back((uint8_t)packet[i]);
	}
}

size_t PacketBuffer::data_available()
{
	return (this->buffer.size() - position);
}