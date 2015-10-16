#ifndef _CONNECTOR_SESSION_H_
#define _CONNECTOR_SESSION_H_

#include <boost/asio.hpp>
#include "../Packet/PacketBuffer.h"
#include <thread>

using namespace Packet;

namespace Connector
{
	class ConnectorSession : public std::enable_shared_from_this<ConnectorSession>
	{
	public:
		ConnectorSession(boost::asio::ip::tcp::socket socket);

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