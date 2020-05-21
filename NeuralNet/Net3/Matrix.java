import java.lang.Math; 
public class Matrix{
	int width;
	int height; 
	double[][] M; 
	/*
	Creates a new Matrix object with the height and width provided and allocates the appropriate space in a 2d array for all of the data. 
	The values in the array are the defaults for a double[][]. 
	*/
	public Matrix(int height, int width){
		this.width 	= width; 
		this.height = height; 
		this.M 		= new double[height][width];
	}
	/*
	Print out the doubles in the matrix in row column order. A extra space is done after each print() call. 
	*/
	void print(){
		int w 	= this.width;
		int h 	= this.height; 
		for(int r = 0; r < h; r++){
			for(int c = 0; c < w; c++){
				System.out.print(this.M[r][c] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}
	/*
	Adds all of the values of the matrix M to this matrix. M is left unchanged. 
	This function throws a error if the size of M does not match the size of this matrix. 
	*/
	void add(Matrix M) throws IllegalArgumentException{
		if(this.width != M.width || this.height != M.height){
			throw new IllegalArgumentException("Adding Matrices of different sizes.");
		}
		for(int r = 0; r < this.height; r++){
			for(int c = 0; c < this.width; c++){
				this.M[r][c] += M.M[r][c];
			}
		}
	}
	/*
	Adds the values of V to each of the columns of this Matrix. 
	This function throws a error if V has more than 1 column or the heights don't matchup. 
	*/
	void addVector(Matrix V) throws IllegalArgumentException{
		if(V.width != 1 || V.height != this.height){
			throw new IllegalArgumentException("Adding Vector of wrong height or non 1 width.");	
		}
		for(int r = 0; r < this.height; r++){
			for(int c = 0; c < this.width; c++){
				this.M[r][c] += V.M[r][0];	
			}
		}
	}
	/*
	Creates a new instance of this matrix and adds M to it. 
	This will likewise throw a error if the size of M does not match the size of this matrix. 
	*/
	Matrix addNew(Matrix M){
		Matrix outputMatrix = copy();
		outputMatrix.add(M);
		return outputMatrix; 
	}
	/*
	Creates a new Matrix with the fields populated with the data in M. 
	*/
	Matrix copy(){
		Matrix outputMatrix = new Matrix(height, width);
		outputMatrix.add(this);
		return outputMatrix; 
	}
	/*
	Returns the value at the r row and c collumn of the Matrix, r and c start from 0. 
	Throws a error if a invalid entry is read. 
	*/
	double read(int r, int c) throws IllegalArgumentException{
		if(0 <= r && r < height && 0 <= c && c < width){
			return M[r][c];	
		}else{
			throw new IllegalArgumentException("Attempting to read a faulty location.");
		}
	}
	/*
	Changes the value of the r row and c collumn of the Matrix with the value in data. 
	Throws a error if changing a non existant entry. 
	*/
	void change(int r, int c, double data) throws IllegalArgumentException{
		if(0 <= c && c < width && 0 <= r && r < height){
			M[r][c] = data; 
		}else{
			throw new IllegalArgumentException("Changing non-existant entry.");
		}
	}
	/*
	Standard matrix multiplication of (this)*(M).
	Returns a new matrix. 
	Throws a error if this.width != M.height. 
	*/
	Matrix rMulti(Matrix M) throws IllegalArgumentException{
		if(width != M.height){
			throw new IllegalArgumentException("Matrix multiplication of incompatable sizes.");
		}
		Matrix outputMatrix = new Matrix(height, M.width);
		double sum;
		for(int r = 0; r < height; r++){
			for(int c = 0; c < M.width; c++){
				sum = 0; 
				for(int i = 0; i < width; i++){
					sum += read(r,i)*M.read(i,c);
				}
				outputMatrix.change(r,c,sum); 
			}
		}
		return outputMatrix; 
	}
	/*
	Standard matrix multiplication of (M)*(this).
	Throws a error if this.height != M.width. 
	*/
	Matrix lMulti(Matrix M){
		return M.rMulti(this);
	}
	/*
	Changes all of the entries of a Matrix to zero. 
	*/
	void zero(){
		for(int r = 0; r < height; r++){
			for(int c = 0; c < width; c++){
				change(r,c,0);	
			}
		}
	}
	/*
	Changes all of the entries of a Matrix to a random number between [-1,1]
	*/
	void random(){
		for(int r = 0; r < height; r++){
			for(int c = 0; c< width; c++){
				change(r,c,Math.random()*2-1);	
			}
		}
	}
	/*
	This is the function that compresses all of R to [0,1]
	*/
	public static double sig(double x){
		return 1/(1+Math.exp(-x));
	}
	/*
	Preforms the sig() function on all of the values in the Matrix. 
	*/
	void sig(){
		for(int r = 0; r < height; r++){
			for(int c = 0; c < width; c++){
				change(r,c,sig(read(r,c)));	
			}
		}
	}
	/*
	This function is the derivative of the sigmoid function we choose. 
	*/
	public static double sigDer(double x){
		return sig(x) * (1 - sig(x)); 	
	}
	/*
	This function is the error function
	*/
	public static double error(double guessValue, double trueValue){
		double temp = guessValue - trueValue;
		return temp*temp; 
	}
	/*
	This function is the derivative of the error function
	*/
	public static double errorDer(double guessValue, double trueValue){
		return 2*(guessValue - trueValue); 	
	}
}
 
