#ifndef _COMMON_CONFIGURATION_CONFIGURATION_H_
#define _COMMON_CONFIGURATION_CONFIGURATION_H_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>

namespace pt = boost::property_tree;

struct AccountConfiguration
{
	std::string redisHost;
	uint16_t redisPort;
	std::vector<std::string> redisSubscribe;
	std::vector<std::string> redisPublish;

	uint16_t accountPort;

	std::string mongoHost;
	uint16_t mongoPort;
	std::string mongoUsername;
	std::string mongoPassword;
	std::string mongoDatabase;

	void load(std::string &filename)
	{
		// Create empty property tree object
		pt::ptree tree;

		// Read JSON to property tree
		pt::read_json(filename, tree);

		// Use the throwing version of get to find the debug filename.
		// If the path cannot be resolved, an exception is thrown.
		redisHost = tree.get<std::string>("redis.hostname");

		// Use the default-value version of get to find the debug level.
		// Note that the default value is used to deduce the target type.
		redisPort = tree.get("redis.port", 0);

		// Use get_child to find the node containing the modules, and iterate over
		// its children. If the path cannot be resolved, get_child throws.
		// A C++11 for-range loop would also work.
		BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("redis.subscribe")) {
			// The data function is used to access the data stored in a node.
			redisSubscribe.push_back(v.second.data());
		}

		BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("redis.publish")) {
			// The data function is used to access the data stored in a node.
			redisPublish.push_back(v.second.data());
		}

		accountPort = tree.get("account.port", 0);

		mongoHost = tree.get<std::string>("mongo.hostname");
		mongoPort = tree.get("mongo.port", 0);
		mongoUsername = tree.get<std::string>("mongo.username");
		mongoPassword = tree.get<std::string>("mongo.password");
		mongoDatabase = tree.get<std::string>("mongo.database");
	}
};

namespace Common
{
	class Configuration
	{
	private:
		AccountConfiguration accountConfig;

	public:
		Configuration()
		{
			std::string filePathRedisConfiguration = "config/account.json";
			try
			{
				accountConfig.load(filePathRedisConfiguration);
			}
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
				getchar();
			}	
		}

		AccountConfiguration* getAccountConfiguration()
		{
			return &this->accountConfig;
		}
	};
}

#endif