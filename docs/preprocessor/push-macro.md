---
title: push_macro
ms.date: 11/04/2016
f1_keywords:
- vc-pragma.push_macro
- push_macro_CPP
helpviewer_keywords:
- pragmas, push_macro
- push_macro pragma
ms.assetid: ac89efc9-afd1-4dfe-bfd1-497229b3e81d
ms.openlocfilehash: 9b866fd5907faf46872665bbcaef97f2352efea9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50535675"
---
# <a name="pushmacro"></a>push_macro
Salva o valor da *macro_name* macro no topo da pilha dessa macro.

## <a name="syntax"></a>Sintaxe

```
#pragma push_macro("
macro_name
")
```

## <a name="remarks"></a>Comentários

Você pode recuperar o valor para *macro_name* com `pop_macro`.

Ver [pop_macro](../preprocessor/pop-macro.md) para obter um exemplo.

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)