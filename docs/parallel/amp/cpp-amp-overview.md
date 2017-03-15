---
title: "Vis&#227;o geral do C++ AMP | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C++ Accelerated Massive Parallelism, requisitos"
  - "C++ Accelerated Massive Parallelism, arquitetura"
  - "C++ AMP"
  - "C++ Accelerated Massive Parallelism, visão geral"
  - "C++ Accelerated Massive Parallelism"
ms.assetid: 9e593b06-6e3c-43e9-8bae-6d89efdd39fc
caps.latest.revision: 60
caps.handback.revision: 60
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vis&#227;o geral do C++ AMP
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

C++ Accelerated Massive Parallelism (C++ AMP) acelera a execução de código C++, tirando proveito do hardware de paralelismo de dados, como uma unidade de processamento gráfico (GPU) em uma placa gráfica discreta. Usando C++ AMP, você pode codificar os algoritmos de dados multidimensional para que a execução pode ser acelerada com o uso de paralelismo em hardware heterogêneo. O modelo de programação do C++ AMP inclui matrizes multidimensionais, indexação, transferência de memória, lado a lado e uma biblioteca de funções matemáticas. Você pode usar extensões de linguagem C++ AMP para controlar como os dados são movidos da CPU para a GPU e de volta, de forma que você pode melhorar o desempenho.  
  
## <a name="system-requirements"></a>Requisitos do sistema  
  
- [!INCLUDE[win7](../../build/includes/win7_md.md)], [!INCLUDE[win8](../../build/includes/win8_md.md)], [!INCLUDE[winsvr08_r2](../Token/winsvr08_r2_md.md)] ou [!INCLUDE[winserver8](../../build/includes/winserver8_md.md)]  
  
-   DirectX 11 recurso nível 11.0 ou hardware mais recente  
  
-   Para depurar no emulador de software, [!INCLUDE[win8](../../build/includes/win8_md.md)] ou [!INCLUDE[winserver8](../../build/includes/winserver8_md.md)] é necessário. Para depurar no hardware, você deve instalar os drivers para a sua placa gráfica. Para obter mais informações, consulte [depurando código de GPU](../Topic/Debugging%20GPU%20Code.md).  
  
## <a name="introduction"></a>Introdução  
 Os exemplos a seguir ilustram os principais componentes do C++ AMP. Suponha que você deseja adicionar os elementos correspondentes das duas matrizes unidimensionais. Por exemplo, você talvez queira adicionar `{1, 2, 3, 4, 5}` e `{6, 7, 8, 9, 10}` para obter `{7, 9, 11, 13, 15}`. Sem o uso de C++ AMP, você pode escrever o código a seguir para adicionar os números e exibir os resultados.  
  
```cpp  
  
#include <iostream>  
  
void StandardMethod() {  
  
    int aCPP[] = {1, 2, 3, 4, 5};  
    int bCPP[] = {6, 7, 8, 9, 10};  
    int sumCPP[5];  
  
    for (int idx = 0; idx < 5; idx++)  
    {  
        sumCPP[idx] = aCPP[idx] + bCPP[idx];  
    }  
  
    for (int idx = 0; idx < 5; idx++)  
    {  
        std::cout << sumCPP[idx] << "\n";  
    }  
}  
  
```  
  
 As partes importantes do código são da seguinte maneira:  
  
-   Dados: Os dados consistem em três matrizes. Todos têm a mesma classificação (um) e comprimento (cinco).  
  
-   Iteração: A primeira `for` loop fornece um mecanismo para iterar através dos elementos nas matrizes. O código que você deseja executar para calcular somas está contido no primeiro `for` bloco.  
  
-   Índice: O `idx` variável acessa os elementos individuais das matrizes.  
  
 Usando C++ AMP, você pode escrever o código a seguir em vez disso.  
  
```cpp  
  
#include <amp.h>  
#include <iostream>  
using namespace concurrency;  
  
const int size = 5;  
  
void CppAmpMethod() {  
    int aCPP[] = {1, 2, 3, 4, 5};  
    int bCPP[] = {6, 7, 8, 9, 10};  
    int sumCPP[size];  
  
    // Create C++ AMP objects.  
    array_view<const int, 1> a(size, aCPP);  
    array_view<const int, 1> b(size, bCPP);  
    array_view<int, 1> sum(size, sumCPP);  
    sum.discard_data();  
  
    parallel_for_each(   
        // Define the compute domain, which is the set of threads that are created.  
        sum.extent,   
        // Define the code to run on each thread on the accelerator.  
 [=](index<1> idx) restrict(amp)  
    {  
        sum[idx] = a[idx] + b[idx];  
    }  
    );  
  
    // Print the results. The expected output is "7, 9, 11, 13, 15".  
    for (int i = 0; i < size; i++) {  
        std::cout << sum[i] << "\n";  
    }  
}  
  
```  
  
 Os mesmos elementos básicos estão presentes, mas o C++ AMP construções são usadas:  
  
-   Dados: Você usar matrizes C++ para construir três C++ AMP [array_view](../../parallel/amp/reference/array-view-class.md) objetos. Você fornece quatro valores para construir uma `array_view` objeto: os valores de dados, a classificação, o tipo de elemento e o comprimento do `array_view` objeto em cada dimensão. A classificação e tipo são passados como parâmetros de tipo. Os dados e comprimento são passados como parâmetros do construtor. Neste exemplo, a matriz de C++ que é passada para o construtor é unidimensional. A classificação e comprimento são usados para construir a forma retangular dos dados de `array_view` objeto e os valores são usados para preencher a matriz de dados. A biblioteca de tempo de execução também inclui o [classe array](../../parallel/amp/reference/array-class.md), que tem uma interface semelhante a `array_view` classe e é abordado neste artigo.  
  
-   Iteração: O [função parallel_for_each (C++ AMP)](../Topic/parallel_for_each%20Function%20\(C++%20AMP\).md) fornece um mecanismo para iterar através dos elementos de dados, ou *computação domínio*. Neste exemplo, o domínio de computação é especificado por `sum.extent`. O código que você deseja executar está contido em uma expressão lambda, ou *função de kernel*. O `restrict(amp)` indica que somente o subconjunto da linguagem C++ que pode acelerar o C++ AMP é usado.  
  
-   Índice: O [classe index](../../parallel/amp/reference/index-class.md) variável, `idx`, é declarada com um para coincidir com a ordem de classificação de `array_view` objeto. Usando o índice, você pode acessar os elementos individuais do `array_view` objetos.  
  
## <a name="shaping-and-indexing-data-index-and-extent"></a>Dados de formatação e indexação: índice e a extensão  
 Você deve definir os valores de dados e declarar a forma dos dados antes de executar o código do kernel. Todos os dados é definido para ser uma matriz (retangular), e você pode definir a matriz para que qualquer classificação (número de dimensões). Os dados podem ser de qualquer tamanho em qualquer uma das dimensões.  
  
### <a name="index-class"></a>Classe index  
 O [classe index](../../parallel/amp/reference/index-class.md) Especifica um local de `array` ou `array_view` objeto, encapsulando o deslocamento da origem em cada dimensão em um único objeto. Quando você acessa um local na matriz, você passa uma `index` objeto para o operador de indexação, `[]`, em vez de uma lista de índices de inteiro. Você pode acessar os elementos em cada dimensão usando o [array:: Operator () operador](../Topic/array::operator\(\)%20Operator.md) ou o [array_view::operator() operador](../Topic/array_view::operator\(\)%20Operator.md).  
  
 O exemplo a seguir cria um índice unidimensional que especifica o terceiro elemento em um unidimensional `array_view` objeto. O índice é usado para imprimir o terceiro elemento o `array_view` objeto. A saída é 3.  
  
```cpp  
 
int aCPP[] = {1, 2, 3, 4, 5};  
array_view<int, 1> a(5, aCPP);

index<1> idx(2);

std::cout <<a[idx] <<"\n";    
// Output: 3  
 
```  
  
 O exemplo a seguir cria um índice bidimensional que especifica o elemento em que a linha = 1 e a coluna = 2 em um bidimensional `array_view` objeto. O primeiro parâmetro no `index` construtor é o componente de linha e o segundo parâmetro é o componente de coluna. A saída é 6.  
  
```cpp  
 
int aCPP[] = {1, 2, 3,  
    4, 5, 6};  
array_view<int, 2> a(2, 3, aCPP);

index<2> idx(1, 2);

std::cout <<a[idx] <<"\n";  
// Output: 6  
 
```  
  
 O exemplo a seguir cria um índice tridimensional que especifica o elemento onde a profundidade = 0, a linha = 1 e a coluna = 3 em um tridimensional `array_view` objeto. Observe que o primeiro parâmetro é o componente de profundidade, o segundo parâmetro é o componente de linha e o terceiro parâmetro é o componente de coluna. A saída é 8.  
  
```cpp  
 
int aCPP[] = {  
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,   
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};  
 
array_view<int, 3> a(2, 3, 4, aCPP);

// Specifies the element at 3, 1, 0.  
index<3> idx(0, 1, 3);

std::cout <<a[idx] <<"\n";  
 
// Output: 8  
 
```  
  
### <a name="extent-class"></a>Classe extent  
 O [classe extent](../Topic/extent%20Class%20\(C++%20AMP\).md) Especifica o comprimento dos dados em cada dimensão do `array` ou `array_view` objeto. Você pode criar uma extensão e usá-lo para criar um `array` ou `array_view` objeto. Você também pode recuperar a extensão de um objeto existente `array` ou `array_view` objeto. O exemplo a seguir imprime o comprimento da extensão em cada dimensão de uma `array_view` objeto.  
  
```cpp  
 
int aCPP[] = {  
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,   
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};  
// There are 3 rows and 4 columns, and the depth is two.  
array_view<int, 3> a(2, 3, 4, aCPP);

std::cout <<"The number of columns is " <<a.extent[2] <<"\n";  
std::cout <<"The number of rows is " <<a.extent[1] <<"\n";  
std::cout <<"The depth is " <<a.extent[0]<<"\n";  
std::cout <<"Length in most significant dimension is " <<a.extent[0] <<"\n";  
 
```  
  
 O exemplo a seguir cria um `array_view` dimensões do objeto que tem o mesmo como o objeto no exemplo anterior, mas este exemplo usa uma `extent` objeto em vez de usar parâmetros explícitos no `array_view` construtor.  
  
```cpp  
 
int aCPP[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};  
extent<3> e(2, 3, 4);

array_view<int, 3> a(e, aCPP);

std::cout <<"The number of columns is " <<a.extent[2] <<"\n";  
std::cout <<"The number of rows is " <<a.extent[1] <<"\n";  
std::cout <<"The depth is " <<a.extent[0] <<"\n";  
 
```  
  
## <a name="moving-data-to-the-accelerator-array-and-arrayview"></a>Mover dados para o acelerador: matriz e array_view  
 Dois contêineres de dados usados para mover dados para o acelerador são definidos na biblioteca de tempo de execução. Eles são o [classe array](../../parallel/amp/reference/array-class.md) e o [classe array_view](../../parallel/amp/reference/array-view-class.md). O `array` é uma classe de contêiner que cria uma cópia profunda dos dados quando o objeto é construído. O `array_view` é uma classe wrapper que copia os dados quando a função de kernel acessa os dados. Quando os dados são necessários no dispositivo de origem de dados são copiados de volta.  
  
### <a name="array-class"></a>Classe array  
 Quando um `array` objeto é criado, uma cópia em profundidade dos dados é criada no Acelerador de se você usar um construtor que inclui um ponteiro para o conjunto de dados. A função de kernel modifica a cópia do Accelerator. Quando a execução da função de kernel estiver concluída, você deve copiar os dados para a estrutura da fonte de dados. O exemplo a seguir multiplica cada elemento em um vetor por 10. Após a função de kernel, [conversão vetor operador] – brokenlink – (... /Topic/array::Operator%20std::Vector%3Cvalue_type%3E%20Operator.MD)is usado para copiar os dados de volta para o objeto de vetor.  
  
```cpp  
 
std::vector<int> data(5);

for (int count = 0; count <5; count++)   
{  
    data[count] = count;  
}  
 
array<int, 1> a(5, data.begin(), data.end());

 
parallel_for_each(
    a.extent, 
 [=, &a](index<1> idx) restrict(amp)  
 {  
    a[idx] = a[idx]* 10;  
 });

 
data = a;  
for (int i = 0; i <5; i++)   
{  
    std::cout <<data[i] <<"\n";  
}  
 
```  
  
### <a name="arrayview-class"></a>Classe array_view  
 O `array_view` tem aproximadamente os mesmos membros como o `array` classe, mas o comportamento básico não é o mesmo. Os dados passados para o `array_view` construtor não é replicado na GPU, como em um `array` construtor. Em vez disso, os dados são copiados para o Acelerador de quando a função de kernel é executada. Portanto, se você criar dois `array_view` objetos que usam os mesmos dados, ambos `array_view` objetos se referem ao mesmo espaço de memória. Quando você fizer isso, você precisa sincronizar qualquer acesso de vários threads. A principal vantagem de usar o `array_view` classe é que os dados são movidos somente se for necessário.  
  
### <a name="comparison-of-array-and-arrayview"></a>Comparação de matriz e array_view  
 A tabela a seguir resume as semelhanças e diferenças entre a `array` e `array_view` classes.  
  
|Descrição|Classe Array|Classe array_view|  
|-----------------|-----------------|-----------------------|  
|Quando a classificação é determinada|Em tempo de compilação.|Em tempo de compilação.|  
|Quando o limite é determinado|Em tempo de execução.|Em tempo de execução.|  
|Forma|Retangular.|Retangular.|  
|Armazenamento de dados|É um contêiner de dados.|É um wrapper de dados.|  
|Copiar|Cópia explícita e profunda na definição.|Cópia implícita quando ele é acessado pela função de kernel.|  
|Recuperação de dados|Copiando dados da matriz para um objeto no thread da CPU.|Por acesso direto do `array_view` do objeto ou chamando o [método array_view:: Synchronize](../Topic/array_view::synchronize%20Method.md) continuar acessando os dados no contêiner original.|  
  
### <a name="shared-memory-with-array-and-arrayview"></a>Memória compartilhada com matriz e array_view  
 Memória compartilhada é a memória que pode ser acessada pela CPU e o acelerador. O uso de memória compartilhada elimina ou reduz significativamente a sobrecarga de cópia de dados entre a CPU e o acelerador. Embora a memória for compartilhada, não pode ser acessada simultaneamente por CPU e o acelerador, e isso fizer um comportamento indefinido.  
  
 `array` objetos podem ser usados para especificar um controle refinado sobre o uso de memória compartilhada se o acelerador associado dá suporte a ela. Se um Acelerador oferece suporte a memória compartilhada é determinada pelo Acelerador [supports_cpu_shared_memory](../Topic/accelerator::supports_cpu_shared_memory%20Data%20Member.md) propriedade, que retorna `true` quando a memória compartilhada é suportada. Se houver suporte para memória compartilhada, o padrão [enumeração access_type](../Topic/access_type%20Enumeration.md) memória alocações do Accelerator é determinado pelo `default_cpu_access_type` propriedade. Por padrão, `array` e `array_view` objetos assumem o mesmo `access_type` primário associado `accelerator`.  
  
 Definindo o [array:: cpu_access_type membro de dados](../Topic/array::cpu_access_type%20Data%20Member.md) propriedade de um `array` explicitamente, você pode exercício refinado de controle sobre memória compartilhada como é usado, para que você possa otimizar o aplicativo para características de desempenho do hardware, com base nos padrões de acesso de memória de seus kernels de computação. Um `array_view` reflete o mesmo `cpu_access_type` como o `array` que ele está associado; ou, se o array_view for criada sem uma fonte de dados, seu `access_type` reflete o ambiente que primeiro faz com que ele alocar armazenamento. Ou seja, se ele for acessado pela primeira vez pelo host (CPU), em seguida, ele se comporta como se ele foram criado em uma fonte de dados de CPU e compartilhamentos do `access_type` do `accelerator_view` associado por captura; no entanto, se ele for o primeiro acessado por um `accelerator_view`, e em seguida, ele se comporta como se ele foi criado sobre uma `array` criado em que `accelerator_view` e compartilha a `array`do `access_type`.  
  
 O exemplo de código a seguir mostra como determinar se o acelerador padrão dá suporte à memória compartilhada e, em seguida, cria várias matrizes que têm configurações diferentes de cpu_access_type.  
  
```cpp  
#include <amp.h>  
#include <iostream>  
  
using namespace Concurrency;  
  
int main()  
{  
  accelerator acc = accelerator(accelerator::default_accelerator);  
  
  // Early out if the default accelerator doesn’t support shared memory.  
  if (!acc.supports_cpu_shared_memory)  
  {  
    std::cout << "The default accelerator does not support shared memory" << std::endl;  
    return 1;  
  }  
  
  // Override the default CPU access type.  
  acc.default_cpu_access_type = access_type_read_write  
  
  // Create an accelerator_view from the default accelerator. The  
  // accelerator_view inherits its default_cpu_access_type from acc.  
  accelerator_view acc_v = acc.default_view;  
  
  // Create an extent object to size the arrays.  
  extent<1> ex(10);  
  
  // Input array that can be written on the CPU.  
  array<int, 1> arr_w(ex, acc_v, access_type_write);  
  
  // Output array that can be read on the CPU.  
  array<int, 1> arr_r(ex, acc_v, access_type_read);  
  
  // Read-write array that can be both written to and read from on the CPU.  
  array<int, 1> arr_rw(ex, acc_v, access_type_read_write);  
}  
  
```  
  
## <a name="executing-code-over-data-parallelforeach"></a>Executar código em dados: parallel_for_each  
 O [parallel_for_each](../Topic/parallel_for_each%20Function%20\(C++%20AMP\).md) função define o código que você deseja executar no Acelerador em relação aos dados na `array` ou `array_view` objeto. Considere o seguinte código contra a introdução deste tópico.  
  
```cpp  
  
#include <amp.h>  
#include <iostream>  
using namespace concurrency;  
  
void AddArrays() {  
    int aCPP[] = {1, 2, 3, 4, 5};  
    int bCPP[] = {6, 7, 8, 9, 10};  
    int sumCPP[5] = {0, 0, 0, 0, 0};  
  
    array_view<int, 1> a(5, aCPP);  
    array_view<int, 1> b(5, bCPP);  
    array_view<int, 1> sum(5, sumCPP);  
  
    parallel_for_each(  
        sum.extent,   
 [=](index<1> idx) restrict(amp)  
        {  
            sum[idx] = a[idx] + b[idx];  
        }  
    );  
  
    for (int i = 0; i < 5; i++) {  
        std::cout << sum[i] << "\n";  
    }  
}  
  
```  
  
 O `parallel_for_each` método utiliza dois argumentos, um domínio de computação e uma expressão lambda.  
  
 O *computação domínio* é um `extent` objeto ou um `tiled_extent` objeto que define o conjunto de threads para criar para execução paralela. Um thread é gerado para cada elemento no domínio de computação. Nesse caso, o `extent` objeto é unidimensional e possui cinco elementos. Portanto, cinco threads são iniciados.  
  
 O *expressão lambda* define o código seja executado em cada segmento. A cláusula de captura, `[=]`, especifica que o corpo da expressão lambda acessará todas as variáveis capturadas por valor, que nesse caso, são `a`, `b`, e `sum`. Neste exemplo, a lista de parâmetros cria um unidimensional `index` variável chamada `idx`. O valor de `idx[0]` é 0 no thread de primeiro e aumenta em um em cada segmento subsequente. O `restrict(amp)` indica que somente o subconjunto da linguagem C++ que pode acelerar o C++ AMP é usado.  As limitações em funções que têm o modificador restringir descritas [restrict (C++ AMP)](../../cpp/restrict-cpp-amp.md). Para obter mais informações, consulte, [sintaxe da expressão Lambda](../../cpp/lambda-expression-syntax.md).  
  
 A expressão lambda pode incluir o código para executar ou ele pode chamar uma função de kernel separado. A função de kernel deve incluir o `restrict(amp)` modificador. O exemplo a seguir é equivalente ao exemplo anterior, mas ele chama uma função de kernel separado.  
  
```cpp  
  
#include <amp.h>  
#include <iostream>  
using namespace concurrency;  
  
void AddElements(index<1> idx, array_view<int, 1> sum, array_view<int, 1> a, array_view<int, 1> b) restrict(amp)  
{  
    sum[idx] = a[idx] + b[idx];  
}  
  
void AddArraysWithFunction() {  
  
    int aCPP[] = {1, 2, 3, 4, 5};  
    int bCPP[] = {6, 7, 8, 9, 10};  
    int sumCPP[5] = {0, 0, 0, 0, 0};  
  
    array_view<int, 1> a(5, aCPP);  
    array_view<int, 1> b(5, bCPP);  
    array_view<int, 1> sum(5, sumCPP);  
  
    parallel_for_each(  
        sum.extent,   
 [=](index<1> idx) restrict(amp)  
        {  
            AddElements(idx, sum, a, b);  
        }  
    );  
  
    for (int i = 0; i < 5; i++) {  
        std::cout << sum[i] << "\n";  
    }  
}  
  
```  
  
## <a name="accelerating-code-tiles-and-barriers"></a>Acelerando código: Blocos e barreiras  
 Você pode obter aceleração adicional usando lado a lado. Lado a lado divide os threads em subconjuntos retangulares iguais ou *peças*. Determinar o tamanho de bloco apropriado com base no seu conjunto de dados e o algoritmo que você está codificando. Para cada thread, você tem acesso ao *global* local de um elemento de dados em relação a todo o `array` ou `array_view` e acesso a *local* local relativo no bloco. Usando o valor de índice local simplifica o código porque você não precisa escrever o código para converter valores de índice de global para local. Para usar lado a lado, chamar o [método Extent:: Tile](../Topic/extent::tile%20Method.md) pelo domínio de computação no `parallel_for_each` método e usar um [tiled_index](../../parallel/amp/reference/tiled-index-class.md) objeto na expressão lambda.  
  
 Em aplicativos típicos, os elementos em um bloco são relacionados de alguma maneira e o código tem de acessar e controlar valores em bloco. Use o [palavra-chave tile_static](../Topic/tile_static%20Keyword.md) palavra-chave e o [método tile_barrier:: wait](../Topic/tile_barrier::wait%20Method.md) para fazer isso. Uma variável que possui o `tile_static` palavra-chave tem um escopo em um bloco inteiro e uma instância da variável é criada para cada peça. Você deve tratar a sincronização de thread de bloco acesso à variável. O [método tile_barrier:: wait](../Topic/tile_barrier::wait%20Method.md) interrompe a execução do thread atual até que todos os threads no bloco tem atingido a chamada para `tile_barrier::wait`. Portanto você pode acumular valores entre a lado a lado usando `tile_static` variáveis. Em seguida, você pode concluir qualquer computações que exigem acesso a todos os valores.  
  
 O diagrama a seguir representa uma matriz bidimensional de amostragem de dados que são organizados em blocos.  
  
 ![Valores de índice em uma extensão lado a lado](../../parallel/amp/media/camptiledgridexample.png "CampTiledGridExample")  
  
 O exemplo de código a seguir usa os dados de amostragem do diagrama anterior. O código substitui cada valor no bloco pela média dos valores no bloco.  
  
```cpp  
 
// Sample data:  
int sampledata[] = {  
    2, 2, 9, 7, 1, 4,  
    4, 4, 8, 8, 3, 4,  
    1, 5, 1, 2, 5, 2,  
    6, 8, 3, 2, 7, 2};  
 
// The tiles:  
// 2 2    9 7    1 4  
// 4 4    8 8    3 4  
//  
// 1 5    1 2    5 2  
// 6 8    3 2    7 2  
 
// Averages:  
int averagedata[] = {   
    0, 0, 0, 0, 0, 0,   
    0, 0, 0, 0, 0, 0,   
    0, 0, 0, 0, 0, 0,   
    0, 0, 0, 0, 0, 0,   
};  
 
array_view<int, 2> sample(4, 6, sampledata);

array_view<int, 2> average(4, 6, averagedata);

 
parallel_for_each(*// Create threads for sample.extent and divide the extent into 2 x 2 tiles.  
    sample.extent.tile<2,2>(), 
 [=](tiled_index<2,2> idx) restrict(amp)  
 { *// Create a 2 x 2 array to hold the values in this tile.  
    tile_static int nums[2][2]; *// Copy the values for the tile into the 2 x 2 array.  
    nums[idx.local[1]][idx.local[0]] = sample[idx.global]; *// When all the threads have executed and the 2 x 2 array is complete, find the average.  
    idx.barrier.wait();
int sum = nums[0][0] + nums[0][1] + nums[1][0] + nums[1][1]; *// Copy the average into the array_view.  
    average[idx.global] = sum / 4;  
 });

 
for (int i = 0; i <4; i++) {  
    for (int j = 0; j <6; j++) {  
    std::cout <<average(i,j) <<" ";  
 }  
    std::cout <<"\n";  
}  
 
// Output:  
// 3 3 8 8 3 3  
// 3 3 8 8 3 3  
// 5 5 2 2 4 4  
// 5 5 2 2 4 4  
 
```  
  
## <a name="math-libraries"></a>Bibliotecas matemáticas  
 C++ AMP inclui duas bibliotecas matemáticas. A biblioteca de precisão dupla no [Namespace Concurrency:: precise_math](../Topic/Concurrency::precise_math%20Namespace.md) fornece suporte para funções de precisão dupla. Ele também fornece suporte para funções de precisão simples, embora o suporte de precisão dupla no hardware ainda é necessária. Ele é compatível com o [especificação C99 (ISO/IEC 9899)](http://go.microsoft.com/fwlink/LinkId=225887). O acelerador deve oferecer suporte a precisão dupla completo. Você pode determinar se ele faz verificando o valor da [Accelerator:: supports_double_precision membro de dados](../Topic/accelerator::supports_double_precision%20Data%20Member.md). A biblioteca de matemática rápida, além de [Namespace Concurrency:: fast_math](../../parallel/amp/reference/concurrency-fast-math-namespace.md), contém outro conjunto de funções matemáticas. Essas funções, que oferece suporte a apenas `float` operandos, executadas mais rapidamente, mas não são tão precisos quanto aqueles na biblioteca de matemática de precisão dupla. As funções estão contidas no arquivo de cabeçalho \< amp_math. h > e todas são declaradas com `restrict(amp)`. As funções de \< cmath> arquivo de cabeçalho são importados para ambos o `fast_math` e `precise_math` namespaces. O `restrict` palavra-chave é usada para distinguir o \< cmath> versão e a versão do C++ AMP. O código a seguir calcula o logaritmo de base 10, usando o método rápido, de cada valor que está no domínio de computação.  
  
```cpp  
  
#include <amp.h>  
#include <amp_math.h>  
#include <iostream>  
using namespace concurrency;  
  
void MathExample() {  
  
    double numbers[] = { 1.0, 10.0, 60.0, 100.0, 600.0, 1000.0 };  
    array_view<double, 1> logs(6, numbers);  
  
    parallel_for_each(  
        logs.extent,  
 [=] (index<1> idx) restrict(amp) {  
            logs[idx] = concurrency::fast_math::log10(logs[idx]);  
        }  
    );  
  
    for (int i = 0; i < 6; i++) {  
        std::cout << logs[i] << "\n";  
    }  
}  
  
```  
  
## <a name="graphics-library"></a>Biblioteca de elementos gráficos  
 C++ AMP inclui uma biblioteca de elementos gráficos que se destina a programação de elementos gráficos acelerados. Essa biblioteca é usada somente em dispositivos que suportam a funcionalidade de gráficos nativa. Os métodos são no [Namespace Concurrency:: Graphics](../../parallel/amp/reference/concurrency-graphics-namespace.md) e estão contidos no arquivo de cabeçalho \< amp_graphics.h >. Os principais componentes da biblioteca de elementos gráficos são:  
  
- [Classe Texture](../Topic/texture%20Class.md): você pode usar a classe de textura para criar texturas de memória ou de um arquivo. Texturas se parecem com matrizes porque eles contêm dados, e lembram contêineres no modelo Biblioteca STL (Standard) em relação à atribuição e construção de cópia. Para obter mais informações, consulte [contêineres STL](../../standard-library/stl-containers.md). Os parâmetros de modelo para o `texture` classe são o tipo de elemento e a classificação. A classificação pode ser 1, 2 ou 3. O tipo de elemento pode ser um dos tipos de vetor curto descritos neste artigo.  
  
- [Classe writeonly_texture_view](../Topic/writeonly_texture_view%20Class.md): fornece acesso somente leitura a qualquer textura.  
  
- [Curto vetor biblioteca](http://msdn.microsoft.com/pt-br/4c4f5bed-c396-493b-a238-c347563f645f): define um conjunto de tipos de vetor curto de comprimento 2, 3 e 4 se baseiam em `int`, `uint`, `float`, `double`, [norma](../../parallel/amp/reference/norm-class.md), ou [unorm](../../parallel/amp/reference/unorm-class.md).  
  
## <a name="includewin8appnamelongtokenwin8appnamelongmdmd-apps"></a>[!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] Aplicativos  
 Como outras bibliotecas do C++, você pode usar C++ AMP em seu [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos. Esses artigos descrevem como incluir código C++ AMP em aplicativos criados usando o C++, c#, Visual Basic ou JavaScript:  
  
- [Usando C++ AMP em aplicativos da Windows Store](../../parallel/amp/using-cpp-amp-in-windows-store-apps.md)  
  
- [Passo a passo: Criando um componente de tempo de execução do Windows básico em C++ e chamando-o em JavaScript](http://go.microsoft.com/fwlink/p/LinkId=249077)  
  
- [Bing Maps Trip Optimizer, um aplicativo da Windows Store em JavaScript e C++](http://go.microsoft.com/fwlink/p/LinkId=249078)  
  
- [Como usar o C++ AMP em c# usando o tempo de execução do Windows](http://go.microsoft.com/fwlink/p/LinkId=249080)  
  
- [Como usar o C++ AMP do c#](http://go.microsoft.com/fwlink/p/LinkId=249081)  
  
- [Chamando funções nativas a partir do código gerenciado](../../dotnet/calling-native-functions-from-managed-code.md)  
  
## <a name="c-amp-and-concurrency-visualizer"></a>C++ AMP e Visualizador de simultaneidade  
 O Visualizador de simultaneidade inclui suporte para analisar o desempenho do código C++ AMP. Esses artigos descrevem esses recursos:  
  
- [Gráfico de atividade de GPU](../Topic/GPU%20Activity%20Graph.md)  
  
- [Atividade de GPU (paginação)](../Topic/GPU%20Activity%20\(Paging\).md)  
  
- [Atividade de GPU (este processo)](../Topic/GPU%20Activity%20\(This%20Process\).md)  
  
- [Atividade de GPU (outros processos)](../Topic/GPU%20Activity%20\(Other%20Processes\).md)  
  
- [Canais (exibição Threads)](../Topic/Channels%20\(Threads%20View\).md)  
  
- [Analisando código do C++ AMP com o Visualizador de simultaneidade](http://go.microsoft.com/fwlink/LinkID=253987&clcid=0x409)  
  
## <a name="performance-recommendations"></a>Recomendações de desempenho  
 Divisão de inteiros não assinados e módulo tem desempenho significativamente melhor do que o módulo e a divisão de inteiros com sinal. É recomendável que você use inteiros sem sinal, quando possível.  
  
## <a name="see-also"></a>Consulte também  
 [C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)   
 [Sintaxe da expressão lambda](../../cpp/lambda-expression-syntax.md)   
 [Referência (C++ AMP)](../../parallel/amp/reference/reference-cpp-amp.md)   
 [Programação paralela no Blog de código nativo](http://go.microsoft.com/fwlink/p/LinkId=238472)
