# Pandoc / PWeave Documents

This repository contains examples of using pweave and pandoc tools to weave to LaTeX
documents, ultimately to create pdf output files, or possibly other types of output
formats in the future.

Slides, notes, handouts and simple paper formats are supported.  In all cases we try
and support pweave of programming languages such as Python and C/C++ so that code chunks
can be executed in documents, producing output in the documents, and in some cases
figures and diagrams (e.g. Python w/ matplotlib output).

Also the documents support LaTeX headings, numbering, equations, math mode and
bibliography generation in all of the example document types.  This allows to create
numbered table of contents, figures and equations in documents.  This also allows
use of Bibtex bibliography files to cite references in documents and automatically
generate bibliographies or references for the documents. 

## Getting Started

Example configuration for Ubuntu 21.10 are given in the bootstrap directory.
This installs needed python, pweave, pandoc, latex and build tools for these
document projects.  A Vagrantfile is provided to allow creation of
virtual vagrant box using official Ubuntu 21.10 image and this bootstrap file.

Most projects use a common Makefile build configuration, which common make targets
in the include subdirectory, and build targets and flags specific to the documents given
in each separate document Makefile.  Use

```
$ make help
```

to list all build targets.  The default build target should rebuild the document(s)
for the document type.  To rebuild a clean document do

```
$ make clean
$ make
```

