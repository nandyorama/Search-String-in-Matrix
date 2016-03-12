#define N 4
int Ischeck(char arr[][N],int i,int j,char * str)
{
	if(i>=0 && i<N && j>=0 && j< N && (arr[i][j]==*str))
		return 1;
	return 0;
}
bool searchWordUtil(char arr[][N],int x,int y,bool visited[][N],char *str)
{
	int r[]={0,-1,1,0};
	int c[]={-1,0,0,1};
	
	if(*str=='\0')
		return true;

	for(int i = 0;i<4;i++)
	{
		if(Ischeck(arr,x+r[i],y+c[i],str))
		{
			return searchWordUtil(arr,x+r[i],y+c[i],visited,str+1);
		}
	}
	return false;
}
bool searchWord(char arr[][N],char * str)
{
	for(int i = 0 ;i< N ;i++)
	{
		for(int j = 0;j<N;j++)
		{
			if(arr[i][j]==*str && searchWordUtil(arr,i,j,visited,str+1))
			{
				return true;
			}
		}
	}
	return false;
}
