import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class CountingSort {
    public static void main(String[] args) throws IOException {
        String nomeArquivo = null; 
        String caminhoArquivoEntrada = System.getProperty("user.dir") + "/../inputs/int_95_ordenado/8_500000_10000000.txt";
        String caminhoArquivoSaida = System.getProperty("user.dir") + "/../output/int_Couting_java";
        try {
            BufferedReader br = new BufferedReader(new FileReader(caminhoArquivoEntrada));
            List<Integer> vetor = new ArrayList<>();
            List<Integer> vetor2 = new ArrayList<>();
            nomeArquivo = br.readLine();
            String line;

            while ((line = br.readLine()) != null) {
                vetor.add(Integer.parseInt(line));
                vetor2.add(0);
            }

            br.close();

            long inicio = System.currentTimeMillis();
            int k = Collections.max(vetor);
            countingSort(vetor,vetor2, k);
            long fim = System.currentTimeMillis();

            //System.out.println(vetor2);

            try (FileWriter fw = new FileWriter(caminhoArquivoSaida, true)) {
                fw.write(nomeArquivo + "\n\tAlgoritmo de ordenacao: CoutingSort\n\tTempo de execucao: " + (fim - inicio) + " ms\n\tQuantidade de numeros: " + vetor.size() + "\n\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void countingSort(List<Integer> vetorA, List<Integer> vetorB, int k) {
        List<Integer> vetorC = new ArrayList<>();
        for(int i = 0; i <=k; i++){
            vetorC.add(i,0);
        }
        for(int j = 0; j < vetorA.size(); j++){
            int value = vetorA.get(j);
            vetorC.set(value, vetorC.get(value) + 1);
        }
        for (int i = 1; i <= k; i++){
            vetorC.set(i, vetorC.get(i)+ vetorC.get(i-1));
        }
        for (int j = vetorA.size()-1; j >= 0; j--){
            int value = vetorA.get(j);
            int index = vetorC.get(value) - 1;
            vetorB.set(index, value);
            vetorC.set(value, vetorC.get(value) - 1);
        }
    }
}
