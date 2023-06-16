#include <iostream>
#include <string>
using namespace std;

int pos=1;
class Token{
public:
	int category;
	string value;
	Token(int cat,string v="-"):category(cat),value(v){}
	Token(const Token& t){
		this->category=t.category;
		this->value=t.value;
	}
};
// 定义单词种别码
const int INT = 100; // 整型常数
const int IDENTIFIER = 111; // 标识符
const int PLUS = 41; // 加号
const int MINUS = 42; // 减号
const int MULTIPLY = 43; // 乘号
const int DIVIDE = 44; // 除号
const int MOD = 45; // 模运算符
const int ASSIGN = 46; // 赋值运算符
const int GREATER_THAN = 47; // 大于号
const int GREATER_EQUAL = 48; // 大于等于号
const int LESS_THAN = 49; // 小于号
const int LESS_EQUAL = 50; // 小于等于号
const int EQUAL = 51; // 等于号
const int NOT_EQUAL = 52; // 不等于号
const int LOGICAL_AND = 53; // 逻辑与
const int LOGICAL_OR = 54; // 逻辑或
const int LOGICAL_NOT = 55; // 逻辑非
const int INCREMENT = 56; // 自增运算符
const int DECREMENT = 57; // 自减运算符
const int LEFT_BRACKET = 81; // 左括号
const int RIGHT_BRACKET = 82; // 右括号
const int SEMICOLON = 84; // 分号
const int LEFT_BRACE = 86; // 左花括号
const int RIGHT_BRACE = 87; // 右花括号
const int LEFT_SQUARE_BRACKET = 88; // 左方括号
const int RIGHT_SQUARE_BRACKET = 89; // 右方括号
const int WHILE = 20; // while关键字
const int IF = 17; // if关键字
const int ELSE = 15; // else关键字
const int INT_TYPE = 5; // int关键字 

// 根据输入的单词进行词法分析
Token lex(const string& input,int t)
{
    string word = ""; // 用于保存当前单词
    for (int i=t;input[i]!='\0';i++)
    {
    	char c=input[i];
        if (c == ' ' || c == '\n' || c == '\t') // 忽略空格、换行和制表符
        {
        	i++;
        if (!word.empty())
        {
        if (word == "int")
        {
        	pos++;
        	return Token(INT_TYPE,"-");
		}
        else if (word == "while")
        {
        	pos++;
        	return Token(WHILE,"-");
		}
        else if (word == "if")
        {
        	pos++;
        	return Token(IF,"-");
		}
        else if (word == "else")
        {
        	pos++;
        	return Token(ELSE,"-");
		}
        else
        {
        	pos++;
        	return Token(IDENTIFIER,word);
		}
        }
        }
        else if (isalpha(c) || isdigit(c)) // 处理字母和数字
        {
            word += c;
			pos++; // 将字符添加到当前单词中
        }
        else // 处理其他符号
        { 
            if (!word.empty())
            {
                // 对当前单词进行判断和分类
                if (isdigit(word[0]))
                    {
                    	return Token(INT,word);
					}
                else
                    {
                    	if (!word.empty())
                          {
                           // 对当前单词进行判断和分类
                               if (word == "int")
                               {
                               	return Token(INT_TYPE,"-");
							   }
                               else if (word == "while")
                               {
                               	return Token(WHILE,"-");
							   }
                               else if (word == "if")
                               {
                               	return Token(IF,"-");
							   }
                               else if (word == "else")
                               {
                               	return Token(ELSE,"-");
							   }
                               else
                               {
                               	return Token(IDENTIFIER,word);
							   }
                               word="";// 清空单词
        }
                    }
                word = ""; // 清空单词
            }
            
            // 对符号进行判断和分类
            switch (c)
            {
                case '+':
                	if(input[i+1]!='+')
                	{
                		pos++;
                		return Token(PLUS,"-");
					}
                    else
                    {
                    i=i+1;
                    pos=pos+2;
                    return Token(INCREMENT,"-");
                    }
                    break;
                case '-':
                	if(input[i+1]!='-')
                	{
                		pos++;
                		return Token(MINUS,"-");
					}
                    else
                    {
                    i=i+1;
                    pos=pos+2;
                    return Token(DECREMENT,"-");
                    }
                    break;
                case '*':
                	{
                		pos++;
                		return Token(MULTIPLY,"-"); 
                		break;
					}
                case '/':
                	{
                		pos++;
                		return Token(DIVIDE,"-");
					}
                    break;
                case '%':
                	{
                		pos++;
                		return Token(MOD,"-");
					}
                    break;
                case '=':
                	{
                		pos++;
                		return Token(ASSIGN,"-");
					}
                	return Token(ASSIGN,"-");
                    break;
                case '>':
                	{
                		pos++;
                		return Token(GREATER_THAN,"-");
					}
                    break;
                case '<':
                	{
                		pos++;
                		return Token(LESS_THAN,"-");
					}
                    break;
                case '!':
                	{
                		pos++;
                		return Token(NOT_EQUAL,"-");
					}
                    break;
                case '&':
                	{
                		pos++;
                		return Token(LOGICAL_AND,"-");
					}
                    break;
                case '|':
                	{
                		pos++;
                		return Token(LOGICAL_OR,"-");
					}
                    break;
                case '(':
                	{
                		pos++;
                		return Token(LEFT_BRACKET,"-");
					}
                    break;
                case ')':
                	{
                		pos++;
                		return Token(RIGHT_BRACKET,"-");
					}
                    break;
                case ';':
                	{
                		pos++;
                		return Token(SEMICOLON,"-");
					}
                    break;
                case '{':
                	{
                		pos++;
                		return Token(LEFT_BRACE,"-");
					}
                    break;
                case '}':
                	{
                		pos++;
                		return Token(RIGHT_BRACE,"-");
					}
                    break;
                case '[':
                	{
                		pos++;
                		return Token(LEFT_SQUARE_BRACKET,"-");
					}
                    break;
                case ']':
                	{
                		pos++;
                		return Token(RIGHT_SQUARE_BRACKET,"-");
					}
                    break;
                default:
                    break;
            }
        }
    }
}

int main()
{
    string input,x;
    cout << "请输入源代码：" << endl;
    x=" ";
	while(getline(cin,input))
	{
		if(input=="#")
		break;
		x+=input;
	} 
	x=x+" ";
	while(pos<x.length()-1)
	{
		Token values=lex(x,pos);
		cout<<"<"<<values.category<<","<<values.value<<">"<<endl;
	}
    return 0;
}

