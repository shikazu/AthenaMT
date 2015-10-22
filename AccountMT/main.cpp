#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Connector\RedisConnector.h"
#include "Server\AccountServer.h"
#include "Connector\RedisAccountSubscription.hpp"

#include "Configuration/Configuration.h"

#include <boost/thread.hpp>
#include <boost/bind.hpp>

boost::asio::io_service io_service;

void publishHandler(RedisAsyncClient &publisher, const RedisValue &)
{
	/*publisher.publish("Account", "First hello", [&](const RedisValue &) {
		
	});*/

	publisher.publish("Account", "Redis Account Test Message");
} 

int main(int argc, char** argv)
{
	Common::Configuration config;

	AccountConfiguration* accountConfig = config.getAccountConfiguration();

	Account::AccountServer account_server(io_service, accountConfig->accountPort);

	/*boost::asio::ip::address address = boost::asio::ip::address::from_string("127.0.0.1");
	const unsigned short port = 6379;

	RedisAsyncClient client(io_service);
	Connector::RedisConnector redis(io_service, client);

	RedisAsyncClient publisher(io_service);
	RedisAsyncClient subscriber(io_service);
	RedisAccountSubscription redisAccountSubscription(io_service);

	publisher.asyncConnect(address, port, [&](bool status, const std::string &err)
	{
		if (!status)
		{
			std::cerr << "Can't connect to redis" << err << std::endl;
		}
		else
		{
			subscriber.asyncConnect(address, port, [&](bool status, const std::string &err)
			{
				if (!status)
				{
					std::cerr << "Can't connect to redis" << err << std::endl;
				}
				else
				{
					subscriber.subscribe("Account",
						boost::bind(&RedisAccountSubscription::onMessage, &redisAccountSubscription, _1),
						boost::bind(&publishHandler, boost::ref(publisher), _1));
				}
			});
		}
	});
	*/
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
	t.join();

	return 0;
}

