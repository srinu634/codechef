import java.math.BigInteger;
import java.util.Scanner;


class Main {

	public static void main(String args[])  {
	int t;
	BigInteger N;
	long n;
	
	Scanner in = new Scanner(System.in);	
	t= in.nextInt( );

	while(t>0) {
	N= in.nextBigInteger( );
	n=N.longValue( );
	
	if(n==2){ 
	System.out.println("2");
	t--;
	continue;
	}


	while(true) {

	if ( n%2==0) {
	n--;
	N=N.subtract(new BigInteger("1"));
	continue;
	}

	if ( N.isProbablePrime(50) ) {
	System.out.println( n );
	break;
	}
	N=N.subtract(new BigInteger("1"));
	n--;
	}//while :true
	
	t--;
			}//test cases
		
	}//main


static	int checkPrime( long  n ){ 	
	long rootn,i;
	rootn= (long)Math.sqrt(n);
	for(i=3;i<=rootn;i=i+2)
	if(n%i==0)
	return -1;
	return 1;
	}


		}//Class