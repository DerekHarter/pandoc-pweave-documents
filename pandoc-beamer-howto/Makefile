# The target document(s) built in this project
docs = presentation.pdf

include ../include/Makefile.inc

SOURCE_FORMAT="markdown+pipe_tables+backtick_code_blocks+auto_identifiers+strikeout+yaml_metadata_block+implicit_figures+all_symbols_escapable+link_attributes+smart+fenced_divs"

DATA_DIR="pandoc"


# project global targets
project-bibs :=
$(cache)/%.tex : PANDOC_FLAGS+=--to=beamer --standalone --dpi=300 --slide-level 2 --toc --listings --shift-heading-level=0 --data-dir=${DATA_DIR} --template default_mod.latex -H pandoc/templates/preamble.tex -f ${SOURCE_FORMAT} -V classoption:aspectratio169

## presentation.pdf
##            : Generate the presentation lecture slides.
##
presentation-docs := presentation.tex
presentation-figures :=
presentation-src := $(presentation-docs) $(presentation-figures) $(project-bibs)
presentation-dest := $(addprefix $(cache)/, $(presentation-src))
$(build)/presentation.pdf : $(presentation-dest)
