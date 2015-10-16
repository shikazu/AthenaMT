#include "PacketBuilder.h"

using namespace Packet;

size_t PacketBuilder::getLength()
{
	return this->buffer.size();
}

uint8_t* PacketBuilder::getData()
{
	return this->buffer.data();
}