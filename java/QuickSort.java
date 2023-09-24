import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class QuickSort {
    public static void main(String[] args) {
        String nomeArquivo = null; 
        String caminhoArquivoEntrada = System.getProperty("user.dir") + "/../inputs/int_decrescente/8_500000_10000000.txt";
        String caminhoArquivoSaida = System.getProperty("user.dir") + "/../output/int_QuickSort_java";
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
            quickSort(vetor,0,vetor.size()-1);
            long fim = System.currentTimeMillis();

            //System.out.println(vetor);

            try (FileWriter fw = new FileWriter(caminhoArquivoSaida, true)) {
                fw.write(nomeArquivo + "\n\tAlgoritmo de ordenacao: QuickSort\n\tTempo de execucao: " + (fim - inicio) + " ms\n\tQuantidade de numeros: " + vetor.size() + "\n\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void quickSort(List<Integer>vetor, int p,int r){
        if(p<r){
            int q = partition(vetor, p, r);
            quickSort(vetor, p, q-1);
            quickSort(vetor, q+1, r);
        }
    }

    public static int partition(List<Integer>vetor, int p, int r){
        int x = vetor.get(r);
        int i = (p - 1);
        int aux;
        for(int j = p; j < r;j++){
            if(vetor.get(j)<=x){
                i++;
                aux = vetor.get(i);
                vetor.set(i, vetor.get(j));
                vetor.set(j, aux);
            }
        }
        aux = vetor.get(i+1);
        vetor.set(i+1, vetor.get(r));
        vetor.set(r, aux);
        return i+1;
    }
}
