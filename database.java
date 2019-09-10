

import java.util.*;

class Signup 
{
    
    String name;
    int age, runs,rank;

}

class database
{
    public static void main(String[] args) {
        int i, t = 0, r = 0, j, k;
        String u, p, c, y, profile , username , password ;
        Scanner s = new Scanner(System.in);
        Signup e[] = new Signup[100];
        Signup temp= new Signup();
        for (i = 0; i < 100; i++) 
        {
            e[i] = new Signup();
        }
        System.out.println("Signin:");
        System.out.println("username:");
        username = s.next();
        System.out.println("password:");
        password = s.next();
        do 
        {

            System.out.println("Login  Search  Display");
            c = s.next();

            if (c.equals("Login")||c.equals("login"))
            {
                System.out.println("Enter your username");
                u = s.next();
                
                if (u.equals(username)) 
                {
                    System.out.println("Enter password");
                    p = s.next();
                    if (p.compareTo(password)==0) 
                    {
                        System.out.println("Enter your age");
                        e[t].age = s.nextInt();
                        System.out.println("Enter your name");
                        e[t].name = s.next();
                        System.out.println("Enter your Runs");
                        e[t].runs = s.nextInt();
                        t++;

                    } 
                    else
                        System.out.println("Incorrect Password");
                } 
                else 
                {
                    System.out.println("User not found");
                }
            }
            else if(c.equals("Search")||c.equals("search")) 
            {
                profile = s.next();
                for(i=0;i<t;i++)
                {
                    if(profile.compareTo(e[i].name)==0)
                    {   System.out.println("Rank\tName\tAge\tRuns");
                        System.out.println(e[i].rank +"\t" + e[i].name + "\t" + e[i].age + "\t" +e[i].runs);
                    }
                }
            }
            else if(c.equals("display")||c.equals("Display")) 
            {
                for(i=0 ; i<=t-1 ; i++)
                {
                    System.out.println("Rank\tName\tAge\tRuns");
                    System.out.println(e[i].rank +"\t" + e[i].name + "\t" + e[i].age + "\t" +e[i].runs);
                }
            }
            else 
            {
                System.out.println("Invalid input");
            }
            
            System.out.println("Exit or Continue");
            y = s.next();
            for (i = 0; i < t; i++) 
            {
                for(j=0;j<t-i-1;j++)
                {
                    if(e[j].runs < e[j+1].runs)
                    {
                        temp = e[j];
                        e[j] = e[j+1];
                        e[j+1] = temp;
                    }
                }
                e[i].rank = i+1;
            }
        } while (y.equals("continue")||y.equals("Continue"));
    }
}