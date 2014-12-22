#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "pic.hpp"

class picture
{
	friend picture frame(const picture&,char,char,char);
	friend picture hcat(const picture &l, const picture &r);
	friend picture vcat(const picture &t, const picture &b);
	friend std::ostream& operator<<(std::ostream &os, const picture &pic);
public:
	picture(const std::vector<std::string>&);
	void reframe(char c, char h, char v) { p->reframe(c,h,v); }

private:
	picture(pic_base *ptr) : p(ptr) { }

	ptr<pic_base> p;
};

picture frame(const picture &pic, char c='^', char h='*', char v='%')
{
	return new frame_pic(pic.p,c,h,v);
}

picture hcat(const picture &l, const picture &r)
{
	return new hcat_pic(l.p,r.p);
}

picture vcat(const picture &t, const picture &b)
{
	return new vcat_pic(t.p,b.p);
}

picture::picture(const std::vector<std::string> &v) : p(new string_pic(v)) { }

std::ostream& operator<<(std::ostream &os, const picture &pic)
{
	const pic_base::ht_sz ht = pic.p->height();
	for(pic_base::ht_sz i=0; i!=ht; ++i)
	{
		pic.p->display(os,i,false);
		os << std::endl;
	}
}
