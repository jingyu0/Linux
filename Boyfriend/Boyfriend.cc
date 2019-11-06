#include "Boyfriend.hpp"

using namespace std;

int main()
{
    //Robot r;
    //string str;
    //volatile bool quit = false;
    //while(!quit){
    //	cout << "我# ";
    //	cin >> str;
    //	std::string s = r.Talk(str);
    //	cout << "Tom$ " << s << endl;
    //    }
    //  std::string s = r.Talk("你好吗？");
    //  cout << s << endl;
  Boyfriend *bf = new Boyfriend();
  if(!bf->LoadEtc()){
	return 1;
  }

  bf->Run();
  return 0;
}
