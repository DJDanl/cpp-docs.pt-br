---
title: Classe poisson_distribution
ms.date: 11/04/2016
f1_keywords:
- random/std::poisson_distribution
- random/std::poisson_distribution::reset
- random/std::poisson_distribution::mean
- random/std::poisson_distribution::param
- random/std::poisson_distribution::min
- random/std::poisson_distribution::max
- random/std::poisson_distribution::operator()
- random/std::poisson_distribution::param_type
- random/std::poisson_distribution::param_type::mean
- random/std::poisson_distribution::param_type::operator==
- random/std::poisson_distribution::param_type::operator!=
helpviewer_keywords:
- std::poisson_distribution [C++]
- std::poisson_distribution [C++], reset
- std::poisson_distribution [C++], mean
- std::poisson_distribution [C++], param
- std::poisson_distribution [C++], min
- std::poisson_distribution [C++], max
- std::poisson_distribution [C++], param_type
- std::poisson_distribution [C++], param_type
ms.assetid: 09614281-349a-45f7-8e95-c0196be0a937
ms.openlocfilehash: fd1464c099d6f666b53387326c1dd863048defdc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372040"
---
# <a name="poisson_distribution-class"></a>Classe poisson_distribution

Gera uma distribuição Poisson.

## <a name="syntax"></a>Sintaxe

```cpp
template<class IntType = int>
class poisson_distribution
   {
public:
   // types
   typedef IntType result_type;
   struct param_type;

   // constructors and reset functions
   explicit poisson_distribution(double mean = 1.0);
   explicit poisson_distribution(const param_type& parm);
   void reset();

   // generating functions
   template <class URNG>
   result_type operator()(URNG& gen);
   template <class URNG>
   result_type operator()(URNG& gen, const param_type& parm);

   // property functions
   double mean() const;
   param_type param() const;
   void param(const param_type& parm);
   result_type min() const;
   result_type max() const;
   };
```

### <a name="parameters"></a>Parâmetros

*IntType*\
O tipo de resultado inteiro, padrão para **int**. Para tipos possíveis, consulte [ \<>aleatórios ](../standard-library/random.md).

## <a name="remarks"></a>Comentários

O modelo de classe descreve uma distribuição que produz valores de um tipo integral especificado pelo usuário com uma distribuição Poisson. A tabela a seguir contém links para artigos sobre cada um dos membros.

||||
|-|-|-|
|[poisson_distribution](#poisson_distribution)|`poisson_distribution::mean`|`poisson_distribution::param`|
|`poisson_distribution::operator()`||[param_type](#param_type)|

A função de propriedade `mean()` retorna o valor do parâmetro de distribuição armazenado *mean*.

O membro da propriedade `param()` define ou retorna o pacote de parâmetros de distribuição armazenado `param_type`.

As funções membro `min()` e `max()` retornam o menor resultado possível e o maior resultado possível, respectivamente.

A função membro `reset()` descarta qualquer valor armazenado em cache, de forma que o resultado da próxima chamada para `operator()` não dependerá dos valores obtidos do mecanismo antes da chamada.

As funções membro `operator()` retornam o próximo valor gerado com base no mecanismo URNG, do pacote de parâmetros atual ou do pacote de parâmetros especificado.

Para obter mais informações sobre as aulas de distribuição e seus membros, consulte [ \<>aleatórios ](../standard-library/random.md).

Para obter informações detalhadas sobre a distribuição Poisson, consulte o artigo da Wolfram MathWorld [Poisson Distribution](https://go.microsoft.com/fwlink/p/?linkid=401112).

## <a name="example"></a>Exemplo

```cpp
// compile with: /EHsc /W4
#include <random>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

void test(const double p, const int s) {

    // uncomment to use a non-deterministic generator
    //    std::random_device gen;
    std::mt19937 gen(1701);

    std::poisson_distribution<> distr(p);

    std::cout << std::endl;
    std::cout << "min() == " << distr.min() << std::endl;
    std::cout << "max() == " << distr.max() << std::endl;
    std::cout << "p() == " << std::fixed << std::setw(11) << std::setprecision(10) << distr.mean() << std::endl;

    // generate the distribution as a histogram
    std::map<int, int> histogram;
    for (int i = 0; i < s; ++i) {
        ++histogram[distr(gen)];
    }

    // print results
    std::cout << "Distribution for " << s << " samples:" << std::endl;
    for (const auto& elem : histogram) {
        std::cout << std::setw(5) << elem.first << ' ' << std::string(elem.second, ':') << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    double p_dist = 1.0;

    int samples = 100;

    std::cout << "Use CTRL-Z to bypass data entry and run using default values." << std::endl;
    std::cout << "Enter a floating point value for the 'mean' distribution parameter (must be greater than zero): ";
    std::cin >> p_dist;
    std::cout << "Enter an integer value for the sample count: ";
    std::cin >> samples;

    test(p_dist, samples);
}
```

Primeiro teste:

```Output
Use CTRL-Z to bypass data entry and run using default values.
Enter a floating point value for the 'mean' distribution parameter (must be greater than zero): 1
Enter an integer value for the sample count: 100
min() == 0
max() == 2147483647
p() == 1.0000000000
Distribution for 100 samples:
    0 ::::::::::::::::::::::::::::::
    1 ::::::::::::::::::::::::::::::::::::::
    2 :::::::::::::::::::::::
    3 ::::::::
    5 :
```

Segundo teste:

```Output
Use CTRL-Z to bypass data entry and run using default values.
Enter a floating point value for the 'mean' distribution parameter (must be greater than zero): 10
Enter an integer value for the sample count: 100
min() == 0
max() == 2147483647
p() == 10.0000000000
Distribution for 100 samples:
    3 :
    4 ::
    5 ::
    6 ::::::::
    7 ::::
    8 ::::::::
    9 ::::::::::::::
   10 ::::::::::::
   11 ::::::::::::::::
   12 :::::::::::::::
   13 ::::::::
   14 ::::::
   15 :
   16 ::
   17 :
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<random>

**Namespace:** std

## <a name="poisson_distributionpoisson_distribution"></a><a name="poisson_distribution"></a>poisson_distribution::poisson_distribuição

Constrói a distribuição.

```cpp
explicit poisson_distribution(RealType mean = 1.0);
explicit binomial_distribution(const param_type& parm);
```

### <a name="parameters"></a>Parâmetros

*significa*\
O parâmetro de distribuição `mean`.

*Parm*\
A estrutura do parâmetro usada para construir a distribuição.

### <a name="remarks"></a>Comentários

**Pré-condição:**`0.0 < mean`

O primeiro construtor cria um objeto cujo valor `mean` armazenado contém o valor *mean*.

O segundo construtor cria um objeto cujos parâmetros armazenados são inicializados de *parm*. Você pode chamar a função de membro `param()` para obter e definir os parâmetros atuais de uma distribuição existente.

## <a name="poisson_distributionparam_type"></a><a name="param_type"></a>poisson_distribution::param_type

Armazena os parâmetros da distribuição.

```cpp
struct param_type {
   typedef poisson_distribution<IntType> distribution_type;
   param_type(double mean = 1.0);
   double mean() const;

   bool operator==(const param_type& right) const;
   bool operator!=(const param_type& right) const;
   };
```

### <a name="parameters"></a>Parâmetros

Consulte os parâmetros do construtor para [poisson_distribution](#poisson_distribution).

### <a name="remarks"></a>Comentários

**Pré-condição:**`0.0 < mean`

Essa estrutura pode ser enviada ao construtor de classe de distribuição na instanciação, para a função de membro `param()` para definir os parâmetros armazenados de uma distribuição existente e para `operator()` a ser usado no lugar dos parâmetros armazenados.

## <a name="see-also"></a>Confira também

[\<>aleatório](../standard-library/random.md)
