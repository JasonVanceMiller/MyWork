public class MetaNet{
	Net[] Nets;
	
	public MetaNet(int count, int[] layerSizes){
		Nets = new Net[count];
		for(int i = 0; i < count; i++){
			Nets[i] = new Net(layerSizes);
		}
	}
	public Matrix propagate(Matrix data, Matrix target){
		int count = Nets.length;
		double[] errors = new double[count];
		Matrix[] outputs = new Matrix[count];
		for(int i = 0; i < count; i++){
			outputs[i] = Nets[i].propagate(data);
			for(int r = 0; r < outputs[i].height; r++){
				for(int c = 0; c < outputs[i].width; c++){
					errors[i] += (target.read(r,c) - outputs[i].read(r,c))*(target.read(r,c) - outputs[i].read(r,c));					
				}
			}		
		}
		int index = 0;
		for(int i = 0; i < count; i++){
			if(errors[index] > errors[i]){
				index = i; 
			}
		}
		return outputs[index];
	}
	public void backProp(Matrix data, Matrix target){
		for(int i = 0; i < Nets.length; i++){
			Nets[i].backProp(data,target);	
		}
	}
}
