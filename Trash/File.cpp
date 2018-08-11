/* C++ implementation of what we need */

#include <bits/stdc++.h>

using namespace std;


vector<string> splitStrings(string str, char dl)
{
    string word = "";

    int num = 0;

    str = str + dl;


    int l = str.size();


    vector<string> substr_list;
    for (int i = 0; i < l; i++) {


        if (str[i] != dl)
            word = word + str[i];

        else {


            if ((int)word.size() != 0)
                substr_list.push_back(word);
            word = "";
        }
    }


    return substr_list;
}
int main()
{
    char c;
    string str;
    FILE *file;
    file = fopen("userlist.txt", "r");
    if (file) {
    while ((c = getc(file)) != EOF)
        str=str+c;
    fclose(file);
    }
    char dl=' ';
    vector<string> res = splitStrings(str, dl);
    for(int i=0;i<res.size();i++){
        FILE *fp;

        res[i]=res[i]+".txt";
        string x=res[i];
        char *y = new char[x.length() + 1];
        strcpy(y, x.c_str());
        //cout << y << endl;
        fp=fopen(y,"w");
        fclose(fp);
    }
}
