#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

bool space(char c)
{
        return isspace(c);
}

bool not_space(char c)
{
        return !isspace(c);
}

std::vector<std::string> split(const std::string &s)
{
        typedef std::string::const_iterator iter;
        std::vector<std::string> ret;

        iter i = s.begin();
        while(i != s.end())
        {
                // ignore leading blanks
                i = std::find_if(i,s.end(),not_space);

                // find end of next word
                iter j = std::find_if(i,s.end(),space);

                // copy the characters in [i,j)
                if(i != s.end())
                {
                        ret.push_back(std::string(i,j));
                }
                i = j;
        }

        return ret;
}

template <class OutputIterator>
void xref(std::istream &in, OutputIterator d, std::vector<std::string> find_words(const std::string &s) = split)
{
	std::string line;
	int line_number = 0;
	std::map<std::string, std::vector<int> > ret;

	// read the next line
	while(std::getline(in,line))
	{
		++line_number;

		// break the input line into words
		std::vector<std::string> words = find_words(line);

		// remember that each word occurs on the current line
		for(std::vector<std::string>::const_iterator it=words.begin();it!=words.end();++it)
		{
			ret[*it].push_back(line_number);
		}
	}

	std::copy(ret.begin(),ret.end(),d);
}

//How in the hell we were supposed to come up with this class at this point in the book is beyond me
template <class T, class charT = char, class traits = std::char_traits<charT> >
class my_ostream_iterator :
  public std::iterator<std::output_iterator_tag, void, void, void, void>
{
  std::basic_ostream<charT, traits>* out_stream;
  const charT* delim;

public:
  typedef charT char_type;
  typedef traits traits_type;
  typedef std::basic_ostream<charT, traits> ostream_type;
  my_ostream_iterator(ostream_type& s) : out_stream(&s), delim(0) {}
  my_ostream_iterator(ostream_type& s, const charT* delimiter)
    : out_stream(&s), delim(delimiter) { }
  my_ostream_iterator(const my_ostream_iterator<T, charT, traits>& x)
    : out_stream(x.out_stream), delim(x.delim) {}
  ~my_ostream_iterator() {}

  // print pair<string, vector<int>> to std out
  my_ostream_iterator<T, charT, traits>& operator=(const T& value) {
    *out_stream << value.first << ": ";
    for (int i = 0; i != value.second.size(); ++i)
      *out_stream << value.second[i] << delim;
    *out_stream << std::endl;
    return *this;
  }

  my_ostream_iterator<T, charT, traits>& operator*() { return *this; }
  my_ostream_iterator<T, charT, traits>& operator++() { return *this; }
  my_ostream_iterator<T, charT, traits>& operator++(int) { return *this; }
};

int main()
{

	std::cout << "Using std::cout directly: " << std::endl;
	my_ostream_iterator<std::pair<std::string, std::vector<int> > > out_it(std::cout," ");
	xref(std::cin,out_it);

	std::cout << std::endl << "Using std::map: " << std::endl;
	std::cin.clear();
	std::map<std::string, std::vector<int> > ret;
	xref(std::cin,std::inserter(ret,ret.begin()));

	// write the results
	for(std::map<std::string, std::vector<int> >::const_iterator it=ret.begin();it!=ret.end();++it)
	{
		// write the word
		std::cout << it->first << " occurs on line(s): ";

		// followed by one or more line numbers
		std::vector<int>::const_iterator line_it = it->second.begin();
		std::cout << *line_it;

		++line_it;
		// write the rest of the line numbers, if any
		while(line_it != it->second.end())
		{
			std::cout << "," << *line_it;
			++line_it;
		}

		// write a new line to separate each word from the list
		std::cout << std::endl;
	}

	return 0;
}
