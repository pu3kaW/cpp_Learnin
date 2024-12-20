#ifndef CLASSIC0_H_
#define CLASSIC0_H_

class Cd
{
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd& operator=(const Cd& d);
};

class Classic : public Cd
{
private:
	char* mvp;
public:
	Classic(const char* m, const char* s1, const char* s2, int n, double x);
	Classic(const char* m, Cd& d);
	Classic();
	~Classic();
	virtual void Report() const;
	Classic& operator=(const Classic& c);
};

#endif

