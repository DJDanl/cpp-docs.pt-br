---
title: Funções &lt;random&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- random/std::generate_canonical
ms.assetid: 2ac9ec59-619b-4b85-a425-f729277c1bc8
helpviewer_keywords:
- std::generate_canonical
ms.openlocfilehash: 5b0cd634dad099669d803d4a2717fc9198151781
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38954152"
---
# <a name="ltrandomgt-functions"></a>Funções &lt;random&gt;

## <a name="generate_canonical"></a>  generate_canonical

Retorna um valor de ponto flutuante de uma sequência aleatória.

> [!NOTE]
> O Padrão ISO C++ determina que essa função deve retornar valores no intervalo [ `0`, `1`). O Visual Studio ainda não é compatível com essa restrição. Como solução alternativa para gerar valores nesse intervalo, use [uniform_real_distribution](../standard-library/uniform-real-distribution-class.md).

```cpp
template <class RealType, size_t Bits, class Generator>
RealType generate_canonical(Generator& Gen);
```

### <a name="parameters"></a>Parâmetros

*RealType* tipo integral de ponto flutuante. Para encontrar os tipos possíveis, consulte [\<random>](../standard-library/random.md).

*Bits* gerador de número aleatório.

*Gen* gerador de número aleatório.

### <a name="remarks"></a>Comentários

As chamadas de função de modelo `operator()` dos *Gen* repetidamente e empacota os valores retornados para um valor de ponto flutuante `x` do tipo *RealType* até coletar o número especificado de bits mantissa em `x`. O número especificado é o menor dos *Bits* (que deve ser diferente de zero) e o número total de bits mantissa em *RealType*. A primeira chamada fornece os bits de ordem inferior. A função retorna `x`.

## <a name="see-also"></a>Consulte também

[\<random>](../standard-library/random.md)<br/>
