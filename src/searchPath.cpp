#include "searchPath.hh"

thsa::searchPath::searchPath()
{
  for (auto i = 0; i <= 5; i++)
    {
      _numberPathForEachSize.push_back(0);
    }
}

int thsa::searchPath::allPath()
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

void thsa::searchPath::searchOnePath(const std::vector<int> &path, int depth)
{
  if (ifInvalidPath(path) != 0)
    return;
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
	  _numberPathForEachSize.at(path.size() - 4) += 1;
	}
    }
}


void thsa::searchPath::printAllPath() const
{
  for (auto i = 4; i <= 9; i++)
    {
      printNumberForOne(i);
    }
}

int thsa::searchPath::ifInvalidPath(const std::vector<int> &path) const
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

void thsa::searchPath::printNumberForOne(int number) const
{
  long int numberPoss = 0;
  for (auto i = 0; i <= (number - 4); i++)
    {
      numberPoss += _numberPathForEachSize.at(i);
    };
  std::cout << "Paths numbers with minimal " << number << " nodes use : " << numberPoss << std::endl;
}
