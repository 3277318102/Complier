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
// ���嵥���ֱ���
const int INT = 100; // ���ͳ���
const int IDENTIFIER = 111; // ��ʶ��
const int PLUS = 41; // �Ӻ�
const int MINUS = 42; // ����
const int MULTIPLY = 43; // �˺�
const int DIVIDE = 44; // ����
const int MOD = 45; // ģ�����
const int ASSIGN = 46; // ��ֵ�����
const int GREATER_THAN = 47; // ���ں�
const int GREATER_EQUAL = 48; // ���ڵ��ں�
const int LESS_THAN = 49; // С�ں�
const int LESS_EQUAL = 50; // С�ڵ��ں�
const int EQUAL = 51; // ���ں�
const int NOT_EQUAL = 52; // �����ں�
const int LOGICAL_AND = 53; // �߼���
const int LOGICAL_OR = 54; // �߼���
const int LOGICAL_NOT = 55; // �߼���
const int INCREMENT = 56; // ���������
const int DECREMENT = 57; // �Լ������
const int LEFT_BRACKET = 81; // ������
const int RIGHT_BRACKET = 82; // ������
const int SEMICOLON = 84; // �ֺ�
const int LEFT_BRACE = 86; // ������
const int RIGHT_BRACE = 87; // �һ�����
const int LEFT_SQUARE_BRACKET = 88; // ������
const int RIGHT_SQUARE_BRACKET = 89; // �ҷ�����
const int WHILE = 20; // while�ؼ���
const int IF = 17; // if�ؼ���
const int ELSE = 15; // else�ؼ���
const int INT_TYPE = 5; // int�ؼ��� 

// ��������ĵ��ʽ��дʷ�����
Token lex(const string& input,int t)
{
    string word = ""; // ���ڱ��浱ǰ����
    for (int i=t;input[i]!='\0';i++)
    {
    	char c=input[i];
        if (c == ' ' || c == '\n' || c == '\t') // ���Կո񡢻��к��Ʊ��
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
        else if (isalpha(c) || isdigit(c)) // ������ĸ������
        {
            word += c;
			pos++; // ���ַ���ӵ���ǰ������
        }
        else // ������������
        { 
            if (!word.empty())
            {
                // �Ե�ǰ���ʽ����жϺͷ���
                if (isdigit(word[0]))
                    {
                    	return Token(INT,word);
					}
                else
                    {
                    	if (!word.empty())
                          {
                           // �Ե�ǰ���ʽ����жϺͷ���
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
                               word="";// ��յ���
        }
                    }
                word = ""; // ��յ���
            }
            
            // �Է��Ž����жϺͷ���
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
    cout << "������Դ���룺" << endl;
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

