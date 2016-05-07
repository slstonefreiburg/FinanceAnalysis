#include "data_processing.h"

using namespace std;

DataProcessing::DataProcessing()
{

}

DataProcessing::~DataProcessing()
{

}

bool DataProcessing::readIn(const std::string &filename)
{
	bool ret = true;
	std::string line;
	std::ifstream myfile(filename.c_str());
	if (myfile.is_open())
	{
		// loop through each row
		if (getline(myfile, line)) {
			// extract each column element
			std::vector<std::string> tokens;
			tokenize(line, tokens, ",");
			if (tokens.size() < 4) {
				cout << "Data Size Error" << endl;
				ret = false;
			}
			else {
				// get the value from the column element
				myIndexData mid;
				mid.date.year = atoi(tokens[0].c_str());
				//mid.date.month = ;
				//mid.date.day = ;
				//mid.time.hour = ;
				//mid.time.min = ;
				//mid.time.sec = ;
				mid.volume = atof(tokens[6].c_str());
				//mid.prive = ;
				//mid.diff = ;
				//mid.change = ;

				// put the data in vector
				_index_data.push_back(mid);
			}
		}
		else {
			cout << "Can't open file " << filename << endl;
			ret = false;
		}

		myfile.close();
	}
	else {
		ret = false;
		cout << "Unable to open file " << filename << endl;
	}

	return ret;
}

void DataProcessing::convertToCNTKFormat()
{

}

void DataProcessing::tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters)
{
	// Skip delimiters at beginning.
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first "non-delimiter".
	std::string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
}
