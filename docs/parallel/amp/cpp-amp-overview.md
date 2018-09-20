---
title: Visão geral do C++ AMP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- C++ Accelerated Massive Parallelism, requirements
- C++ Accelerated Massive Parallelism, architecture
- C++ AMP
- C++ Accelerated Massive Parallelism, overview
- C++ Accelerated Massive Parallelism
ms.assetid: 9e593b06-6e3c-43e9-8bae-6d89efdd39fc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a4f574bc55b383fc35d37790f74ddcaa73df3e96
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46405470"
---
# <a name="c-amp-overview"></a>Visão geral do C++ AMP

C++ Accelerated Massive Parallelism (C++ AMP) acelera a execução do código C++, tirando proveito do hardware de dados paralelos, como uma unidade de processamento gráfico (GPU) em uma placa gráfica discreta. Usando o C++ AMP, você pode codificar algoritmos de dados multidimensionais, de modo que a execução possa ser acelerada usando o paralelismo em hardware heterogêneo. O modelo de programação do C++ AMP inclui matrizes multidimensionais, indexação, transferência de memória, agrupamento lado a lado e uma biblioteca de funções matemáticas. Você pode usar extensões de linguagem do C++ AMP para controlar como os dados são movidos da CPU para a GPU e vice-versa, para que você pode melhorar o desempenho.

## <a name="system-requirements"></a>Requisitos de sistema

- O Windows 7, Windows 8, Windows Server 2008 R2 ou Windows Server 2012

- Nível de recursos 11.0 do DirectX 11 ou hardware posterior

- Para depuração no emulador de software, o Windows 8 ou Windows Server 2012 é necessária. Para depurar no hardware, você deve instalar os drivers para a sua placa gráfica. Para obter mais informações, consulte [depurando código de GPU](/visualstudio/debugger/debugging-gpu-code).

## <a name="introduction"></a>Introdução

Os dois exemplos a seguir ilustram os principais componentes do C++ AMP. Suponha que você deseja adicionar os elementos correspondentes de duas matrizes unidimensionais. Por exemplo, talvez você queira adicionar `{1, 2, 3, 4, 5}` e `{6, 7, 8, 9, 10}` para obter `{7, 9, 11, 13, 15}`. Sem usar o C++ AMP, você pode escrever o código a seguir para adicionar os números e exibir os resultados.

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

- Dados: Os dados consistem em três matrizes. Todos têm a mesma classificação (um) e comprimento (cinco).

- Iteração: A primeira `for` loop fornece um mecanismo para iteração através dos elementos nas matrizes. O código que você deseja executar para calcular as somas está contido no primeiro `for` bloco.

- Índice: A `idx` variável acessa os elementos individuais das matrizes.

Usando o C++ AMP, você pode escrever o código a seguir em vez disso.

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

Os mesmos elementos básicos estão presentes, mas o C++ AMP construções são usadas:

- Dados: Você usa matrizes C++ para construir três C++ AMP [array_view](../../parallel/amp/reference/array-view-class.md) objetos. Você fornece quatro valores para construir uma `array_view` objeto: os valores de dados, a classificação, o tipo de elemento e o comprimento do `array_view` objeto em cada dimensão. A classificação e tipo são passados como parâmetros de tipo. Os dados e comprimento são passados como parâmetros do construtor. Neste exemplo, a matriz de C++ que é passada para o construtor é unidimensional. A classificação e o comprimento são usados para construir a forma retangular dos dados no `array_view` objeto e os valores são usados para preencher a matriz de dados. A biblioteca de tempo de execução também inclui o [classe array](../../parallel/amp/reference/array-class.md), que tem uma interface que se parece com o `array_view` de classe e é discutida posteriormente neste artigo.

- Iteração: O [função (C++ AMP) parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) fornece um mecanismo para iteração através dos elementos de dados, ou *domínio de cálculo*. Neste exemplo, o domínio de cálculo é especificado pelo `sum.extent`. O código que você deseja executar está contido em uma expressão lambda, ou *função de kernel*. O `restrict(amp)` indica que somente o subconjunto da linguagem C++ que o C++ AMP pode acelerar é usado.

- Índice: A [classe index](../../parallel/amp/reference/index-class.md) variável `idx`, é declarado com a classificação um para coincidir com a classificação do `array_view` objeto. Usando o índice, você pode acessar os elementos individuais do `array_view` objetos.

## <a name="shaping-and-indexing-data-index-and-extent"></a>Modelando e indexando dados: índice e extensão

Você deve definir os valores de dados e declarar a forma dos dados antes de executar o código de kernel. Todos os dados são definidos para serem uma matriz (retangular), e você pode definir a matriz para ter qualquer classificação (número de dimensões). Os dados podem ser de qualquer tamanho em qualquer uma das dimensões.

### <a name="index-class"></a>Classe index

O [classe index](../../parallel/amp/reference/index-class.md) Especifica um local na `array` ou `array_view` objeto encapsulando o deslocamento da origem em cada dimensão em um único objeto. Quando você acessa um local na matriz, você passa um `index` objeto para o operador de indexação, `[]`, em vez de uma lista de índices inteiros. Você pode acessar os elementos em cada dimensão usando o [array:: Operator () operador](reference/array-class.md#operator_call) ou o [array_view::operator() operador](reference/array-view-class.md#operator_call).

O exemplo a seguir cria um índice unidimensional que especifica o terceiro elemento em um unidimensional `array_view` objeto. O índice é usado para imprimir o terceiro elemento no `array_view` objeto. A saída é 3.

```cpp
int aCPP[] = {1, 2, 3, 4, 5};
array_view<int, 1> a(5, aCPP);

index<1> idx(2);

std::cout << a[idx] << "\n";
// Output: 3
```

O exemplo a seguir cria um índice bidimensional que especifica o elemento no qual a linha = 1 e a coluna = 2 em bidimensional `array_view` objeto. O primeiro parâmetro no `index` construtor é o componente de linha, e o segundo parâmetro é o componente de coluna. A saída é 6.

```cpp
int aCPP[] = {1, 2, 3, 4, 5, 6};
array_view<int, 2> a(2, 3, aCPP);

index<2> idx(1, 2);

std::cout <<a[idx] << "\n";
// Output: 6
```

O exemplo a seguir cria um índice tridimensional que especifica o elemento onde a profundidade = 0, linha = 1 e a coluna = 3 em um tridimensional `array_view` objeto. Observe que o primeiro parâmetro é o componente profundidade, o segundo parâmetro é o componente de linha e o terceiro parâmetro é o componente de coluna. A saída é 8.

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

O [classe extent](../../parallel/amp/reference/extent-class.md) Especifica o comprimento dos dados em cada dimensão da `array` ou `array_view` objeto. Você pode criar uma extensão e usá-lo para criar uma `array` ou `array_view` objeto. Você também pode recuperar a extensão de existente `array` ou `array_view` objeto. O exemplo a seguir imprime o comprimento da extensão em cada dimensão de um `array_view` objeto.

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

O exemplo a seguir cria uma `array_view` dimensões de objeto que tem o mesmo que o objeto no exemplo anterior, mas este exemplo usa um `extent` objeto em vez de usar parâmetros explícitos no `array_view` construtor.

```cpp
int aCPP[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
extent<3> e(2, 3, 4);

array_view<int, 3> a(e, aCPP);

std::cout << "The number of columns is " << a.extent[2] << "\n";
std::cout << "The number of rows is " << a.extent[1] << "\n";
std::cout << "The depth is " << a.extent[0] << "\n";
```

## <a name="moving-data-to-the-accelerator-array-and-arrayview"></a>Movimentação de dados para o acelerador: array e array_view

Dois contêineres de dados usados para mover dados para o acelerador são definidos na biblioteca de tempo de execução. Eles são os [classe array](../../parallel/amp/reference/array-class.md) e o [classe array_view](../../parallel/amp/reference/array-view-class.md). O `array` é uma classe de contêiner que cria uma cópia profunda dos dados quando o objeto é construído. O `array_view` é uma classe de wrapper que copia os dados quando a função de kernel acessa os dados. Quando os dados são necessários no dispositivo de origem de dados são copiados de volta.

### <a name="array-class"></a>Classe array

Quando um `array` objeto é construído, uma cópia profunda dos dados é criada no Acelerador se você usar um construtor que inclui um ponteiro para o conjunto de dados. A função de kernel modifica a cópia no acelerador. Quando a execução da função de kernel for concluída, você deve copiar os dados novamente para a estrutura de dados de origem. O exemplo a seguir multiplica cada elemento em um vetor por 10. Depois que a função de kernel for concluída, o `vector conversion operator` é usado para copiar os dados de volta para o objeto vector.

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

### <a name="arrayview-class"></a>Classe array_view

O `array_view` tem quase os mesmos membros que o `array` classe, mas o comportamento subjacente não é o mesmo. Dados passados para o `array_view` construtor não é replicado na GPU, assim como em um `array` construtor. Em vez disso, os dados são copiados para o acelerador quando a função de kernel é executada. Portanto, se você criar dois `array_view` objetos que usam os mesmos dados, ambos `array_view` objetos se referirem ao mesmo espaço de memória. Quando você fizer isso, você precisa sincronizar qualquer acesso multissegmentado. A principal vantagem de usar o `array_view` classe é que os dados são movidos somente se for necessário.

### <a name="comparison-of-array-and-arrayview"></a>Comparação entre array e array_view

A tabela a seguir resume as semelhanças e diferenças entre o `array` e `array_view` classes.

|Descrição|Classe Array|Classe array_view|
|-----------------|-----------------|-----------------------|
|Quando a classificação é determinada|Em tempo de compilação.|Em tempo de compilação.|
|Quando a extensão é determinada|Em tempo de execução.|Em tempo de execução.|
|Forma|Retangular.|Retangular.|
|Armazenamento de dados|É um contêiner de dados.|É um wrapper de dados.|
|Copiar|Cópia explícita e profunda na definição.|Cópia implícita quando ele é acessado pela função de kernel.|
|Recuperação de dados|Copiando os dados de matriz de volta a um objeto no thread da CPU.|Por acesso direto do `array_view` do objeto ou chamando o [modo_de_exibição_da_matrix método](reference/array-view-class.md#synchronize) para continuar acessando os dados no contêiner original.|

### <a name="shared-memory-with-array-and-arrayview"></a>Memória compartilhada com matriz e array_view

Memória compartilhada é a memória que pode ser acessada pela CPU e pelo acelerador. O uso de memória compartilhada elimina ou reduz significativamente a sobrecarga de copiar dados entre a CPU e o acelerador. Embora a memória for compartilhada, não pode ser acessada simultaneamente pela CPU e pelo Acelerador, e isso fizer um comportamento indefinido.

`array` objetos podem ser usados para especificar um controle refinado sobre o uso de memória compartilhada se o acelerador associado oferecer suporte a ele. Se um acelerador dá suporte à memória compartilhada é determinado pelo Acelerador [supports_cpu_shared_memory](reference/accelerator-class.md#supports_cpu_shared_memory) propriedade, que retorna **verdadeiro** quando há suporte para a memória compartilhada. Se a memória compartilhada é suportada, o padrão [enumeração access_type](reference/concurrency-namespace-enums-amp.md#access_type) memória alocações no Acelerador é determinado pela `default_cpu_access_type` propriedade. Por padrão, `array` e `array_view` objetos recebem no mesmo `access_type` como o primário associado `accelerator`.

Definindo o [array:: cpu_access_type membro de dados](reference/array-class.md#cpu_access_type) propriedade de um `array` explicitamente, você pode exercício refinado de controle sobre como a memória compartilhada é usada, para que você possa otimizar o aplicativo para o desempenho do hardware características, com base nos padrões de acesso de memória dos kernels de computação. Uma `array_view` reflete o mesmo `cpu_access_type` como o `array` que ele está associado; ou, se o array_view for construído sem uma fonte de dados, seu `access_type` reflete o ambiente que primeiro faz com que ele alocar o armazenamento. Ou seja, se for acessada primeiro pelo host (CPU), em seguida, ele se comporta como se tivesse sido criada em uma fonte de dados de CPU e compartilhamentos a `access_type` do `accelerator_view` associada por captura; no entanto, se ele for o primeiro acessados por um `accelerator_view`, ela se comportará como se fosse criados ao longo de um `array` criada nessa `accelerator_view` e compartilha o `array`do `access_type`.

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

## <a name="executing-code-over-data-parallelforeach"></a>Executando o código sobre dados: parallel_for_each

O [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) função define o código que você deseja executar no Acelerador contra os dados de `array` ou `array_view` objeto. Considere o seguinte código da introdução deste tópico.

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

O `parallel_for_each` método utiliza dois argumentos, um domínio de cálculo e uma expressão lambda.

O *domínio de cálculo* é um `extent` objeto ou um `tiled_extent` objeto que define o conjunto de segmentos a ser criado para execução paralela. Um thread é gerado para cada elemento no domínio do cálculo. Nesse caso, o `extent` objeto é unidimensional e tem cinco elementos. Portanto, cinco segmentos são iniciados.

O *expressão lambda* define o código seja executado em cada thread. A cláusula de captura `[=]`, especifica que o corpo da expressão lambda acessará todas as variáveis capturadas por valor, que nesse caso são `a`, `b`, e `sum`. Neste exemplo, a lista de parâmetros cria um unidimensional `index` variável chamada `idx`. O valor da `idx[0]` é 0 no primeiro segmento e aumenta um em cada segmento subsequente. O `restrict(amp)` indica que somente o subconjunto da linguagem C++ que o C++ AMP pode acelerar é usado.  As restrições em funções que têm o modificador de restrição são descritas em [restrict (AMP C++)](../../cpp/restrict-cpp-amp.md). Para obter mais informações, consulte, [sintaxe de expressão Lambda](../../cpp/lambda-expression-syntax.md).

A expressão lambda pode incluir o código para executar ou ele pode chamar uma função de kernel separada. A função de kernel deve incluir o `restrict(amp)` modificador. O exemplo a seguir é equivalente ao exemplo anterior, mas chama uma função de kernel separada.

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

## <a name="accelerating-code-tiles-and-barriers"></a>Acelerando código: Blocos e barreiras

Você pode obter aceleração adicional usando lado a lado. Lado a lado divide os threads em subconjuntos retangulares iguais ou *blocos*. Determinar o tamanho de bloco apropriado com base em seu conjunto de dados e o algoritmo que você está codificando. Para cada thread, você tem acesso à *global* local de um elemento de dados relativo a todo `array` ou `array_view` e o acesso ao *local* local relativo ao bloco. Usando o valor de índice local simplifica o seu código, porque você não precisa escrever o código para converter valores de índice de global para local. Para usar disposição lado a lado, chame o [Extent:: Tile método](reference/extent-class.md#tile) no domínio de cálculo na `parallel_for_each` método e usar um [tiled_index](../../parallel/amp/reference/tiled-index-class.md) objeto na expressão lambda.

Em aplicativos típicos, os elementos em um bloco são relacionados de alguma forma e o código tem de acessar e manter controle dos valores através do bloco. Use o [palavra-chave tile_static](../../cpp/tile-static-keyword.md) palavra-chave e o [tile_barrier:: wait método](reference/tile-barrier-class.md#wait) para fazer isso. Uma variável que tem o **tile_static** palavra-chave tem um escopo em um bloco inteiro, e uma instância da variável é criada para cada peça. Você deve tratar a sincronização de thread de bloco acesso à variável. O [tile_barrier:: wait método](reference/tile-barrier-class.md#wait) interrompe a execução do thread atual até que todos os threads no tile tenham atingido a chamada para `tile_barrier::wait`. Portanto, você pode acumular valores através do bloco usando **tile_static** variáveis. Em seguida, você pode concluir qualquer cálculo que exija acesso a todos os valores.

O diagrama a seguir representa uma matriz bidimensional de dados que são organizados em blocos de amostragem.

![Indexar valores em uma extensão lado a lado](../../parallel/amp/media/camptiledgridexample.png "camptiledgridexample")

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

## <a name="math-libraries"></a>Bibliotecas de matemática

O C++ AMP inclui duas bibliotecas matemáticas. A biblioteca de precisão dupla na [Namespace Concurrency:: precise_math](../../parallel/amp/reference/concurrency-precise-math-namespace.md) fornece suporte para funções de precisão dupla. Ele também fornece suporte para funções de precisão simples, embora o suporte de precisão dupla no hardware ainda seja necessário. Ele está em conformidade com o [especificação C99 (ISO/IEC 9899)](http://go.microsoft.com/fwlink/p/?linkid=225887). O acelerador deve oferecer suporte de precisão dupla completo. Você pode determinar se ele tem verificando o valor da [Accelerator:: supports_double_precision membro de dados](reference/accelerator-class.md#supports_double_precision). A biblioteca de matemática rápida, além de [Namespace Concurrency:: fast_math](../../parallel/amp/reference/concurrency-fast-math-namespace.md), contém outro conjunto de funções matemáticas. Essas funções, que dão suporte apenas `float` operandos, executar mais rapidamente, mas não são tão precisos quanto aquelas na biblioteca de matemática de precisão dupla. As funções estão contidas na \<amp_math. h > arquivo de cabeçalho e todas são declaradas com `restrict(amp)`. As funções na \<cmath > arquivo de cabeçalho são importadas em ambos os `fast_math` e `precise_math` namespaces. O **restringir** palavra-chave é usado para distinguir o \<cmath > versão e a versão do C++ AMP. O código a seguir calcula o logaritmo de base 10, usando o método rápido, de cada valor que está no domínio do cálculo.

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

C++ AMP inclui uma biblioteca de elementos gráficos que se destina a programação acelerada de elementos gráficos. Essa biblioteca é usada somente em dispositivos que dão suporte à funcionalidade de gráficos nativa. Os métodos estão na [Namespace Concurrency:: Graphics](../../parallel/amp/reference/concurrency-graphics-namespace.md) e estão contidos no \<amp_graphics. h > arquivo de cabeçalho. Os principais componentes da biblioteca de elementos gráficos são:

- [Classe Texture](../../parallel/amp/reference/texture-class.md): você pode usar a classe texture para criar texturas da memória ou de um arquivo. As texturas são semelhantes a matrizes porque elas contêm dados e são semelhantes aos recipientes na biblioteca padrão C++ em relação à atribuição e construção de cópia. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../../standard-library/stl-containers.md). Os parâmetros de modelo para o `texture` classe são o tipo de elemento e a classificação. A classificação pode ser 1, 2 ou 3. O tipo de elemento pode ser um dos tipos de vetor curto que são descritos mais adiante neste artigo.

- [Classe writeonly_texture_view](../../parallel/amp/reference/writeonly-texture-view-class.md): fornece acesso somente gravação para qualquer textura.

- Biblioteca de vetor curto: Define um conjunto de tipos de vetor curto de comprimento 2, 3 e 4, que se baseiam **int**, `uint`, **float**, **double**, [norm ](../../parallel/amp/reference/norm-class.md), ou [unorm](../../parallel/amp/reference/unorm-class.md).

## <a name="universal-windows-platform-uwp-apps"></a>Aplicativos do Universal Windows Platform (UWP)

Como em outras bibliotecas de C++, você pode usar o C++ AMP em seus aplicativos UWP. Esses artigos descrevem como incluir código de C++ AMP em aplicativos que é criado usando o C++, c#, Visual Basic ou JavaScript:

- [Usando C++ AMP em aplicativos UWP](../../parallel/amp/using-cpp-amp-in-windows-store-apps.md)

- [Passo a passo: Criando um componente básico do tempo de execução do Windows em C++ e chamá-lo a partir do JavaScript](http://go.microsoft.com/fwlink/p/?linkid=249077)

- [O Bing Maps Trip Optimizer, um aplicativo de janela Store em JavaScript e C++](http://go.microsoft.com/fwlink/p/?linkid=249078)

- [Como usar o C++ AMP do c# usando o tempo de execução do Windows](http://go.microsoft.com/fwlink/p/?linkid=249080)

- [Como usar o C++ AMP do c#](http://go.microsoft.com/fwlink/p/?linkid=249081)

- [Chamando funções nativas de código gerenciado](../../dotnet/calling-native-functions-from-managed-code.md)

## <a name="c-amp-and-concurrency-visualizer"></a>C++ AMP e Visualizador de simultaneidade

O Visualizador de concorrência inclui suporte para analisar o desempenho do código C++ AMP. Esses artigos descrevem esses recursos:

- [Gráfico de atividade de GPU](/visualstudio/profiling/gpu-activity-graph)

- [Atividade de GPU (paginação)](/visualstudio/profiling/gpu-activity-paging)

- [Atividade de GPU (este processo)](/visualstudio/profiling/gpu-activity-this-process)

- [Atividade de GPU (outros processos)](/visualstudio/profiling/gpu-activity-other-processes)

- [Canais (exibição de threads)](/visualstudio/profiling/channels-threads-view)

- [Analisando código AMP de C++ com o Visualizador de simultaneidade](https://blogs.msdn.microsoft.com/nativeconcurrency/2012/03/09/analyzing-c-amp-code-with-the-concurrency-visualizer/)

## <a name="performance-recommendations"></a>Recomendações de desempenho

Módulo e a divisão de inteiros sem sinal têm desempenho significativamente melhor do que o módulo e a divisão de inteiros com sinal. É recomendável que você use números inteiros sem sinal quando possível.

## <a name="see-also"></a>Consulte também

[C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)<br/>
[Sintaxe da expressão lambda](../../cpp/lambda-expression-syntax.md)<br/>
[Referência (C++ AMP)](../../parallel/amp/reference/reference-cpp-amp.md)<br/>
[Programação paralela no Blog de código nativo](http://go.microsoft.com/fwlink/p/?linkid=238472)