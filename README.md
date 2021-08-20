# Benchmark for high-performance algorithms in adaptive optics control
[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.5171804.svg)](https://doi.org/10.5281/zenodo.5171804)

## Summary
This benchmark can be used for applications in high-performance computing for adaptive optics control. 

## Description
This is a reduced benchmark case, which implements the MVM algorithm widely used for performing adaptive optics for extremely large telescopes. Reduced refers here to a smaller problem size. Since the MVM algorithms is a matrix-based method, the input files may become very large. Thus, we assume here a smaller problem size to reduce the dimension of matrices involved. Note that the source files are working for a larger problem size as well. For a detailed step-by-step description we refer to the PDF document in the documentation directory of this repository.

## Directory structure
In the directory source you can find all source files required to run the benchmark test. The directory benchmark contains the input and output data for the specific example. In the directory documentation you can find a PDf file with a detailed step-by-step description of the benchmark case.

## Disclaimer
In downloading this SOFTWARE you are deemed to have read and agreed to the following terms:
This SOFTWARE has been designed with an exclusive focus on civil applications. It is not to be used
for any illegal, deceptive, misleading or unethical purpose or in any military applications. This includes ANY APPLICATION WHERE THE USE OF THE SOFTWARE MAY RESULT IN DEATH,
PERSONAL INJURY OR SEVERE PHYSICAL OR ENVIRONMENTAL DAMAGE. Any redistribution of the software must retain this disclaimer. BY INSTALLING, COPYING, OR OTHERWISE
USING THE SOFTWARE, YOU AGREE TO THE TERMS ABOVE. IF YOU DO NOT AGREE TO
THESE TERMS, DO NOT INSTALL OR USE THE SOFTWARE

## Acknowledgments
<img src="/images/EU_Flag.png" alt="EU Flag"  width="150" height="100" />
The ROMSOC project has received funding from the European Union’s Horizon 2020 research and innovation programme under the Marie Skłodowska-Curie Grant Agreement No. 765374.
This repository reflects the views of the author(s) and does not necessarily reflect the views or policy of the European Commission. The REA cannot be held responsible for any use that may be made of the information this repository contains.
