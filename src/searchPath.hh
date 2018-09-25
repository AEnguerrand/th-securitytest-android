#ifndef TH_SECURITYTEST_ANDROID_SEARCHPATH_HH
#define TH_SECURITYTEST_ANDROID_SEARCHPATH_HH

#include <vector>
#include <array>
#include <iostream>

namespace thsa
{
  class searchPath
  {
   private:
    long int _numberPath;
    /**
     * @details
     * array description:
     * 0,1: path
     * 3: point use = valid / point not use = invalid
     */
    const std::vector<std::vector<int> > _invalidPath = {
	    {1, 3, 2},
	    {3, 1, 2},
	    {1, 7, 6},
	    {7, 1, 6},
	    {1, 9, 5},
	    {9, 1, 5},
	    {2, 8, 5},
	    {8, 2, 5},
	    {3, 7, 5},
	    {7, 3, 5},
	    {4, 6, 5},
	    {6, 4, 5},
	    {7, 9, 8},
	    {9, 7, 8},
	    {3, 9, 4},
	    {9, 3, 4}
    };
   public:
    searchPath();

    ~searchPath();

    int allPath();

    void printAllPath();

   private:
    void searchOnePath(const std::vector<int> &path, int depth);

    int ifInvalidPath(const std::vector<int> &path);
  };
}

#endif //TH_SECURITYTEST_ANDROID_SEARCHPATH_HH
