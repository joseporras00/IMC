/*********************************************************************
* File  : MultilayerPerceptron.cpp
* Date  : 2020
*********************************************************************/

#include "MultilayerPerceptron.h"

#include "util.h"


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>  // To establish the seed srand() and generate pseudorandom numbers rand()
#include <limits>
#include <math.h>


using namespace imc;
using namespace std;
using namespace util;

// ------------------------------
// Constructor: Default values for all the parameters
MultilayerPerceptron::MultilayerPerceptron():
	nOfLayers(0),
	layers(0),
	//etc
{

}

// ------------------------------
// Allocate memory for the data structures
// nl is the number of layers and npl is a vetor containing the number of neurons in every layer
// Give values to Layer* layers
int MultilayerPerceptron::initialize(int nl, int npl[]) {
	nOfLayers=nl;
	int i,j=0;

	for(i=0;i<nOfLayers;i++){
		layers[i].nOfNeurons=npl[i];
		layers[i].neurons= new Neuron[layers[i].nOfNeurons];
		if(layers[i].neurons==NULL){
			return -1;
		}

		for(j=0;j<layers[i].nOfNeurons;j++){
			layers[i].neurons[j].out=1.0;
			layers[i].neurons[j].delta=0.0;

			if(i>0){
				int nOfWeights=layers[i-1].nOfNeurons+1;
				layers[i].neurons[j].w=new double[nOfWeights];
				layers[i].neurons[j].deltaW=new double[nOfWeights];
				layers[i].neurons[j].lastDeltaW=new double[nOfWeights];
				layers[i].neurons[j].wCopy=new double[nOfWeights];
				if(layers[i].neurons[j].w==NULL){
					return -1
				}
			}
		}
	}
}


// ------------------------------
// DESTRUCTOR: free memory
MultilayerPerceptron::~MultilayerPerceptron() {
	freeMemory();
}


// ------------------------------
// Free memory for the data structures
void MultilayerPerceptron::freeMemory() {
	for(i=0;i<nOfLayers;i++){
		for(j=0;j<layers[i].nOfNeurons;j++){
			layers[i].neurons[j].w.clear;
			layers[i].neurons[j].deltaWts.clear;
			layers[i].neurons[j].lastDeltaW.clear;
			layers[i].neurons[j].wCopy.clear;		
			
		}
	}
}

// ------------------------------
// Feel all the weights (w) with random numbers between -1 and +1
void MultilayerPerceptron::randomWeights() {
	for(int i=0;i<nOfLayers;i++){
		for(int j=0;j<layers[i].nOfNeurons;j++){
			int nPesos=layers[i-1].nOfNeurons+1;
			for(int k=0;k<nPesos;k++){
				layers[i].neurons[j].w=randomDouble(-1,1);
			}
		}
	}
}

// ------------------------------
// Feed the input neurons of the network with a vector passed as an argument
void MultilayerPerceptron::feedInputs(double* input) {

}

// ------------------------------
// Get the outputs predicted by the network (out vector the output layer) and save them in the vector passed as an argument
void MultilayerPerceptron::getOutputs(double* output)
{

}

// ------------------------------
// Make a copy of all the weights (copy w in wCopy)
void MultilayerPerceptron::copyWeights() {

}

// ------------------------------
// Restore a copy of all the weights (copy wCopy in w)
void MultilayerPerceptron::restoreWeights() {

}

// ------------------------------
// Calculate and propagate the outputs of the neurons, from the first layer until the last one -->-->
void MultilayerPerceptron::forwardPropagate() {
	
}

// ------------------------------
// Obtain the output error (MSE) of the out vector of the output layer wrt a target vector and return it
double MultilayerPerceptron::obtainError(double* target) {
	return -1;
}


// ------------------------------
// Backpropagate the output error wrt a vector passed as an argument, from the last layer to the first one <--<--
void MultilayerPerceptron::backpropagateError(double* target) {
	
}


// ------------------------------
// Accumulate the changes produced by one pattern and save them in deltaW
void MultilayerPerceptron::accumulateChange() {

}

// ------------------------------
// Update the network weights, from the first layer to the last one
void MultilayerPerceptron::weightAdjustment() {


}

// ------------------------------
// Print the network, i.e. all the weight matrices
void MultilayerPerceptron::printNetwork() {
	int i,j,k;

	for(i=1;i<nOfLayers;i++){
		cout << "Layer "<<i<<"\n--------"<<endl;
		for(j=0;j<layers[i].nOfNeurons;j++){
			int nOfWeights=layers[i-1].nOfNeurons+1;
			for(k=0;k<nOfWeights;k++){
				cout<<layers
			}

		}
	}
}

// ------------------------------
// Perform an epoch: forward propagate the inputs, backpropagate the error and adjust the weights
// input is the input vector of the pattern and target is the desired output vector of the pattern
void MultilayerPerceptron::performEpochOnline(double* input, double* target) {

}

// ------------------------------
// Read a dataset from a file name and return it
Dataset* MultilayerPerceptron::readData(const char *fileName) {


	return NULL;
}

// ------------------------------
// Perform an online training for a specific trainDataset
void MultilayerPerceptron::trainOnline(Dataset* trainDataset) {
	int i;
	for(i=0; i<trainDataset->nOfPatterns; i++){
		performEpochOnline(trainDataset->inputs[i], trainDataset->outputs[i]);
	}
}

// ------------------------------
// Test the network with a dataset and return the MSE
double MultilayerPerceptron::test(Dataset* testDataset) {
	return -1.0;
}


// Optional - KAGGLE
// Test the network with a dataset and return the MSE
// Your have to use the format from Kaggle: two columns (Id y predictied)
void MultilayerPerceptron::predict(Dataset* pDatosTest)
{
	int i;
	int j;
	int numSalidas = layers[nOfLayers-1].nOfNeurons;
	double * obtained = new double[numSalidas];
	
	cout << "Id,Predicted" << endl;
	
	for (i=0; i<pDatosTest->nOfPatterns; i++){

		feedInputs(pDatosTest->inputs[i]);
		forwardPropagate();
		getOutputs(obtained);
		
		cout << i;

		for (j = 0; j < numSalidas; j++)
			cout << "," << obtained[j];
		cout << endl;

	}
}

// ------------------------------
// Run the traning algorithm for a given number of epochs, using trainDataset
// Once finished, check the performance of the network in testDataset
// Both training and test MSEs should be obtained and stored in errorTrain and errorTest
void MultilayerPerceptron::runOnlineBackPropagation(Dataset * trainDataset, Dataset * pDatosTest, int maxiter, double *errorTrain, double *errorTest)
{
	int countTrain = 0;

	// Random assignment of weights (starting point)
	randomWeights();

	double minTrainError = 0;
	int iterWithoutImproving;
	double testError = 0;

	double validationError = 1;

	// Generate validation data
	if(validationRatio > 0 && validationRatio < 1){
		// .......
	}


	// Learning
	do {

		trainOnline(trainDataset);
		double trainError = test(trainDataset);
		if(countTrain==0 || trainError < minTrainError){
			minTrainError = trainError;
			copyWeights();
			iterWithoutImproving = 0;
		}
		else if( (trainError-minTrainError) < 0.00001)
			iterWithoutImproving = 0;
		else
			iterWithoutImproving++;

		if(iterWithoutImproving==50){
			cout << "We exit because the training is not improving!!"<< endl;
			restoreWeights();
			countTrain = maxiter;
		}


		countTrain++;

		// Check validation stopping condition and force it
		// BE CAREFUL: in this case, we have to save the last validation error, not the minimum one
		// Apart from this, the way the stopping condition is checked is the same than that
		// applied for the training set

		cout << "Iteration " << countTrain << "\t Training error: " << trainError << "\t Validation error: " << validationError << endl;

	} while ( countTrain<maxiter );

	cout << "NETWORK WEIGHTS" << endl;
	cout << "===============" << endl;
	printNetwork();

	cout << "Desired output Vs Obtained output (test)" << endl;
	cout << "=========================================" << endl;
	for(int i=0; i<pDatosTest->nOfPatterns; i++){
		double* prediction = new double[pDatosTest->nOfOutputs];

		// Feed the inputs and propagate the values
		feedInputs(pDatosTest->inputs[i]);
		forwardPropagate();
		getOutputs(prediction);
		for(int j=0; j<pDatosTest->nOfOutputs; j++)
			cout << pDatosTest->outputs[i][j] << " -- " << prediction[j] << " ";
		cout << endl;
		delete[] prediction;

	}

	testError = test(pDatosTest);
	*errorTest=testError;
	*errorTrain=minTrainError;

}

// Optional Kaggle: Save the model weights in a textfile
bool MultilayerPerceptron::saveWeights(const char * archivo)
{
	// Object for writing the file
	ofstream f(archivo);

	if(!f.is_open())
		return false;

	// Write the number of layers and the number of layers in every layer
	f << nOfLayers;

	for(int i = 0; i < nOfLayers; i++)
		f << " " << layers[i].nOfNeurons;
	f << endl;

	// Write the weight matrix of every layer
	for(int i = 1; i < nOfLayers; i++)
		for(int j = 0; j < layers[i].nOfNeurons; j++)
			for(int k = 0; k < layers[i-1].nOfNeurons + 1; k++)
				f << layers[i].neurons[j].w[k] << " ";

	f.close();

	return true;

}

// ------------------------------
// Read a dataset from a file name and return it
Dataset* MultilayerPerceptron::readData(const char *fileName) {

	ifstream myFile(fileName);    // Create an input stream

    if (!myFile.is_open()) {
       cout << "ERROR: I cannot open the file " << fileName << endl;
       return NULL;
    }

	Dataset * dataset = new Dataset;
	if(dataset==NULL)
		return NULL;

	string line;
	int i,j;


	if( myFile.good()) {
		getline(myFile,line);   // Read a line
		istringstream iss(line);
		iss >> dataset->nOfInputs;
		iss >> dataset->nOfOutputs;
		iss >> dataset->nOfPatterns;
	}
	dataset->inputs = new double*[dataset->nOfPatterns];
	dataset->outputs = new double*[dataset->nOfPatterns];

	for(i=0; i<dataset->nOfPatterns; i++){
		dataset->inputs[i] = new double[dataset->nOfInputs];
		dataset->outputs[i] = new double[dataset->nOfOutputs];
	}

	i=0;
	while ( myFile.good()) {
		getline(myFile,line);   // Read a line
		if (! line.empty()) {
			istringstream iss(line);
			for(j=0; j< dataset->nOfInputs; j++){
				double value;
				iss >> value;
				if(!iss)
					return NULL;
				dataset->inputs[i][j] = value;
			}
			for(j=0; j< dataset->nOfOutputs; j++){
				double value;
				iss >> value;
				if(!iss)
					return NULL;
				dataset->outputs[i][j] = value;
			}
			i++;
		}
	}

	myFile.close();

	return dataset;
}


// Optional Kaggle: Load the model weights from a textfile
bool MultilayerPerceptron::readWeights(const char * archivo)
{
	// Object for reading a file
	ifstream f(archivo);

	if(!f.is_open())
		return false;

	// Number of layers and number of neurons in every layer
	int nl;
	int *npl;

	// Read number of layers
	f >> nl;

	npl = new int[nl];

	// Read number of neurons in every layer
	for(int i = 0; i < nl; i++)
		f >> npl[i];

	// Initialize vectors and data structures
	initialize(nl, npl);

	// Read weights
	for(int i = 1; i < nOfLayers; i++)
		for(int j = 0; j < layers[i].nOfNeurons; j++)
			for(int k = 0; k < layers[i-1].nOfNeurons + 1; k++)
				f >> layers[i].neurons[j].w[k];

	f.close();
	delete[] npl;

	return true;
}