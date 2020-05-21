public class NetTest{
	public static void main(String[] args){
		int[] size = {3,4,4,3};
		Net N = new Net(size); 
		Matrix M = new Matrix(3,2);
		M.random();
		N.propagate(M).print();
		
	
	}
}