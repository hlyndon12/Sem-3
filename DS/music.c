#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int no,duration;
    char name[40];
    char artist[40];
    char url[2000];
    struct node *link;
};
struct node *p;
char choice;
void add();
void del();
void display();
void count();
void shuffle();
void sort();
void play();
void main()
{
    FILE *fp;
    int c,i;
    p=NULL;
    
    
    printf("Welcome to the music player\n Create your own playlist\n");
    for(i=0;i<100;i++)
    {
    
    printf("\nMenu\n1.Add song\n2.Delete a song\n3.Display playlist\n4.No. of songs added\n5.Play the songs\n6.Sort\n7.Exit.\nEnter your choice: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
                add();
                break;
        case 2:
                del();
                break;
        case 3:
                display();
                break;
        case 4:
                count();
                break;
        case 5:
                play();
                break;
        case 6:
                sort();
                break;
        case 7:
                exit(0);
                break;
        default:
                printf("Invalid option");
                break;
    }
    
    }

}
void add()
{
    int no,dur;
    char n[40],a[40];
    char u[200];
    struct node *temp,*q;
    temp=NULL;
    temp=(struct node *)malloc(sizeof(struct node *));
    printf("\nEnter the song no.:");
    scanf("%d",&no);
    printf("\nEnter the song name:");
    scanf("%s",&n);
    printf("\nEnter the artist's name:");
    scanf("%s",&a);
    printf("\nEnter the duration of song in seconds:");
    scanf("%d",&dur);
    printf("\nCopy and paste the song's link:");
    scanf(" %[^\n]%*c",u); 
    
    temp->no=no;
    temp->duration=dur;
    strcpy(temp->artist,a);
    strcpy(temp->name,n);
    strcpy(temp->url,u);
    temp->link=NULL;
    if(p==NULL)
    {
        p=temp;
        
        
        printf("\nSong added succesfully");
    }
    else
    {
        q=p;
        while(q->link!=NULL)
        {
            q=q->link;
        }
        q->link=temp;
        printf("\nSong Added Succesfully");
    }
    
}
void del()
{
    char x[40];
    struct node *q,*old;
    int found=0;
    if(p==NULL)
    {
        printf("\nPlaylist does not exist");
    }
    else
    {
        printf("\nEnter the name of the song that you want to delete:");
        scanf("%s",&x);
        q=p;
        while(q!=NULL)
        {
            if(q->name==x)
            {
                if(q==p)
                {
                    p=q->link;
                    q=NULL;
                    found=1;
                }
                else
                {
                    if(q==NULL)
                    {
                        old->link=NULL;
                        found=1;
                        q=old=NULL;
                    }
                    else
                    {
                        old->link=q->link;
                        found=1;
                        q=old=NULL;
                    }
                    
                }
                
            }
            else
            {
                old=q;
                q=q->link;
            }
            
        }
    }
    if(found==1)
    {
        printf("\nSong has been deleted");
    }
    else
    {
        printf("\nSong not found");
    }
    
}
void count()
{
    int i=0;
    struct node *q;
    q=p;
    if(p==NULL)
    {
        printf("\nPlaylist is empty");
    }
    else
    {    
        while(q!=NULL)
        {   
            i++;
            q=q->link;
        }
        printf("\nNo. of songs =%d",i);
    }
}
void display()
{
    struct node *q;
    q=p;
    if(p==NULL)
    {
        printf("\nPlaylist is empty");
    }
    else
    {
        while(q!=NULL)
        {
            printf("%s\n",q->name);
            printf("%s",q->url);
            printf("%s",q->name);
            printf("%s",q->artist);
            printf("%d",q->duration);
            q=q->link;
        }
    }
}
void play()
{
struct node *q;
char command[100];
char name[50];

q=p;
if(p==NULL)
{
    printf("\nPlaylist is empty");
}
    else
    {
        while(q!=NULL)
            {
                strcpy(command,"start wmplayer /close \"c:\\Users\\hlynd\\OneDrive\\Desktop\\DS\\");
                strcat(command, q->url);
                strcat(command,".mp3\"");
                system(command);
                q=q->link;
            }

    }
}
/*void shuffle()
{
    int n;
    struct node *q;
    q=p;
    if(p==NULL)
    {
        printf("Playlist is empty");
    }
    else
    {
         while(q!=NULL)
        {   
            n++;
            q=q->link;
        }
          
    } 
    }*/
    void sort()
    {
        int ch,d1,d2,n=0;
        struct node *q,*fwd,*temp;
        q=p;
        printf("\nSub Menu\n1.Sort by Name\n2.Sort by Artist\n3.Sort by Song's length\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    if(p==NULL)
                    {
                        printf("\nPlaylist is empty");
                    }
                    else
                    {
                        if(n==1)
                        {
                            printf("\nList Sorted Successfully");
                        }
                        else
                        {
                            while(q!=NULL)
                            {
                                d1=q->name[0];
                                fwd=q->link;
                                while(fwd!=NULL)
                                {
                                    d2=fwd->name[0];
                                    if(d2<d1)
                                    {
                                        temp=q;
                                        q=fwd;
                                        fwd=temp;
                                    }
                                    fwd=fwd->link;
                                }
                                q=q->link;

                            }
                            n=1;
                        }
                        
                    }
                    break;
            case 2:
                     if(p==NULL)
                    {
                        printf("\nPlaylist is empty");
                    }
                    else
                    {
                        if(n==1)
                        {
                            printf("\nList Sorted Successfully");
                        }
                        else
                        {
                            while(q!=NULL)
                            {
                                d1=q->artist[0];
                                fwd=q->link;
                                while(fwd!=NULL)
                                {
                                    d2=fwd->artist[0];
                                    if(d2<d1)
                                    {
                                        temp=q;
                                        q=fwd;
                                        fwd=temp;
                                    }
                                    fwd=fwd->link;
                                }
                                q=q->link;

                            }
                            n=1;
                        }
                        
                    }
                    break;
            case 3:
                     if(p==NULL)
                    {
                        printf("\nPlaylist is empty");
                    }
                    else
                    {
                        if(n==1)
                        {
                            printf("\nList Sorted Successfully");
                        }
                        else
                        {
                            while(q!=NULL)
                            {
                            
                                fwd=q->link;
                                while(fwd!=NULL)
                                {
                                    
                                    if(q->duration>fwd->duration)
                                    {
                                        temp=q;
                                        q=fwd;
                                        fwd=temp;
                                    }
                                    fwd=fwd->link;
                                }
                                q=q->link;

                            }
                            n=1;
                        }
                        
                    }
                    break;
            default:
                    printf("Invalid choice");
                    break;
                    
        }
    }
    