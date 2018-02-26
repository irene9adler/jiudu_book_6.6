//�Ŷ� ���������� flood fill ��6.6
#include <stdio.h>
#define M 100
char co[M][M];
bool mark[M][M] = {false};
int m,n;//���ο��С ȫ��
int go[] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

void DFS(int x,int y)
{
    int i;
    for(i = 0;i < 8;i++)
    {
        int nx,ny;
        nx += go[i][0];
        ny += go[i][1];//�õ���һλ��

        if(nx < 0 || ny < 0 || nx > m || ny > n) continue;
        if(co[nx][ny] == '*') continue;

        //��λ��Ϊ@
        if(mark[nx][ny] == false)
        {
            mark[nx][ny] = true;
            DFS(nx,ny);//��չ��λ�ã��ݹ飩�����if���ǽ�������
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
            for(j = 0;j < n; j++)//��������ͼ
          {
              if(mark[i][j] == true)  continue;
              if(mark[i][j] == '*') continue;
              DFS(i,j);//�����λ�ÿ�ʼDFS��չ����λ����@����û������չ��true
              res ++;
          }

        printf("%d\n",res);
    }
    return 0;
}
