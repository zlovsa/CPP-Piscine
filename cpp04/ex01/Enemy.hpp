#ifndef ENEMY_HPP
# define ENEMY_HPP

class Enemy
{
public:
	Enemy(int hp, std::string const &type);
	virtual ~Enemy();
	std::string const &getType() const;
	int getHP() const;
	void takeDamage(int damage);

private:
	Enemy();
	Enemy(Enemy const &other);
	Enemy &operator=(Enemy const &other);
	int _hp;
	std::string _type;
};

#endif
