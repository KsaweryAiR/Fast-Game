#include "audio.h"

Audio::Audio()
{

    auto kill =std::make_unique<sf::SoundBuffer>();
    if (!kill->loadFromFile("kill.wav")) {
        throw("Could not load texture");
         }
        buffer_.emplace_back(std::move(kill));
        kill_.setBuffer(**(buffer_.end()-1));
        kill_.setVolume(60);

        auto coin =std::make_unique<sf::SoundBuffer>();
        if (!coin->loadFromFile("coin.wav")) {
            throw("Could not load texture");
             }
            buffer_.emplace_back(std::move(coin));
            coin_.setBuffer(**(buffer_.end()-1));
            coin_.setVolume(100);
}
void Audio::Playmusic()
{
    if (soundtrack_.openFromFile("joshua_mclean.wav")) {
            soundtrack_.setVolume(15);
            soundtrack_.setLoop(true);
            soundtrack_.play();
        }
}
void Audio::playkill()
{

    kill_.play();
}
void Audio::playcoin()
{

    coin_.play();
}

