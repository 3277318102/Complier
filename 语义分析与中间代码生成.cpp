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
    Token(){}
};
Token s;
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
const int douhao = 85;//���� 
const int LEFT_BRACE = 86; // ������
const int RIGHT_BRACE = 87; // �һ�����
const int LEFT_SQUARE_BRACKET = 88; // ������
const int RIGHT_SQUARE_BRACKET = 89; // �ҷ�����
const int WHILE = 20; // while�ؼ���
const int IF = 17; // if�ؼ���
const int ELSE = 15; // else�ؼ���
const int INT_TYPE = 5; // int�ؼ��� 

// ��������ĵ��ʽ��дʷ�����
Token lex(const string& input, int t)
{
    string word = ""; // ���ڱ��浱ǰ����
    for (int i = t; input[i] != '\0'; i++)
    {
        char c = input[i];
        if (c == ' ' || c == '\n' || c == '\t') // ���Կո񡢻��к��Ʊ��
        {
            i++;
            if (!word.empty())
            {
                // �Ե�ǰ���ʽ����жϺͷ���
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
                    return Token(INT, word);
                }
                else
                {
                    if (!word.empty())
                    {
                        // �Ե�ǰ���ʽ����жϺͷ���
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
                        word = "";// ��յ���
                    }
                }
                word = ""; // ��յ���
            }

            // �Է��Ž����жϺͷ���
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
//����������м��������
//������Ԫʽ�ṹ��
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
//�﷨��������
string expr();
string term();
string unary();
string factor();
string rest5(string rest5_in);
string rest6(string rest6_in);
void Bool();
void equality();
void rel();
void rest4();
void rop_expr();
void stmts();
void rest0(); 
void stmt();
string loc();
string resta(string resta_inArray);
void elist();
void rest1();

void stmts()
{
	cout<<"stmts -> stmt rest0"<<endl;
	stmt();
	rest0();
}

void rest0()
{
	if(pos >= input.size())
	{
		cout<<"rest0 - > ?"<<endl;
		return;
	}
	{
		cout<<"rest0 -> stmt rest0"<<endl;
		stmt();
		rest0();
	}
}

void stmt()
{
	if(s.category==17)
	{
		cout<<"stmt -> if(bool) stmt else stmt"<<endl;
		s=lex(input,pos-1);
		Bool();
		s=lex(input,pos-1);
		stmt();
	}
	else if(s.category==20)
	{
	    cout<<"stmt -> while(bool) stmt"<<endl;
	    s=lex(input,pos-1);
	    Bool();
	    s= lex(input,pos-1);
	    stmt();
	}
	else
	{
		string expr_place,loc_place; 
		cout<<"stmt -> loc = expr;"<<endl;
		loc_place=loc();
		s=lex(input,pos-1);
		expr_place=expr();
		emit("=",expr_place,"-",loc_place);
	}
}

string loc()
{
	cout<<"loc -> id resta"<<endl;
	string resta_inArray,resta_place;
	resta_inArray=s.value;
	s=lex(input,pos-1);
	resta_place=resta(resta_inArray);
	return resta_place;
}

string resta(string resta_inArray)
{
	if(s.category==88)
	{
		cout<<"resta -> [elist]"<<endl;
		s=lex(input,pos-1);
		elist();
		s=lex(input,pos-1);
		return "";
	}
	else
	{
		cout<<"resta -> ?"<<endl;
		return resta_inArray;
	}
}

void elist()
{
	cout<<"elist -> expr rest1"<<endl;
	expr();
	rest1();
}

void rest1()
{
	if(s.category==85)
	{
		cout<<"rest1 -> ,expr rest1"<<endl;
		s=lex(input,pos-1);
		expr();
		rest1();
	}
	else
	{
		cout<<"rest1 -> ?"<<endl;
	}
}

void Bool()
{
    cout << "bool -> equality" << endl;
    equality();
}

void equality()
{
    cout << "equality -> rel rest4" << endl;
    rel();
    rest4();
}

void rel()
{
    cout << "rel -> expr rop_expr" << endl;
    expr();
    rop_expr();
}

void rest4()
{
    if (s.category == 51)
    {
        cout << "rest4 -> == rel rest4" << endl;
        s = lex(input, pos-1);
        rel();
        rest4();
    }
    else if (s.category == 52)
    {
        cout << "rest4 -> !=rel rest4" << endl;
        s = lex(input, pos-1);
        rel();
        rest4();
    }
    else
    {
        cout << "rest5 -> ?" << endl;
    }
}

void rop_expr()
{
    if (s.category == 49)
    {
        cout << "rop_expr -> <expr" << endl;
        s = lex(input, pos-1);
        expr();
    }
    else if (s.category == 50)
    {
        cout << "rop_expr -> <=expr" << endl;
        s = lex(input, pos-1);
        expr();
    }
    else if (s.category == 47)
    {
        cout << "rop_expr -> >expr" << endl;
        s = lex(input, pos-1);
        expr();
    }
    else if (s.category == 48)
    {
        cout << "rop_expr -> >=expr" << endl;
        s = lex(input, pos-1);
        expr();
    }
    else
    {
        cout << "rop_expr -> ?" << endl;
    }
}

string expr()
{
	string rest5_in,rest5_place;
    cout << "expr - > term rest5" << endl;
    rest5_in=term();
    rest5_place=rest5(rest5_in);
    return rest5_place;
}

string term()
{   string term_place,rest6_in,unary_place,rest6_place;
    cout << "term - > unary rest6" << endl;
    rest6_in=unary();
    term_place=rest6(rest6_in);
    return term_place;
}

string unary()
{
	string unary_place;
    cout << "unary - > factor" << endl;
    unary_place=factor();
    return unary_place;
}

string rest5(string rest5_in)
{
	string rest51_in,rest51_place,term_place,rest5_place;
    if (s.category == 41)
    {
        cout << "rest5 -> + term rest5" << endl;
        string op=s.value;
        s = lex(input, pos-1);
        term_place=term();
        rest51_in=newTemp();
        emit(op,rest5_in,term_place,rest51_in);
        rest5_place=rest5(rest51_in);
        return rest5_place;
    }
    else if(s.category==42)
    {
    	cout << "rest5 -> - term rest5" << endl;
        string op=s.value;
        s = lex(input, pos-1);
        term_place=term();
        rest51_in=newTemp();
        emit(op,rest5_in,term_place,rest51_in);
        rest5_place=rest5(rest51_in);
        return rest5_place;
	}
    else
    {
        cout << "rest5 -> ?" << endl;
        return rest5_in;
    }
}

string rest6(string rest6_in)
{
	string rest6_place,rest61_in,rest61_place,unary_place;
    if (s.category == 43)
    {
        cout << "rest6 -> * unary rest5" << endl;
        string op=s.value;
        s = lex(input, pos-1 );
        unary_place=unary();
        rest61_in=newTemp();
        emit(op,rest6_in,unary_place,rest61_in);
        rest6_place=rest5(rest61_in);
        return rest6_place;
    }
    else if(s.category==44)
    {
    	cout << "rest6 -> / unary rest5" << endl;
        string op=s.value;
        s = lex(input, pos-1 );
        unary_place=unary();
        rest61_in=newTemp();
        emit(op,rest6_in,unary_place,rest61_in);
        rest6_place=rest5(rest61_in);
        return rest6_place;
	}
    else
    {
        cout << "rest6 -> ?" << endl;
        return rest6_in;
    }
}

string factor()
{
	string value,factor_place;
    if (s.category == 81)
    {
        cout << "factor -> (expr)" << endl;
        s = lex(input, pos-1 );
        factor_place=expr();
        return factor_place;
    }
    else if(s.category == 100)
    {
        cout << "factor -> num" << endl;
        value=s.value;
        s = lex(input, pos-1);
        return value;
    }
    else
    {
    	cout<<"factor -> loc"<<endl;
    	factor_place=loc();
    	return factor_place;
	}

}
void printQuadruples() {
        for (const auto& quad : quadruples) {
            cout << quad.op << ", " << quad.arg1 << ", " << quad.arg2 << ", " << quad.result << endl;
        }
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
        s = lex(input, pos-1);
        stmts();
        i += pos;
        pos = 1;
    }
    printQuadruples();
    return 0;
}
