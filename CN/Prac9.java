import java.util.*;
class Prac9
{
	public static void main(String[] args) {
        
        //Taking Input from the user
		Scanner sc=new Scanner(System.in);
        System.out.println("Enter TokenGeneration Time(Give Smaller Input for better visualization):");
        double t=sc.nextDouble();

        //Calling the function 
		TokenGeneration token=new TokenGeneration("TokenGeneration",t);

		}
}
class TokenGeneration implements Runnable {
    //sec --> TokenGeneration Time
    //exit --> boolean variable which sets to true whenever users wants to exit program
    //name --> Sets name to thread
    //t,t1 --> An instance of thread
    //b --> An instance of BuckerRemoval Thread


 	double sec;
    private boolean exit;
 	Scanner sc=new Scanner(System.in);
    private String name;
    Thread t,t1;
 	  BucketRemoval b;
    TokenGeneration(String threadname,double sec)
    {
    	this.sec=sec;
        name = threadname;
        t = new Thread(this, name);

        System.out.println("Enter Capacity:");
        int c=sc.nextInt();

        System.out.println("Enter BucketRemoval time:(Make it slighter more than TokenGeneration time)");
        double bt=sc.nextDouble();

        System.out.println("Wait for Some Time:");
        b=new BucketRemoval("BucketRemoval",c,bt);

        t1=new Thread(b,"BucketRemoval");
        System.out.println("New thread: " + t);

        exit = false;
        t.start();
        t1.start();
    }
    //Called whenever start() method is called
    public void run()
    {   
        //Runs untill user doesn't want to end program
    	try{
         while(true){
        	 Thread.sleep((long)(sec*1000.0));
        	 b.inc();
    	}
        }catch(Exception e){
        	System.out.println("e");
        }
    }
    public void stop()
    {
        exit = true;
    }
    
}
class BucketRemoval implements Runnable {
    //exit --> boolean variable which sets to true whenever users wants to exit program
    //name --> Sets name to thread
    //q --> Each packets are added into the queue
    //sum --> keeps tracks of total packets present at any particular instance
    //rate -->Rate at which packets needs to be removed
    //capacity --> Total bucket capacity

    private boolean exit;
 	int capacity;
    private String name;
    Thread t;
 	Queue<Integer> q;
 	int sum;
 	double rate;
    BucketRemoval(String threadname,int capacity,double rate)
    {
    	this.rate=rate;
    	this.sum=0;
    	this.q=new LinkedList<>();
    	this.capacity=capacity;
        name = threadname;
        t = new Thread(this, name);
        System.out.println("New thread: " + t);
        exit = false;
    }
 
    public void run()
    {
    	sum=Math.min(sum,capacity);
    	try{
    		while(true){
            // At each interval through poission distribution a random amount is selected and
            // if available packets are less than present then it is being removed.
    		Thread.sleep((long)(rate*1000.0));
    		int toBeRemoved=getPoisson(5);

            //Printing present, toBeRemoved and Removed packets
    		System.out.println("Tokens Available: "+sum);
    		System.out.println("Packets to be Removed: "+toBeRemoved);
    		if (toBeRemoved<=sum) {
    			
    			sum-=toBeRemoved;
    			System.out.println("Packets removed: "+toBeRemoved);
    		}
    	}
    	}catch(Exception e){
    		System.out.println(e);
    	}
    }
    public void stop()
    {
        exit = true;
    }
    //An utility function for random amount of packets selection
    public static int getPoisson(double lambda) {
 	 double L = Math.exp(-lambda);
 	 double p = 1.0;
	 int k = 0;
	 do {
	    k++;
	    p *= Math.random();
	  } while (p > L);

	 return k - 1;
	}
	public void inc(){
		this.sum++;
	}
	
}