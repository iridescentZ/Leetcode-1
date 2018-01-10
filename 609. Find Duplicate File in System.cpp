/*
���� �����Ŀ�����ҵ����뵽��·������ͬ���ݵ�·��
�����˳�� û��Ҫ��
�����·�������ݶ������ֺ���ĸ
��ͬ��Ŀ¼�²������ͬ�����ļ�
������Ϣ���� ·���� �ļ���һ���ո����

�뷨������һmap map<string,vector<string>>
����һ����������� ����Ӧ����ͬ�����ݵ�·�����뵽 ͬһ��value�����鵱��
����ٴα���һ��map �����е�value���ڵ���2�ļ��뵽������鵱��

��һ�� �����뵱�еõ���Ҫ�����ݺ�·��
�����Ŀ���ҵ��뷨û���� ����map�ȽϿ� ���Ƕ���string�ķ�Ƭ�ͷ������۵�һЩ������Ҫע��
��Ҫ�úõ��ܽ�string��һϵ�еĲ����������÷�
substr,find,nops
 */
 

class Solution {
public:
	void subs(string& temp,string& value,unordered_map<string,vector<string>>& m) {//���������Ҫ������ȡ�����temp��key��value������map����
        int posl = temp.find('(');
        string val = (value + '/' + temp.substr(0,posl));
        int posr = temp.find(')');
        string key = temp.substr(posl+1,posr-posl-1);
        m[key].push_back(val);//���ﲻ��Ҫ�ж�map������û�� ��Ϊ[]������ �����ǰmap��û�оͲ���һ��vector<string>> ���vector�ǰ�����������Լ���Ĭ�Ϲ��캯����ʼ����Ҳ����һ���յ�vector
	}

    vector<vector<string>> findDuplicate(vector<string>& paths) {
    	unordered_map<string,vector<string>> m;
    	vector<vector<string>> res;
        
        for(auto it : paths) {
    		int pos = it.find(' ');
    		string value = it.substr(0,pos);
    		string temp = it.substr(pos+1,it.size()-pos-1);

            if(temp.find(' ')==std::string::npos) {//�жϵ�ǰ��·���ǲ���ֻ��һ���ļ�
                subs(temp,value,m);
            }

    		while(temp.find(' ')!=std::string::npos) { //��ǰ·������ļ��Ĵ���
                int p = temp.find(' ');
                string temp2 = temp.substr(p+1,temp.size()-p-1); 
                subs(temp,value,m);
                temp = temp2;
                if(temp.find(' ')==std::string::npos) {//�������Ը��ļ������һ���ļ���ʱ��
                    subs(temp,value,m);
                }
    		}
        }
        
        for(auto each : m) {
        	if(each.second.size()>=2) {
        		res.push_back(each.second);
        	}
        }
        
        return res;
    }
};





class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> table;
        vector<vector<string>> res;
        vector<string> cur;

        int n = paths.size();
        for(int i = 0; i < n; i++){
            stringstream ss(paths[i]);
            string root, file;
            getline(ss, root, ' ');
            while (getline(ss, file, ' ')){
                string file_name = file.substr(0, file.find('('));
                string file_content = file.substr(file.find('(')+1, file.find(')')-file.find('(')-1);
                table[file_content].push_back(root + "/" + file_name);
            }
        }
        for(auto &i : table){
            if(i.second.size() >= 2)
                res.push_back(i.second);
        }
        return res;
    }
};