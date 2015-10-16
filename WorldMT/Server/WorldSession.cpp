#include "WorldSession.h"

#include <iostream>

using namespace World;

WorldSession::WorldSession(boost::asio::ip::tcp::socket socket) : _socket(std::move(socket))
{

}


void WorldSession::do_read()
{
	auto self(shared_from_this());
	_socket.async_read_some(boost::asio::buffer(packet, 4096), [this, self](boost::system::error_code ec, std::size_t length)
	{
		std::cout << "Received " << length << " bytes" << std::endl;
		if (!ec)
		{
			packet_buffer.appendPacket(packet, length);
			if (packet_buffer.data_available() > 0)
			{
				this->handle_packets();
			}
		}
	});
}

void WorldSession::do_write(char *write_buffer, std::size_t length)
{
	auto self(shared_from_this());
	boost::asio::async_write(_socket, boost::asio::buffer(write_buffer, length),
		[this, self](boost::system::error_code ec, std::size_t length)
	{
		if (!ec)
		{
			this->do_read();
		}
	});
}

void WorldSession::start()
{
	this->do_read();
}

void WorldSession::handle_packets()
{
	while (packet_buffer.data_available() >= 2)
	{
		uint16_t PacketType = packet_buffer.getData<uint16_t>();

		std::cout << "PacketType:" << std::hex << PacketType << std::endl;

		switch (PacketType)
		{
		case 0x9000:
			break;
		default:
			std::cout << "Received Unknown PacketType: " << std::hex << PacketType << std::dec << std::endl;
			break;
		}
	}

	this->do_read();
}