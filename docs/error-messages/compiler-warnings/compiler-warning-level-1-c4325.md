---
title: Aviso do compilador (nível 1) C4325
ms.date: 08/27/2018
f1_keywords:
- C4325
helpviewer_keywords:
- C4325
ms.assetid: 8127a08c-d626-481b-aa7b-04a3fdc9a9ec
ms.openlocfilehash: e0a13761b0657d054065358994638779817dad6a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80163018"
---
# <a name="compiler-warning-level-1-c4325"></a>Aviso do compilador (nível 1) C4325

> atributos da seção padrão '*seção*' ignorados

## <a name="remarks"></a>Comentários

Você não pode alterar os atributos de uma seção padrão. Por exemplo:

```cpp
#pragma section(".sdata", long)
```

Isso substituiria a seção `.sdata` padrão que usa o tipo de dados **Short** com o tipo de dados **Long** .

As seções padrão cujos atributos você não pode alterar incluem,

- . Data

- .sdata

- . BSS

- . seção sbss

- .text

- . const

- .sconst

- .rdata

- .srdata

Seções adicionais podem ser adicionadas posteriormente.

## <a name="see-also"></a>Confira também

[seção](../../preprocessor/section.md)
