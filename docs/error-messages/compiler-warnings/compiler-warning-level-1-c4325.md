---
title: Compilador aviso (nível 1) C4325
ms.date: 08/27/2018
f1_keywords:
- C4325
helpviewer_keywords:
- C4325
ms.assetid: 8127a08c-d626-481b-aa7b-04a3fdc9a9ec
ms.openlocfilehash: 293cbbcfe134f6cb4f5e1bf924be7c03fa278833
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408531"
---
# <a name="compiler-warning-level-1-c4325"></a>Compilador aviso (nível 1) C4325

> atributos para seção padrão '*seção*' ignorado

## <a name="remarks"></a>Comentários

Você não pode alterar os atributos de uma seção padrão. Por exemplo:

```cpp
#pragma section(".sdata", long)
```

Isso substituiria o `.sdata` seção padrão que usa o **curto** tipo de dados com o **longo** tipo de dados.

Incluem seções padrão cujos atributos que você não pode alterar,

- .data

- .sdata

- BSS

- .sbss

- .text

- .const

- .sconst

- .rdata

- .srdata

Seções adicionais podem ser adicionadas posteriormente.

## <a name="see-also"></a>Consulte também

[seção](../../preprocessor/section.md)