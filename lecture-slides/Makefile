# The target document(s) built in this project
docs = u01-memory-caching.pdf

include ../include/Makefile.inc


# project global targets
project-bibs :=
$(cache)/%.tex : PANDOC_FLAGS+=--to=beamer --standalone --dpi=300

## u01-memory-caching.pdf
##            : Generate the u01-memory-caching lecture slides.
##
u01-memory-caching-docs := u01-memory-caching.tex
u01-memory-caching-figures :=
u01-memory-caching-src := $(u01-memory-caching-docs) $(u01-memory-caching-figures) $(project-bibs)
u01-memory-caching-dest := $(addprefix $(cache)/, $(u01-memory-caching-src))
$(build)/u01-memory-caching.pdf : $(u01-memory-caching-dest)
