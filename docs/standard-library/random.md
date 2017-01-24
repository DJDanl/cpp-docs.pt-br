---
title: "&lt;random&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "<random>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho random"
ms.assetid: 60afc25c-b162-4811-97c1-1b65398d4c57
caps.latest.revision: 58
caps.handback.revision: 46
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;random&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define instalações para a geração de números aleatórios, permitindo a criação de números aleatórios distribuídos uniformemente.  
  
## Sintaxe  
  
```  
#include <random>  
```  
  
## Resumo  
 Um *gerador de número aleatório* é um objeto que produz uma seqüência de valores pseudo\-aleatória. Um gerador que produz valores que são distribuídos uniformemente em um intervalo especificado é um *gerador de número aleatório uniforme* \(URNG\). Uma classe de modelo criada para agir como um URNG é conhecida como um *mecanismo* se essa classe possuir determinados traços em comum, que são discutidos neste artigo. Um URNG pode ser — e geralmente está — combinada com um *distribuição* transmitindo o URNG como um argumento para a distribuição `operator()` para produzir valores que são distribuídos de maneira que é definida pela distribuição.  
  
 Esses links levam para as principais seções deste artigo:  
  
-   [Exemplos](#code)  
  
-   [Lista categorizada](#listing)  
  
-   [Mecanismos e distribuições](#engdist)  
  
-   [Comentários](#comments)  
  
### Dicas rápidas  
 Aqui estão algumas dicas para ter em mente ao usar `<random>`:  
  
-   Em geral, os URNGs produzem bits brutos que podem ser moldados pelas distribuições. \(Uma exceção notável é [std::shuffle\(\)](../Topic/std::shuffle.md) porque ele usa um URNG diretamente.\)  
  
-   Uma única instância de um URNG ou distribuição segura não pode ser chamada simultaneamente porque executando um URNG ou distribuição é uma operação de modificação. Para obter mais informações, consulte [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md).  
  
-   [Typedefs predefinidos](#typedefs) de vários mecanismos fornecidos; esta é a melhor maneira de criar um URNG se um mecanismo estiver sendo usado.  
  
-   O emparelhamento mais útil para a maioria dos aplicativos é o `mt19937` mecanismo com `uniform_int_distribution`, conforme mostrado no [exemplo de código](#code) posteriormente neste artigo.  
  
 Há muitas opções para escolher no `<random>` cabeçalho e nenhum deles é preferível para a função de tempo de execução C desatualizada `rand()`. Para obter informações sobre o que há de errado com `rand()` e como `<random>` aborda essas limitações, consulte [Este vídeo](http://go.microsoft.com/fwlink/?LinkId=397615).  
  
##  <a name="code"></a> Exemplos  
 O exemplo de código a seguir mostra como gerar alguns números aleatórios nesse caso cinco deles usando um gerador criado com semente não determinista.  
  
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
  
 **Saída:**  
  
```Output  
2430338871 3531691818 2723770500 3252414483 3632920437  
```  
  
 Embora esses são números aleatórios de alta qualidade e diferentes sempre que este programa seja executado, eles não são necessariamente em um intervalo útil. Para controlar o intervalo, use uma distribuição uniforme, conforme mostrado no código a seguir:  
  
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
  
 **Saída:**  
  
```Output  
5 1 6 1 2  
```  
  
 O próximo exemplo de código mostra um conjunto mais realista de casos de uso com geradores de números aleatórios uniformemente distribuídos misturando o conteúdo de um vetor e uma matriz.  
  
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
  
## Saída de exemplo e comentários de código  
  
```Output  
Usando o URNG random_device: vetor aleatória: 5-4 2 3 0 5-2 0 4 2 2-1 -4-3 1 4 4 1 2-2 aleatória matriz: O Li V K C Ti N Mg Ne Sc Cl B Cr Mn Ca Al F P Na ser Si Ar Fe S He H – usando URNG constante semente mersenne twister: vetor aleatória : -1 3 3 de 5-5 0 0 -3-4 1-4 0-3 -2-3 1 de 5-4 -1-1 aleatória matriz: Al O Ne Si Na ser C N Cr Mn H V F Sc Mg Fe K Ca S Ti B P Ar Cl Li He - usando URNG semente não-determinística mersenne twister: vetor aleatória: 5-4 0 2 1-2 4 4-4 0 0 4-5 4 -1-5-3 0 0 3 matriz aleatória : Si Fe Al Ar Na P B Sc H F Mg Li C Ti ele N Mn ser O Ca Cr V K Ne Cl S – aquecimento"semente não-determinística usando" URNG mersenne twister de: vetor aleatória: 3-1 4-2 1 3 0 5-5-5 0 0 5 0-3 de 3 2-4 5 0 matriz aleatória: Si C Sc H no S Cr K Li Al Ti Cl B Mn ele Fe Ne ser Ar V P Ca N Mg F-  
```  
  
 Esse código demonstra duas aleatorizações diferentes, aleatorizar um vetor de inteiros e embaralhar uma matriz de dados indexados — com uma função de modelo de teste. A primeira chamada para a função de teste usa o URNG protegido por criptografia, não determinista, não passível de propagação, não repetíveis `random_device`. O segundo teste executado usa `mersenne_twister_engine` como URNG, com uma semente de constante de 32 bits determinística, que significa que os resultados são repetidos. A terceira execução do teste propaga `mersenne_twister_engine` com um resultado não determinista de 32 bits de `random_device`. O quarta execução do teste é expandida usando um [propagar sequência](../standard-library/seed-seq-class.md) preenchido com `random_device` resultados, que oferece efetivamente mais do que a aleatorização não determinista de 32 bits \(mas ainda não protegido por criptografia\). Para obter mais informações, leia.  
  
##  <a name="listing"></a> Lista categorizada  
  
###  <a name="urngs"></a> Geradores de números aleatórios uniformes  
 URNGs geralmente são descritos em termos dessas propriedades:  
  
1.  **Período**: quantas iterações são necessárias para repetir a seqüência de números gerada. Quanto maior, melhor.  
  
2.  **Desempenho**: rapidez números podem ser gerados e quanta memória isso ocupa. Quanto menor, melhor.  
  
3.  **Qualidade**: A proximidade de números aleatórios verdadeiramente sequência gerada. Isso é geralmente chamado de "*aleatoriedade*".  
  
 As seções a seguir listam os uniformes geradores de números aleatórios \(URNGs\) fornecidos a `<random>` cabeçalho.  
  
####  <a name="rd"></a> Gerador não determinista  
  
|||  
|-|-|  
|[Classe random\_device](../Topic/random_device%20Class.md)|Gera uma sequência aleatória não determinista, criptograficamente segura usando um dispositivo externo. Geralmente usado para propagar um mecanismo. Baixo desempenho, qualidade bastante alta. Para obter mais informações, consulte [Comentários](#comments).|  
  
####  <a name="typedefs"></a> Definições de tipo de mecanismo com parâmetros predefinidos  
 Para mecanismos de instanciação e adaptadores de mecanismo. Para obter mais informações, consulte [Mecanismos e distribuições](#engdist).  
  
-   `default_random_engine` O mecanismo padrão.  
    `typedef mt19937 default_random_engine;`  
  
-   `knuth_b` Mecanismo de Knuth.  
    `typedef shuffle_order_engine<minstd_rand0, 256> knuth_b;`  
  
-   `minstd_rand0` 1988 mecanismo padrão mínimo \(Lewis, Goodman e Miller, 1969\).  
    `typedef linear_congruential_engine<unsigned int, 16807, 0, 2147483647> minstd_rand0;`  
  
-   `minstd_rand` Mecanismo padrão mínimo atualizado `minstd_rand0` \(Park, Miller e Stockmeyer, 1993\).  
    `typedef linear_congruential_engine<unsigned int, 48271, 0, 2147483647> minstd_rand;`  
  
-   `mt19937` 32 bits mecanismo Mersenne twister \(Matsumoto e Nishimura, 1998\).  
    `typedef mersenne_twister_engine<unsigned int, 32, 624, 397, 31, 0x9908b0df, 11, 0xffffffff, 7, 0x9d2c5680, 15, 0xefc60000, 18, 1812433253> mt19937;`  
  
-   `mt19937_64` 64 bits mecanismo Mersenne twister \(Matsumoto e Nishimura, 2000\).  
    `typedef mersenne_twister_engine<unsigned long long, 64, 312, 156, 31, 0xb5026f5aa96619e9ULL, 29, 0x5555555555555555ULL, 17, 0x71d67fffeda60000ULL, 37, 0xfff7eee000000000ULL, 43, 6364136223846793005ULL> mt19937_64;`  
  
-   `ranlux24` mecanismo RANLUX de 24 bits \(Martin Lüscher e Fred James, 1994\).  
    `typedef discard_block_engine<ranlux24_base, 223, 23> ranlux24;`  
  
-   `ranlux24_base` Usado como base para `ranlux24`.  
    `typedef subtract_with_carry_engine<unsigned int, 24, 10, 24> ranlux24_base;`  
  
-   `ranlux48` mecanismo RANLUX de 48 bits \(Martin Lüscher e Fred James, 1994\).  
    `typedef discard_block_engine<ranlux48_base, 389, 11> ranlux48;`  
  
-   `ranlux48_base` Usado como base para `ranlux48`.  
    `typedef subtract_with_carry_engine<unsigned long long, 48, 5, 12> ranlux48_base;`  
  
####  <a name="eng"></a> Modelos de mecanismos  
 Modelos de mecanismos são usados como URNGs independentes ou como mecanismos de base passados para [adaptadores do mecanismo](#engadapt). Geralmente, eles são instanciados com um [predefinidos typedef de mecanismo](#typedefs) e passado para um [distribuição](#distributions). Para obter mais informações, consulte o [mecanismos e distribuições](#engdist) seção.  
  
|||  
|-|-|  
|[Classe linear\_congruential\_engine](../standard-library/linear-congruential-engine-class.md)|Gera uma sequência aleatória usando o algoritmo Congruente linear. Mais simples e mais baixa qualidade.|  
|[Classe mersenne\_twister\_engine](../standard-library/mersenne-twister-engine-class.md)|Gera uma sequência aleatória usando o algoritmo Mersenne twister. Mais complexo, e é a mais alta qualidade, exceto para a classe random\_device. Desempenho muito rápido.|  
|[Classe subtract\_with\_carry\_engine](../Topic/subtract_with_carry_engine%20Class.md)|Gera uma sequência aleatória usando o algoritmo de subtração com transferência. Um aprimoramento em `linear_congruential_engine`, mas muito mais baixa qualidade e desempenho do que `mersenne_twister_engine`.|  
  
####  <a name="engadapt"></a> Modelos de adaptador do mecanismo  
 Adaptadores de mecanismo são modelos que adaptam outros mecanismos \(base\). Geralmente, eles são instanciados com um [predefinidos typedef de mecanismo](#typedefs) e passado para um [distribuição](#distributions). Para obter mais informações, consulte o [mecanismos e distribuições](#engdist) seção.  
  
|||  
|-|-|  
|[Classe discard\_block\_engine](../standard-library/discard-block-engine-class.md)|Gera uma sequência aleatória descartando valores retornados pelo mecanismo básico.|  
|[Classe independent\_bits\_engine](../standard-library/independent-bits-engine-class.md)|Gera uma sequência aleatória com um número especificado de bits recompactando bits dos valores retornados pelo mecanismo básico.|  
|[Classe shuffle\_order\_engine](../Topic/shuffle_order_engine%20Class.md)|Gera uma sequência aleatória reordenando os valores retornados do mecanismo de base.|  
  
 \[[Modelos de mecanismos](#eng)\]  
  
###  <a name="distributions"></a> Distribuições de número aleatório  
 As seções a seguir listam as distribuições fornecidas no `<random>` cabeçalho. Distribuições são um mecanismo de pós\-processamento, geralmente usando a saída URNG como entrada e distribuem a saída de uma função de densidade de probabilidade estatística definida. Para obter mais informações, consulte o [mecanismos e distribuições](#engdist) seção.  
  
#### Distribuições uniformes  
  
|||  
|-|-|  
|[Classe uniform\_int\_distribution](../standard-library/uniform-int-distribution-class.md)|Produz uma distribuição de valor de inteiro uniforme em um intervalo no intervalo fechado \[a, b\] \(inclusivo\-inclusivo\).|  
|[Classe uniform\_real\_distribution](../Topic/uniform_real_distribution%20Class.md)|Produz um real uniforme distribuição de valor \(ponto flutuante\) em um intervalo no intervalo \[a, b\) \(inclusivo\-exclusivo\).|  
|[generate\_canonical](../Topic/generate_canonical.md)|Produz uma distribuição uniforme de valores reais \(ponto flutuante\) de uma determinada precisão em \[0, 1\) \(inclusivo\-exclusivo\).|  
  
 \[[Distribuições de número aleatório](#distributions)\]  
  
#### Distribuições Bernoulli  
  
|||  
|-|-|  
|[Classe bernoulli\_distribution](../standard-library/bernoulli-distribution-class.md)|Produz uma distribuição Bernoulli de `bool` valores.|  
|[Classe binomial\_distribution](../standard-library/binomial-distribution-class.md)|Produz uma distribuição binomial de valores inteiros.|  
|[Classe geometric\_distribution](../standard-library/geometric-distribution-class.md)|Produz uma distribuição geométrica de valores inteiros.|  
|[Classe negative\_binomial\_distribution](../standard-library/negative-binomial-distribution-class.md)|Produz uma distribuição binomial negativa de valores inteiros.|  
  
 \[[Distribuições de número aleatório](#distributions)\]  
  
#### Distribuições normais  
  
|||  
|-|-|  
|[Classe cauchy\_distribution](../standard-library/cauchy-distribution-class.md)|Produz uma distribuição de Cauchy de valores reais \(ponto flutuante\).|  
|[Classe chi\_squared\_distribution](../Topic/chi_squared_distribution%20Class.md)|Produz uma distribuição qui\-quadrada de valores reais \(ponto flutuante\).|  
|[Classe fisher\_f\_distribution](../Topic/fisher_f_distribution%20Class.md)|Produz uma distribuição F \(também conhecido como distribuição F de Snedecor ou distribuição Fisher – Snedecor\) de valores reais \(ponto flutuante\).|  
|[Classe lognormal\_distribution](../Topic/lognormal_distribution%20Class.md)|Produz uma distribuição log\-normal de valores reais \(ponto flutuante\).|  
|[Classe normal\_distribution](../standard-library/normal-distribution-class.md)|Produz uma distribuição normal \(Gaussian\) de valores reais \(ponto flutuante\).|  
|[Classe student\_t\_distribution](../standard-library/student-t-distribution-class.md)|Produz um aluno *t*\-distribuição de valores reais \(ponto flutuante\).|  
  
 \[[Distribuições de número aleatório](#distributions)\]  
  
#### Distribuições Poisson  
  
|||  
|-|-|  
|[Classe exponential\_distribution](../standard-library/exponential-distribution-class.md)|Produz uma distribuição exponencial de valores reais \(ponto flutuante\).|  
|[Classe extreme\_value\_distribution](../Topic/extreme_value_distribution%20Class.md)|Produz uma distribuição de valor extremo de valores reais \(ponto flutuante\).|  
|[Classe gamma\_distribution](../standard-library/gamma-distribution-class.md)|Produz uma distribuição gama de valores reais \(ponto flutuante\).|  
|[Classe poisson\_distribution](../standard-library/poisson-distribution-class.md)|Produz uma distribuição Poisson de valores inteiros.|  
|[Classe weibull\_distribution](../Topic/weibull_distribution%20Class.md)|Produz uma distribuição Weibull de valores reais \(ponto flutuante\).|  
  
 \[[Distribuições de número aleatório](#distributions)\]  
  
#### Distribuições de amostragem  
  
|||  
|-|-|  
|[Classe discrete\_distribution](../standard-library/discrete-distribution-class.md)|Produz uma distribuição discreta de inteiros.|  
|[Classe piecewise\_constant\_distribution](../Topic/piecewise_constant_distribution%20Class.md)|Produz um em partes constante distribuição de valores reais \(ponto flutuante\).|  
|[Classe piecewise\_linear\_distribution](../standard-library/piecewise-linear-distribution-class.md)|Produz um em partes linear distribuição de valores reais \(ponto flutuante\).|  
  
 \[[Distribuições de número aleatório](#distributions)\]  
  
### Funções de utilitário  
 Esta seção lista as funções de utilitário gerais fornecidas no `<random>` cabeçalho.  
  
|||  
|-|-|  
|[Classe seed\_seq](../standard-library/seed-seq-class.md)|Gera uma sequência embaralhada e não polarizada. Usado para evitar a replicação de transmissões variadas aleatórias. Útil quando vários URNGs são instanciados dos mecanismos.|  
  
### Operadores  
 Esta seção lista os operadores fornecidos no `<random>` cabeçalho.  
  
|||  
|-|-|  
|`operator==`|Testa se o URNG no lado esquerdo do operador é igual ao mecanismo do lado direito.|  
|`operator!=`|Testa se o URNG no lado esquerdo do operador não é igual ao mecanismo do lado direito.|  
|`operator<<`|Grava informações de estado em um fluxo.|  
|`operator>>`|Extrai informações de estado de um fluxo.|  
  
##  <a name="engdist"></a> Mecanismos e distribuições  
 Consulte as seções a seguir para obter informações sobre cada uma dessas categorias de classe de modelo definido em `<random>`. Ambas essas categorias de classe de modelo assumem um tipo como um argumento e usam nomes de parâmetro de modelo compartilhados para descrever as propriedades do tipo que são permitidas como um tipo de argumento real, da seguinte maneira:  
  
-   `IntType` indicates a `short`, `int`, `long`, `long long`, `unsigned short`, `unsigned int`, `unsigned long`, or `unsigned long long`.  
  
-   `UIntType` indica `unsigned short`, `unsigned int`, `unsigned long`, ou `unsigned long long`.  
  
-   `RealType` indica um `float`, `double`, ou `long double`.  
  
### Mecanismos  
 [Modelos de mecanismos](#eng) e [Modelos de adaptador do mecanismo](#engadapt) são modelos cujos parâmetros personalizam o gerador criado.  
  
 Um *mecanismo* é uma classe ou classe de modelo cujas instâncias \(geradores\) agem como uma fonte de números aleatórios uniformemente distribuído entre um valor mínimo e máximo. Um *adaptador do mecanismo* oferece uma sequência de valores que possuem propriedades de aleatoriedade diferentes usando os valores produzidos por outro mecanismo de número aleatório e aplicando um algoritmo de algum tipo a esses valores.  
  
 Cada mecanismo e adaptador de mecanismo tem os seguintes membros:  
  
-   `typedef`  `numeric-type`  `result_type` é o tipo retornado pelo gerador de `operator()`. O `numeric-type` é passado como um parâmetro de modelo na instanciação.  
  
-   `result_type operator()` Retorna valores que são distribuídos uniformemente entre `min()` e `max()`.  
  
-   `result_type min()` Retorna o valor mínimo que é retornado pelo gerador de `operator()`. Adaptadores do mecanismo usam o mecanismo de base `min()` resultado.  
  
-   `result_type max()` Retorna o valor máximo que é retornado pelo gerador de `operator()`. Quando `result_type` é um tipo integral \(números inteiros\), `max()` é o valor máximo que pode ser retornado de fato \(inclusivo\); quando `result_type` é um tipo ponto flutuante \(com valor real\), `max()` é o menor valor maior do que todos os valores que podem ser retornados \(não inclusivo\). Adaptadores do mecanismo usam o mecanismo de base `max()` resultado.  
  
-   `void seed(result_type s)` propaga o gerador com valor de semente `s`. Para mecanismos, a assinatura é `void seed(result_type s = default_seed)` para suporte de parâmetro padrão \(adaptadores do mecanismo definem um separado `void seed()`, consulte a próxima subseção\).  
  
-   `template <class Seq> void seed(Seq& q)` propaga o gerador usando um [seed\_seq](../standard-library/seed-seq-class.md)`Seq`.  
  
-   Um construtor explícito com argumento `result_type x` que cria uma gerador propagado como se fosse chamando `seed(x)`.  
  
-   Um construtor explícito com argumento `seed_seq& seq` que cria uma gerador propagado como se fosse chamando `seed(seq)`.  
  
-   `void discard(unsigned long long count)` efetivamente chama `operator()``count` vezes e descarta cada valor.  
  
 **Adaptadores do mecanismo** também oferecem suporte esses membros \(`Engine` é o primeiro parâmetro de modelo de um adaptador de mecanismo, designando o tipo do mecanismo básico\):  
  
-   Um construtor padrão para inicializar o gerador de como se do construtor de padrão do mecanismo básico.  
  
-   Um construtor explícito com o argumento `const Engine& eng`. Isso é para oferecer suporte à construção de cópia usando o mecanismo básico.  
  
-   Um construtor explícito com o argumento `Engine&& eng`. Isso é para oferecer suporte à construção de movimentação usando o mecanismo básico.  
  
-   `void seed()` que inicializa o gerador com o valor de semente padrão do mecanismo básico.  
  
-   `const Engine& base()` função de propriedade que retorna o mecanismo básico que foi usada para construir o gerador.  
  
 Cada mecanismo mantém uma *estado* que determina a seqüência de valores que serão geradas por chamadas subsequentes para `operator()`. Os estados de dois gerados instanciados dos mecanismos do mesmo tipo podem ser comparados usando `operator==` e `operator!=`. Se os dois estados comparam como iguais, elas gerarão a mesma seqüência de valores. O estado de um objeto pode ser salvos em um fluxo como uma seqüência de valores não assinados de 32 bits usando o `operator<<` do gerador. O estado não é alterado ao salvá\-lo. Um estado salvo pode ser lido no gerador instanciado de um mecanismo do mesmo tipo usando `operator>>`.  
  
### Distribuições  
 A [Distribuições de número aleatório](#distributions) é uma classe ou classe de modelo cujas instâncias transformam uma transmissão de números aleatórios distribuídos uniformemente obtidos de um mecanismo em um fluxo de números aleatórios que possuem uma distribuição específica. Cada distribuição possui os seguintes membros:  
  
-   `typedef`  `numeric-type`  `result_type` é o tipo retornado para a distribuição `operator()`. O `numeric-type` é passado como um parâmetro de modelo na instanciação.  
  
-   `template <class URNG> result_type operator()(URNG& gen)` Retorna valores que são distribuídos de acordo com a definição da distribuição, usando `gen` como uma fonte de valores aleatórios distribuídos uniformemente e armazenado *parâmetros da distribuição*.  
  
-   `template <class URNG> result_type operator()(URNG& gen, param_type p)` Retorna valores distribuídos de acordo com a definição da distribuição, usando `gen` como uma fonte de valores aleatórios distribuídos uniformemente e a estrutura dos parâmetros `p`.  
  
-   `typedef`  `unspecified-type`  `param_type` é o pacote de parâmetros transmitido opcionalmente para `operator()` e é usado no lugar dos parâmetros armazenados para gerar o valor de retorno.  
  
-   Um `const param&` construtor inicializa os parâmetros armazenados do seu argumento.  
  
-   `param_type param() const` Obtém os parâmetros armazenados.  
  
-   `void param(const param_type&)` Define os parâmetros armazenados do seu argumento.  
  
-   `result_type min()` Retorna o valor mínimo que é retornado para a distribuição `operator()`.  
  
-   `result_type max()` Retorna o valor máximo é retornado para a distribuição `operator()`. Quando `result_type` é um tipo integral \(números inteiros\), `max()` é o valor máximo que pode ser retornado de fato \(inclusivo\); quando `result_type` é um tipo ponto flutuante \(com valor real\), `max()` é o menor valor maior do que todos os valores que podem ser retornados \(não inclusivo\).  
  
-   `void reset()` descarta qualquer valor armazenado em cache, para que o resultado da próxima chamada para `operator()` não dependa dos valores obtidos do mecanismo antes da chamada.  
  
 Uma estrutura de parâmetro é um objeto que armazena todos os parâmetros necessários para uma distribuição. Ele contém:  
  
-   `typedef`  `distribution-type`  `distribution_type`, que é o tipo da distribuição.  
  
-   Um ou mais construtores que usam o mesmo parâmetro de lista como o take de construtores de distribuição.  
  
-   As mesmas funções de acesso do parâmetro de distribuição.  
  
-   Operadores de comparação de igualdade e desigualdade.  
  
 Para obter mais informações, consulte os subtópicos de referência abaixo deste, vinculados anteriormente neste artigo.  
  
##  <a name="comments"></a> Comentários  
 Há dois urngs bastante úteis no Visual Studio —`mt19937` e `random_device`conforme mostrado na tabela de comparação:  
  
|URNG|Rápida?|Protegido por criptografia?|Passível de propagação?|Determinística?|  
|----------|-------------|---------------------------------|-----------------------------|---------------------|  
|`mt19937`|Sim|Não|Sim|Yes<sup>*</sup>|  
|`random_device`|Não|Sim|Não|Não|  
  
 <sup>* Quando fornecido com uma semente conhecida.</sup>  
  
 Embora o padrão ISO C\+\+ não exija `random_device` para ser criptograficamente seguro, no Visual Studio, ele é implementado para ser criptograficamente seguro. \(O termo "proteção criptográfica" não implica em garantias, mas se refere a um nível mínimo de entropia — e, portanto, o nível de previsibilidade — um determinado algoritmo aleatório oferece. Para obter mais informações, consulte o artigo da Wikipedia [criptograficamente seguro gerador de números pseudoaleatórios](http://go.microsoft.com/fwlink/?LinkId=398017).\) Como o padrão ISO C\+\+ não exigem isso, outras plataformas podem implementar `random_device` como um simple pseudo gerador de número aleatório \(sem proteção criptográfica\) e pode apenas ser adequado como uma fonte de propagação para gerador de outro. Verifique a documentação dessas plataformas ao usar `random_device` no código de plataforma cruzada.  
  
 Por definição, `random_device` resultados não são reproduzíveis e um efeito colateral é que ele fique significativamente mais lenta do que outros URNGs. A maioria dos aplicativos que não precisam ser criptograficamente seguro usar `mt19937` ou uma semelhante do mecanismo, embora você talvez queira propagá\-lo com uma chamada para `random_device`, conforme mostrado no [exemplo de código](#code).  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)