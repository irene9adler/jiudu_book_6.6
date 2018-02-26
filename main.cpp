//九度 第六章搜索 flood fill 例6.6
#include <stdio.h>
#define M 100
char co[M][M];
bool mark[M][M] = {false};
int m,n;//矩形框大小 全局
int go[] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

void DFS(int x,int y)
{
    int i;
    for(i = 0;i < 8;i++)
    {
        int nx,ny;
        nx += go[i][0];
        ny += go[i][1];//得到下一位置

        if(nx < 0 || ny < 0 || nx > m || ny > n) continue;
        if(co[nx][ny] == '*') continue;

        //该位置为@
        if(mark[nx][ny] == false)
        {
            mark[nx][ny] = true;
            DFS(nx,ny);//扩展该位置（递归）上面的if就是结束条件
        }

    }

}

int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m == 0 && n == 0) break;
        int i,j;
        for(i = 0; i < m;i++)
        {
            for(j = 0;j < n; j++)

                    scanf("%c",&co[i][j]);
        }

        int res = 0;
        for(i = 0; i < m;i++)
        {
            for(j = 0;j < n; j++)//遍历整个图
          {
              if(mark[i][j] == true)  continue;
              if(mark[i][j] == '*') continue;
              DFS(i,j);//从这个位置开始DFS扩展（该位置是@并且没被块扩展成true
              res ++;
          }

        printf("%d\n",res);
    }
    return 0;
}
