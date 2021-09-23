
	char file_name[100];
    cin>>file_name;
    ifstream myfile(file_name);	    //open the file
	string temp;    
    while(getline(myfile,temp))	    //read line by line 
	{
		istringstream is(temp);	
		string text;
		while(is>>text)             //remove the space
		{
            ...
		}
		

string keyword[32]={
	"auto","break","case","char","const","continue","default","double",
	"do","else","enum","extern","float","for","goto","if","int","long",
	"register","return","short","signed","sizeof","static","struct",
	"switch","typedef","union","unsigned","void","volatile","while"
	};
	
int Judge1(string str,string str1)	
{
	int Judge_letter(char str);
	int location=str.find(str1,0);
	int len=str1.length();
	if(location!=string::npos)
	{
		if(location==0)
		{
			if(Judge_letter(str[location+len])==0)
				return 1;
			else 
				return 0;
		}
		else
		{
			if(Judge_letter(str[location-1])==0&&Judge_letter(str[location+len])==0)
				return 1;
			else
				return 0;
		}
	}
	return 0;
}
 
int Judge_letter(char str)			
{
	if(str>='a'&&str<='z'){
		return 1;
	}
		
	if(str>='A'&&str<='Z'){
		return 1;
	}
	if(str=='_'){
		return 0; 
	}
	if(str>='0'&&str<='9'){
		
		return 0;
	}
	return 0;
}	


void Level_1(string word_1)		
{
	for(int a=0;a<32;a++)			
	{
		if(Judge1(word_1,keyword[a])==1)
		{
			keyword_num++;
			break;
		}
	}
}	

void Level_34(string word_3)		
{
	if(Judge1(word_3,"else if"))	
	{
		top++;
		stack[top]=2;
	}
	else
	{
		if(Judge1(word_3,"if"))
		{
			top++;
			stack[top]=1;
		}
		else
		{
			if(Judge1(word_3,"else"))
			{
				if(stack[top]==1)
				{
					ifelse_num++;
					top--;
				}
				else	
				{
					if(stack[top]==2)
					{
						if_elseif_else_num++;
						top--;
					}
				}
			}
		}
	}
}
