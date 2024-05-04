#include <bits/stdc++.h>
using namespace std;

///To check Character
bool ischar(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

///To check Double operator
bool operator_1(string s)
{
    string operators[] = {"<<", ">>", "==", "&&", "||", "++", "+=", "-=", "*=", "/=", "!=", ">=", "<="};
    return find(begin(operators), end(operators), s) != end(operators);
}

///To Check Punctuation
bool Ispunctuation(char c)
{
    string punctuations = ",.!;:'\"()[]{}&_/$#@|~^`";
    return punctuations.find(c) != string::npos;
}

/// TO check single operator
bool isoperator(char c)
{
    string operators = "+-*/%=><&|!^?:.";
    return operators.find(c) != string::npos;
}

///TO Check Keyword
bool iskeyword(string s)
{
    string keywords[] =
    {
        "cout", "cin", "endl","auto", "bool", "break", "case", "catch", "char", "class", "const",
        "continue", "default", "delete", "do", "double", "else", "enum", "explicit",
        "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline",
        "int", "long", "mutable", "namespace", "new", "operator", "private", "protected",
        "public", "register", "return", "short", "signed", "sizeof", "static", "struct",
        "switch", "template", "this", "throw", "true", "try", "typedef", "typeid",
        "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "while"
    };

    return find(begin(keywords), end(keywords), s) != end(keywords);
}

///To Check Constraints
bool isconstant(const string& str)
{
    return (str[0] == '"' && str[str.size() - 1] == '"') || (str[0] == '\'' && str[str.size() - 1] == '\'') ||
           (all_of(str.begin(), str.end(), ::isdigit));
}




///Main Function
int main()
{
    ifstream file("lex_input.txt");

    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string datatypes [] = {"int", "double", "float", "char", "long", "short"};
    string line;
    map<string, int> variables;
    map<string, int> identifiermap;
    vector<string> keywords;
    vector<string> identifiers;
    vector<string> constants;
    vector<char> punctuations;
    vector<string> operators;

    while (getline(file, line))
    {
        istringstream iss(line);

        string word;
        vector<string>words;

        while(iss >> word)
        {
            words.push_back(word);
        }

        for(int i = 0; i < words.size(); i++)
        {
            if(words[i]=="#include" || words[i]=="using" || words[i]=="#define" || words[i].size()==0)
            {
                words.clear();
                break;
            }
            //Check Variable Declaration

            if(ischar(words[i][0]))
            {
                //Check Data-type or Variable
                bool datatypeflag = false;
                for(auto &datatype : datatypes)
                {
                    if(datatype == words[i])
                    {

                        datatypeflag = true;
                        int sizee = words[i+1].size();

                        if(words[i+1][sizee-1] == ')')
                        {
                            words[i+1].pop_back();
                            words[i+1].pop_back();
                        }
                    }
                }
                if(iskeyword(words[i]))break;

                if(variables[words[i]]>0)break;
            }
            else if(iskeyword(words[i]))continue;
        }
    }

    ifstream file2("lex_input.txt");

    if (!file2.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    while (getline(file2, line))
    {
        istringstream iss(line);
        string word;

        while (iss >> word)
        {
            if (word == "#include" || word == "using" || word == "#define" || word.size() == 0)
            {
                break;
            }

            if(word.back()==';')
            {
                punctuations.push_back(word.back());
                word.pop_back();
            }

            if (operator_1(word))
            {
                operators.push_back(word);
            }
            else if (iskeyword(word))
            {
                keywords.push_back(word);
            }
            else if (ischar(word[0]))
            {
                if(identifiermap[word]<1)
                {
                    identifiers.push_back(word);
                    identifiermap[word]++;
                    if(word.back() == ')')
                    {
                        punctuations.push_back(word[word.size()-2]);
                        punctuations.push_back(word.back());
                    }
                }

            }
            else if (isconstant(word))
            {
                constants.push_back(word);
            }
            else
            {
                for (char c : word)
                {
                    if (Ispunctuation(c))
                    {
                        punctuations.push_back(c);
                    }
                    else if (isoperator(c))
                    {
                        string op(1, c);
                        operators.push_back(op);
                    }
                }
            }
        }
    }

cout << left << setw(18) << "Constants" << setw(18) << "Identifiers" << setw(18) << "Keywords" << setw(20) << "Punctuations" << "Operators" << endl << endl;

size_t maxSize = max({constants.size(), identifiers.size(), keywords.size(), punctuations.size(), operators.size()});
for (size_t i = 0; i < maxSize; ++i)
{
    cout << left << setw(18) << (i < constants.size() ? constants[i] : "")
         << setw(18) << (i < identifiers.size() ? identifiers[i] : "")
         << setw(18) << (i < keywords.size() ? keywords[i] : "")
         << setw(20) << (i < punctuations.size() ? string(1, punctuations[i]) : "")
         << (i < operators.size() ? operators[i] : "") << endl;
}

    getchar();
}
