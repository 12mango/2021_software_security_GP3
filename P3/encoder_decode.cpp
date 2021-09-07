#include<iostream>
#include<cstdio>
#include<direct.h>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

vector<string> files;  

void get_files(string path){
	
	/*读取路径下的文件*/

    long hFile = 0;  //文件句柄 
    struct _finddata_t fileinfo;  //文件信息  
    string p;
    if((hFile=_findfirst(p.assign(path).append("\\*").c_str(),&fileinfo))!=-1){  
        do{
            if((fileinfo.attrib&_A_SUBDIR)){
                if(strcmp(fileinfo.name,".")!=0&&strcmp(fileinfo.name,"..")!=0){
                	get_files(p.assign(path).append("\\").append(fileinfo.name));  
                }
            }  
            else{
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));  
            }  
        }while(_findnext(hFile,&fileinfo)==0); 
        _findclose(hFile);
    }
    
    /*
	for(int i=0;i<files.size();i++){
    	cout<<files[i].c_str()<<endl;  
	}
	*/
}

void get_compiler_version(){
	
	/* 查看编译器版本号 */
	#ifdef _MSC_VER
		cout<<"hello MSVC"<< endl;
		cout<<_MSC_VER<<endl;
	
	#elif __GNUC__
		cout <<"hello gcc"<< endl;
		cout<<__GNUC__<<endl;
	
	#elif __BORLANDC__
		cout <<"hello Borland c++"<< endl;
		cout <<__BORLANDC__<< endl;
	#endif
}

string get_path(){
	char buf[1010];
 	getcwd(buf,sizeof(buf));
 	//puts(buf);
 	return string(buf);
}


int pt=-1;
string key = "_%S0FtwAre*secURitY";

void output(unsigned short ch,ofstream &outFile){
	/*输出加密串*/ 
	pt++;
	pt%=key.length();
	ch^=key[pt];
	outFile.put(ch);
}

string gen_path(string path,bool isEncode){
	if(isEncode){
		return path+".gp3";
	}
	path=path.substr(0,path.length()-4);
	path=path.substr(0,path.find_last_of('.'))+"_decode"+path.substr(path.find_last_of('.'));
	return path;
}

void encode_or_decode(string path,bool isEncode){
	/*对称的加解密*/
	
	ifstream inFile(path.c_str(),ios::in|ios::binary);
	ofstream outFile(gen_path(path,isEncode).c_str(),ios::out|ios::binary);
	
	while(!inFile.eof()){
		unsigned short ch=inFile.get();
		if(inFile.fail()){
			break;
		}
		output(ch,outFile);
	}
}

string self=string(__FILE__).substr(0,string(__FILE__).length()-4)+".exe";

int main()
{

	cout<<self<<endl;
	//cout<<__FILE__<<endl;  
	//get_compiler_version()
	
	get_files(get_path());
	
	for(auto iter=files.cbegin();iter!=files.end();++iter){
		
		string path=(*iter);
		
		//加密过的不重复加密 
		if(path.substr(path.length()-4,4)==".gp3"||strstr(path.c_str(),"_decode")){
			continue;
		}
		
		if(path==self){
			continue;
		}
		cout<<path<<endl;
		encode_or_decode(path,true);
	}
	
	pt=-1;
	
	for(auto iter=files.cbegin();iter!=files.end();++iter){
		string path=(*iter);
		
		//加密过的才解密 
		if(path.substr(path.length()-4,4)!=".gp3"){
			continue;
		}
		
		if(path==self){
			continue;
		}
		cout<<path<<endl;
		encode_or_decode(path,false);
	}

}
