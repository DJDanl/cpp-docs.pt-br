---
title: Funções &lt;random&gt;
ms.date: 09/04/2019
f1_keywords:
- random/std::generate_canonical
ms.assetid: 2ac9ec59-619b-4b85-a425-f729277c1bc8
helpviewer_keywords:
- std::generate_canonical
ms.openlocfilehash: 3d94f607fc6b7bdf22d7f573f590b451dbaa718d
ms.sourcegitcommit: fd0f8839da5c6a3663798a47c6b0bb6e63b518bd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2019
ms.locfileid: "70273834"
---
# <a name="ltrandomgt-functions"></a>Funções &lt;random&gt;

## <a name="generate_canonical"></a>generate_canonical

Retorna um valor de ponto flutuante de uma sequência aleatória.

```cpp
template <class RealType, size_t Bits, class Generator>
RealType generate_canonical(Generator& Gen);
```

### <a name="parameters"></a>Parâmetros

*RealType*\
O tipo integral de ponto flutuante. Para encontrar os tipos possíveis, consulte [\<random>](../standard-library/random.md).

*Bits*\
O número de bits de aleatoriedade a ser usado.

*Gerador*\
Uma classe de gerador de número aleatório.

*Geral*\
Uma referência a uma instância de um gerador de número aleatório do tipo *gerador*.

### <a name="remarks"></a>Comentários

A função de modelo `operator()` chama a *Gen* repetidamente e empacota os valores retornados em um valor `x` de ponto flutuante do tipo *RealType* até que ele tenha coletado o número especificado de `x`bits mantissa em. O número especificado é o menor de *bits* (que deve ser diferente de zero) e o número total de bitsmantissa em RealType. A primeira chamada fornece os bits de ordem inferior. A função retorna `x`.
