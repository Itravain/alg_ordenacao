import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class CountingSort {
    public static void main(String[] args) {
        String nomeArquivo = null; 
        String caminhoArquivoEntrada = System.getProperty("user.dir") + "/../inputs/int_aleatorio1";
        String caminhoArquivoSaida = System.getProperty("user.dir") + "/../output/int_Couting_java";
        try {
            BufferedReader br = new BufferedReader(new FileReader(caminhoArquivoEntrada));
            List<Integer> vetor = new ArrayList<>();
            List<Integer> vetor2 = new ArrayList<>();
            nomeArquivo = br.readLine();
            String line;

            while ((line = br.readLine()) != null) {
                vetor.add(Integer.parseInt(line));
            }

            br.close();

            long inicio = System.currentTimeMillis();
            int k = Collections.max(vetor);
            countingSort(vetor,vetor2, k);
            long fim = System.currentTimeMillis();

            System.out.println(vetor);

            try (FileWriter fw = new FileWriter(caminhoArquivoSaida, true)) {
                fw.write(nomeArquivo + "\n\tAlgoritmo de ordenacao: CoutingSort\n\tTempo de execucao: " + (fim - inicio) + " ms\n\tQuantidade de numeros: " + vetor.size() + "\n\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void countingSort(List<Integer>vetor, List<Integer>vetor2, int k){
        List<Integer> vetor3 = new ArrayList<>();
        int i;
        for (i = 0; i<k; k++){
            vetor3.add(0);
        }
        for (i = 0; i<(vetor.size()-1); i++){
            vetor3.set(vetor.get(i), vetor3.get(i)+1);
        }
        
    }
}
