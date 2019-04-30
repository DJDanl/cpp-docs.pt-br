---
title: auto_inline
ms.date: 11/04/2016
f1_keywords:
- auto_inline_CPP
- vc-pragma.auto_inline
helpviewer_keywords:
- pragmas, auto_inline
- auto_inline pragma
ms.assetid: f7624cd1-be76-429a-881c-65c9040acf43
ms.openlocfilehash: c59dcc8ec7749a91565d5af043b1bd9e9eaa16ea
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62403558"
---
# <a name="autoinline"></a>auto_inline
Exclui quaisquer funções definidas dentro do intervalo em que **desativar** é especificado seja considerado como candidatos para a expansão embutida automática.

## <a name="syntax"></a>Sintaxe

```
#pragma auto_inline( [{on | off}] )
```

## <a name="remarks"></a>Comentários

Para usar o **auto_inline** pragma, coloque-o imediatamente antes e depois (não in) uma definição de função. O pragma entra em vigor na primeira definição de função, após a consideração do pragma.

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)