public class NetMain{
	public static void main(String[] args){
		Matrix M = new Matrix(2,2);
		M.zero();
		M.change(0,0,1);
		M.change(1,1,1);
		int[] temp = {2,3,3,2};
		
		MetaNet N = new MetaNet(10, temp);
		M.print();
		 
		N.propagate(M,M).print();
		for(int i = 0; i < 100000; i++){
		N.backProp(M,M);
		}
		N.propagate(M,M).print();

		 
		
		
	}

}