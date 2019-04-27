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
ms.openlocfilehash: 5602dd91b7d017c49a122524e469100b0ec6debf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62179822"
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