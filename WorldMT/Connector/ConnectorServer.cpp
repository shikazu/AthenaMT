#include "ConnectorServer.h"

using namespace Connector;

ConnectorServer::ConnectorServer(boost::asio::io_service &io_service, uint16_t port) : acceptor(io_service, tcp::endpoint(tcp::v4(), port)), socket(io_service)
{
	std::cout << "ConnectorServer Accept" << std::endl;
	do_accept();
}

ConnectorServer::~ConnectorServer()
{

}

void ConnectorServer::do_accept()
{
	std::cout << "Do Accept" << std::endl;
	acceptor.async_accept(socket, [this](boost::system::error_code ec)
	{
		if (!ec)
		{
			std::cout << "Account Server Connection accepted!" << std::endl;
			std::make_shared<ConnectorSession>(std::move(socket))->start();
		}

		do_accept();
	});
}

