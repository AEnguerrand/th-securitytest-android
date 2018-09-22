#include "searchPath.hh"

thsa::searchPath::searchPath() :
	_numberPath(0)
{
}

thsa::searchPath::~searchPath()
{

}

int thsa::searchPath::allPath(void)
{
  for (auto i = 4; i <= 9; i++)
    {
      for (auto a = 1; a <= 9; a++)
	{
	  std::vector<int> tmp = {a};
	  searchOnePath(tmp, i);
	}
    }
  return 0;
}

void thsa::searchPath::searchOnePath(std::vector<int> path, int depth)
{
  depth -= 1;
  if (depth > 0)
    {
      for (auto a = 1; a <= 9; a++)
	{
	  if (std::find(path.begin(), path.end(), a) == path.end())
	    {
	      std::vector<int> tmp;
	      tmp.assign(path.begin(), path.end());
	      tmp.push_back(a);
	      searchOnePath(tmp, depth);
	    }
	}
    }
  else
    {
      if (ifInvalidPath(path) == 0)
	{
	  _numberPath += 1;
	}
    }
}

void thsa::searchPath::printAllPath(void)
{
  std::cout << "Paths numbers: " << _numberPath << std::endl;
}

int thsa::searchPath::ifInvalidPath(std::vector<int> path)
{
  static bool found;
  for (auto i = path.begin(); (i + 1) != path.end(); i++)
    {
      for (auto a = _invalidPath.begin(); a != _invalidPath.end(); a++)
	{
	  if (*i == a->at(0) && *(i + 1) == a->at(1))
	    {
	      found = false;
	      for (auto u = path.begin(); u != i; u++)
		{
		  if (*u == a->at(2))
		    found = true;
		}
	      if (!found)
		return (1);
	    }
	}
    }
  return (0);
}
