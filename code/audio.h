#ifndef AUDIO_H
#define AUDIO_H
#include <SFML/Audio.hpp>
#include <iostream>



class Audio
{
    sf::Music soundtrack_;
    sf::Sound kill_;
    sf::Sound coin_;
    std::vector<std::unique_ptr<sf::SoundBuffer>> buffer_;

public:
    Audio();
    void Playmusic();
    void playkill();
    void playcoin();
};

#endif // AUDIO_H
