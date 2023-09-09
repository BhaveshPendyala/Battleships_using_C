#include <stdio.h>

char d[2][14],e[2][14],p[3],m[2][14],n[2][14];

int BoundaryCase(int FirstRow, char FirstColumn, int Orientation, int Size, int t)
{
    int i,c,s;
    for(i=0;i<t;i++)
    {
        for(s=0;s<Size;s++)
        {
            if(Orientation==1)
            {
               if(e[0][i]==FirstRow && (int)e[1][i]==(int)FirstColumn+s)
                {
                    printf("A ship is already occupying one or more of the points specified to place this ship. Please enter a new position.\n");
                    scanf("%c",&FirstColumn);
                    scanf("%d%*c",&FirstRow);
                    i=1;
                    s=Size;
                }
            }
            else if(Orientation==2)
            {
                if(e[0][i]==FirstRow+s && e[1][i]==FirstColumn)
                {
                    printf("A ship is already occupying one or more of the points specified to place this ship. Please enter a new position.\n");
                    scanf("%c",&FirstColumn);
                    scanf("%d%*c",&FirstRow);
                    i=-1;
                    s=Size;
                }
            }
            else if(Orientation==3)
            {
                if(e[0][i]==FirstRow && (int)e[1][i]==(int)FirstColumn-s)
                {
                    printf("A ship is already occupying one or more of the points specified to place this ship. Please enter a new position.\n");
                    scanf("%c",&FirstColumn);
                    scanf("%d%*c",&FirstRow);
                    i=-1;
                    s=Size;
                }
            }
            else if(Orientation==4)
            {
                if(e[0][i]==FirstRow-s && e[1][i]==FirstColumn)
                {
                    printf("A ship is already occupying one or more of the points specified to place this ship. Please enter a new position.\n");
                    scanf("%c",&FirstColumn);
                    scanf("%d%*c",&FirstRow);
                    i=-1;
                    s=Size;
                }
            }
        }
    }
    while(Orientation!=1 && Orientation!=2 && Orientation!=3 && Orientation!=4)
    {
        printf("The value of Orientation should be one among 1, 2, 3 or 4.\n");
        printf("Enter the orientation as 1 to place the ship facing Right, 2 for facing downwards, 3 for facing left and 4 for facing upwards\n");
        scanf("%d%*c",&Orientation);
    }
    while(((FirstRow>(10-Size)) && Orientation==2)||((FirstRow<Size) && Orientation==4)||FirstRow>9||FirstRow<1)
    {
        printf("You cannot place a ship at this position as the given position exceeds the bounds.\n Please give a valid value for FirstRow depending on the size and orientation of the ship.\n");
        scanf("%d%*c",&FirstRow);
    }
    c=(int)FirstColumn;
    while(((c>(74-Size)) && Orientation==1)||((c<(64+Size)) && Orientation==3)||c<65||c>73)
    {
        printf("You cannot place a ship at this position as the given position exceeds the bounds.\n Please give a valid value for FirstColumn depending on the size and orientation of the ship.\n");
        scanf("%c%*c",&FirstColumn);
        c=(int)FirstColumn;
    }
    p[0]=FirstRow;
    p[1]=FirstColumn;
    p[2]=Orientation;
    
    return 0;
}

int ShipPosition()
{
    int FirstRow,Orientation,Size,i,x,b,t;
    char FirstColumn,y;
    char z[5];
    int a[5];
    Size=2;
    t=0;
    while(Size<=5)
    {
    	printf("ShipSize-%d:\n",Size);
        printf("Enter the column value of the first point where you want to place your ship\n");
        printf("NOTE: Column values range from A to I\n");
        scanf("%c",&FirstColumn);
        printf("Enter the row value of the first point where you want to place your ship\n");
        printf("NOTE: Row values range from 1 to 9\n");
        scanf("%d",&FirstRow);
        printf("Enter the orientation as 1 to place the ship facing Right, 2 for facing downwards, 3 for facing left and 4 for facing upwards\n");
        printf("NOTE: Orientation refers to the direction in which you want to place your ship\n");
        scanf("%d%*c",&Orientation);
        BoundaryCase(FirstRow,FirstColumn,Orientation,Size,t);
        a[0]=p[0];
        z[0]=p[1];
        FirstRow=p[0];
        FirstColumn=p[1];
        Orientation=p[2];
        if(Orientation==1)
        {
            for(i=1;i<Size;i++)
            {
                x=(int)FirstColumn+i;
                y=(char)x;
                z[i]=y;
            }
            for(i=1;i<=Size;i++)
            {
                e[0][t+i-1]=FirstRow;
                e[1][t+i-1]=z[i-1];
            }
            t=t+Size;
        }
        else if(Orientation==2)
        {
            for(i=1;i<Size;i++)
            {
                b=FirstRow+i;
                a[i]=b;
            }
            for(i=1;i<=Size;i++)
            {
                e[1][t+i-1]=FirstColumn;
                e[0][t+i-1]=a[i-1];
            }
            t=t+Size;
        }
        else if(Orientation==3)
        {
            for(i=1;i<Size;i++)
            {
                x=(int)FirstColumn-i;
                y=(char)x;
                z[i]=y;
            }
            for(i=1;i<=Size;i++)
            {
                e[0][t+i-1]=FirstRow;
                e[1][t+i-1]=z[i-1];
            }
            t=t+Size;
        }
        else
        {
            for(i=1;i<Size;i++)
            {
                b=FirstRow-i;
                a[i]=b;
            }
            for(i=1;i<=Size;i++)
            {
                e[1][t+i-1]=FirstColumn;
                e[0][t+i-1]=a[i-1];
            }
            t=t+Size;
        }
        Size=Size+1;
    }

    return 0;
}

int Attack1(int q)
{
    int g,R1,c,i;
    char C1;
    g=-1;
    printf("Player-1: Enter the column and row of the point where you want to attack\n");
    scanf("%c",&C1);
    scanf("%d%*c",&R1);
    c=(int)C1;
    while(R1<1 || R1>9 || c<65 || c>73)
    {
        printf("No such point exists. Please enter a valid point.\n");
        scanf("%c",&C1);
        scanf("%d%*c",&R1);
        c=(int)C1;
    }
    
	while(g==-1)
    {
    	for(i=0;i<q;i++)
	    {
	    	if(n[0][i]==R1 && n[1][i]==C1)
	    	{
	    		printf("The ship at this point was already hit. Enter another point.\n");
	    		scanf("%c",&C1);
        		scanf("%d%*c",&R1);
        		i=q;
			}
		}
		if(i==q)
		{
			g=0;
		}
	}
    while(g!=14 && g!=-1)
    {
        if(R1==e[0][g] && C1==e[1][g])
        {
        	n[0][q]=R1;
        	n[1][q]=C1;
            q=q+1;
            printf("You have hit a ship\n");
            g=-1;
        }
        else
        {
            g=g+1;
        }
    }
    if(g==14)
    {
        printf("You failed to hit a ship\n");
    }

    return q;
}

int Attack2(int r)
{
    int g,R2,c,i;
    char C2;
    g=-1;
    printf("Player-2: Enter the column and row of the point where you want to attack\n");
    scanf("%c",&C2);
    scanf("%d%*c",&R2);
    c=(int)C2;
    while(R2<1 || R2>9 || c<65 || c>73)
    {
        printf("No such point exists. Please enter a valid point.\n");
        scanf("%c",&C2);
        scanf("%d%*c",&R2);
        c=(int)C2;
    }
    while(g==-1)
    {
    	for(i=0;i<r;i++)
	    {
	    	if(m[0][i]==R2 && m[1][i]==C2)
	    	{
	    		printf("The ship at this point was already hit. Enter another point.\n");
	    		scanf("%c",&C2);
        		scanf("%d%*c",&R2);
        		i=r;
			}
		}
		if(i==r)
		{
			g=0;
		}
	}
    while(g!=14 && g!=-1)
    {
        if(R2==d[0][g] && C2==d[1][g])
        {
            m[0][r]=R2;
            m[1][r]=C2;
			r=r+1;
            printf("You have hit a ship\n");
            g=-1;
        }
        else
        {
            g=g+1;
        }
    }
    if(g==14)
    {
        printf("You failed to hit a ship\n");
    }

    return r;
}

int WinLose(int q,int r,int f)
{
    if(q==14)
    {
        printf("Player 1 is the winner\n");
        f=0;
    }
    else if(r==14)
    {
        printf("Player 2 is the winner\n");
        f=0;
    }
    
    return f;
}

int main()
{
    int i,f,j,q,r,k;
    q=0;
    r=0;
    j=1;
    f=1;
    while(j<=2)
    {
    	printf("Player-%d:\n",j);
        ShipPosition();
        if(j==1)
        {
            for(i=0;i<2;i++)
            {
                for(k=0;k<14;k++)
                {
                    d[i][k]=e[i][k];
                }
            }
        }
        j=j+1;
    }
    while(f!=0)
    {
        q=Attack1(q);
        f=WinLose(q,r,f);
        if(f!=0)
        {
            r=Attack2(r);
            f=WinLose(q,r,f);
        }
    }

    return 0;
}
