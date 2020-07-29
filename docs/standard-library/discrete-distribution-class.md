---
title: Classe discrete_distribution
ms.date: 11/04/2016
f1_keywords:
- random/std::discrete_distribution
- random/std::discrete_distribution::reset
- random/std::discrete_distribution::probabilities
- random/std::discrete_distribution::param
- random/std::discrete_distribution::min
- random/std::discrete_distribution::max
- random/std::discrete_distribution::operator()
- random/std::discrete_distribution::param_type
- random/std::discrete_distribution::param_type::probabilities
- random/std::discrete_distribution::param_type::operator==
- random/std::discrete_distribution::param_type::operator!=
helpviewer_keywords:
- std::discrete_distribution [C++]
- std::discrete_distribution [C++], reset
- std::discrete_distribution [C++], probabilities
- std::discrete_distribution [C++], param
- std::discrete_distribution [C++], min
- std::discrete_distribution [C++], max
- std::discrete_distribution [C++], param_type
- std::discrete_distribution [C++], param_type
ms.assetid: 8c8ba8f8-c06f-4f07-b354-f53950142fcf
ms.openlocfilehash: 65d5c993efd1cb9c6dd35f11223ed39e026ed7c6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217799"
---
# <a name="discrete_distribution-class"></a>Classe discrete_distribution

Gera uma distribuição discreta de inteiros que tem intervalos com largura uniforme e probabilidade uniforme em cada intervalo.

## <a name="syntax"></a>Sintaxe

```cpp
template<class IntType = int>
class discrete_distribution
   {
public:
   // types
   typedef IntType result_type;
   struct param_type;

   // constructor and reset functions
   discrete_distribution();
   template <class InputIterator>
   discrete_distribution(InputIterator firstW, InputIterator lastW);
   discrete_distribution(initializer_list<double> weightlist);
   template <class UnaryOperation>
   discrete_distribution(size_t count, double xmin, double xmax, UnaryOperation funcweight);
   explicit discrete_distribution(const param_type& parm);
   void reset();

   // generating functions
   template <class URNG>
   result_type operator()(URNG& gen);
   template <class URNG>
   result_type operator()(URNG& gen, const param_type& parm);

   // property functions
   vector<double> probabilities() const;
   param_type param() const;
   void param(const param_type& parm);
   result_type min() const;
   result_type max() const;
   };
```

### <a name="parameters"></a>parâmetros

*IntType*\
O tipo de resultado inteiro, o padrão é **`int`** . Para possíveis tipos, consulte [\<random>](../standard-library/random.md) .

## <a name="remarks"></a>Comentários

Essa distribuição de amostragem tem intervalos de largura uniforme e probabilidade uniforme em cada intervalo. Para obter informações sobre outras distribuições de amostragem, consulte [Classe piecewise_linear_distribution](../standard-library/piecewise-linear-distribution-class.md) e [Classe piecewise_constant_distribution](../standard-library/piecewise-constant-distribution-class.md).

A tabela a seguir contém links para artigos sobre cada um dos membros:

|||
|-|-|
|[discrete_distribution](#discrete_distribution)|`discrete_distribution::param`|
|`discrete_distribution::operator()`|[param_type](#param_type)|

A função de propriedade `vector<double> probabilities()` mostra as probabilidades de cada inteiro gerado.

Para obter mais informações sobre classes de distribuição e seus membros, consulte [\<random>](../standard-library/random.md) .

## <a name="example"></a>Exemplo

```cpp
// compile with: /EHsc /W4
#include <random>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

void test(const int s) {

    // uncomment to use a non-deterministic generator
    // random_device rd;
    // mt19937 gen(rd());
    mt19937 gen(1701);

    discrete_distribution<> distr({ 1, 2, 3, 4, 5 });

    cout << endl;
    cout << "min() == " << distr.min() << endl;
    cout << "max() == " << distr.max() << endl;
    cout << "probabilities (value: probability):" << endl;
    vector<double> p = distr.probabilities();
    int counter = 0;
    for (const auto& n : p) {
        cout << fixed << setw(11) << counter << ": " << setw(14) << setprecision(10) << n << endl;
        ++counter;
    }
    cout << endl;

    // generate the distribution as a histogram
    map<int, int> histogram;
    for (int i = 0; i < s; ++i) {
        ++histogram[distr(gen)];
    }

    // print results
    cout << "Distribution for " << s << " samples:" << endl;
    for (const auto& elem : histogram) {
        cout << setw(5) << elem.first << ' ' << string(elem.second, ':') << endl;
    }
    cout << endl;
}

int main()
{
    int samples = 100;

    cout << "Use CTRL-Z to bypass data entry and run using default values." << endl;
    cout << "Enter an integer value for the sample count: ";
    cin >> samples;

    test(samples);
}
```

```Output
Use CTRL-Z to bypass data entry and run using default values.
Enter an integer value for the sample count: 100
min() == 0
max() == 4
probabilities (value: probability):
          0:   0.0666666667
          1:   0.1333333333
          2:   0.2000000000
          3:   0.2666666667
          4:   0.3333333333

Distribution for 100 samples:
    0 :::
    1 ::::::::::::::
    2 ::::::::::::::::::
    3 :::::::::::::::::::::::::::::
    4 ::::::::::::::::::::::::::::::::::::
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<random>

**Namespace:** std

## <a name="discrete_distributiondiscrete_distribution"></a><a name="discrete_distribution"></a>discrete_distribution::d iscrete_distribution

Constrói a distribuição.

```cpp
// default constructor
discrete_distribution();

// construct using a range of weights, [firstW, lastW)
template <class InputIterator>
discrete_distribution(InputIterator firstW, InputIterator lastW);

// construct using an initializer list for range of weights
discrete_distribution(initializer_list<double> weightlist);

// construct using unary operation function
template <class UnaryOperation>
discrete_distribution(size_t count, double low, double high, UnaryOperation weightfunc);

// construct from an existing param_type structure
explicit discrete_distribution(const param_type& parm);
```

### <a name="parameters"></a>parâmetros

*firstW*\
O primeiro iterador na lista do qual a distribuição deve ser construída.

*lastW*\
O último iterador na lista do qual a distribuição deve ser construída (não inclusivo, pois os iteradores usam um elemento vazio no final).

*pesolist*\
O [initializer_list](../cpp/initializers.md) do qual construir a distribuição.

*contar*\
O número de elementos no intervalo de distribuição. Se `count==0`, equivalente ao construtor padrão (sempre gera zero).

*pequena*\
O valor mais baixo no intervalo de distribuição.

*elevada*\
O valor mais alto no intervalo de distribuição.

*weightfunc*\
O objeto que representa a função de probabilidade para a distribuição. O parâmetro e o valor de retorno devem ser conversíveis **`double`** .

*Parm*\
A estrutura `param_type` usada para construir a distribuição.

### <a name="remarks"></a>Comentários

O construtor padrão constrói um objeto cujo valor de probabilidade armazenado possui um elemento com valor 1. Isso resultará em uma distribuição que sempre gera um zero.

O construtor do intervalo do iterador que tem parâmetros *firstW* e *lastW* constrói um objeto de distribuição usando valores de peso obtidos dos iteradores na sequência de intervalo [*firstW*, *lastW*).

O construtor da lista de inicializadores que tem um parâmetro *weightlist* constrói um objeto de distribuição com pesos da lista do inicializador *weightlist*.

O construtor que tem os parâmetros *count*, *low*, *high* e *weightfunc* constrói um objeto de distribuição inicializado com base nessas regras:

- Se *count* < 1, **n** = 1 e, como tal, equivale ao construtor padrão, sempre gerando zero.
- Se *count* > 0, **n** = *count*. Fornecido **d** = (*alto*  -  *baixo*)/ **n** é maior que zero, usando subintervalos de **d** uniforme, cada peso é atribuído da seguinte maneira: `weight[k] = weightfunc(x)` , em que **x**  =  *baixo*  +  **k**  *  **d**  +  **d** /2, para **k** = 0,..., **n** -1.

O construtor que tem um parâmetro `param_type`*parm* constrói um objeto de distribuição usando *parm* como a estrutura de parâmetro armazenada.

## <a name="discrete_distributionparam_type"></a><a name="param_type"></a>discrete_distribution::p aram_type

Armazena todos os parâmetros da distribuição.

```cpp
struct param_type {
   typedef discrete_distribution<result_type> distribution_type;
   param_type();

   // construct using a range of weights, [firstW, lastW)
   template <class InputIterator>
   param_type(InputIterator firstW, InputIterator lastW);

   // construct using an initializer list for range of weights
   param_type(initializer_list<double> weightlist);

   // construct using unary operation function
   template <class UnaryOperation>
   param_type(size_t count, double low, double high, UnaryOperation weightfunc);

   std::vector<double> probabilities() const;

   bool operator==(const param_type& right) const;
   bool operator!=(const param_type& right) const;
   };
```

### <a name="parameters"></a>parâmetros

*firstW*\
O primeiro iterador na lista do qual a distribuição deve ser construída.

*lastW*\
O último iterador na lista do qual a distribuição deve ser construída (não inclusivo, pois os iteradores usam um elemento vazio no final).

*pesolist*\
O [initializer_list](../cpp/initializers.md) do qual construir a distribuição.

*contar*\
O número de elementos no intervalo de distribuição. Se *count* for 0, ele será equivalente ao construtor padrão (sempre gera zero).

*pequena*\
O valor mais baixo no intervalo de distribuição.

*elevada*\
O valor mais alto no intervalo de distribuição.

*weightfunc*\
O objeto que representa a função de probabilidade para a distribuição. O parâmetro e o valor de retorno devem ser conversíveis **`double`** .

*Certo*\
O objeto `param_type` a ser comparado a este.

### <a name="remarks"></a>Comentários

Este pacote de parâmetros pode ser passado para `operator()` para gerar o valor retornado.

## <a name="see-also"></a>Confira também

[\<random>](../standard-library/random.md)
