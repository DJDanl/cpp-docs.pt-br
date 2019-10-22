---
title: Classe subtract_with_carry_engine
ms.date: 11/04/2016
f1_keywords:
- random/std::subtract_with_carry_engine
- random/std::subtract_with_carry_engine::default_seed
- random/std::subtract_with_carry_engine::discard
- random/std::subtract_with_carry_engine::min
- random/std::subtract_with_carry_engine::max
- random/std::subtract_with_carry_engine::seed
helpviewer_keywords:
- std::subtract_with_carry_engine [C++]
- std::subtract_with_carry_engine [C++], default_seed
- std::subtract_with_carry_engine [C++], discard
- std::subtract_with_carry_engine [C++], min
- std::subtract_with_carry_engine [C++], max
- std::subtract_with_carry_engine [C++], seed
ms.assetid: 94a055f2-a620-4a22-ac34-c156924bab31
ms.openlocfilehash: 63cbbb3a1a508b41c1e0632eda3eeabe4fda6696
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72685825"
---
# <a name="subtract_with_carry_engine-class"></a>Classe subtract_with_carry_engine

Gera uma sequência aleatória usando o algoritmo de subtração com transferência (Fibonacci com retardo).

## <a name="syntax"></a>Sintaxe

```cpp
template <class UIntType, size_t W, size_t S, size_t R>
class subtract_with_carry_engine;
```

### <a name="parameters"></a>Parâmetros

@No__t_1 de *UIntType*
O tipo de resultado inteiro sem sinal. Para ver os tipos possíveis, consulte [\<random>](../standard-library/random.md).

*W* \
**Tamanho da palavra**. Tamanho de cada palavra da sequência de estado, em bits. **Pré-condição**: `0 < W ≤ numeric_limits<UIntType>::digits`

@No__t_1 *S*
**Curto retardo**. Número de valores inteiros. **Pré-condição**: `0 < S < R`

*R*\
**Longo retardo**. Determina a recorrência na série gerada.

## <a name="members"></a>Membros

||||
|-|-|-|
|`subtract_with_carry_engine::subtract_with_carry_engine`|`subtract_with_carry_engine::min`|`subtract_with_carry_engine::discard`|
|`subtract_with_carry_engine::operator()`|`subtract_with_carry_engine::max`|`subtract_with_carry_engine::seed`|
|`default_seed` é um membro constante, definido como `19780503u`, usado como valor padrão do parâmetro `subtract_with_carry_engine::seed` e construtor de valor único.|||

Para obter mais informações sobre membros do mecanismo, consulte [\<random>](../standard-library/random.md).

## <a name="remarks"></a>Comentários

O modelo de classe de `substract_with_carry_engine` é uma melhoria em relação ao [linear_congruential_engine](../standard-library/linear-congruential-engine-class.md). Nenhum desses mecanismos é tão rápido nem apresenta resultados de qualidade tão altos quanto o [mersenne_twister_engine](../standard-library/mersenne-twister-engine-class.md).

Esse mecanismo produz valores de um tipo integral não assinado especificado pelo usuário usando a relação de recorrência ( *período*) `x(i) = (x(i - R) - x(i - S) - cy(i - 1)) mod M`, em que `cy(i)` tem o valor `1` se `x(i - S) - x(i - R) - cy(i - 1) < 0`, caso contrário `0` e `M` tem o valor `2`<sup>W</sup>. O estado do mecanismo é um indicador de transporte mais valores de *R* . Esses valores consistem nos últimos valores de *r* retornados se `operator()` tiver sido chamado pelo menos *r* vezes, caso contrário, os valores de `N` que foram retornados e os últimos valores de `R - N` da semente.

O argumento de modelo `UIntType` deve ser grande o suficiente para manter valores até `M - 1`.

Embora seja possível construir um gerador diretamente com base nesse mecanismo, também é possível usar um dos typedefs predefinidos:

`ranlux24_base`: usado como base para `ranlux24`.
`typedef subtract_with_carry_engine<unsigned int, 24, 10, 24> ranlux24_base;`

`ranlux48_base`: usado como base para `ranlux48`.
`typedef subtract_with_carry_engine<unsigned long long, 48, 5, 12> ranlux48_base;`

Para obter informações detalhadas sobre o algoritmo de mecanismo de subtração com transferência, consulte o artigo da Wikipédia [Lagged Fibonacci generator](https://en.wikipedia.org/wiki/Lagged_Fibonacci_generator) (Gerador de retardamento de Fibonacci).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<random>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<random>](../standard-library/random.md)
