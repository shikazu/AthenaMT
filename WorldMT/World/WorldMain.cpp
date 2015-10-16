#include "WorldMain.h"

#include "../Connector/ConnectorClient.h"

using namespace World;

WorldMain::WorldMain()
{
	this->start_account_connector_client();
	this->start_world_connector_server();

	this->startup();
}

WorldMain::~WorldMain()
{

}

void WorldMain::start_account_connector_client()
{
	try
	{
		tcp::resolver Resolver(account_connector_io_service);
		tcp::resolver::query Query("localhost", "25000");

		tcp::resolver::iterator EndPointIterator = Resolver.resolve(Query);

		Connector::ConnectorClient Client(account_connector_io_service, EndPointIterator);

		std::cout << "Creating Connector Client Thread" << std::endl;
		boost::thread ClientThread(boost::bind(&boost::asio::io_service::run, &account_connector_io_service));
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void WorldMain::start_world_connector_server()
{

	
}

void WorldMain::startup()
{

}