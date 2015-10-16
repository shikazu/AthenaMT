#ifndef _ACCOUNT_SERVER_H_
#define _ACCOUNT_SERVER_H_

#include <iostream>
#include <boost/asio.hpp>

#include "WorldSession.h"

using boost::asio::ip::tcp;

namespace World
{
	class WorldServer
	{
	public:
		WorldServer(boost::asio::io_service &io_service, uint16_t port);
		~WorldServer();

	private:
		void do_accept();

		tcp::acceptor acceptor;
		tcp::socket socket;
	};
}

#endif