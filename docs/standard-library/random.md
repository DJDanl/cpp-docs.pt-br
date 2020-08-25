---
title: '&lt;random&gt;'
ms.date: 08/24/2017
f1_keywords:
- <random>
helpviewer_keywords:
- random header
ms.assetid: 60afc25c-b162-4811-97c1-1b65398d4c57
ms.openlocfilehash: e66ffbfba7a7cc4a7dfebbc2dcc074842de3c1ac
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831432"
---
# <a name="ltrandomgt"></a>&lt;random&gt;

Define instalações para a geração aleatória de números, permitindo a criação de números aleatórios distribuídos uniformemente.

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<random>

**Namespace:** std

> [!NOTE]
> A \<random> biblioteca usa a instrução ' #include <initializer_list> '.

## <a name="summary"></a>Resumo

Um *gerador de número aleatório* é um objeto que produz uma sequência de valores pseudoaleatórios. Um gerador que produz valores que são distribuídos uniformemente em um intervalo especificado é um URNG (*Gerador de Número Aleatório Uniforme*). Um modelo de classe criado para funcionar como um URNG é chamado de *mecanismo* se essa classe tiver determinadas características comuns, que serão discutidas posteriormente neste artigo. Um URNG pode ser e geralmente é, combinado a uma *distribution* transmitindo o URNG como um argumento para que o `operator()` da distribuição produza valores que são distribuídos de maneira definida pela distribuição.

Esses links levam para as seções principais deste artigo:

- [Exemplos](#code)

- [Listagem categorizada](#listing)

- [Mecanismos e distribuições](#engdist)

- [Comentários](#comments)

### <a name="quick-tips"></a>Dicas rápidas

Aqui estão algumas dicas para manter em mente ao usar o \<random>:

- Para a maioria dos propósitos, os URNGs produzem bits brutos que podem ser moldados pelas distribuições. (Uma exceção notável disso é [std::shuffle()](../standard-library/algorithm-functions.md#shuffle), pois ele utiliza um URNG diretamente.)

- Uma única instanciação de um URNG ou distribuição não pode ser chamada com segurança simultaneamente, pois executar um URNG ou uma distribuição é uma operação de modificação. Para obter mais informações, consulte [Acesso thread-safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md).

- São fornecidos [typedefs predefinidos](#typedefs) de diversos mecanismos; esse é o modo preferido de criar um URNG se um mecanismo estiver sendo usado.

- O emparelhamento mais útil para a maioria dos aplicativos é o mecanismo `mt19937` com `uniform_int_distribution`, como mostrado no [exemplo de código](#code) posteriormente neste artigo.

Há muitas opções dentre as quais escolher no cabeçalho \<random>, e deve-se dar preferência a qualquer uma delas em relação à antiga função de Runtime C`rand()`. Para obter informações sobre o que há de errado com o `rand()` e como o \<random> lida com esses imprevistos, veja [este vídeo](https://go.microsoft.com/fwlink/p/?linkid=397615).

## <a name="examples"></a><a name="code"></a> Exemplos

O exemplo de código a seguir mostra como gerar alguns números aleatórios;nesse caso cinco deles usando um gerador criado com semente não determinista.

```cpp
#include <random>
#include <iostream>

using namespace std;

int main()
{
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.
                        // replace the call to rd() with a
                        // constant value to get repeatable
                        // results.

    for (int i = 0; i < 5; ++i) {
        cout << gen() << " "; // print the raw output of the generator.
    }
    cout << endl;
}
```

```Output
2430338871 3531691818 2723770500 3252414483 3632920437
```

Ao passo que esses são números aleatórios de alta qualidade e diferentes sempre que este programa seja executado, eles não são necessariamente em um intervalo útil. Para controlar o intervalo, use uma distribuição uniforme, conforme mostrado no código a seguir:

```cpp
#include <random>
#include <iostream>

using namespace std;

int main()
{
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.
    uniform_int_distribution<> dist(1,6); // distribute results between 1 and 6 inclusive.

    for (int i = 0; i < 5; ++i) {
        cout << dist(gen) << " "; // pass the generator to the distribution.
    }
    cout << endl;
}
```

```Output
5 1 6 1 2
```

O seguinte exemplo de código mostra um conjunto mais realista de casos de uso com geradores de números aleatórios uniformemente distribuídos misturando o conteúdo de um vetor e uma matriz.

```cpp
// cl.exe /EHsc /nologo /W4 /MTd
#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <functional> // ref()

using namespace std;

template <typename C> void print(const C& c) {
    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

template <class URNG>
void test(URNG& urng) {

    // Uniform distribution used with a vector
    // Distribution is [-5, 5] inclusive
    uniform_int_distribution<int> dist(-5, 5);
    vector<int> v;

    for (int i = 0; i < 20; ++i) {
        v.push_back(dist(urng));
    }

    cout << "Randomized vector: ";
    print(v);

    // Shuffle an array
    // (Notice that shuffle() takes a URNG, not a distribution)
    array<string, 26> arr = { { "H", "He", "Li", "Be", "B", "C", "N", "O", "F",
        "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc",
        "Ti", "V", "Cr", "Mn", "Fe" } };

    shuffle(arr.begin(), arr.end(), urng);

    cout << "Randomized array: ";
    print(arr);
    cout << "--" << endl;
}

int main()
{
    // First run: non-seedable, non-deterministic URNG random_device
    // Slower but crypto-secure and non-repeatable.
    random_device rd;
    cout << "Using random_device URNG:" << endl;
    test(rd);

    // Second run: simple integer seed, repeatable results
    cout << "Using constant-seed mersenne twister URNG:" << endl;
    mt19937 engine1(12345);
    test(engine1);

    // Third run: random_device as a seed, different each run
    // (Desirable for most purposes)
    cout << "Using non-deterministic-seed mersenne twister URNG:" << endl;
    mt19937 engine2(rd());
    test(engine2);

    // Fourth run: "warm-up" sequence as a seed, different each run
    // (Advanced uses, allows more than 32 bits of randomness)
    cout << "Using non-deterministic-seed \"warm-up\" sequence mersenne twister URNG:" << endl;
    array<unsigned int, mt19937::state_size> seed_data;
    generate_n(seed_data.begin(), seed_data.size(), ref(rd));
    seed_seq seq(begin(seed_data), end(seed_data));
    mt19937 engine3(seq);
    test(engine3);
}
```

```Output
Using random_device URNG:
Randomized vector: 5 -4 2 3 0 5 -2 0 4 2 -1 2 -4 -3 1 4 4 1 2 -2
Randomized array: O Li V K C Ti N Mg Ne Sc Cl B Cr Mn Ca Al F P Na Be Si Ar Fe S He H
--
Using constant-seed mersenne twister URNG:
Randomized vector: 3 -1 -5 0 0 5 3 -4 -3 -4 1 -3 0 -3 -2 -4 5 1 -1 -1
Randomized array: Al O Ne Si Na Be C N Cr Mn H V F Sc Mg Fe K Ca S Ti B P Ar Cl Li He
--
Using non-deterministic-seed mersenne twister URNG:
Randomized vector: 5 -4 0 2 1 -2 4 4 -4 0 0 4 -5 4 -5 -1 -3 0 0 3
Randomized array: Si Fe Al Ar Na P B Sc H F Mg Li C Ti He N Mn Be O Ca Cr V K Ne Cl S
--
Using non-deterministic-seed "warm-up" sequence mersenne twister URNG:
Randomized vector: -1 3 -2 4 1 3 0 -5 5 -5 0 0 5 0 -3 3 -4 2 5 0
Randomized array: Si C Sc H Na O S Cr K Li Al Ti Cl B Mn He Fe Ne Be Ar V P Ca N Mg F
--
```

Esse código demonstra duas aleatorizações diferentes, aleatorizar um vetor de inteiros e embaralhar uma matriz de dados indexados, com uma função de modelo de teste. A primeira chamada para a função de teste usa URNG protegido por criptografia, não determinista, não passível de propagação e não repetível `random_device`. A segunda execução do teste usa `mersenne_twister_engine` como URNG, com semeação constante determinista de 32 bits, o que significa que os resultados podem ser repetidos. A terceira execução do teste propaga `mersenne_twister_engine` com um resultado não determinista de 32 bits de `random_device`. A quarta execução de teste é expandida usando uma [sequência de semeação](../standard-library/seed-seq-class.md) preenchida com resultados de `random_device`, que oferece efetivamente mais do que a aleatoriedade não determinística de 32 bits (mas ainda sem proteção por criptografia). Para obter mais informações, continue lendo.

## <a name="categorized-listing"></a><a name="listing"></a> Lista categorizada

### <a name="uniform-random-number-generators"></a><a name="urngs"></a> Geradores de Números Aleatórios Uniformes

URNGs geralmente são descritos de acordo com essas propriedades:

1. **Duração do período**: quantas iterações são necessárias para repetir a sequência de números gerada. Quanto maior, melhor.

2. **Desempenho**: a velocidade com que os números podem ser gerados e quanta memória isso ocupa. Quanto menor, melhor.

3. **Qualidade**: a proximidade de uma sequência gerada de números verdadeiramente aleatórios. Isso geralmente é chamado de “*aleatoriedade*”.

As seções a seguir listam os URNGs (geradores de números aleatórios uniformes) fornecidos no cabeçalho \<random>.

#### <a name="non-deterministic-generator"></a><a name="rd"></a> Gerador não determinístico

[Classe random_device](../standard-library/random-device-class.md)\
Gera uma sequência aleatória não determinista protegida por criptografia usando um dispositivo externo. Geralmente usado para propagar um mecanismo. Baixo desempenho, qualidade bastante alta. Para obter mais informações, consulte [comentários](#comments).

#### <a name="engine-typedefs-with-predefined-parameters"></a><a name="typedefs"></a> Typedefs de Mecanismo com Parâmetros Predefinidos

Para mecanismos de instanciação e adaptadores de mecanismos. Para obter mais informações, consulte [Mecanismos e Distribuições](#engdist).

- `default_random_engine` O mecanismo padrão.

    ```cpp
    typedef mt19937 default_random_engine;
    ```

- `knuth_b` Mecanismo de Knuth.

    ```cpp
    typedef shuffle_order_engine<minstd_rand0, 256> knuth_b;
    ```

- `minstd_rand0` Mecanismo padrão mínimo de 1988 (Lewis, Goodman e Miller, 1969).

    ```cpp
    typedef linear_congruential_engine<unsigned int, 16807, 0, 2147483647> minstd_rand0;
    ```

- `minstd_rand` Mecanismo padrão mínimo atualizado `minstd_rand0` (Park, Miller e Stockmeyer, 1993).

    ```cpp
    typedef linear_congruential_engine<unsigned int, 48271, 0, 2147483647> minstd_rand;
    ```

- `mt19937` Mecanismo Mersenne Twister de 32 bits (Matsumoto e Nishimura, 1998).

    ```cpp
    typedef mersenne_twister_engine<
        unsigned int, 32, 624, 397,
        31, 0x9908b0df,
        11, 0xffffffff,
        7, 0x9d2c5680,
        15, 0xefc60000,
        18, 1812433253> mt19937;
    ```

- `mt19937_64` Mecanismo Mersenne Twister de 64 bits (Matsumoto e Nishimura, 2000).

    ```cpp
    typedef mersenne_twister_engine<
        unsigned long long, 64, 312, 156,
        31, 0xb5026f5aa96619e9ULL,
        29, 0x5555555555555555ULL,
        17, 0x71d67fffeda60000ULL,
        37, 0xfff7eee000000000ULL,
        43, 6364136223846793005ULL> mt19937_64;
    ```

- `ranlux24` Mecanismo RANLUX de 24 bits (Martin Lüscher e Fred James, 1994).

    ```cpp
    typedef discard_block_engine<ranlux24_base, 223, 23> ranlux24;
    ```

- `ranlux24_base` Usado como base para `ranlux24`.

    ```cpp
    typedef subtract_with_carry_engine<unsigned int, 24, 10, 24> ranlux24_base;
    ```

- `ranlux48` Mecanismo RANLUX de 48 bits (Martin Lüscher e Fred James, 1994).

    ```cpp
    typedef discard_block_engine<ranlux48_base, 389, 11> ranlux48;
    ```

- `ranlux48_base` Usado como base para `ranlux48`.

    ```cpp
    typedef subtract_with_carry_engine<unsigned long long, 48, 5, 12> ranlux48_base;
    ```

#### <a name="engine-templates"></a><a name="eng"></a> Modelos de Mecanismos

Modelos de mecanismos são usados como URNGs independentes ou como mecanismos de base transmitidos a [adaptadores de mecanismo](#engadapt). Geralmente, eles são instanciados com um [typedef de mecanismo predefinido](#typedefs) e transmitidos a uma [distribuição](#distributions). Para obter mais informações, consulte a seção [Mecanismos e Distribuições](#engdist).

|Nome|Descrição|
|-|-|
|[Classe linear_congruential_engine](../standard-library/linear-congruential-engine-class.md)|Gera uma sequência aleatória usando o algoritmo congruente linear. Mais simplista e com qualidade mais baixa.|
|[Classe mersenne_twister_engine](../standard-library/mersenne-twister-engine-class.md)|Gera uma sequência aleatória usando o algoritmo mersenne twister. Mais complexo e de qualidade mais alta, exceto pela classe random_device. Desempenho muito rápido.|
|[Classe subtract_with_carry_engine](../standard-library/subtract-with-carry-engine-class.md)|Gera uma sequência aleatória usando o algoritmo de subtração com transferência. Um aprimoramento em relação ao `linear_congruential_engine`, mas com qualidade e desempenho muito menores que `mersenne_twister_engine`.|

#### <a name="engine-adaptor-templates"></a><a name="engadapt"></a> Modelos de Adaptador de Mecanismo

Adaptadores de mecanismo são modelos que adaptam outros mecanismos (básicos). Geralmente, eles são instanciados com um [typedef de mecanismo predefinido](#typedefs) e transmitidos a uma [distribuição](#distributions). Para obter mais informações, consulte a seção [Mecanismos e Distribuições](#engdist).

|Nome|Descrição|
|-|-|
|[Classe discard_block_engine](../standard-library/discard-block-engine-class.md)|Gera uma sequência aleatória descartando valores retornados pelo mecanismo de base.|
|[Classe independent_bits_engine](../standard-library/independent-bits-engine-class.md)|Gera uma sequência aleatória com um número especificado de bits recompactando bits dos valores retornados pelo mecanismo básico.|
|[Classe shuffle_order_engine](../standard-library/shuffle-order-engine-class.md)|Gera uma sequência aleatória reordenando os valores retornados pelo mecanismo de base.|

[[Modelos de mecanismo](#eng)]

### <a name="random-number-distributions"></a><a name="distributions"></a> Distribuições de Número Aleatório

As seções a seguir listam as distribuições fornecidas no cabeçalho \<random>. As distribuições são um mecanismo de pós-processamento, que geralmente usam uma saída de URNG como entrada e distribuem a saída de acordo com uma função de densidade probabilística estatística definida. Para obter mais informações, consulte a seção [Mecanismos e Distribuições](#engdist).

#### <a name="uniform-distributions"></a>Distribuições Uniformes

|Nome|Descrição|
|-|-|
|[Classe uniform_int_distribution](../standard-library/uniform-int-distribution-class.md)|Produz uma distribuição de valor inteiro uniforme em um intervalo no intervalo fechado \[a, b] (inclusivo-inclusivo).|
|[Classe uniform_real_distribution](../standard-library/uniform-real-distribution-class.md)|Produz uma distribuição de valor real uniforme (ponto flutuante) em um intervalo no intervalo semiaberto [a, b) (inclusivo-exclusivo).|
|[generate_canonical](../standard-library/random-functions.md#generate_canonical)|Produz uma distribuição igual de valores reais (ponto flutuante) de uma determinada precisão em [0, 1) (inclusivo-exclusivo).|

[[Distribuições de número aleatório](#distributions)]

#### <a name="bernoulli-distributions"></a>Distribuições Bernoulli

|Nome|Descrição|
|-|-|
|[Classe bernoulli_distribution](../standard-library/bernoulli-distribution-class.md)|Produz uma distribuição de Bernoulli de **`bool`** valores.|
|[Classe binomial_distribution](../standard-library/binomial-distribution-class.md)|Produz uma distribuição binomial de valores inteiros.|
|[Classe geometric_distribution](../standard-library/geometric-distribution-class.md)|Produz uma distribuição geométrica de valores inteiros.|
|[Classe negative_binomial_distribution](../standard-library/negative-binomial-distribution-class.md)|Produz uma distribuição binomial negativa de valores inteiros.|

[[Distribuições de número aleatório](#distributions)]

#### <a name="normal-distributions"></a>Distribuições normais

|Nome|Descrição|
|-|-|
|[Classe cauchy_distribution](../standard-library/cauchy-distribution-class.md)|Produz uma distribuição de Cauchy de valores reais (ponto flutuante).|
|[Classe chi_squared_distribution](../standard-library/chi-squared-distribution-class.md)|Produz uma distribuição qui-quadrada de valores reais (ponto flutuante).|
|[Classe fisher_f_distribution](../standard-library/fisher-f-distribution-class.md)|Produz uma distribuição F (também conhecida como distribuição F do Snedecor ou a distribuição Fisher-Snedecor) de valores reais (ponto flutuante).|
|[Classe lognormal_distribution](../standard-library/lognormal-distribution-class.md)|Produz uma distribuição normal de log de valores reais (ponto flutuante).|
|[Classe normal_distribution](../standard-library/normal-distribution-class.md)|Produz uma distribuição normal (Gaussian) de valores reais (ponto flutuante).|
|[Classe student_t_distribution](../standard-library/student-t-distribution-class.md)|Produz uma *t*-distribution de valores reais (ponto flutuante).|

[[Distribuições de número aleatório](#distributions)]

#### <a name="poisson-distributions"></a>Distribuições Poisson

|Nome|Descrição|
|-|-|
|[Classe exponential_distribution](../standard-library/exponential-distribution-class.md)|Produz uma distribuição exponencial de valores reais (ponto flutuante).|
|[Classe extreme_value_distribution](../standard-library/extreme-value-distribution-class.md)|Produz uma distribuição de valor extremo de valores reais (ponto flutuante).|
|[Classe gamma_distribution](../standard-library/gamma-distribution-class.md)|Produz uma distribuição gama de valores reais (ponto flutuante).|
|[Classe poisson_distribution](../standard-library/poisson-distribution-class.md)|Produz uma distribuição Poisson de valores inteiros.|
|[Classe weibull_distribution](../standard-library/weibull-distribution-class.md)|Produz uma distribuição Weibull de valores reais (ponto flutuante).|

[[Distribuições de número aleatório](#distributions)]

#### <a name="sampling-distributions"></a>Distribuições de Amostragem

|Nome|Descrição|
|-|-|
|[Classe discrete_distribution](../standard-library/discrete-distribution-class.md)|Produz uma distribuição inteira discreta.|
|[Classe piecewise_constant_distribution](../standard-library/piecewise-constant-distribution-class.md)|Produz uma distribuição constante em partes de valores reais (ponto flutuante).|
|[Classe piecewise_linear_distribution](../standard-library/piecewise-linear-distribution-class.md)|Produz uma linear constante em partes de valores reais (ponto flutuante).|

[[Distribuições de número aleatório](#distributions)]

### <a name="utility-functions"></a>Funções de utilitário

Esta seção lista as funções de utilitário gerais fornecidas no cabeçalho \<random>.

|Nome|Descrição|
|-|-|
|[Classe seed_seq](../standard-library/seed-seq-class.md)|Gera uma sequência de transmissão embaralhada e não polarizada. Usadas para evitar a replicação de transmissões variadas aleatórias. Útil quando vários URNGs são instanciados dos mecanismos.|

### <a name="operators"></a>Operadores

Esta seção lista os operadores fornecidos no cabeçalho \<random>.

|Nome|Descrição|
|-|-|
|`operator==`|Testa se o URNG no lado esquerdo do operador é igual ao mecanismo do lado direito.|
|`operator!=`|Testa se o URNG no lado esquerdo do operador não é igual ao mecanismo do lado direito.|
|`operator<<`|Grava informações de estado em uma transmissão.|
|`operator>>`|Extrai informações de estado de uma transmissão.|

## <a name="engines-and-distributions"></a><a name="engdist"></a> Mecanismos e distribuições

Consulte as seções a seguir para obter informações sobre cada uma dessas categorias de modelo de classe definidas em \<random> . Ambas as categorias de modelo de classe usam um tipo como um argumento e usam nomes de parâmetro de modelo compartilhado para descrever as propriedades do tipo que são permitidas como um tipo de argumento real, da seguinte maneira:

- `IntType` indica um **`short`** , **`int`** , **`long`** , **`long long`** , **`unsigned short`** , **`unsigned int`** , **`unsigned long`** ou **`unsigned long long`** .

- `UIntType` indica **`unsigned short`** , **`unsigned int`** , **`unsigned long`** ou **`unsigned long long`** .

- `RealType` indica um **`float`** , **`double`** , ou **`long double`** .

### <a name="engines"></a>Motores

[Modelos do mecanismo](#eng) e [Modelos de adaptador do mecanismo](#engadapt) são modelos cujos parâmetros personalizam o gerador criado.

Um *mecanismo* é um modelo de classe ou classe cujas instâncias (geradores) atuam como uma fonte de números aleatórios distribuídos uniformemente entre um valor mínimo e máximo. Um *adaptador do mecanismo* oferece uma sequência de valores que têm propriedades de aleatoriedade diferentes assumindo valores produzidos por outro mecanismo de número aleatório e aplicando um algoritmo de algum tipo a esses valores.

Cada mecanismo e adaptador do mecanismo possuem os seguintes membros:

- **`typedef`**`numeric-type` `result_type` é o tipo que é retornado pelo gerador `operator()` . O `numeric-type` é transferido como um parâmetro de modelo na instanciação.

- `result_type operator()` retorna valores que são distribuídos uniformemente entre `min()` e `max()`.

- `result_type min()` retorna o valor mínimo retornado pelo `operator()`do gerador. Adaptadores do mecanismo usam o resultado `min()` do mecanismo de base.

- `result_type max()` retorna o valor máximo retornado pelo `operator()`do gerador. Quando `result_type` é um tipo integral (com valor inteiro), `max()` é o valor máximo que pode ser retornado de fato (inclusivo); quando `result_type` é um tipo de ponto flutuante (com valor real), `max()` é o menor valor superior a todos os valores que podem ser retornados (não inclusivo). Adaptadores do mecanismo usam o resultado `max()` do mecanismo de base.

- `void seed(result_type s)` propaga o gerador com o valor de semente `s`. Para mecanismos, a assinatura é `void seed(result_type s = default_seed)` para suporte ao parâmetro padrão (adaptadores do mecanismo definem um `void seed()` separado, consulte a próxima subseção).

- `template <class Seq> void seed(Seq& q)`propaga o gerador usando um [seed_seq](../standard-library/seed-seq-class.md) `Seq` .

- Um construtor explícito com o argumento `result_type x` que cria uma gerador propagado como se fosse chamando `seed(x)`.

- Um construtor explícito com o argumento `seed_seq& seq` que cria uma gerador propagado como se fosse chamando `seed(seq)`.

- `void discard(unsigned long long count)` efetivamente chama `operator()` `count` vezes e descarta cada valor.

**Adaptadores do mecanismo** também dão suporte a esses membros (`Engine` é o primeiro parâmetro de modelo de um adaptador do mecanismo, designando o tipo do mecanismo básico):

- Um construtor padrão para inicializar o gerado como se fosse a partir do construtor padrão do mecanismo básico.

- Um construtor explícito com o argumento `const Engine& eng`. Isso serve para oferecer suporte à construção de cópia usando o mecanismo básico.

- Um construtor explícito com o argumento `Engine&& eng`. Isso serve para oferecer suporte à construção de movimentação usando o mecanismo básico.

- `void seed()` que inicializa o gerador com o valor de semente padrão do mecanismo básico.

- `const Engine& base()` função da propriedade que retorna o mecanismo básico usado para construir o gerador.

Cada mecanismo mantém um *state* que determina a sequência de valores que será gerada pelas chamadas subsequentes para `operator()`. Os estados de dois gerados instanciados a partir de mecanismos do mesmo tipo podem ser comparados usando `operator==` e `operator!=`. Se os dois estados forem comparados e forem iguais, eles gerarão a mesma sequência de valores. O estado de um objeto pode ser salvo em uma transmissão como uma sequência de valores sem sinal de 32 bits usando o `operator<<` do gerador. O estado não é alterado ao salvá-lo. Um estado salvo pode ser lido no gerador instanciado de um mecanismo do mesmo tipo usando `operator>>`.

### <a name="distributions"></a>Distribuições

[Distribuições de números aleatórios](#distributions) são um modelo de classe ou classe cujas instâncias transformam um fluxo de números aleatórios distribuídos uniformemente obtidos de um mecanismo em um fluxo de números aleatórios que têm uma distribuição específica. Cada distribuição possui os seguintes membros:

- **`typedef`**`numeric-type` `result_type` é o tipo que é retornado pelas distribuições `operator()` . O `numeric-type` é transferido como um parâmetro de modelo na instanciação.

- `template <class URNG> result_type operator()(URNG& gen)` retorna valores que são distribuídos de acordo com a definição da distribuição, usando `gen` como uma fonte de valores aleatórios distribuídos uniformemente e os *parâmetros armazenados da distribuição*.

- `template <class URNG> result_type operator()(URNG& gen, param_type p)` retorna valores distribuídos de acordo com a definição da distribuição, usando `gen` como uma fonte de valores aleatórios distribuídos uniformemente e a estrutura de parâmetros `p`.

- **`typedef`**`unspecified-type` `param_type` é o pacote de parâmetros, opcionalmente, passado para `operator()` e é usado no lugar dos parâmetros armazenados para gerar seu valor de retorno.

- Um construtor `const param&` inicializa os parâmetros armazenados do seu argumento.

- `param_type param() const` obtém os parâmetros armazenados.

- `void param(const param_type&)` define os parâmetros armazenados do seu argumento.

- `result_type min()` retorna o valor mínimo retornado pelo `operator()` da distribuição.

- `result_type max()` retorna o valor máximo retornado pelo `operator()` da distribuição. Quando `result_type` é um tipo integral (com valor inteiro), `max()` é o valor máximo que pode ser retornado de fato (inclusivo); quando `result_type` é um tipo de ponto flutuante (com valor real), `max()` é o menor valor superior a todos os valores que podem ser retornados (não inclusivo).

- `void reset()` descarta qualquer valor armazenado em cache, de forma que o resultado da próxima chamada para `operator()` não dependa dos valores obtidos do mecanismo antes da chamada.

Uma estrutura de parâmetro é um objeto que armazena todos os parâmetros necessários para uma distribuição. Ele contém:

- **`typedef`**`distribution-type` `distribution_type` , que é o tipo de sua distribuição.

- Um ou mais construtores que assumem as mesmas listas de parâmetros assumidos pelos construtores da distribuição.

- As mesmas funções de acesso do parâmetro que a distribuição.

- Operadores de comparação de equalidade e inequalidade.

Para obter mais informações, consulte os subtópicos de referência abaixo deste, vinculados anteriormente neste artigo.

## <a name="remarks"></a><a name="comments"></a> Comentários

Há dois URNGs bastante úteis no Visual Studio — `mt19937` e `random_device` — como mostrado na tabela de comparação:

|URNG|Rápido|Protegido por criptografia|Propagável|Determinística|
|----------|-----------|---------------------|---------------|--------------------|
|`mt19937`|Sim|Não|Sim|Ok<sup>*</sup>|
|`random_device`|Não|Sim|Não|Não|

<sup>* Quando fornecido com uma semente conhecida.</sup>

Embora o Padrão ISO C++ não exija que o `random_device` seja protegido por criptografia, no Visual Studio, ele é implementado com proteção criptográfica. (O termo “proteção criptográfica” não implica em garantias, mas se refere ao nível mínimo de entropia e, portanto, ao nível de previsibilidade, que um determinado algoritmo aleatório oferece. Para obter mais informações, consulte o artigo da Wikipédia [pseudoaleatória o gerador de número criptograficamente seguro](https://go.microsoft.com/fwlink/p/?linkid=398017).) Como o ISO C++ Standard não requer isso, outras plataformas podem ser implementadas `random_device` como um gerador de números pseudo aleatórios simples (não criptograficamente seguro) e podem ser adequadas apenas como uma fonte de semente para outro gerador. Verifique a documentação dessas plataformas ao usar `random_device` no código entre plataformas.

Por definição, resultados do `random_device` não são reproduzíveis e um efeito colateral é que ele pode ser executado de maneira significativamente mais lenta do que outros URNGs. A maioria dos aplicativos que não exige proteção criptográfica usa o `mt19937` ou um mecanismo semelhante, embora possa ser útil propagá-lo com uma chamada para `random_device`, como mostrado no [exemplo de código](#code).

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
