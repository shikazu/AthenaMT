#include "Connector\ConnectorClient.h"

#include <thread>

boost::asio::io_service io_service;

int main(int argc, char** argv)
{
	try {
		tcp::resolver Resolver(io_service);
		tcp::resolver::query Query("localhost", "25000");

		tcp::resolver::iterator EndPointIterator = Resolver.resolve(Query);

		Connector::ConnectorClient Client(io_service, EndPointIterator);

		boost::thread ClientThread(boost::bind(&boost::asio::io_service::run, &io_service));
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	while (1)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}