import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MergeSort {
    public static void main(String[] args) {
        String nomeArquivo = null; 
        String caminhoArquivoEntrada = System.getProperty("user.dir") + "/../inputs/int_aleatorio1";
        String caminhoArquivoSaida = System.getProperty("user.dir") + "/../output/int_Bubble_java";
        try {
            BufferedReader br = new BufferedReader(new FileReader(caminhoArquivoEntrada));
            List<Integer> vetor = new ArrayList<>();
            nomeArquivo = br.readLine();
            String line;

            while ((line = br.readLine()) != null) {
                vetor.add(Integer.parseInt(line));
            }

            br.close();

            long inicio = System.currentTimeMillis();
            mergeSort(vetor);
            long fim = System.currentTimeMillis();

            System.out.println(vetor);

            try (FileWriter fw = new FileWriter(caminhoArquivoSaida, true)) {
                fw.write(nomeArquivo + "\n\tAlgoritmo de ordenacao: BubbleSort\n\tTempo de execucao: " + (fim - inicio) + " ms\n\tQuantidade de numeros: " + vetor.size() + "\n\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void mergeSort(List<Integer> vetor){
        int n = vetor.size();
        
    }
}
