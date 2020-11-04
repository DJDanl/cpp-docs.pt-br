---
title: Visão geral do C++ AMP
ms.date: 11/19/2018
helpviewer_keywords:
- C++ Accelerated Massive Parallelism, requirements
- C++ Accelerated Massive Parallelism, architecture
- C++ AMP
- C++ Accelerated Massive Parallelism, overview
- C++ Accelerated Massive Parallelism
ms.assetid: 9e593b06-6e3c-43e9-8bae-6d89efdd39fc
ms.openlocfilehash: 0eeda43a279be74ea71669b55356603e980cab40
ms.sourcegitcommit: d77159732a8e782b2a1b7abea552065f2b6f61c1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/04/2020
ms.locfileid: "93344742"
---
# <a name="c-amp-overview"></a>Visão geral do C++ AMP

A C++ Accelerated Massive Parallelism (C++ AMP) acelera a execução do código C++ aproveitando o hardware de dados paralelos, como uma GPU (unidade de processamento gráfico) em uma placa gráfica discreta. Usando C++ AMP, você pode codificar algoritmos de dados multidimensionais para que a execução possa ser acelerada usando paralelismo em hardware heterogêneo. O modelo de programação do C++ AMP inclui matrizes multidimensionais, indexação, transferência de memória, agrupamento lado a lado e uma biblioteca de funções matemáticas. Você pode usar C++ AMP extensões de idioma para controlar como os dados são movidos da CPU para a GPU e de volta, para que você possa melhorar o desempenho.

## <a name="system-requirements"></a>Requisitos do Sistema

- Windows 7 ou posterior

- Windows Server 2008 R2 ou posterior

- Nível de recurso do DirectX 11 11,0 ou hardware posterior

- Para depuração no emulador de software, o Windows 8 ou o Windows Server 2012 é necessário. Para depurar no hardware, você deve instalar os drivers para a sua placa gráfica. Para obter mais informações, consulte [depuração de código de GPU](/visualstudio/debugger/debugging-gpu-code).

- Observação: no momento, não há suporte para AMP no ARM64.

## <a name="introduction"></a>Introdução

Os dois exemplos a seguir ilustram os principais componentes do C++ AMP. Suponha que você queira adicionar os elementos correspondentes das matrizes 2 1-dimensional. Por exemplo, talvez você queira adicionar `{1, 2, 3, 4, 5}` e `{6, 7, 8, 9, 10}` obter `{7, 9, 11, 13, 15}` . Sem usar C++ AMP, você pode escrever o código a seguir para adicionar os números e exibir os resultados.

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

As partes importantes do código são as seguintes:

- Dados: os dados consistem em três matrizes. Todos têm a mesma classificação (um) e comprimento (cinco).

- Iteração: o primeiro **`for`** loop fornece um mecanismo para iterar pelos elementos nas matrizes. O código que você deseja executar para calcular as somas está contido no primeiro **`for`** bloco.

- Index: a `idx` variável acessa os elementos individuais das matrizes.

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
        [=](index<1> idx) restrict(amp) {
            sum[idx] = a[idx] + b[idx];
        }
    );

    // Print the results. The expected output is "7, 9, 11, 13, 15".
    for (int i = 0; i < size; i++) {
        std::cout << sum[i] << "\n";
    }
}
```

Os mesmos elementos básicos estão presentes, mas C++ AMP construções são usadas:

- Dados: você usa matrizes C++ para construir três objetos de [array_view](../../parallel/amp/reference/array-view-class.md) de C++ amp. Você fornece quatro valores para construir um `array_view` objeto: os valores de dados, a classificação, o tipo de elemento e o comprimento do `array_view` objeto em cada dimensão. A classificação e o tipo são passados como parâmetros de tipo. Os dados e o comprimento são passados como parâmetros do construtor. Neste exemplo, a matriz C++ que é passada para o construtor é unidimensional. A classificação e o comprimento são usados para construir a forma retangular dos dados no `array_view` objeto e os valores de dados são usados para preencher a matriz. A biblioteca de tempo de execução também inclui a [classe de matriz](../../parallel/amp/reference/array-class.md), que tem uma interface que se assemelha à `array_view` classe e é discutida posteriormente neste artigo.

- Iteração: a [função parallel_for_each (C++ amp)](reference/concurrency-namespace-functions-amp.md#parallel_for_each) fornece um mecanismo para iterar por meio dos elementos de dados ou do *domínio de computação*. Neste exemplo, o domínio de computação é especificado por `sum.extent` . O código que você deseja executar está contido em uma expressão lambda ou em uma *função de kernel*. O `restrict(amp)` indica que apenas o subconjunto da linguagem C++ que C++ amp pode acelerar é usado.

- Index: a variável de [classe de índice](../../parallel/amp/reference/index-class.md) , `idx` , é declarada com uma classificação de um para corresponder à classificação do `array_view` objeto. Usando o índice, você pode acessar os elementos individuais dos `array_view` objetos.

## <a name="shaping-and-indexing-data-index-and-extent"></a>Formatação e indexação de dados: índice e extensão

Você deve definir os valores de dados e declarar a forma dos dados antes de poder executar o código do kernel. Todos os dados são definidos para serem uma matriz (Retangular) e você pode definir a matriz para ter qualquer classificação (número de dimensões). Os dados podem ter qualquer tamanho em qualquer uma das dimensões.

### <a name="index-class"></a>Classe index

A [classe index](../../parallel/amp/reference/index-class.md) especifica um local no `array` objeto ou `array_view` encapsulando o deslocamento da origem em cada dimensão em um objeto. Ao acessar um local na matriz, você passa um `index` objeto para o operador de indexação, `[]` , em vez de uma lista de índices inteiros. Você pode acessar os elementos em cada dimensão usando o [operador array:: Operator ()](reference/array-class.md#operator_call) ou o [operador array_view:: Operator ()](reference/array-view-class.md#operator_call).

O exemplo a seguir cria um índice unidimensional que especifica o terceiro elemento em um objeto unidimensional `array_view` . O índice é usado para imprimir o terceiro elemento no `array_view` objeto. A saída é 3.

```cpp
int aCPP[] = {1, 2, 3, 4, 5};
array_view<int, 1> a(5, aCPP);

index<1> idx(2);

std::cout << a[idx] << "\n";
// Output: 3
```

O exemplo a seguir cria um índice bidimensional que especifica o elemento em que a linha = 1 e a coluna = 2 em um objeto bidimensional `array_view` . O primeiro parâmetro no `index` Construtor é o componente de linha e o segundo parâmetro é o componente de coluna. A saída é 6.

```cpp
int aCPP[] = {1, 2, 3, 4, 5, 6};
array_view<int, 2> a(2, 3, aCPP);

index<2> idx(1, 2);

std::cout <<a[idx] << "\n";
// Output: 6
```

O exemplo a seguir cria um índice tridimensional que especifica o elemento no qual a profundidade = 0, a linha = 1 e a coluna = 3 em um objeto tridimensional `array_view` . Observe que o primeiro parâmetro é o componente de profundidade, o segundo parâmetro é o componente de linha e o terceiro parâmetro é o componente de coluna. A saída é 8.

```cpp
int aCPP[] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

array_view<int, 3> a(2, 3, 4, aCPP);

// Specifies the element at 3, 1, 0.
index<3> idx(0, 1, 3);

std::cout << a[idx] << "\n";
// Output: 8
```

### <a name="extent-class"></a>Classe extent

A [classe de extensão](../../parallel/amp/reference/extent-class.md) especifica o comprimento dos dados em cada dimensão do `array` objeto ou `array_view` . Você pode criar uma extensão e usá-la para criar `array` um `array_view` objeto ou. Você também pode recuperar a extensão de um `array` objeto existente `array_view` . O exemplo a seguir imprime o comprimento da extensão em cada dimensão de um `array_view` objeto.

```cpp
int aCPP[] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
// There are 3 rows and 4 columns, and the depth is two.
array_view<int, 3> a(2, 3, 4, aCPP);

std::cout << "The number of columns is " << a.extent[2] << "\n";
std::cout << "The number of rows is " << a.extent[1] << "\n";
std::cout << "The depth is " << a.extent[0] << "\n";
std::cout << "Length in most significant dimension is " << a.extent[0] << "\n";
```

O exemplo a seguir cria um `array_view` objeto que tem as mesmas dimensões que o objeto no exemplo anterior, mas este exemplo usa um `extent` objeto em vez de usar parâmetros explícitos no `array_view` Construtor.

```cpp
int aCPP[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
extent<3> e(2, 3, 4);

array_view<int, 3> a(e, aCPP);

std::cout << "The number of columns is " << a.extent[2] << "\n";
std::cout << "The number of rows is " << a.extent[1] << "\n";
std::cout << "The depth is " << a.extent[0] << "\n";
```

## <a name="moving-data-to-the-accelerator-array-and-array_view"></a>Movendo dados para o acelerador: matriz e array_view

Dois contêineres de dados usados para mover dados para o acelerador são definidos na biblioteca de tempo de execução. Elas são a [classe Array](../../parallel/amp/reference/array-class.md) e a [classe array_view](../../parallel/amp/reference/array-view-class.md). A `array` classe é uma classe de contêiner que cria uma cópia profunda dos dados quando o objeto é construído. A `array_view` classe é uma classe de wrapper que copia os dados quando a função de kernel acessa os dados. Quando os dados são necessários no dispositivo de origem, os dados são copiados de volta.

### <a name="array-class"></a>Classe array

Quando um `array` objeto for construído, uma cópia profunda dos dados será criada no acelerador se você usar um construtor que inclua um ponteiro para o conjunto de dados. A função kernel modifica a cópia no acelerador. Quando a execução da função de kernel for concluída, você deverá copiar os dados de volta para a estrutura de dados de origem. O exemplo a seguir multiplica cada elemento em um vetor por 10. Depois que a função de kernel for concluída, o `vector conversion operator` será usado para copiar os dados de volta para o objeto de vetor.

```cpp
std::vector<int> data(5);

for (int count = 0; count <5; count++)
{
    data[count] = count;
}

array<int, 1> a(5, data.begin(), data.end());

parallel_for_each(
    a.extent,
    [=, &a](index<1> idx) restrict(amp) {
        a[idx] = a[idx]* 10;
    });

data = a;
for (int i = 0; i < 5; i++)
{
    std::cout << data[i] << "\n";
}
```

### <a name="array_view-class"></a>Classe array_view

O `array_view` tem quase os mesmos membros que a `array` classe, mas o comportamento subjacente não é o mesmo. Os dados passados para o `array_view` Construtor não são replicados na GPU como se trata de um `array` Construtor. Em vez disso, os dados são copiados para o acelerador quando a função de kernel é executada. Portanto, se você criar dois `array_view` objetos que usam os mesmos dados, ambos os `array_view` objetos referem-se ao mesmo espaço de memória. Ao fazer isso, você precisa sincronizar qualquer acesso multithread. A principal vantagem de usar a `array_view` classe é que os dados serão movidos somente se for necessário.

### <a name="comparison-of-array-and-array_view"></a>Comparação entre matriz e array_view

A tabela a seguir resume as semelhanças e diferenças entre as `array` `array_view` classes e.

|Descrição|Classe Array|Classe array_view|
|-----------------|-----------------|-----------------------|
|Quando a classificação é determinada|No momento da compilação.|No momento da compilação.|
|Quando a extensão é determinada|Em tempo de execução.|Em tempo de execução.|
|Forma|Retangular.|Retangular.|
|Armazenamento de dados|É um contêiner de dados.|É um wrapper de dados.|
|Copiar|Cópia explícita e profunda na definição.|Cópia implícita quando é acessada pela função de kernel.|
|Recuperação de dados|Copiando os dados da matriz de volta para um objeto no thread da CPU.|Acesse diretamente o `array_view` objeto ou chamando o [método array_view:: Synchronize](reference/array-view-class.md#synchronize) para continuar acessando os dados no contêiner original.|

### <a name="shared-memory-with-array-and-array_view"></a>Memória compartilhada com matriz e array_view

Memória compartilhada é a memória que pode ser acessada pela CPU e pelo acelerador. O uso da memória compartilhada elimina ou reduz significativamente a sobrecarga de copiar dados entre a CPU e o acelerador. Embora a memória seja compartilhada, ela não pode ser acessada simultaneamente pela CPU e pelo acelerador, e fazer isso causa um comportamento indefinido.

`array` os objetos podem ser usados para especificar o controle refinado sobre o uso de memória compartilhada se o acelerador associado der suporte a ele. Se um acelerador dá suporte à memória compartilhada é determinado pela propriedade de [supports_cpu_shared_memory](reference/accelerator-class.md#supports_cpu_shared_memory) do acelerador, que retorna **`true`** quando há suporte para a memória compartilhada. Se houver suporte para memória compartilhada, a [enumeração de access_type](reference/concurrency-namespace-enums-amp.md#access_type) padrão para alocações de memória no acelerador será determinada pela `default_cpu_access_type` propriedade. Por padrão, `array` e os `array_view` objetos assumem o mesmo `access_type` que o primário associado `accelerator` .

Ao definir a propriedade [array:: Cpu_access_type data member](reference/array-class.md#cpu_access_type) de um `array` explicitamente, você pode exercitar o controle refinado sobre como a memória compartilhada é usada, para que você possa otimizar o aplicativo para as características de desempenho do hardware, com base nos padrões de acesso à memória de seus kernels de computação. Um `array_view` reflete o mesmo `cpu_access_type` que o `array` que está associado; ou, se o array_view for construído sem uma fonte de dados, seu `access_type` refletirá o ambiente que primeiro faz com que ele aloque o armazenamento. Ou seja, se ele for acessado pela primeira vez pelo host (CPU), ele se comportará como se fosse criado em uma fonte de dados de CPU e compartilhará o `access_type` do `accelerator_view` associado pela captura; no entanto, se ele for acessado pela primeira vez por um `accelerator_view` , ele se comportará como se tivesse sido criado `array` em um criado `accelerator_view` e compartilhará o `array` `access_type` .

O exemplo de código a seguir mostra como determinar se o acelerador padrão dá suporte à memória compartilhada e, em seguida, cria várias matrizes que têm diferentes configurações de cpu_access_type.

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

## <a name="executing-code-over-data-parallel_for_each"></a>Executando código sobre dados: parallel_for_each

A função [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) define o código que você deseja executar no acelerador em relação aos dados no `array` objeto ou `array_view` . Considere o código a seguir da introdução deste tópico.

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

O `parallel_for_each` método usa dois argumentos, um domínio de computação e uma expressão lambda.

O *domínio de computação* é um `extent` objeto ou um `tiled_extent` objeto que define o conjunto de threads a serem criados para execução paralela. Um thread é gerado para cada elemento no domínio de computação. Nesse caso, o `extent` objeto é unidimensional e tem cinco elementos. Portanto, cinco threads são iniciados.

A *expressão lambda* define o código a ser executado em cada thread. A cláusula Capture, `[=]` , especifica que o corpo da expressão lambda acessa todas as variáveis capturadas por valor, que nesse caso são `a` , `b` e `sum` . Neste exemplo, a lista de parâmetros cria uma variável unidimensional `index` chamada `idx` . O valor de `idx[0]` é 0 no primeiro thread e aumenta em cada thread subsequente. O `restrict(amp)` indica que apenas o subconjunto da linguagem C++ que C++ amp pode acelerar é usado.  As limitações nas funções que têm o modificador restrict são descritas em [restringir (C++ amp)](../../cpp/restrict-cpp-amp.md). Para obter mais informações, consulte [sintaxe de expressão lambda](../../cpp/lambda-expression-syntax.md).

A expressão lambda pode incluir o código a ser executado ou pode chamar uma função de kernel separada. A função de kernel deve incluir o `restrict(amp)` modificador. O exemplo a seguir é equivalente ao exemplo anterior, mas chama uma função de kernel separada.

```cpp
#include <amp.h>
#include <iostream>
using namespace concurrency;

void AddElements(
    index<1> idx,
    array_view<int, 1> sum,
    array_view<int, 1> a,
    array_view<int, 1> b) restrict(amp) {
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
        [=](index<1> idx) restrict(amp) {
            AddElements(idx, sum, a, b);
        }
    );

    for (int i = 0; i < 5; i++) {
        std::cout << sum[i] << "\n";
    }
}
```

## <a name="accelerating-code-tiles-and-barriers"></a>Acelerando o código: blocos e barreiras

Você pode obter aceleração adicional usando blocos. O agrupamento divide os threads em subconjuntos ou *blocos* iguais retangulares. Você determina o tamanho do bloco apropriado com base em seu conjunto de dados e o algoritmo que está codificando. Para cada thread, você tem acesso ao local *global* de um elemento de dados em relação ao todo `array` ou `array_view` ao acesso ao local *local* em relação ao bloco. Usar o valor de índice local simplifica seu código porque você não precisa escrever o código para converter valores de índice de global para local. Para usar o disposição em cascata, chame o [método extensão:: Tile](reference/extent-class.md#tile) no domínio de computação no `parallel_for_each` método e use um [tiled_index](../../parallel/amp/reference/tiled-index-class.md) objeto na expressão lambda.

Em aplicativos típicos, os elementos em um bloco estão relacionados de alguma forma, e o código precisa acessar e manter o controle dos valores no bloco. Use a palavra-chave [Tile_static palavra-chave](../../cpp/tile-static-keyword.md) e o [método tile_barrier:: Wait](reference/tile-barrier-class.md#wait) para fazer isso. Uma variável que tem a palavra-chave **tile_static** tem um escopo em todo um bloco e uma instância da variável é criada para cada bloco. Você deve lidar com a sincronização de acesso de thread de bloco para a variável. O [método tile_barrier:: Wait](reference/tile-barrier-class.md#wait) interrompe a execução do thread atual até que todos os threads no bloco tenham atingido a chamada para `tile_barrier::wait` . Portanto, você pode acumular valores em todo o bloco usando variáveis **tile_static** . Em seguida, você pode concluir qualquer computação que exija acesso a todos os valores.

O diagrama a seguir representa uma matriz bidimensional de dados de amostragem que é organizada em blocos.

![Valores de índice em uma extensão em ladrilho](../../parallel/amp/media/camptiledgridexample.png "Valores de índice em uma extensão em ladrilho")

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

parallel_for_each(
    // Create threads for sample.extent and divide the extent into 2 x 2 tiles.
    sample.extent.tile<2,2>(),
        [=](tiled_index<2,2> idx) restrict(amp) {
        // Create a 2 x 2 array to hold the values in this tile.
        tile_static int nums[2][2];

        // Copy the values for the tile into the 2 x 2 array.
        nums[idx.local[1]][idx.local[0]] = sample[idx.global];

        // When all the threads have executed and the 2 x 2 array is complete, find the average.
        idx.barrier.wait();
        int sum = nums[0][0] + nums[0][1] + nums[1][0] + nums[1][1];

        // Copy the average into the array_view.
        average[idx.global] = sum / 4;
    });

for (int i = 0; i <4; i++) {
    for (int j = 0; j <6; j++) {
        std::cout << average(i,j) << " ";
    }
    std::cout << "\n";
}

// Output:
// 3 3 8 8 3 3
// 3 3 8 8 3 3
// 5 5 2 2 4 4
// 5 5 2 2 4 4
```

## <a name="math-libraries"></a>Bibliotecas matemáticas

C++ AMP inclui duas bibliotecas matemáticas. A biblioteca de precisão dupla no [namespace Concurrency::p recise_math](../../parallel/amp/reference/concurrency-precise-math-namespace.md) fornece suporte para funções de precisão dupla. Ele também fornece suporte para funções de precisão única, embora o suporte de precisão dupla no hardware ainda seja necessário. Ele está em conformidade com a [especificação C99 (ISO/IEC 9899)](https://go.microsoft.com/fwlink/p/?linkid=225887). O acelerador deve oferecer suporte a precisão dupla completa. Você pode determinar se ele faz verificando o valor do [membro de dados Accelerator:: supports_double_precision](reference/accelerator-class.md#supports_double_precision). A biblioteca de matemática rápida, no [namespace Concurrency:: fast_math](../../parallel/amp/reference/concurrency-fast-math-namespace.md), contém outro conjunto de funções matemáticas. Essas funções, que dão suporte apenas aos **`float`** operandos, são executadas mais rapidamente, mas não são tão precisas quanto aquelas na biblioteca matemática de precisão dupla. As funções estão contidas no \<amp_math.h> arquivo de cabeçalho e todas são declaradas com `restrict(amp)` . As funções no \<cmath> arquivo de cabeçalho são importadas para `fast_math` os `precise_math` namespaces e. A **`restrict`** palavra-chave é usada para distinguir a \<cmath> versão e a versão C++ amp. O código a seguir calcula o logaritmo de base 10, usando o método rápido, de cada valor que está no domínio de computação.

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
            logs[idx] = concurrency::fast_math::log10(numbers[idx]);
        }
    );

    for (int i = 0; i < 6; i++) {
        std::cout << logs[i] << "\n";
    }
}
```

## <a name="graphics-library"></a>Biblioteca de gráficos

O C++ AMP inclui uma biblioteca de gráficos projetada para a programação de gráficos acelerada. Essa biblioteca é usada somente em dispositivos que dão suporte à funcionalidade de gráficos nativos. Os métodos estão no [namespace Concurrency:: Graphics](../../parallel/amp/reference/concurrency-graphics-namespace.md) e estão contidos no arquivo de \<amp_graphics.h> cabeçalho. Os principais componentes da biblioteca de gráficos são:

- [classe de textura](../../parallel/amp/reference/texture-class.md): você pode usar a classe de textura para criar texturas da memória ou de um arquivo. As texturas assemelham-se às matrizes porque contêm dados e se assemelham a contêineres na biblioteca padrão C++ em relação à construção de atribuição e de cópia. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../../standard-library/stl-containers.md). Os parâmetros de modelo para a `texture` classe são o tipo de elemento e a classificação. A classificação pode ser 1, 2 ou 3. O tipo de elemento pode ser um dos tipos de vetores curtos descritos posteriormente neste artigo.

- [classe writeonly_texture_view](../../parallel/amp/reference/writeonly-texture-view-class.md): fornece acesso somente gravação a qualquer textura.

- Biblioteca de vetores curta: define um conjunto de tipos de vetores curtos de comprimento 2, 3 e 4 que são baseados em **`int`** , `uint` , **`float`** , **`double`** , [normal](../../parallel/amp/reference/norm-class.md)ou [unorm](../../parallel/amp/reference/unorm-class.md).

## <a name="universal-windows-platform-uwp-apps"></a>Aplicativos da UWP (Plataforma Universal do Windows)

Assim como outras bibliotecas de C++, você pode usar C++ AMP em seus aplicativos UWP. Estes artigos descrevem como incluir C++ AMP código em aplicativos que é criado usando C++, C#, Visual Basic ou JavaScript:

- [Usando C++ AMP em aplicativos UWP](../../parallel/amp/using-cpp-amp-in-windows-store-apps.md)

- [Walkthrough: Criando um componente Windows Runtime básico em C++ e chamando-o do JavaScript](/previous-versions/windows/apps/hh755833(v=vs.140))

- [Otimizador de viagens do Bing Maps, um aplicativo da Windows Store em JavaScript e C++](/previous-versions/windows/apps/hh699893(v=vs.140))

- [Como usar C++ AMP do C# usando o Windows Runtime](https://devblogs.microsoft.com/pfxteam/how-to-use-c-amp-from-c-using-winrt/)

- [Como usar o C++ AMP do C #](https://devblogs.microsoft.com/pfxteam/how-to-use-c-amp-from-c/)

- [Chamando funções nativas do código gerenciado](../../dotnet/calling-native-functions-from-managed-code.md)

## <a name="c-amp-and-concurrency-visualizer"></a>C++ AMP e visualizador de simultaneidade

O Visualizador de simultaneidade inclui suporte para analisar o desempenho de C++ AMP código. Estes artigos descrevem esses recursos:

- [Gráfico de atividade de GPU](/visualstudio/profiling/gpu-activity-graph)

- [Atividade de GPU (paginação)](/visualstudio/profiling/gpu-activity-paging)

- [Atividade de GPU (este processo)](/visualstudio/profiling/gpu-activity-this-process)

- [Atividade de GPU (outros processos)](/visualstudio/profiling/gpu-activity-other-processes)

- [Canais (exibição de threads)](/visualstudio/profiling/channels-threads-view)

- [Analisando C++ AMP código com o Visualizador de simultaneidade](/archive/blogs/nativeconcurrency/analyzing-c-amp-code-with-the-concurrency-visualizer)

## <a name="performance-recommendations"></a>Recomendações de desempenho

O módulo e a divisão de inteiros não assinados têm desempenho significativamente melhor do que o módulo e a divisão de inteiros assinados. É recomendável que você use inteiros sem sinal quando possível.

## <a name="see-also"></a>Confira também

[C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)<br/>
[Sintaxe de expressão lambda](../../cpp/lambda-expression-syntax.md)<br/>
[Referência (C++ AMP)](../../parallel/amp/reference/reference-cpp-amp.md)<br/>
[Programação paralela no blog de código nativo](/archive/blogs/nativeconcurrency/)
