#include <string>
#include <iostream>
#include <fstream>

#include "NobleConfig.h"
#include "sleepy_discord/sleepy_discord.h"

#define DISCORD_TOKEN_FNAME "discord_token.txt"

class NobleClient : public SleepyDiscord::DiscordClient
{
public:
	using SleepyDiscord::DiscordClient::DiscordClient;
	void onMessage(SleepyDiscord::Message message) override {
		if (message.startsWith("whcg hello"))
			sendMessage(message.channelID, "Hello " + message.author.username + ", NobleChat stands no chance");
	}
};

int main() 
{
	std::string fpath = std::string(NOBLE_PROJECT_SOURCE_DIR) + "/" + std::string(DISCORD_TOKEN_FNAME);
	std::ifstream f(fpath);
	if (f) {
		std::string token;
		std::getline(f, token);
		NobleClient client(token);
		client.run();
		std::cout << "NobleClient has started successfully!" << std::endl;
	} else {
		std::cout << "Provide: '" << DISCORD_TOKEN_FNAME << "', located at: '" << NOBLE_PROJECT_SOURCE_DIR << "'." << std::endl;
	}
}