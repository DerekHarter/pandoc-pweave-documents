# make variables and build product locations
PANDOC_FLAGS=
out := _out
cache := $(out)/.cache
build := $(out)/pdf
mkdir = @mkdir -p $(dir $@)

target-docs := $(addprefix $(build)/, $(docs))


# defines of commands and flags used by the build
define pdflatex
TEXINPUTS=".:$(cache):" pdflatex -output-directory="$(cache)" -interaction=nonstopmode -shell-escape -file-line-error $< | grep "Output"
endef

define biber
biber  $(basename $< .tex) | grep "Output"
endef

define rubber
rubber -m pdftex --inplace
endef

define make-depend
../scripts/deps.py $@ < $< > $(cache)/$*.d
endef


## List of all valid targets in this project:
## ------------------------------------------
## all        : by default generate all pdf documents in this repository.
##
.PHONY : all
all : $(target-docs)

## knit       : knit all documents, usually equivalent to make all, but a
##              useful target for adding commands in scripts to ensure we
##              are knitting the document(s)
##
.PHONY : knit
knit: $(target-docs)


$(cache)/%.tex : %.pmd
	@echo "\n\n"
        
	@echo "************ Weaving Markdown: $< **************"
	$(mkdir)
	pweave -f texminted -o $(cache)/$*.md $<
	pandoc $(PANDOC_FLAGS) -o $@ $(cache)/$*.md
	$(make-depend)

$(cache)/%.bib : %.bib
	$(mkdir)
	cp $< $@

$(cache)/%.tex : %.tex
	$(mkdir)
	cp $< $@
	$(make-depend)

$(cache)/%.png : %.png
	$(mkdir)
	cp $< $@

$(cache)/%.sty : %.sty
	$(mkdir)
	cp $< $@

$(cache)/%.cls : %.cls
	$(mkdir)
	cp $< $@

$(build)/%.pdf : $(cache)/%.tex
	@echo "\n\n"
	@echo "************ Building PDF: $@ **************"
	$(mkdir)
	#$(rubber) $<
	$(pdflatex)
	$(biber)
	$(pdflatex)
	$(pdflatex)
	cp $(cache)/$*.pdf $@
	cp $(cache)/$*.pdf $*.pdf


## clean      : Remove auto-generated files for a completely clean rebuild.
##
.PHONY : clean
clean  :
	rm -rf $(out)
	rm -f *.pdf


## help       : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' ../include/Makefile.inc $<
