import java.util.*;
class ByteStuffing{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Flag Sequence");
		String flag=sc.next(); 
		System.out.println("Enter Esc Sequence");
		String esc=sc.next();
		System.out.println("Enter no. of Frames");
		int n=sc.nextInt();
		String[] data=new String[n];
		for (int i=0; i<n;i++ ) {
			data[i]=sc.next();

		}
		List<String> send=new ArrayList<>();
		send.add(flag);
		for (String s:data) {
			if (s.equals(flag) || s.equals(esc)) {
				send.add(esc);
				send.add(s);
			}else {
				send.add(s);
			}
		}
		send.add(flag);
		System.out.println("=========Data with byte stuffing=========");
		for(String s:send)
			System.out.print(s+" ");
		System.out.println("");
		StringBuffer received=new StringBuffer();
		send.remove(0);
		send.remove(send.size()-1);
		for(int i=0;i<send.size();i++){
			String s=send.get(i);
			if (s.equals(esc)) {
				received.append(send.get(i+1)+" ");
				i++;
			}else{
				received.append(s+" ");
			}

		}
		System.out.println("=========Data decoded at Reciever end=========");
		System.out.println(received);
	}
}