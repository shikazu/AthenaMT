#include <iostream>

#include "Connector\ConnectorServer.h"
#include "Server\AccountServer.h"

/*#include "../Common/3rdParty/chaiscript/chaiscript.hpp"
#include "../Common/3rdParty/chaiscript/chaiscript_stdlib.hpp"*/

#include <thread>

boost::asio::io_service io_service_account;
boost::asio::io_service io_service_connector;

void run_connector_server()
{
	io_service_connector.run();
}

void run_account_server()
{
	io_service_account.run();
}

int main(int argc, char** argv)
{
	Connector::ConnectorServer connector_server(io_service_connector, 25000);
	Account::AccountServer account_server(io_service_account, 6900);

	std::thread *t_account = new std::thread(run_account_server);
	std::thread *t_connector = new std::thread(run_connector_server);

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}

