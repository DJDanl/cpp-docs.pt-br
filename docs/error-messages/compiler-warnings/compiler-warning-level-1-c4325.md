---
title: Compilador aviso (nível 1) C4325 | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4325
dev_langs:
- C++
helpviewer_keywords:
- C4325
ms.assetid: 8127a08c-d626-481b-aa7b-04a3fdc9a9ec
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cd265938afb51cc402dc84f38b7e95188c6292a7
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43197479"
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

- . Data

- . sdata

- BSS

- . sbss

- . Text

- . const

- .sconst

- . RDATA

- .srdata

Seções adicionais podem ser adicionadas posteriormente.

## <a name="see-also"></a>Consulte também

[seção](../../preprocessor/section.md)