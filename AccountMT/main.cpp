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

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <mysql_error.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

boost::asio::io_service io_service;

void publishHandler(RedisAsyncClient &publisher, const RedisValue &)
{
	/*publisher.publish("Account", "First hello", [&](const RedisValue &) {
		
	});*/

	publisher.publish("Account", "Redis Account Test Message");
} 

using namespace std;

int main(int argc, char** argv)
{
	Common::Configuration config;

	AccountConfiguration* accountConfig = config.getAccountConfiguration();

	Account::AccountServer account_server(io_service, accountConfig->accountPort);

	// MySQL C++ Connector PoC
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "");
		/* Connect to the MySQL test database */
		con->setSchema("test");

		stmt = con->createStatement();
		res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
		while (res->next()) {
			cout << "\t... MySQL replies: ";
			/* Access column data by alias or column name */
			cout << res->getString("_message") << endl;
			cout << "\t... MySQL says it again: ";
			/* Access column fata by numeric offset, 1 is the first column */
			cout << res->getString(1) << endl;
		}
		delete res;
		delete stmt;
		delete con;

	}
	catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

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

