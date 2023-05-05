#include<bits/stdc++.h>
using namespace std;

void CharCount(FILE *file)//统计字符数量 
{
    int charcount=0;
    char ch;
    ch=fgetc(file);
    while(!feof(file))
    {
        charcount++;
        ch=fgetc(file);
    }
    cout<<"字符数:"<<charcount<<endl;
    rewind(file);
}

void WordCount(FILE *file)//统计单词数量 
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
    cout<<"单词数:"<<wordcount<<endl;
    rewind(file);
}

void LineCount(FILE *file)//统计句子数 
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
    cout<<"句子数:"<<linecount<<endl;
    rewind(file);
}

void Advance(FILE *file)
{
    //代码行
    int CodeLine=0;
    //空行
    int EmptyLine=0;
    //注释行
    int AnnotaLine=0;
    int i=0;
    int linecount=0;
    char ch,str[100];

    //获取总行数
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
        //读取一行字符串来判断每行状态
        fgets(str,sizeof(str),file);
        //空行
        if(str[0]=='\n')
        {
            EmptyLine++;
            continue;
        }
        //空行
        for(i=0;str[i]!='\n';i++)
        {
            //本行代码含有大括号
            if(str[i]=='{'||str[i]=='}')
            {
                //大括号后面没有代码，空行增1，读取下一行
                if(str[i+1]=='\n')
                {
                    EmptyLine++;
                    goto ABC;
                }
                else
                {
                    //大括号后面是空或者tab，继续判断下一个字符
                    while(str[i+1]==' '||str[i+1]=='\t')
                    {
                        i++;
                        //满足循环条件且最后是换行符，空行增1
                        if(str[i+1]=='\n')
                        {
                            EmptyLine++;
                            goto ABC;
                        }
                    }
                }
            }
            else
                //本行代码只有空行或者tab，空行增1
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
        //注释行加1
        for(i=0;str[i]!='\n'&&str[i]!='\0';i++)
        {
            //判断第一个字符是不是注释字符
            if(str[i]=='/')
            {
                //判断第二个字符，是的话注释行增1
                if(str[i+1]=='/')
                {
                    AnnotaLine++;
                    break;
                }
                //不是的话直接跳出循环，减少时间耗费
                else
                    break;
            }
            
        }
        ABC:;
    }
    cout<<"空行："<<EmptyLine<<endl;
    cout<<"注释行："<<AnnotaLine<<endl;
    //总行数减去空行和注释行得到代码行数
    cout<<"代码行："<<linecount-EmptyLine-AnnotaLine+1<<endl;
    rewind(file);
}

int main(int argc, char* argv[])
{
    FILE *file;
    switch(argc)
    {
        //不同的输入情况
        case 3:
            file=fopen(argv[2],"r");
            if(file==NULL)
            {
                cout<<"不能打开文件！"<<endl;
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
                cout<<"格式错误!"<<endl;
            }
            break;
        case 4:
            file=fopen(argv[3],"r");
            if(file==NULL)
            {
                cout<<"不能打开文件!"<<endl;
                exit(0);
            }
            // -c -w 或者 -c -l 或者 -w -l 
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
                    printf("格式错误!\n");
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
                cout<<"格式错误!"<<endl;
            }
            break;
        case 5:
            file=fopen(argv[4],"r");
            if(file==NULL)
            {
                printf("不能打开文件");
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
                printf("格式错误!\n");
            }
            break;
        case 6:
            file=fopen(argv[5],"r");
            if(file==NULL)
            {
                printf("不能打开文件");
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
                printf("格式错误!\n");
            }
            break;
        default:
            {
                cout<<"参数个数不正确!"<<endl;
                exit(0);
            }
    }
    return 0;
}
