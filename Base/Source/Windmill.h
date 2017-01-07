#ifndef WINDMILL_H
#define WINDMILL_H

class GenericEntity;
class Windmill
{
public:
	Windmill();
	~Windmill();

	void Update(double dt);

private:
	GenericEntity* parts[3];
};

#endif 