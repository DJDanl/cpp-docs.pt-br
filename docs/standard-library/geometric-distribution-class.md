---
title: Classe geometric_distribution
ms.date: 11/04/2016
f1_keywords:
- random/std::geometric_distribution
- random/std::geometric_distribution::reset
- random/std::geometric_distribution::p
- random/std::geometric_distribution::param
- random/std::geometric_distribution::min
- random/std::geometric_distribution::max
- random/std::geometric_distribution::operator()
- random/std::geometric_distribution::param_type
- random/std::geometric_distribution::param_type::p
- random/std::geometric_distribution::param_type::operator==
- random/std::geometric_distribution::param_type::operator!=
helpviewer_keywords:
- std::geometric_distribution [C++]
- std::geometric_distribution [C++], reset
- std::geometric_distribution [C++], p
- std::geometric_distribution [C++], param
- std::geometric_distribution [C++], min
- std::geometric_distribution [C++], max
- std::geometric_distribution [C++], param_type
- std::geometric_distribution [C++], param_type
ms.assetid: 38f933af-3b49-492e-9d26-b6b272a60013
ms.openlocfilehash: 66af7aba99d1510b6d4416543e54890a9e891f7e
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688014"
---
# <a name="geometric_distribution-class"></a>Classe geometric_distribution

Gera uma distribuição geométrica.

## <a name="syntax"></a>Sintaxe

```cpp
template<class IntType = int>
class geometric_distribution {
public:
    // types
    typedef IntType result_type;
    struct param_type;

    // constructors and reset functions
    explicit geometric_distribution(double p = 0.5);
    explicit geometric_distribution(const param_type& parm);
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

### <a name="parameters"></a>Parâmetros

@No__t_1 *IntType*
O tipo de resultado inteiro, o padrão é **int**. Para possíveis tipos, consulte [\<random >](../standard-library/random.md).

@No__t_1 *URNG*
O mecanismo do gerador de número aleatório uniforme. Para ver os tipos possíveis, consulte [\<random>](../standard-library/random.md).

## <a name="remarks"></a>Comentários

O modelo de classe descreve uma distribuição que produz valores de um tipo integral especificado pelo usuário com uma distribuição geométrica. A tabela a seguir contém links para artigos sobre cada um dos membros.

||||
|-|-|-|
|[geometric_distribution](#geometric_distribution)|`geometric_distribution::p`|`geometric_distribution::param`|
|`geometric_distribution::operator()`||[param_type](#param_type)|

A função de propriedade `p()` retorna o valor do parâmetro de distribuição armazenado `p`.

O membro da propriedade `param()` define ou retorna o pacote de parâmetros de distribuição armazenado `param_type`.

As funções membro `min()` e `max()` retornam o menor resultado possível e o maior resultado possível, respectivamente.

A função membro `reset()` descarta qualquer valor armazenado em cache, de forma que o resultado da próxima chamada para `operator()` não dependerá dos valores obtidos do mecanismo antes da chamada.

As funções membro `operator()` retornam o próximo valor gerado com base no mecanismo URNG, do pacote de parâmetros atual ou do pacote de parâmetros especificado.

Para obter mais informações sobre as classes de distribuição e seus membros, consulte [\<random>](../standard-library/random.md).

Para obter informações detalhadas sobre a distribuição qui-quadrado, consulte o artigo da Wolfram MathWorld [Geometric Distribution](https://go.microsoft.com/fwlink/p/?linkid=400529) (Distribuição geométrica).

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

    std::geometric_distribution<> distr(p);

    std::cout << std::endl;
    std::cout << "min() == " << distr.min() << std::endl;
    std::cout << "max() == " << distr.max() << std::endl;
    std::cout << "p() == " << std::fixed << std::setw(11) << std::setprecision(10) << distr.p() << std::endl;

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
    double p_dist = 0.5;

    int samples = 100;

    std::cout << "Use CTRL-Z to bypass data entry and run using default values." << std::endl;
    std::cout << "Enter a floating point value for the \'p\' distribution parameter: ";
    std::cin >> p_dist;
    std::cout << "Enter an integer value for the sample count: ";
    std::cin >> samples;

    test(p_dist, samples);
}
```

Primeiro teste:

```Output
Use CTRL-Z to bypass data entry and run using default values.
Enter a floating point value for the 'p' distribution parameter: .5
Enter an integer value for the sample count: 100

min() == 0
max() == 2147483647
p() == 0.5000000000
Distribution for 100 samples:
    0 :::::::::::::::::::::::::::::::::::::::::::::::::::::
    1 ::::::::::::::::::::::::::
    2 ::::::::::::
    3 ::::::
    4 ::
    5 :
```

Segundo teste:

```Output
Use CTRL-Z to bypass data entry and run using default values.
Enter a floating point value for the 'p' distribution parameter: .1
Enter an integer value for the sample count: 100

min() == 0
max() == 2147483647
p() == 0.1000000000
Distribution for 100 samples:
    0 :::::::::
    1 :::::::::::
    2 ::::::::::
    3 :::::::
    4 :::::
    5 ::::::::
    6 :::
    7 ::::::
    8 :::::::
    9 :::::
   10 :::
   11 :::
   12 ::
   13 :
   14 :::
   15 ::
   16 :::
   17 :::
   20 :::::
   21 :
   29 :
   32 :
   35 :
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<random>

**Namespace:** std

## <a name="geometric_distribution"></a>  geometric_distribution::geometric_distribution

Constrói a distribuição.

```cpp
explicit geometric_distribution(double p = 0.5);
explicit geometric_distribution(const param_type& parm);
```

### <a name="parameters"></a>Parâmetros

*p* \
O parâmetro de distribuição `p`.

\ de *parâmetros*
A estrutura do parâmetro usada para construir a distribuição.

### <a name="remarks"></a>Comentários

**Pré-condição:** `0.0 < p && p < 1.0`

o primeiro construtor constrói um objeto cujo valor `p` armazenado contém o valor *p*.

O segundo construtor cria um objeto cujos parâmetros armazenados são inicializados de *parm*. Você pode chamar a função de membro `param()` para obter e definir os parâmetros atuais de uma distribuição existente.

## <a name="param_type"></a>  geometric_distribution::param_type

Armazena os parâmetros da distribuição.

```cpp
struct param_type {
   typedef geometric_distribution<result_type> distribution_type;
   param_type(double p = 0.5);
   double p() const;

   bool operator==(const param_type& right) const;
   bool operator!=(const param_type& right) const;
   };
```

### <a name="parameters"></a>Parâmetros

*p* \
O parâmetro de distribuição `p`.

\ *à direita*
O instância de `param_type` a ser comparada com isto.

### <a name="remarks"></a>Comentários

**Pré-condição:** `0.0 < p && p < 1.0`

Essa estrutura pode ser enviada ao construtor de classe de distribuição na instanciação, para a função de membro `param()` para definir os parâmetros armazenados de uma distribuição existente e para `operator()` a ser usado no lugar dos parâmetros armazenados.

## <a name="see-also"></a>Consulte também

[\<random>](../standard-library/random.md)
