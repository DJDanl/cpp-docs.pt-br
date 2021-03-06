---
title: Funções &lt;random&gt;
ms.date: 09/04/2019
f1_keywords:
- random/std::generate_canonical
ms.assetid: 2ac9ec59-619b-4b85-a425-f729277c1bc8
helpviewer_keywords:
- std::generate_canonical
ms.openlocfilehash: 3d94f607fc6b7bdf22d7f573f590b451dbaa718d
ms.sourcegitcommit: 19016630f9d35f365e9ba249e0f3617515d7ca33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/20/2020
ms.locfileid: "92274596"
---
# <a name="ltrandomgt-functions"></a>Funções &lt;random&gt;

## <a name="generate_canonical"></a><a name="generate_canonical"></a> generate_canonical

Retorna um valor de ponto flutuante de uma sequência aleatória.

```cpp
template <class RealType, size_t Bits, class Generator>
RealType generate_canonical(Generator& Gen);
```

### <a name="parameters"></a>Parâmetros

*RealType*\
O tipo integral de ponto flutuante. Para possíveis tipos, consulte [\<random>](../standard-library/random.md) .

*Bits*\
O número de bits de aleatoriedade a ser usado.

*Gerador*\
Uma classe de gerador de número aleatório.

*Geral*\
Uma referência a uma instância de um gerador de número aleatório do tipo *gerador*.

### <a name="remarks"></a>Comentários

A função de modelo chama `operator()` a *Gen* repetidamente e empacota os valores retornados em um valor de ponto flutuante `x` do tipo *RealType* até que ele tenha coletado o número especificado de bits mantissa em `x` . O número especificado é o menor de *bits* (que deve ser diferente de zero) e o número total de bits mantissa em *RealType*. A primeira chamada fornece os bits de ordem inferior. A função retorna `x`.
