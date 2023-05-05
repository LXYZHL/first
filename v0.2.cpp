#include<bits/stdc++.h>
using namespace std;

void CharCount(FILE *file)//ͳ���ַ�����
{
    int charcount=0;
    char ch;
    ch=fgetc(file);
    while(!feof(file))
    {
        charcount++;
        ch=fgetc(file);
    }
    cout<<"�ַ���:"<<charcount<<endl;
    rewind(file);
}

void WordCount(FILE *file)//ͳ�Ƶ�������
{
    int wordcount=0;
    char ch;
    ch=fgetc(file);
    while(!feof(file))
    {
        if(isalnum(ch))
        {
            while(isalnum(ch)||ch=='-')
            {
                ch=fgetc(file);
            }
            wordcount++;
        }

        ch=fgetc(file);
    }
    cout<<"������:"<<wordcount<<endl;
    rewind(file);
}

void LineCount(FILE *file)//ͳ�ƾ�����
{
    int linecount=0;
    char ch;
    ch=fgetc(file);
    while(!feof(file))
    {
        if(ch=='.'||ch=='!'||ch=='?')
        {
            linecount++;
        }
        ch=fgetc(file);
    }
    cout<<"������:"<<linecount<<endl;
    rewind(file);
}

int main(int argc, char* argv[])
{
    FILE *file;
    switch(argc)
    {
        //��ͬ���������
        case 3:
            file=fopen(argv[2],"r");
            if(file==NULL)
            {
                cout<<"���ܴ��ļ���"<<endl;
                exit(0);
            }
            if(strcmp(argv[1],"-c")==0)
            {
                CharCount(file);
            }
            else if(strcmp(argv[1],"-w")==0)
            {
                WordCount(file);
            }
            else if(strcmp(argv[1],"-l")==0)
            {
                LineCount(file);
            }
            else
            {
                cout<<"��ʽ����!"<<endl;
            }
            break;
        case 4:
            file=fopen(argv[3],"r");
            if(file==NULL)
            {
                cout<<"���ܴ��ļ�!"<<endl;
                exit(0);
            }
            //6�����
            if(strcmp(argv[1],"-c")==0)
            {
            	if(strcmp(argv[2],"-l")==0)
            	{
            		CharCount(file);
            		LineCount(file);
				}
				else if(strcmp(argv[2],"-w")==0)
            	{
            		CharCount(file);
            		WordCount(file);
				}
			}
			else if(strcmp(argv[1],"-w")==0)
            {
            	if(strcmp(argv[2],"-c")==0)
            	{
            		WordCount(file);
            		CharCount(file);
				}
				else if(strcmp(argv[2],"-l")==0)
            	{
            		WordCount(file);
            		LineCount(file);
				}
			}
			else if(strcmp(argv[1],"-l")==0)
            {
            	if(strcmp(argv[2],"-c")==0)
            	{
            		LineCount(file);
            		CharCount(file);
				}
				else if(strcmp(argv[2],"-w")==0)
            	{
            		LineCount(file);
            		WordCount(file);
				}
			}
            else
            {
                cout<<"��ʽ����!"<<endl;
            }
            break;
        case 5:
            file=fopen(argv[4],"r");
            if(file==NULL)
            {
                printf("���ܴ��ļ�");
                exit(0);
            }
            //6�����
            if((strcmp(argv[1],"-c")==0)&&
               (strcmp(argv[2],"-w")==0)&&
               (strcmp(argv[3],"-l")==0))
            {
                CharCount(file);
                WordCount(file);
                LineCount(file);
            }
            else if((strcmp(argv[1],"-c")==0)&&
               		(strcmp(argv[2],"-l")==0)&&
               		(strcmp(argv[3],"-w")==0))
            {
                CharCount(file);
                LineCount(file);
                WordCount(file);
            }
            else if((strcmp(argv[1],"-l")==0)&&
               		(strcmp(argv[2],"-w")==0)&&
               		(strcmp(argv[3],"-c")==0))
            {
                LineCount(file);
                WordCount(file);
                CharCount(file);
            }
            else if((strcmp(argv[1],"-l")==0)&&
               		(strcmp(argv[2],"-c")==0)&&
               		(strcmp(argv[3],"-w")==0))
            {
            	LineCount(file);
                CharCount(file);
                WordCount(file);
            }
            else if((strcmp(argv[1],"-w")==0)&&
               		(strcmp(argv[2],"-l")==0)&&
               		(strcmp(argv[3],"-c")==0))
            {
            	WordCount(file);
                LineCount(file);
                CharCount(file);
            }
            else if((strcmp(argv[1],"-w")==0)&&
               		(strcmp(argv[2],"-c")==0)&&
               		(strcmp(argv[3],"-l")==0))
            {
                WordCount(file);
                CharCount(file);
                LineCount(file);
            }
            else
            {
                printf("��ʽ����!\n");
            }
            break;
        default:
            {
                cout<<"������������ȷ!"<<endl;
                exit(0);
            }
    }
    return 0;
}
