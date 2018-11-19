Resultados_hw4.pdf: Resultados_hw4.tex 45.pdf OtrosAngulos.pdf
	pdflatex Resultados_hw4.tex
	rm Resultados_hw4.log
	rm Resultados_hw4.aux
	rm FronterasFijasInicial.pdf FronterasFijasAvance1.pdf FronterasFijasAvance2.pdf FronterasFijasEq.pdf FronterasFijasPromedio.pdf FronterasAbiertasInicial.pdf FronterasAbiertasAvance1.pdf FronterasAbiertasAvance2.pdf FronterasAbiertasEq.pdf FronterasAbiertasPromedio.pdf FronterasPeriodicasInicial.pdf FronterasPeriodicasAvance1.pdf FronterasPeriodicasAvance2.pdf FronterasPeriodicasEq.pdf FronterasPeriodicasPromedio.pdf temperaturaPromedio.pdf temperaturaPromedioLogarimtica.pdf 45.pdf OtrosAngulos.pdf
45.pdf: datos45.dat datos.dat 
	python3 Plots_hw4.py
	rm datos45.dat datos.dat DatosOtrosAngulos.dat angulo45.dat otrosAngulos.dat

datos45.dat: ODE.cpp
	g++ ODE.cpp
	./a.out
	rm a.out

datos.dat: PDE.cpp
	g++ PDE.cpp
	./a.out
	rm a.out
