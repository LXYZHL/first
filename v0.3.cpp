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

void Advance(FILE *file)
{
    //������
    int CodeLine=0;
    //����
    int EmptyLine=0;
    //ע����
    int AnnotaLine=0;
    int i=0;
    int linecount=0;
    char ch,str[100];

    //��ȡ������
    ch=fgetc(file);
    while(!feof(file))
    {
        if(ch=='\n'||ch=='\0')
        {
            linecount++;
        }
        ch=fgetc(file);    
    }
    rewind(file);
    while(!feof(file))
    {
        //��ȡһ���ַ������ж�ÿ��״̬
        fgets(str,sizeof(str),file);
        //����
        if(str[0]=='\n')
        {
            EmptyLine++;
            continue;
        }
        //����
        for(i=0;str[i]!='\n';i++)
        {
            //���д��뺬�д�����
            if(str[i]=='{'||str[i]=='}')
            {
                //�����ź���û�д��룬������1����ȡ��һ��
                if(str[i+1]=='\n')
                {
                    EmptyLine++;
                    goto ABC;
                }
                else
                {
                    //�����ź����ǿջ���tab�������ж���һ���ַ�
                    while(str[i+1]==' '||str[i+1]=='\t')
                    {
                        i++;
                        //����ѭ������������ǻ��з���������1
                        if(str[i+1]=='\n')
                        {
                            EmptyLine++;
                            goto ABC;
                        }
                    }
                }
            }
            else
                //���д���ֻ�п��л���tab��������1
                while(str[i]==' '||str[i]=='\t')
                {
                    i++;
                    if(str[i]=='\n')
                    {
                        EmptyLine++;
                        goto ABC;
                    }
                    
                }
        }
        //ע���м�1
        for(i=0;str[i]!='\n'&&str[i]!='\0';i++)
        {
            //�жϵ�һ���ַ��ǲ���ע���ַ�
            if(str[i]=='/')
            {
                //�жϵڶ����ַ����ǵĻ�ע������1
                if(str[i+1]=='/')
                {
                    AnnotaLine++;
                    break;
                }
                //���ǵĻ�ֱ������ѭ��������ʱ��ķ�
                else
                    break;
            }
            
        }
        ABC:;
    }
    cout<<"���У�"<<EmptyLine<<endl;
    cout<<"ע���У�"<<AnnotaLine<<endl;
    //��������ȥ���к�ע���еõ���������
    cout<<"�����У�"<<linecount-EmptyLine-AnnotaLine+1<<endl;
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
            else if(strcmp(argv[1],"-a")==0)
            {
                Advance(file);
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
            // -c -w ���� -c -l ���� -w -l 
            if(strcmp(argv[1],"-c")==0)
            {
                if(strcmp(argv[2],"-w")==0)
                {
                    CharCount(file);
                    WordCount(file);
                }
                else if(strcmp(argv[2],"-l")==0)
                {
                    CharCount(file);
                    LineCount(file);
                }
                else
                {
                    printf("��ʽ����!\n");
                }
            }
            else if(strcmp(argv[1],"-w")==0&&
                    strcmp(argv[2],"-l")==0)
            {
                WordCount(file);
                LineCount(file);
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
            // -c -w -l
            if((strcmp(argv[1],"-c")==0)&&
               (strcmp(argv[2],"-w")==0)&&
               (strcmp(argv[3],"-l")==0))
            {
                CharCount(file);
                WordCount(file);
                LineCount(file);
            }
            
            else
            {
                printf("��ʽ����!\n");
            }
            break;
        case 6:
            file=fopen(argv[5],"r");
            if(file==NULL)
            {
                printf("���ܴ��ļ�");
                exit(0);
            }
            // -c -w -l -a
            if((strcmp(argv[1],"-c")==0)&&
               (strcmp(argv[2],"-w")==0)&&
               (strcmp(argv[3],"-l")==0)&&
               (strcmp(argv[4],"-a")==0))
            {
                CharCount(file);
                WordCount(file);
                LineCount(file);
                Advance(file);
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
