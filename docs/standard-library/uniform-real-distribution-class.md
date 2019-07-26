---
title: Classe uniform_real_distribution
ms.date: 11/04/2016
f1_keywords:
- random/std::uniform_real_distribution
- random/std::uniform_real_distribution::reset
- random/std::uniform_real_distribution::a
- random/std::uniform_real_distribution::b
- random/std::uniform_real_distribution::param
- random/std::uniform_real_distribution::min
- random/std::uniform_real_distribution::max
- random/std::uniform_real_distribution::operator()
- random/std::uniform_real_distribution::param_type
- random/std::uniform_real_distribution::param_type::a
- random/std::uniform_real_distribution::param_type::b
- random/std::uniform_real_distribution::param_type::operator==
- random/std::uniform_real_distribution::param_type::operator!=
helpviewer_keywords:
- std::uniform_real_distribution [C++]
- std::uniform_real_distribution [C++], reset
- std::uniform_real_distribution [C++], a
- std::uniform_real_distribution [C++], b
- std::uniform_real_distribution [C++], param
- std::uniform_real_distribution [C++], min
- std::uniform_real_distribution [C++], max
- std::uniform_real_distribution [C++], param_type
- std::uniform_real_distribution [C++], param_type
ms.assetid: 5cf906fd-0319-4984-b21b-98425cd7532d
ms.openlocfilehash: 752226c9cacfdd36b93890502d62187f7b44a8da
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68454945"
---
# <a name="uniformrealdistribution-class"></a>Classe uniform_real_distribution

Gera uma distribuição de ponto flutuante uniforme (todos os valores têm a mesma probabilidade) no intervalo de saída que é inclusivo-exclusivo.

## <a name="syntax"></a>Sintaxe

```cpp
template<class RealType = double>
   class uniform_real_distribution {
public:
   // types
   typedef RealType result_type;
   struct param_type;

   // constructors and reset functions
   explicit uniform_real_distribution(
      result_type a = 0.0, result_type b = 1.0);
   explicit uniform_real_distribution(const param_type& parm);
   void reset();

   // generating functions
   template <class URNG>
      result_type operator()(URNG& gen);
   template <class URNG>
      result_type operator()(URNG& gen, const param_type& parm);

   // property functions
   result_type a() const;
   result_type b() const;
   param_type param() const;
   void param(const param_type& parm);
   result_type min() const;
   result_type max() const;
};
```

### <a name="parameters"></a>Parâmetros

*RealType*\
O tipo de resultado de ponto flutuante, assume o padrão de **Double**. Para encontrar os tipos possíveis, consulte [\<random>](../standard-library/random.md).

## <a name="remarks"></a>Comentários

A classe de modelo descreve uma distribuição inclusive-exclusive que produz valores de um tipo de ponto flutuante integral especificado pelo usuário, com tal distribuição que todo valor seja igualmente provável. A tabela a seguir contém links para artigos sobre cada um dos membros.

||||
|-|-|-|
|[uniform_real_distribution](#uniform_real_distribution)|`uniform_real_distribution::a`|`uniform_real_distribution::param`|
|`uniform_real_distribution::operator()`|`uniform_real_distribution::b`|[param_type](#param_type)|

O membro da propriedade `a()` retorna o limite mínimo armazenado no momento da distribuição e `b()` retorna o limite máximo armazenado no momento. Para essa classe de distribuição, esses valores mínimo e máximo são os mesmos retornados pelas funções de propriedade comuns `min()` e `max()`, descritas no tópico [\<random>](../standard-library/random.md).

O membro da propriedade `param()` define ou retorna o pacote de parâmetros de distribuição armazenado `param_type`.

As funções membro `min()` e `max()` retornam o menor resultado possível e o maior resultado possível, respectivamente.

A função membro `reset()` descarta qualquer valor armazenado em cache, de forma que o resultado da próxima chamada para `operator()` não dependerá dos valores obtidos do mecanismo antes da chamada.

As funções membro `operator()` retornam o próximo valor gerado com base no mecanismo URNG, do pacote de parâmetros atual ou do pacote de parâmetros especificado.

Para obter mais informações sobre as classes de distribuição e seus membros, consulte [\<random>](../standard-library/random.md).

## <a name="example"></a>Exemplo

```cpp
// compile with: /EHsc /W4
#include <random>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

void test(const double a, const double b, const int s) {

    // uncomment to use a non-deterministic seed
    //    std::random_device rd;
    //    std::mt19937 gen(rd());
    std::mt19937 gen(1729);

    std::uniform_real_distribution<> distr(a,b);

    std::cout << "lower bound == " << distr.a() << std::endl;
    std::cout << "upper bound == " << distr.b() << std::endl;

    // generate the distribution as a histogram
    std::map<double, int> histogram;
    for (int i = 0; i < s; ++i) {
        ++histogram[distr(gen)];
    }

    // print results
    std::cout << "Distribution for " << s << " samples:" << std::endl;
    int counter = 0;
    for (const auto& elem : histogram) {
        std::cout << std::fixed << std::setw(11) << ++counter << ": "
            << std::setprecision(10) << elem.first << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    double a_dist = 1.0;
    double b_dist = 1.5;

    int samples = 10;

    std::cout << "Use CTRL-Z to bypass data entry and run using default values." << std::endl;
    std::cout << "Enter a floating point value for the lower bound of the distribution: ";
    std::cin >> a_dist;
    std::cout << "Enter a floating point value for the upper bound of the distribution: ";
    std::cin >> b_dist;
    std::cout << "Enter an integer value for the sample count: ";
    std::cin >> samples;

    test(a_dist, b_dist, samples);
}
```

```Output
Use CTRL-Z to bypass data entry and run using default values.
Enter a floating point value for the lower bound of the distribution: 0
Enter a floating point value for the upper bound of the distribution: 1
Enter an integer value for the sample count: 10
lower bound == 0
upper bound == 1
Distribution for 10 samples:
          1: 0.0288609485
          2: 0.2007994386
          3: 0.3027480117
          4: 0.4124758695
          5: 0.4413777133
          6: 0.4846447405
          7: 0.6225745916
          8: 0.6880935217
          9: 0.7541936723
         10: 0.8795716566
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<random>

**Namespace:** std

## <a name="uniform_real_distribution"></a>  uniform_real_distribution::uniform_real_distribution

Constrói a distribuição.

```cpp
explicit uniform_real_distribution(result_type a = 0.0, result_type b = 1.0);
explicit uniform_real_distribution(const param_type& parm);
```

### <a name="parameters"></a>Parâmetros

*um*\
O limite inferior para valor aleatório (inclusivo).

*b*\
O limite superior para valor aleatório (exclusivo).

*Parm*\
A estrutura `param_type` usada para construir a distribuição.

### <a name="remarks"></a>Comentários

**Pré-condição:** `a < b`

O primeiro construtor constrói um objeto cujo *valor armazenado contém* o valor a e cujo valor *de* *b* armazenado contém o valor *b*.

O segundo construtor cria um objeto cujos parâmetros armazenados são inicializados de *parm*. Você pode chamar a função de membro `param()` para obter e definir os parâmetros atuais de uma distribuição existente.

## <a name="param_type"></a>  uniform_real_distribution::param_type

Armazena todos os parâmetros da distribuição.

```cpp
struct param_type {
   typedef uniform_real_distribution<result_type> distribution_type;
   param_type(result_type a = 0.0, result_type b = 1.0);
   result_type a() const;
   result_type b() const;

   bool operator==(const param_type& right) const;
   bool operator!=(const param_type& right) const;
   };
```

### <a name="parameters"></a>Parâmetros

*um*\
O limite inferior para valor aleatório (inclusivo).

*b*\
O limite superior para valor aleatório (exclusivo).

*Certo*\
O objeto `param_type` a ser comparado a este.

### <a name="remarks"></a>Comentários

**Pré-condição:** `a < b`

Essa estrutura pode ser enviada ao construtor de classe de distribuição na instanciação, para a função de membro `param()` para definir os parâmetros armazenados de uma distribuição existente e para `operator()` a ser usado no lugar dos parâmetros armazenados.

## <a name="see-also"></a>Consulte também

[\<random>](../standard-library/random.md)
