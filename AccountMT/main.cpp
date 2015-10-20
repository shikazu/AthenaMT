#include <iostream>

#include "Connector\ConnectorServer.h"
#include "Server\AccountServer.h"

/*#include "../Common/3rdParty/chaiscript/chaiscript.hpp"
#include "../Common/3rdParty/chaiscript/chaiscript_stdlib.hpp"*/

#include <boost/thread.hpp>
#include <boost/bind.hpp>

boost::asio::io_service io_service;

int main(int argc, char** argv)
{
	Connector::ConnectorServer connector_server(io_service, 25000);
	Account::AccountServer account_server(io_service, 6900);

	std::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
	t.join();

	return 0;
}

