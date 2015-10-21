#include "AccountSession.h"

#include <iostream>

using namespace Account;

AccountSession::AccountSession(boost::asio::ip::tcp::socket socket) : _socket(std::move(socket))
{

}


void AccountSession::do_read()
{
	auto self(shared_from_this());
	_socket.async_read_some(boost::asio::buffer(packet, 4096), [this, self](boost::system::error_code ec, std::size_t length)
	{
		std::cout << "Received " << length << " bytes" << std::endl;
		if (!ec)
		{
			packet_buffer.appendBuffer(packet, length);
			if (packet_buffer.dataAvailable() > 0)
			{
				this->handle_packets();
			}
		}
	});
}

void AccountSession::do_write(char *write_buffer, std::size_t length)
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

void AccountSession::start()
{
	this->do_read();
}

void AccountSession::handle_packets()
{
	while (packet_buffer.dataAvailable() >= 2)
	{
		uint16_t PacketType = packet_buffer.getData<uint16_t>();

		std::cout << "PacketType:" << std::hex << PacketType << std::endl;

		switch (PacketType)
		{
		case 0x64: // PACKET_CA_LOGIN
			this->handle_login(packet_buffer, PacketType);
			break;
		default:
			std::cout << "Received Unknown PacketType: " << std::hex << PacketType << std::dec << std::endl;
			break;
		}

		if (packet_buffer.dataAvailable() == 0)
		{
			packet_buffer.clear();
		}
	}
	this->do_read();
}
