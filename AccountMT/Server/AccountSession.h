#ifndef _ACCOUNT_SESSION_H_
#define _ACCOUNT_SESSION_H_

#include <boost/asio.hpp>
#include "../Packet/PacketBuffer.h"
#include "../Packet/Packets/Packets.h"

#include <iostream>

using namespace Packet;

namespace Account
{
	class AccountSession : public std::enable_shared_from_this<AccountSession>
	{
	public:
		AccountSession(boost::asio::ip::tcp::socket socket);

		void start();

	private:
		boost::asio::ip::tcp::socket _socket;

		char packet[4096];
		PacketBuffer packet_buffer;

		void do_read();
		void do_write(char* write_buffer, std::size_t length);

		void handle_packets();

		void handle_login(PacketBuffer &buffer, uint16_t PacketType)
		{
			if (PacketType == 0x64)
			{
				PACKET_CA_LOGIN *packet_ca_login = new PACKET_CA_LOGIN(packet_buffer);

				std::cout << "User \"" << packet_ca_login->ID << "\" wants to login with password \"" << packet_ca_login->Passwd << "\"" << std::endl;
			}
		}
	};
}


#endif