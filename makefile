all: TDTS07_labreport1.pdf

TDTS07_labreport1.pdf: TDTS07_labreport1.tex
	pdflatex TDTS07_labreport1.tex && \
	pdflatex TDTS07_labreport1.tex && \
	pdflatex TDTS07_labreport1.tex

clean:
	rm -f TDTS07_labreport1.toc TDTS07_labreport1.log TDTS07_labreport1.aux TDTS07_labreport1.pdf