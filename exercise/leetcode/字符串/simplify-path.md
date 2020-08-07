

Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.


简化绝对路径。

用一个vector模拟路径的层次来解决 .. 的问题。

对一些修改不够仔细， 容易相当然。
我需要达到什么效果取修改它， 是否实现了该效果， 会遇到什么问题. 

class Solution {
public:
    string simplifyPath(string path) {

        if(path.size() <= 1) return path;        
        
        std::vector<string> pathList;

        for (int i = 1; i < path.size();)
        {
            string tmp;
            // 去除连续的 '/'
            while(i<path.size() && path[i] == '/'){
                i++;
            } 

            while(i<path.size() && path[i] != '/'){
                tmp += path[i];
                i++;
            } 

            if(!tmp.empty() && tmp != "."){
                if(tmp != ".."){
                    pathList.push_back(tmp);
                }else if(!pathList.empty()){ 
                    pathList.pop_back();
                }
            }
        }

        string result;
    
        for (int i = 0; i < pathList.size(); ++i)
        {
            result += "/" + pathList[i];
        }

        return result.empty() ? "/" : result;

    }
};