import java.net.*;
import java.io.*;
class Client1 {
    public static void main(String srgs[])throws IOException
    {
        Socket s=null;
        BufferedReader get=null;
        PrintWriter put=null;
        try
        { 
            s=new Socket("127.0.0.1",8081);
            get=new BufferedReader(new InputStreamReader(s.getInputStream()));
            put=new PrintWriter(s.getOutputStream(),true);
        }  
        catch(Exception e)
        {
            System.exit(0);
        }
        String u,f;
        System.out.println("Enter the file name to transfer from server:");
        DataInputStream dis=new DataInputStream(System.in);
        f=dis.readLine();
        put.println(f);
        File f1=new File("out.txt");
        FileOutputStream  fs=new FileOutputStream(f1);
        byte nl[]={'\n'};
        while((u=get.readLine())!=null)
        { 
            byte jj[]=u.getBytes();
            fs.write(jj);
            fs.write(nl);

        }
        fs.close();
        System.out.println("File received");
        s.close();
    }
}