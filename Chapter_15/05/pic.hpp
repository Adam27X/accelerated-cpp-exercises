#pragma once

#include <vector>
#include <string>
#include <algorithm>

#include "ptr.hpp"

class picture; // forward declaration

class pic_base
{
	friend std::ostream& operator<<(std::ostream&, const picture&);
	friend class frame_pic;
	friend class hcat_pic;
	friend class vcat_pic;
	friend class string_pic;
	friend class picture;

	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;
public:
	virtual ~pic_base() { }

protected:
	static void pad(std::ostream &os, wd_sz beg, wd_sz end)
	{
		while(beg != end)
		{
			os << " ";
			++beg;
		}
	}

private:
	virtual wd_sz width() const = 0;
	virtual ht_sz height() const = 0;
	virtual void display(std::ostream&, ht_sz, bool) const = 0;
	virtual void reframe(char,char,char) = 0;
};

class string_pic: public pic_base
{
	friend class picture;

private:
	string_pic(const std::vector<std::string> &v) : data(v) { }
	ht_sz height() const { return data.size(); }
	wd_sz width() const;
	void display(std::ostream&, ht_sz, bool) const;
	void reframe(char,char,char) { }

	std::vector<std::string> data;
};

pic_base::wd_sz string_pic::width() const
{
	pic_base::wd_sz n = 0;
	for(pic_base::ht_sz i=0; i!=data.size(); ++i)
	{
		n = std::max(n,data[i].size());
	}

	return n;
}

void string_pic::display(std::ostream &os, ht_sz row, bool do_pad) const
{
	wd_sz start = 0;
		
	// write the row if we're still in range
	if(row < height())
	{
		os << data[row];
		start = data[row].size();
	}
	
	// pad the output if necessary
	if(do_pad)
	{
		pad(os,start,width());
	}
}

class frame_pic: public pic_base
{
	friend picture frame(const picture&,char,char,char);

private:
	frame_pic(const ptr<pic_base> &pic, char cc='^', char hh='*', char vv='%'): p(pic), c(cc), h(hh), v(vv)  { }

	wd_sz width() const { return p->width() + 4; }
	ht_sz height() const { return p->height() + 4; }
	void display(std::ostream &, ht_sz, bool) const;
	void reframe(char,char,char);

	ptr<pic_base> p;
	char c;
	char h;
	char v;
};

void frame_pic::display(std::ostream &os, ht_sz row, bool do_pad) const
{
	if(row >= height())
	{
		// out of range
		if(do_pad)
		{
			pad(os,0,width());
		}
	}
	else
	{
		if(row == 0 || row == height() - 1)
		{
			// top or bottom row
			os << c << std::string(width()-2, h) << c;
		}
		else if(row == 1 || row == height() - 2)
		{
			// second from top or bottom row
			os << v;
			pad(os,1,width()-1);
			os << v;
		}
		else
		{
			// interior row
			os << v << " ";
			p->display(os,row-2,true);
			os << " " << v;
		}
	}
}

void frame_pic::reframe(char cc, char hh, char vv)
{
	p->reframe(cc,hh,vv);
	c = cc;
	h = hh;
	v = vv;
}

class hcat_pic: public pic_base
{
	friend picture hcat(const picture &, const picture &);
	
private:
	hcat_pic(const ptr<pic_base> &l, const ptr<pic_base> &r) : left(l), right(r) { }
	
	wd_sz width() const { return left->width() + right->width(); }
	ht_sz height() const { return std::max(left->height(),right->height()); }
	void display(std::ostream&,ht_sz,bool) const;
	void reframe(char,char,char);

	ptr<pic_base> left,right;
};

void hcat_pic::display(std::ostream &os, ht_sz row, bool do_pad) const
{
	ht_sz lht = left->height();
	ht_sz rht = right->height();

	if(lht > rht) //center the right picture
	{
		left->display(os,row,do_pad || row < right->height());

		ht_sz pad = (lht - rht)/2;
		ht_sz right_row = (row < pad) ? rht : row-pad;
		right->display(os,right_row,do_pad);
	}
	else if(rht > lht)
	{
		ht_sz pad = (rht - lht)/2;
		ht_sz left_row = (row < pad) ? lht : row-pad;
		left->display(os,left_row,do_pad || row < right->height());

		right->display(os,row,do_pad);
	}
	else
	{
		left->display(os,row,do_pad || row < right->height());
		right->display(os,row,do_pad);
	}
}

void hcat_pic::reframe(char c, char h, char v)
{
	left->reframe(c,h,v);
	right->reframe(c,h,v);
}

class vcat_pic: public pic_base
{
	friend picture vcat(const picture &, const picture &);

private:
	vcat_pic(const ptr<pic_base> &t, const ptr<pic_base> &b) : top(t), bottom(b) { }
	
	wd_sz width() const { return std::max(top->width(),bottom->width()); }
	ht_sz height() const { return top->height() + bottom->height(); }
	void display(std::ostream&,ht_sz,bool) const;
	void reframe(char,char,char);

	ptr<pic_base> top,bottom;
};

void vcat_pic::display(std::ostream &os, ht_sz row, bool do_pad) const
{
	wd_sz w = 0;
	if(row < top->height())
	{
		// we are in the top subpicture
		top->display(os,row,do_pad);
		w = top->width();
	}
	else if(row < height())
	{
		// we are in the bottom subpicture
		bottom->display(os,row-top->height(),do_pad);
		w = bottom->width();
	}

	if(do_pad)
	{
		pad(os,w,width());
	}
}

void vcat_pic::reframe(char c, char h, char v)
{
	top->reframe(c,h,v);
	bottom->reframe(c,h,v);
}
