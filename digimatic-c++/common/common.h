#pragma once

#include <algorithm>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

namespace westerstrom
{
	inline std::vector<std::string> readLines(const std::string& inputFile)
	{
		std::vector<std::string> lines;
		std::fstream f(inputFile);

		while(!f.eof())
		{
			std::string line;
			if(std::getline(f, line))
			{
				line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
				line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
				lines.push_back(line);
			}
		}
		return lines;
	}

	inline std::vector<std::string> split(const std::regex& re, const std::string& subject)
	{
		using namespace std;
		vector<string> container{sregex_token_iterator(subject.begin(), subject.end(), re, -1),
		                         sregex_token_iterator()};
		return container;
	}

	inline std::vector<int> splitNumbers(const std::string& line)
	{
		using namespace std;
		vector<int> ints;
		regex re("\\D+");
		transform(sregex_token_iterator(line.begin(), line.end(), re, -1), sregex_token_iterator(),
		          back_inserter(ints), [](const auto& s) -> int {
			          try
			          {
				          return stoi(s);
			          } catch(const invalid_argument&)
			          {
				          return 0;
			          }
		          });
		return ints;
	}
} // namespace westerstrom
