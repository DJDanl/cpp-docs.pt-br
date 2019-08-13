---
title: Estrutura nullopt_t
ms.date: 08/04/2019
f1_keywords:
- optional/std::nullopt_t
- optional/std::nullopt
ms.openlocfilehash: 1f453a5d75de3f6dedb133d55c094a4f4274e08f
ms.sourcegitcommit: 16c0392fc8d96e814c3a40b0c5346d7389aeb525
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/12/2019
ms.locfileid: "68957051"
---
# <a name="nullopt_t-struct"></a>Estrutura nullopt_t

O `nullopt_t` tipo é um tipo exclusivo e vazio usado para indicar que um objeto [opcional](optional-class.md) não contém um valor.

A constante `nullopt` do tipo `nullopt_t` indica que `optional` um tipo tem um estado não inicializado. Ele pode ser usado para inicializar um `optional` objeto ou comparado com um.

## <a name="syntax"></a>Sintaxe

```cpp
struct nullopt_t;
inline constexpr nullopt_t nullopt{ /*implementation-defined*/ };
```

## <a name="see-also"></a>Consulte também

[\<> opcional](optional.md)\
[classe opcional](optional-class.md)
