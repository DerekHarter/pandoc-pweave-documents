# The target document(s) built in this project
docs = pweave-template.pdf

include ../include/Makefile.inc

## pweave-template.pdf
##            : Generate the pweave-template.pdf example from markdown/tex
##              templates.
##
pweave-template-docs := pweave-template.tex
pweave-template-bibs := pweave-template.bib
pweave-template-figures := figures/example-fig1.png
pweave-template-src := $(pweave-template-docs) $(pweave-template-bibs) $(pweave-template-figures)
pweave-template-dest := $(addprefix $(cache)/, $(pweave-template-src))
$(cache)/pweave-template.tex : PANDOC_FLAGS+=-s -N
$(build)/pweave-template.pdf : $(pweave-template-dest)
