---
title: Estrutura treat_as_floating_point
ms.date: 11/04/2016
f1_keywords:
- chrono/std::chrono::treat_as_floating_point
ms.assetid: d0a2161c-bbb2-4924-8961-7568d5ad5434
ms.openlocfilehash: 1b7b58983032ee74ed3d88feb7325cd537e1cc2f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50493854"
---
# <a name="treatasfloatingpoint-structure"></a>Estrutura treat_as_floating_point

Especifica se `Rep` pode ser tratado como um tipo de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Rep>
struct treat_as_floating_point : is_floating_point<Rep>;
```

## <a name="remarks"></a>Comentários

`Rep` pode ser tratado como um tipo de ponto flutuante somente quando a especialização `treat_as_floating_point<Rep>` é derivada de [true_type](../standard-library/type-traits-typedefs.md#true_type). A classe de modelo pode ser especializada para um tipo definido pelo usuário.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<chrono >

**Namespace:** std::chrono

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<chrono>](../standard-library/chrono.md)<br/>
