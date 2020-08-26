---
title: Classe bernoulli_distribution
ms.date: 11/04/2016
f1_keywords:
- random/std::bernoulli_distribution
- random/std::bernoulli_distribution::reset
- random/std::bernoulli_distribution::p
- random/std::bernoulli_distribution::param
- random/std::bernoulli_distribution::min
- random/std::bernoulli_distribution::max
- random/std::bernoulli_distribution::operator()
- random/std::bernoulli_distribution::param_type
- random/std::bernoulli_distribution::param_type::p
- random/std::bernoulli_distribution::param_type::operator==
- random/std::bernoulli_distribution::param_type::operator!=
helpviewer_keywords:
- std::bernoulli_distribution [C++]
- std::bernoulli_distribution [C++], reset
- std::bernoulli_distribution [C++], p
- std::bernoulli_distribution [C++], param
- std::bernoulli_distribution [C++], min
- std::bernoulli_distribution [C++], max
- std::bernoulli_distribution [C++], param_type
- std::bernoulli_distribution [C++], param_type
ms.assetid: 586bcde1-95ca-411a-bf17-4aaf19482f34
ms.openlocfilehash: bfb63451c8789f7d390e2387ed8fadae23d1c7a5
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846518"
---
# <a name="bernoulli_distribution-class"></a>Classe bernoulli_distribution

Gera uma distribuição Bernoulli.

## <a name="syntax"></a>Sintaxe

```cpp
class bernoulli_distribution
   {
public:
   // types
   typedef bool result_type;
   struct param_type;

   // constructors and reset functions
   explicit bernoulli_distribution(double p = 0.5);
   explicit bernoulli_distribution(const param_type& parm);
   void reset();

   // generating functions
   template <class URNG>
   result_type operator()(URNG& gen);
   template <class URNG>
   result_type operator()(URNG& gen, const param_type& parm);

   // property functions
   double p() const;
   param_type param() const;
   void param(const param_type& parm);
   result_type min() const;
   result_type max() const;
   };
```

### <a name="parameters"></a>parâmetros

*URNG*\
O mecanismo do gerador de número aleatório uniforme. Para possíveis tipos, consulte [\<random>](../standard-library/random.md) .

## <a name="remarks"></a>Comentários

A classe descreve uma distribuição que produz valores do tipo **`bool`** , distribuídos de acordo com a função de probabilidade discreta de distribuição de Bernoulli. A tabela a seguir contém links para artigos sobre cada um dos membros.

[bernoulli_distribution](#bernoulli_distribution)\
[param_type](#param_type)

O membro da propriedade `p()` retorna o valor para o parâmetro de distribuição armazenado `p`.

O membro da propriedade `param()` define ou retorna o pacote de parâmetros de distribuição armazenado `param_type`.

As funções membro `min()` e `max()` retornam o menor resultado possível e o maior resultado possível, respectivamente.

A função membro `reset()` descarta qualquer valor armazenado em cache, de forma que o resultado da próxima chamada para `operator()` não dependerá dos valores obtidos do mecanismo antes da chamada.

As funções membro `operator()` retornam o próximo valor gerado com base no mecanismo URNG, do pacote de parâmetros atual ou do pacote de parâmetros especificado.

Para obter mais informações sobre classes de distribuição e seus membros, consulte [\<random>](../standard-library/random.md) .

Para obter informações detalhadas sobre a função de probabilidade discreta da distribuição Bernoulli, consulte o artigo da Wolfram MathWorld [Bernoulli Distribution](https://go.microsoft.com/fwlink/p/?linkid=398467) (Distribuição Bernoulli).

## <a name="example"></a>Exemplo

```cpp
// compile with: /EHsc /W4
#include <random>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

void test(const double p, const int s) {

    // uncomment to use a non-deterministic seed
    //    std::random_device rd;
    //    std::mt19937 gen(rd());
    std::mt19937 gen(1729);

    std::bernoulli_distribution distr(p);

    std::cout << "p == " << distr.p() << std::endl;

    // generate the distribution as a histogram
    std::map<bool, int> histogram;
    for (int i = 0; i < s; ++i) {
        ++histogram[distr(gen)];
    }

    // print results
    std::cout << "Histogram for " << s << " samples:" << std::endl;
    for (const auto& elem : histogram) {
        std::cout << std::boolalpha << std::setw(5) << elem.first << ' ' << std::string(elem.second, ':') << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    double p_dist = 0.5;
    int samples = 100;

    std::cout << "Use CTRL-Z to bypass data entry and run using default values." << std::endl;
    std::cout << "Enter a double value for p distribution (where 0.0 <= p <= 1.0): ";
    std::cin >> p_dist;
    std::cout << "Enter an integer value for a sample count: ";
    std::cin >> samples;

    test(p_dist, samples);
}
```

```Output
Use CTRL-Z to bypass data entry and run using default values.
Enter a double value for p distribution (where 0.0 <= p <= 1.0): .45
Enter an integer value for a sample count: 100
p == 0.45
Histogram for 100 samples:
false :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
true :::::::::::::::::::::::::::::::::::::::::
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<random>

**Namespace:** std

## <a name="bernoulli_distributionbernoulli_distribution"></a><a name="bernoulli_distribution"></a> bernoulli_distribution:: bernoulli_distribution

Constrói a distribuição.

```cpp
explicit bernoulli_distribution(double p = 0.5);
explicit bernoulli_distribution(const param_type& parm);
```

### <a name="parameters"></a>parâmetros

*DTI*\
O parâmetro de distribuição `p` armazenado.

*Parm*\
A estrutura `param_type` usada para construir a distribuição.

### <a name="remarks"></a>Comentários

**Pré-condição:**`0.0 ≤ p ≤ 1.0`

o primeiro construtor constrói um objeto cujo valor `p` armazenado contém o valor *p*.

O segundo construtor cria um objeto cujos parâmetros armazenados são inicializados de *parm*. Você pode chamar a função de membro `param()` para obter e definir os parâmetros atuais de uma distribuição existente.

## <a name="bernoulli_distributionparam_type"></a><a name="param_type"></a> bernoulli_distribution::p aram_type

Contém os parâmetros da distribuição.

struct param_type {typedef bernoulli_distribution distribution_type; param_type (p duplo = 0,5); Double p () const;

   bool operator==(const param_type& right) const; bool operator!=(const param_type& right) const; };

### <a name="parameters"></a>parâmetros

*DTI*\
O parâmetro de distribuição `p` armazenado.

### <a name="remarks"></a>Comentários

**Pré-condição:**`0.0 ≤ p ≤ 1.0`

Essa estrutura pode ser enviada ao construtor de classe de distribuição na instanciação, para a função de membro `param()` para definir os parâmetros armazenados de uma distribuição existente e para `operator()` a ser usado no lugar dos parâmetros armazenados.

## <a name="see-also"></a>Confira também

[\<random>](../standard-library/random.md)
