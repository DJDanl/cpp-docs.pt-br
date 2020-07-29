---
title: Aviso do compilador (nível 1) C4325
ms.date: 08/27/2018
f1_keywords:
- C4325
helpviewer_keywords:
- C4325
ms.assetid: 8127a08c-d626-481b-aa7b-04a3fdc9a9ec
ms.openlocfilehash: 551680bc1d24097200a1e641bc4238f883ad94dd
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230695"
---
# <a name="compiler-warning-level-1-c4325"></a>Aviso do compilador (nível 1) C4325

> atributos da seção padrão '*seção*' ignorados

## <a name="remarks"></a>Comentários

Você não pode alterar os atributos de uma seção padrão. Por exemplo:

```cpp
#pragma section(".sdata", long)
```

Isso substituiria a `.sdata` seção padrão que usa o **`short`** tipo de dados com o **`long`** tipo de dados.

As seções padrão cujos atributos você não pode alterar incluem,

- . Data

- . sdata

- . BSS

- . seção sbss

- .text

- . const

- .sconst

- . rdata

- .srdata

Seções adicionais podem ser adicionadas posteriormente.

## <a name="see-also"></a>Confira também

[Section](../../preprocessor/section.md)
