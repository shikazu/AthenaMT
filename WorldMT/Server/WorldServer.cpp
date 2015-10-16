#include "WorldServer.h"

using namespace World;

WorldServer::WorldServer(boost::asio::io_service &io_service, uint16_t port) : acceptor(io_service, tcp::endpoint(tcp::v4(), port)), socket(io_service)
{
	std::cout << "Account Server Accept" << std::endl;
	do_accept();
}

WorldServer::~WorldServer()
{

}

void WorldServer::do_accept()
{
	std::cout << "Do Accept" << std::endl;
	acceptor.async_accept(socket, [this](boost::system::error_code ec)
	{
		if (!ec)
		{
			std::cout << "Account Server Connection accepted!" << std::endl;
			std::make_shared<WorldSession>(std::move(socket))->start();
		}

		do_accept();
	});
}