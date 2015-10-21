#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Connector\RedisConnector.h"
#include "Server\AccountServer.h"
#include "Connector\RedisAccountSubscription.hpp"

#include "../Common/Configuration/Configuration.h"

#include "../Common/3rdParty/json/picojson.h"

#include <boost/thread.hpp>
#include <boost/bind.hpp>

boost::asio::io_service io_service;

void publishHandler(RedisAsyncClient &publisher, const RedisValue &)
{
	/*publisher.publish("Account", "First hello", [&](const RedisValue &) {
		
	});*/

	publisher.publish("Account", "Redis Account Test Message");
} 

std::string slurp(std::ifstream& in) {
	return static_cast<std::stringstream const&>(std::stringstream() << in.rdbuf()).str();
}

std::string readFile(std::string fileName)
{
	std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
	if (ifs.is_open())
	{
		std::cout << "File has been opened!" << std::endl;
		return slurp(ifs);
	}
	else
	{
		return "failed!";
	}
}



int main(int argc, char** argv)
{
	Common::Configuration config;
	/* std::string jsonConfig = readFile("config/account.json");

	std::cout << "Config: " << jsonConfig << std::endl;

	if (jsonConfig.length() > 0)
	{
		picojson::value value;
		picojson::parse(value, jsonConfig);

		picojson::object root_object = value.get<picojson::object>();
		std::cout << root_object["redis"] << std::endl;

		picojson::object redis_object = root_object["redis"].get<picojson::object>();
		std::cout << redis_object["host"].get<std::string>() << ":" << redis_object["port"].get<double>() << std::endl;
	}
	*/

	Account::AccountServer account_server(io_service, 6900);

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

