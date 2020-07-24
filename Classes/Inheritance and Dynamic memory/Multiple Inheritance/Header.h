#ifndef HEADER_H_
#define HEADER_H_
#include <string>

class Worker {
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() : fullname("No One"), id(0L) {};
	Worker(const std::string& s, long n) : fullname(s), id(n) {};
	virtual void Set() = 0;
	virtual void Show() const = 0;
	virtual ~Worker() = 0;
};

class Waiter : virtual public Worker {
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter() : Worker(), panache(0) {};
	Waiter(const std::string& s, long n, int p = 0) : Worker(s, n), panache(p) {};
	Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) {};
	void Set();
	void Show() const;
};

class Singer : virtual public Worker {
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
	void Data() const;
	void Get();
private:
	static char* pv[Vtypes];
	int voice;
public:
	Singer() : Worker(), voice(other) {};
	Singer(const std::string& s, long n, int v = other) : Worker(s, n), voice(v) {};
	Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) {};
	void Set();
	void Show() const;
};

class SingerWaiter : public Singer, public Waiter {
protected:
	void Data() const;
	void Get();
public:
	SingerWaiter() {};
	SingerWaiter(const std::string& s, long n, int p = 0, int v = other) : Worker(s, n), Singer(s, n, v), Waiter(s, n, p) {};
	SingerWaiter(const Worker& wk, int p = 0, int v = other) : Worker(wk), Singer(wk, v), Waiter(wk, p) {};
	SingerWaiter(const Singer& wk, int p = 0) : Worker(wk), Singer(wk), Waiter(wk, p) {};
	SingerWaiter(const Waiter& wk, int v = other) : Worker(wk), Singer(wk, v), Waiter(wk) {};
	void Set();
	void Show() const;
};

#endif