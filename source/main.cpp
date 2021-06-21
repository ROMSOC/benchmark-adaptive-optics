#include <iostream>
#include <fstream>
#include <Eigen>

using namespace std;
using namespace Eigen;

// function definitions for reading matrices from .txt file
void read_sparse_matrix(const std::string& filename, SparseMatrix<float, RowMajor>& matrix);
void read_matrix(std::string file, MatrixXf& matrix);

int main()
{
    // read matrices from benchmark test files
    SparseMatrix<float, RowMajor> P;
    read_sparse_matrix("../benchmark/P.txt", P);
    SparseMatrix<float, RowMajor> Gamma;
    read_sparse_matrix("../benchmark/SH.txt", Gamma);
    SparseMatrix<float, RowMajor> invCeta;
    read_sparse_matrix("../benchmark/invCeta.txt", invCeta);
    SparseMatrix<float, RowMajor> F;
    read_sparse_matrix("../benchmark/F.txt", F);
    MatrixXf invCphi(P.cols(),P.cols());
    read_matrix("../benchmark/invCphi.txt", invCphi);

    // read sensor measurements from benchmark test files
    VectorXf s(invCeta.cols());
    fstream input("../benchmark/s.txt");
    string line;
    int indx = 0;
    if (input.is_open()) {
        while (getline(input,line)) {
            s(indx)=stof(line);
            indx++;
        }
        input.close();
    }
    cout << "read input done!" << endl;

    // calculate reconstruction matrix R
    MatrixXf R(P.cols(), P.cols());
    cout << "start computation..." << endl;
    R = (Gamma*P).transpose()*invCeta*(Gamma*P)+invCphi;

    // reconstruct turbulent layers from sensor measurements
    cout << "reconstruct layers from sensor measurements..." << endl;
    VectorXf b = (Gamma*P).transpose()*invCeta*s;
    VectorXf phi = R.colPivHouseholderQr().solve(b);

    // apply mirror fitting
    cout << "compute actuator commands..." << endl;
    VectorXf a(F.cols());
    a = F*phi;
    cout << "computation done!" << endl;

    // save actuator commands to file
    ofstream output("../benchmark/out.txt");
    if (output.is_open()) {
        for(int i = 0; i < a.size(); i++) {
            output << a(i) << '\n';
        }
    }
    cout << "stored output file out.txt!" << endl;

    return 0;
}

void read_sparse_matrix(const std::string& filename, SparseMatrix<float, RowMajor>& matrix) {
    ifstream fin(filename);
    if(fin.is_open()) {
        int M = 0, N = 0, L = 0;
        fin >> M >> N >> L;
        vector<Eigen::Triplet<float>> triple;
        triple.reserve(L);
        int m, n;
        float data;
        while (fin >> n >> m >> data) {
            triple.push_back(Triplet<float>(m-1, n-1, data));// m - 1 and n - 1 to set index start from 0
        }
        fin.close();

        matrix.resize(M, N);
        matrix.reserve(L);
        matrix.setFromTriplets(triple.begin(), triple.end());
    }
    else {
        std::cout << "Can not open sparse matrix file: " << filename << std::endl;
    }
}

void read_matrix(std::string file, MatrixXf& matrix) {
    std::ifstream in(file);
    std::string line;
    int row=0, col=0;

    if (in.is_open()) {
        while (std::getline(in, line)) {
            char* ptr = (char*) line.c_str();
            int len = line.length();

            col = 0;
            char* start = ptr;
            for (int i = 0; i<len; i++) {
                if (ptr[i]=='\t') {
                    matrix(row, col++) = stof(start);
                    start = ptr+i+1;
                }
            }
            row++;
        }
        in.close();
    }
}