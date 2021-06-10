#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Earthworm");

    sf::Texture tex; 
    if (!tex.loadFromFile("earthworm-jim.png"))
        return -1;

    sf::Sprite spr;
    spr.setTexture(tex);
    spr.setPosition(0, -45);

    sf::Music music;
    if (!music.openFromFile("earthworm-jim-music-new-junk-city.ogg"))
        return -1;

    int counter = 0;

    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev)) {
            switch (ev.type) {
                case sf::Event::Closed: window.close();
            }
        }

        window.clear();
        
        if (counter >= 10) {
            float newPosX = spr.getPosition().x + 1;
            if (newPosX >= 400)
                newPosX = -(float)spr.getTexture()->getSize().x;

            spr.setPosition(newPosX, spr.getPosition().y);
            counter -= 10;
        }
        window.draw(spr);
        window.display();
        ++counter;
    }

}