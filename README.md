<img src="images/romsoclogo-logo.png" alt="ROMSOC logo"  width="150"/>

# Benchmark for high-performance algorithms in adaptive optics control
[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.5171804.svg)](https://doi.org/10.5281/zenodo.5171804) [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/ROMSOC/benchmark-adaptive-optics/HEAD?labpath=Benchmark.ipynb)

## Summary
This benchmark can be used for applications in high-performance computing for adaptive optics control. 

## Description
This is a reduced benchmark case, which implements the MVM algorithm widely used for performing adaptive optics for extremely large telescopes. Reduced refers here to a smaller problem size. Since the MVM algorithms is a matrix-based method, the input files may become very large. Thus, we assume here a smaller problem size to reduce the dimension of matrices involved. Note that the source files are working for a larger problem size as well. For a detailed step-by-step description we refer to the PDF document in the documentation directory of this repository.

## Directory structure
In the directory source you can find all source files required to run the benchmark test. The directory benchmark contains the input and output data for the specific example. In the directory documentation you can find a PDf file with a detailed step-by-step description of the benchmark case.

## Run Jupyter notebooks
The entire benchmark repository can be executed in a provided Docker container where a full installation of Intel OneAPI is available. Once you have clone or downloaded this repository, to build the container just type
```bash
docker build -t benchmark-adaptive-optics . 
```
and for running it locally:
```bash
docker run -it --rm -p 8888:8888 benchmark-adaptive-optics jupyter-lab --ip=0.0.0.0 --port=8888 --allow-root
```

Alternatively, user-friendly Jupyter Notebooks could be used to run different benchmarks on the cloud. For instance, the benchmark is available at:
[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/ROMSOC/benchmark-adaptive-optics/HEAD?labpath=Benchmark.ipynb). Please, notice that mybinder cloud computations are limited to 2GB of RAM memory.

## Disclaimer
In downloading this SOFTWARE you are deemed to have read and agreed to the following terms:
This SOFTWARE has been designed with an exclusive focus on civil applications. It is not to be used
for any illegal, deceptive, misleading or unethical purpose or in any military applications. This includes ANY APPLICATION WHERE THE USE OF THE SOFTWARE MAY RESULT IN DEATH,
PERSONAL INJURY OR SEVERE PHYSICAL OR ENVIRONMENTAL DAMAGE. Any redistribution of the software must retain this disclaimer. BY INSTALLING, COPYING, OR OTHERWISE
USING THE SOFTWARE, YOU AGREE TO THE TERMS ABOVE. IF YOU DO NOT AGREE TO
THESE TERMS, DO NOT INSTALL OR USE THE SOFTWARE

## Acknowledgments
<img src="images/EU_Flag.png" alt="EU Flag"  width="150" height="100" />
The ROMSOC project has received funding from the European Union’s Horizon 2020 research and innovation programme under the Marie Skłodowska-Curie Grant Agreement No. 765374.
This repository reflects the views of the author(s) and does not necessarily reflect the views or policy of the European Commission. The REA cannot be held responsible for any use that may be made of the information this repository contains.
