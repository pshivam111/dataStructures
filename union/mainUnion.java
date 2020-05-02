import java.util.Scanner;

 class QuickFindUF
{
    private int id[];
    public QuickFindUF(int N) 
    {
         id = new int[N];
         for(int i=0;i<N;i++)
            id[i]=i;   
    }

    public boolean connected(int p,int q)
    {
        return id[p]==id[q];
    }

    public void union(int p, int q)
    {
        int pid =id[p];
        int qid =id[q];
        for(int i=0;i<id.length;i++)
        if(id[i]==pid) 
            id[i]=qid;
    }
}

class QuickFindUFLazy
{

    private int id[];
    public QuickFindUFLazy(int N)
    {
        for(int i=0;i<N;i++)
            id[i]=i;
    }
    public boolean.connected(int p,int q)
    {
        int proot;
        while(id[p]!=p)
            p=id[p];
        while(id[q]!=q)
            q=id[q];
        if(p==q)
            return true;
        else 
            return false;
    }
}

public class mainUnion {
public static void main(String[] args) {
    System.out.println("Main code");
    Scanner ip=new Scanner(System.in);

    int N=ip.nextInt();
    QuickFindUF uf = new QuickFindUF(N);
    ip.close();
    System.out.println(String.valueOf(uf.connected(6, 5)));
}
}
