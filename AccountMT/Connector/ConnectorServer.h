#ifndef _CONNECTOR_SERVER_H_
#define _CONNECTOR_SERVER_H_

#include <iostream>
#include <boost/asio.hpp>

#include "ConnectorSession.h"

using boost::asio::ip::tcp;

namespace Connector
{
	class ConnectorServer
	{
	public:
		ConnectorServer(boost::asio::io_service &io_service, uint16_t port);
		~ConnectorServer();

	private:
		void do_accept();		

		tcp::acceptor acceptor;
		tcp::socket socket;
	};
}

#endif