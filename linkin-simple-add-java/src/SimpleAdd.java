import java.io.*;
import java.util.Objects;

/**
 * SimpleAdd
 * 计算简单整数加法
 *
 * @author hengyumo
 * @version 1.0
 * @since 2020/2/19
 */
public class SimpleAdd {

    public static void main(String[] args) throws IOException {
        // -input input1.txt -output output.txt
        File input = null, output = null;
        for (int i = 0; i < args.length; i++) {
            switch (args[i]) {
                case "-input":
                    input = new File(args[++i]);
                    break;
                case "-output":
                    output = new File(args[++i]);
                    break;
                default:
                    System.out.println("不支持的选项");
                    System.exit(1);
            }
        }
        Objects.requireNonNull(input);
        Objects.requireNonNull(output);
        try (BufferedReader reader = new BufferedReader(new FileReader(input));
             BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
            String line = reader.readLine();
            StringBuilder result = new StringBuilder();
            while (line != null) {
                String[] params = line.split("\\+");
                int sum = 0;
                for (String param : params) {
                    sum += Integer.parseInt(param);
                }
                result.append(sum).append('\n');
                line = reader.readLine();
            }
            writer.write(result.toString());
        }
    }
}
