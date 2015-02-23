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
};

class string_pic: public pic_base
{
	friend class picture;

private:
	string_pic(const std::vector<std::string> &v) : data(v) { }
	ht_sz height() const { return data.size(); }
	wd_sz width() const;
	void display(std::ostream&, ht_sz, bool) const;

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
	friend picture frame(const picture&);

private:
	frame_pic(const ptr<pic_base> &pic): p(pic) { }

	wd_sz width() const { return p->width() + 4; }
	ht_sz height() const { return p->height() + 4; }
	void display(std::ostream &, ht_sz, bool) const;

	ptr<pic_base> p;
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
			os << std::string(width(), '*');
		}
		else if(row == 1 || row == height() - 2)
		{
			// second from top or bottom row
			os << "*";
			pad(os,1,width()-1);
			os << "*";
		}
		else
		{
			// interior row
			os << "* ";
			p->display(os,row-2,true);
			os << " *";
		}
	}
}

class hcat_pic: public pic_base
{
	friend picture hcat(const picture &, const picture &);
	
private:
	hcat_pic(const ptr<pic_base> &l, const ptr<pic_base> &r) : left(l), right(r) { }
	
	wd_sz width() const { return left->width() + right->width(); }
	ht_sz height() const { return std::max(left->height(),right->height()); }
	void display(std::ostream&,ht_sz,bool) const;

	ptr<pic_base> left,right;
};

void hcat_pic::display(std::ostream &os, ht_sz row, bool do_pad) const
{
	left->display(os,row,do_pad || row < right->height());
	right->display(os,row,do_pad);
}

class vcat_pic: public pic_base
{
	friend picture vcat(const picture &, const picture &);

private:
	vcat_pic(const ptr<pic_base> &t, const ptr<pic_base> &b) : top(t), bottom(b) { }
	
	wd_sz width() const { return std::max(top->width(),bottom->width()); }
	ht_sz height() const { return top->height() + bottom->height(); }
	void display(std::ostream&,ht_sz,bool) const;

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
