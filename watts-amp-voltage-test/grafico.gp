# Imposta il percorso al file dati
datafile = "dati.csv"

# Imposta il separatore di colonne come virgola
set datafile separator ","

# Imposta il titolo del grafico e le etichette degli assi
set title "Andamento Volts e Ampere in funzione WattsOra"
set xlabel "WattsOra(Watts)"
set ylabel "Valore"

# Imposta l'intervallo di visualizzazione sull'asse x
set xrange [0:1000]

# Imposta l'intervallo di visualizzazione sull'asse y per Volts
set yrange [0:3.6]

# Imposta l'intervallo di visualizzazione sull'asse y per Ampere
set y2range [0:30]
set y2tics

# Imposta l'incremento sull'asse x
set xtics 100

# Traccia il grafico dei Volts nel tempo
plot datafile using 1:2 with lines lc rgb "blue" title "Volts", \
     datafile using 1:3 axes x1y2 with lines lc rgb "red" title "Ampere"


