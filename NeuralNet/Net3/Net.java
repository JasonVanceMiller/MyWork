public class Net{
	Matrix[] layers; 
	Matrix[] layerBias;
	Matrix[] layerEval;
	int[] size; 

	//Holds all of the DLi+1/DL matrix
	Matrix[][] GradLayer; 
	//Holds the final DE/DN derivative. 
	Matrix[] GradError; 
	//Holds all fo the DE/DLi derivatives.
	Matrix[][] GradAgg; 
	//Holds all of the changes to the weights, sum of DE/Dwijk
	Matrix[] GradWeights;
	//Holds all of the changes to the bias, sum fo DE/Dbij
	Matrix[] GradBias; 

	public Net(int[] layerSize){
		this.size = new int[layerSize.length];
		for(int i = 0; i < layerSize.length; i++){
			this.size[i] = layerSize[i];	
		}
		this.layers = new Matrix[layerSize.length - 1];	
		this.layerBias = new Matrix[layerSize.length - 1];	
		this.layerEval = new Matrix[layerSize.length];
		
		for(int i = 0; i < layerSize.length - 1; i++){
			this.layers[i] = new Matrix(layerSize[i+1],layerSize[i]);		
			this.layers[i].random();
			this.layerBias[i] = new Matrix(layerSize[i+1],1);
			this.layerBias[i].random();
		}
	}
	/*
	These two functions will go through the entire net, doing the matrix multiplication, applying the layer bias and storing the values of each product in layer eval. 
	*/
	Matrix propLayer(Matrix data, int index){
		Matrix temp = layers[index].rMulti(data);
		temp.addVector(layerBias[index]);
		temp.sig(); 
		layerEval[index+1] = temp;
		return temp; 
	}	
	Matrix propagate(Matrix data){
		Matrix temp = data.copy();
		layerEval[0] = data.copy();
		for(int i = 0; i < layers.length; i++){
				temp = propLayer(temp, i);
		}
		return temp; 
	}
	public void print(){
		for(int i = 0; i < layers.length; i++){
			layers[i].print();
			layerBias[i].print();
		}
	}
	public Net copy(){
		Net N = new Net(this.size);
		for(int i = 0; i < layers.length; i++){
				N.layers[i] = this.layers[i].copy();
				N.layerBias[i] = this.layerBias[i].copy();
		}
		return N; 
		
	}
	
	//finds the Dli+1 from Dli der
	/*
	This sets up empty arrays for Grad Layer, Grad Agg. Sets up zeroed matrices for GradBias, GradWeights and Grad Error. 
	*/
	public void propSetUp(Matrix data, Matrix target){
		GradLayer = new Matrix[layers.length][data.width];
		GradAgg = new Matrix[layers.length][data.width];
		GradError = new Matrix[data.width];
		GradBias = new Matrix[layers.length];
		GradWeights = new Matrix[layers.length];
		for(int i = 0; i < layers.length; i++){
			GradBias[i] = new Matrix(layers[i].height, 1);	
			GradWeights[i] = new Matrix(layers[i].height,layers[i].width);
			GradBias[i].zero();
			GradWeights[i].zero();
		}
		for(int i = 0; i < data.width; i++){
			GradError[i] = new Matrix(1, target.height);
			GradError[i].zero();
		}
	}
	public void backProp(Matrix data, Matrix target){
		Matrix output = this.propagate(data); 
		//def all of the arrays
		this.propSetUp(data, target);

		//i = 0 is not really used because that is the changes to the input data, but i want it to  
		//work badly instead of not at all. 
		for(int dataIndex = 0; dataIndex < data.width; dataIndex++){
			for(int i = 0; i < layers.length; i++){
				layerDer(i, dataIndex); 	
			}
			//GradLayer is now filled with all of the change values for the data set. 
			for(int i = 0; i < target.height; i++){
				GradError[dataIndex].change(0,i, 2*(output.read(i,dataIndex) - target.read(i,dataIndex)));
			}
			//GradError is now filled with DE/DLn
			GradAgg[GradAgg.length-1][dataIndex] = GradError[dataIndex].copy();
			for(int i = GradAgg.length - 2; i >= 0; i--){
				GradAgg[i][dataIndex] = GradAgg[i+1][dataIndex].rMulti(GradLayer[i+1][dataIndex]);
			}
			//GradAgg is now filled with DE/DLi
			for(int i = 0; i < layers.length; i++){
				double scalar; 
				for(int r = 0; r < layers[i].height; r++){
					scalar = layerEval[i+1].read(r,dataIndex);
					scalar = scalar * (1-scalar);
					
					GradBias[i].M[r][0] -= scalar * GradAgg[i][dataIndex].M[0][r]; 
					for(int c = 0; c < layers[i].width; c++){
							GradWeights[i].M[r][0] -= scalar*layerEval[i].read(c,dataIndex)*GradAgg[i][dataIndex].M[0][r];
					}
				}
			}
			//now we have DE/Dw for all weights stored
		}
		applyProp();
		
		
	}
	public void applyProp(){
		for(int i = 0; i < layers.length; i++){
			layers[i].add(GradWeights[i]);
			layerBias[i].add(GradBias[i]);
		}
	}
	/*
	Fills the Grad layer with the Dli/Dl values. 
	*/
	public void layerDer(int index, int dataIndex){
		double scalar;
		GradLayer[index][dataIndex] = new Matrix(size[index+1],size[index]);
		for(int r = 0; r < size[index+1]; r++){
			scalar = layerEval[index+1].read(r,dataIndex)*(1-layerEval[index+1].read(r,dataIndex));
			for(int c = 0; c < size[index]; c++){
				GradLayer[index][dataIndex].change(r,c,scalar*layers[index].read(r,c));
			}
		}
	}
	
	
}