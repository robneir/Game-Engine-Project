#ifndef _FILE_UTILS_
#define _FILE_UTILS

namespace Scorch
{
namespace Utilities
{
	class FileUtils
	{
	public:
		static std::string read_file(const char* filepath)
		{
			FILE* file = fopen(filepath, "rt"); // r for read only and t for text file (which has line endings).
			if (file)
			{
				fseek(file, 0, SEEK_END);
				unsigned long length = ftell(file);
				char* data = new char[length + 1];
				memset(data, 0, length + 1);
				fseek(file, 0, SEEK_SET);
				fread(data, 1, length, file);
				fclose(file);
				std::string res = data;
				delete[] data;
				return res;
			}
			return "";
		}
	};
	
}; // Scorch namespace
}; // Utilities namespace

#endif 
