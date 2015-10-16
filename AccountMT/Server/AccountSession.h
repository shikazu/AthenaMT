#ifndef _ACCOUNT_SESSION_H_
#define _ACCOUNT_SESSION_H_

#include <boost/asio.hpp>
#include "../Packet/PacketBuffer.h"
#include "../Packet/Packets/Packets.h"

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
	};
}


#endif