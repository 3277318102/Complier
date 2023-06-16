#include <iostream>
#include <string>
#include <vector>
using namespace std;

int pos = 1;
string input;
class Token {
public:
    int category;
    string value;
    Token(int cat, string v = "-") :category(cat), value(v) {}
    Token(const Token& t) {
        this->category = t.category;
        this->value = t.value;
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
const int douhao = 85;//逗号 
const int LEFT_BRACE = 86; // 左花括号
const int RIGHT_BRACE = 87; // 右花括号
const int LEFT_SQUARE_BRACKET = 88; // 左方括号
const int RIGHT_SQUARE_BRACKET = 89; // 右方括号
const int WHILE = 20; // while关键字
const int IF = 17; // if关键字
const int ELSE = 15; // else关键字
const int INT_TYPE = 5; // int关键字 

// 根据输入的单词进行词法分析
Token lex(const string& input, int t)
{
    string word = ""; // 用于保存当前单词
    for (int i = t; input[i] != '\0'; i++)
    {
        char c = input[i];
        if (c == ' ' || c == '\n' || c == '\t') // 忽略空格、换行和制表符
        {
            i++;
            if (!word.empty())
            {
                // 对当前单词进行判断和分类
                if (word == "int")
                {
                    pos++;
                    return Token(INT_TYPE, "-");
                }
                else if (word == "while")
                {
                    pos++;
                    return Token(WHILE, "-");
                }
                else if (word == "if")
                {
                    pos++;
                    return Token(IF, "-");
                }
                else if (word == "else")
                {
                    pos++;
                    return Token(ELSE, "-");
                }
                else
                {
                    pos++;
                    return Token(IDENTIFIER, word);
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
                    return Token(INT, word);
                }
                else
                {
                    if (!word.empty())
                    {
                        // 对当前单词进行判断和分类
                        if (word == "int")
                        {
                            return Token(INT_TYPE, "-");
                        }
                        else if (word == "while")
                        {
                            return Token(WHILE, "-");
                        }
                        else if (word == "if")
                        {
                            return Token(IF, "-");
                        }
                        else if (word == "else")
                        {
                            return Token(ELSE, "-");
                        }
                        else
                        {
                            return Token(IDENTIFIER, word);
                        }
                        word = "";// 清空单词
                    }
                }
                word = ""; // 清空单词
            }

            // 对符号进行判断和分类
            switch (c)
            {
            case '+':
                if (input[i + 1] != '+')
                {
                    pos++;
                    return Token(PLUS, "+");
                }
                else
                {
                    i = i + 1;
                    pos = pos + 2;
                    return Token(INCREMENT, "++");
                }
                break;
            case '-':
                if (input[i + 1] != '-')
                {
                    pos++;
                    return Token(MINUS, "-");
                }
                else
                {
                    i = i + 1;
                    pos = pos + 2;
                    return Token(DECREMENT, "--");
                }
                break;
            case '*':
            {
                pos++;
                return Token(MULTIPLY, "*");
                break;
            }
            case '/':
            {
                pos++;
                return Token(DIVIDE, "/");
            }
            break;
            case '%':
            {
                pos++;
                return Token(MOD, "%");
            }
            break;
            case '=':
                if (input[i + 1] != '=')
                {
                    pos++;
                    return Token(ASSIGN, "=");
                }
                else
                {
                    i = i + 1;
                    pos = pos + 2;
                    return Token(EQUAL, "==");
                }
                break;
            case '>':
            	if (input[i + 1] != '=')
                {
                    pos++;
                    return Token(GREATER_THAN, ">");
                }
                else
                {
                    i = i + 1;
                    pos = pos + 2;
                    return Token(GREATER_EQUAL, ">=");
                }
                break;
            case '<':
            	if (input[i + 1] != '=')
                {
                    pos++;
                    return Token(LESS_THAN, "<");
                }
                else
                {
                    i = i + 1;
                    pos = pos + 2;
                    return Token(LESS_EQUAL, "<=");
                }
                break;
//            {
//                pos++;
//                return Token(LESS_THAN, "-");
//            }
//            break;
            case '!':
            {
                pos++;
                return Token(NOT_EQUAL, "!");
            }
            break;
            case '&':
            {
                pos++;
                return Token(LOGICAL_AND, "&");
            }
            break;
            case '|':
            {
                pos++;
                return Token(LOGICAL_OR, "|");
            }
            break;
            case '(':
            {
                pos++;
                return Token(LEFT_BRACKET, "(");
            }
            break;
            case ')':
            {
                pos++;
                return Token(RIGHT_BRACKET, ")");
            }
            break;
            case ';':
            {
                pos++;
                return Token(SEMICOLON, "-");
            }
            break;
            case ',':
			{
				pos++;
				return Token(douhao,"-");
			 } 
			 break;
            case '{':
            {
                pos++;
                return Token(LEFT_BRACE, "-");
            }
            break;
            case '}':
            {
                pos++;
                return Token(RIGHT_BRACE, "-");
            }
            break;
            case '[':
            {
                pos++;
                return Token(LEFT_SQUARE_BRACKET, "-");
            }
            break;
            case ' ':
            {
            		pos++;
            		return Token(-1,"-");
		    }
				break;
            case ']':
            {
                pos++;
                return Token(RIGHT_SQUARE_BRACKET, "-");
            }
            break;
            default:
                break;
            }
        }
    }
}
//语义分析与中间代码生成
//定义四元式结构体
struct Quadruple {
    string op;
    string arg1;
    string arg2;
    string result;
}; 

vector<Quadruple> quadruples;


void emit(string op, string arg1, string arg2, string result) {
    Quadruple quad;
    quad.op = op;
    quad.arg1 = arg1;
    quad.arg2 = arg2;
    quad.result = result;
    quadruples.push_back(quad);
}

string newTemp() {
    static int tempCount = 0;
    tempCount++;
    return "t" + to_string(tempCount);
}
//语法分析部分
void expr(Token& s);
void term(Token& s);
void unary(Token& s);
void factor(Token& s);
void rest5(Token& s);
void rest6(Token& s);
void Bool(Token& s);
void equality(Token& s);
void rel(Token& s);
void rest4(Token& s);
void rop_expr(Token& s);
void stmts(Token& s);
void rest0(Token& s); 
void stmt(Token& s);
void loc(Token& s);
void resta(Token& s);
void elist(Token& s);
void rest1(Token& s);

string stmts(Token& s)
{
	cout<<"stmts -> stmt rest0"<<endl;
	//s=lex(input,pos-1);
	stmt(s);
	rest0(s);
}

string rest0(Token& s)
{
//	if(s.category==-1)
//	{
//		cout<<"rest0 -> ?"<<endl;
//	}
	//else
	if(pos >= input.size())
	{
		cout<<"rest0 - > ?"<<endl;
		return;
	}
	{
		cout<<"rest0 -> stmt rest0"<<endl;
		//s=lex(input,pos-1);
		stmt(s);
		rest0(s);
	}
}

string stmt(Token& s)
{
	if(s.category==17)
	{
		cout<<"stmt -> if(bool) stmt else stmt"<<endl;
		s=lex(input,pos-1);
		Bool(s);
		s=lex(input,pos-1);
		stmt(s);
	}
	else if(s.category==20)
	{
	    cout<<"stmt -> while(bool) stmt"<<endl;
	    s=lex(input,pos-1);
	    Bool(s);
	    s= lex(input,pos-1);
	    stmt(s);
	}
	else
	{
		cout<<"stmt -> loc = expr;"<<endl;
		//s=lex(input,pos-1);
		loc(s);
		s=lex(input,pos-1);
		expr(s);
	}
}

string loc(Token& s)
{
	cout<<"loc -> id resta"<<endl;
	s=lex(input,pos-1);
	resta(s);
}

string resta(Token& s)
{
	if(s.category==88)
	{
		cout<<"resta -> [elist]"<<endl;
		s=lex(input,pos-1);
		elist(s);
		s=lex(input,pos-1);
	}
	else
	{
		cout<<"resta -> ?"<<endl;
	}
}

string elist(Token& s)
{
	cout<<"elist -> expr rest1"<<endl;
	expr(s);
	//s=lex(input,pos-1);
	rest1(s);
}

string rest1(Token& s)
{
	string value;
	if(s.category==85)
	{
		value = s.value;
		cout<<"rest1 -> ,expr rest1"<<endl;
		s=lex(input,pos-1);
		expr(s);
		rest1(s);
	}
	else
	{
		cout<<"rest1 -> ?"<<endl;
	}
}

string Bool(Token &s)
{
    cout << "bool -> equality" << endl;
    return equality(s);
}

string equality(Token &s)
{
    cout << "equality -> rel rest4" << endl;
    string value=rel(s);
    rest4(s);
    return value;
}

string rel(Token& s)
{
	string value;
    cout << "rel -> expr rop_expr" << endl;
    value=expr(s);
    rop_expr(s);
    return value;
}

string rest4(Token& s)
{
	string value;
    if (s.category == 51)
    {
    	value = s.value;
        cout << "rest4 -> == rel rest4" << endl;
        s = lex(input, pos-1);
        rel(s);
        rest4(s);
    }
    else if (s.category == 52)
    {
    	value = s.value;
        cout << "rest4 -> !=rel rest4" << endl;
        s = lex(input, pos-1);
        rel(s);
        rest4(s);
    }
    else
    {
    	value="";
        cout << "rest5 -> ?" << endl;
    }
    return value;
}

string rop_expr(Token& s)
{
	string value;
    if (s.category == 49)
    {
        cout << "rop_expr -> <expr" << endl;
        value = s.value;
        s = lex(input, pos-1);
        expr(s);
    }
    else if (s.category == 50)
    {
    	value = s.value;
        cout << "rop_expr -> <=expr" << endl;
        s = lex(input, pos-1);
        expr(s);
    }
    else if (s.category == 47)
    {
    	value = s.value;
        cout << "rop_expr -> >expr" << endl;
        s = lex(input, pos-1);
        expr(s);
    }
    else if (s.category == 48)
    {
    	value = s.value;
        cout << "rop_expr -> >=expr" << endl;
        s = lex(input, pos-1);
        expr(s);
    }
    else
    {
    	value="";
        cout << "rop_expr -> ?" << endl;
    }
    return value;
}

string expr(Token& s)
{
    cout << "expr - > term rest5" << endl;
    string value=term(s);
    rest5(s);
    return value;
}

string term(Token& s)
{
    cout << "term - > unary rest6" << endl;
    string value=unary(s);
    rest6(s);
    return value;
}

string unary(Token& s)
{
	string value;
    cout << "unary - > factor" << endl;
    //s=lex(input,pos-1);
    value=factor(s);
    return value;
}

string rest5(Token& s)
{
	string value;
    if (s.category == 41)
    {
        cout << "rest5 -> + term rest5" << endl;
        Token x = lex(input, pos-1);
        value=term(x);
        rest5(x);
    }
    else if (s.category == 42)
    {
        cout << "rest5 -> - term rest5" << endl;
        Token x = lex(input, pos-1);
        value=term(x);
        rest5(x);
    }
    else
    {
    	value="";
        cout << "rest5 -> ?" << endl;
    }
    return value;
}

string rest6(Token& s)
{
	string value;
    if (s.category == 43)
    {
        cout << "rest6 -> * term rest5" << endl;
        Token x = lex(input, pos-1 );
        value=term(x);
        rest5(x);
    }
    else if (s.category == 44)
    {
        cout << "rest6 -> / term rest5" << endl;
        Token x = lex(input, pos-1 );
        value=term(x);
        rest5(x);
    }
    else
    {
    	value="";
        cout << "rest6 -> ?" << endl;
    }
    return value;
}

string factor(Token& s)
{
	string value;
    if (s.category == 81)
    {
        cout << "factor -> (expr)" << endl;
        s = lex(input, pos-1 );
        value=expr(s);
        //s=lex(input,pos-1);
    }
    else if(s.category == 100)
    {
    	value = s.value;
    	s = lex(input, pos-1);
        cout << "factor -> num" << endl;
        //s = lex(input, pos-1);
    }
    else
    {   
        value =loc(s);
    	cout<<"factor -> loc"<<endl;
    	//s=lex(input,pos-1);
	}
    return value;
}

int main()
{
    string x;
    cout << "Enter an expression: ";
	while(getline(cin,x))
	{
		if(x=="#")
		break;
		input+=x;
	} 
	input=input+" ";
    int i = 0;
    while (i < input.length())
    {
        Token s = lex(input, pos-1);
        stmts(s);
        i += pos;
        pos = 1;
    }

    return 0;
}

