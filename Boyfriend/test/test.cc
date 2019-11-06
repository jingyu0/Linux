#include <iostream>
#include <json/json.h>
#include <memory>
#include <sstream>

using namespace std;
int main()
{
  Json::Value root;
  Json::StreamWriterBuilder wb;
  std::ostringstream ss;
 
  Json::Value item;
  item["school"] = "西财";
  item["height"] = 187.5f;
   
  root["nick_name"]="hello";
  root["date"] = "2019-7-24/4/5/6";
  root["message"] = "你好";
  root["age"] = "12";
//  root["info"] = item;
  root["info"][0] = item;
  root["info"][1] = item;
  root["info"][1] = item;

//智能指针
  unique_ptr<Json::StreamWriter> sw(wb.newStreamWriter());
  sw->write(root,&ss);
  string str = ss.str();
  cout<<str<<endl;

  return 0;
  
}
