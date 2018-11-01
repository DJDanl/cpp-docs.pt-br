---
title: inline_recursion
ms.date: 11/04/2016
f1_keywords:
- inline_recursion_CPP
- vc-pragma.inline_recursion
helpviewer_keywords:
- pragmas, inline_recursion
- inline_recursion pragma
ms.assetid: cfef5791-63b7-45ac-9574-623747b9b9c9
ms.openlocfilehash: 635d33d91e779d88b56e353d0cddf6b34b313855
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50523833"
---
# <a name="inlinerecursion"></a>inline_recursion
Controla a expansão embutida das chamadas de função diretas ou mutuamente recursivas.

## <a name="syntax"></a>Sintaxe

```
#pragma inline_recursion( [{on | off}] )
```

## <a name="remarks"></a>Comentários

Use este pragma para controlar as funções marcado como [embutido](../cpp/inline-functions-cpp.md) e [inline](../cpp/inline-functions-cpp.md) ou funções que o compilador expandirá automaticamente sob o `/Ob2` opção. O uso desse pragma requer uma [/Ob](../build/reference/ob-inline-function-expansion.md) configuração da opção de compilador de 1 ou 2. O estado padrão para **inline_recursion** está desativado. Este pragma entra em vigor na primeira chamada de função após o pragma ser percebido e não afeta a definição da função.

O **inline_recursion** pragma controla como as funções recursivas são expandidas. Se **inline_recursion** está desativado e se uma função embutida chama a mesmo (direta ou indiretamente), a função será expandida apenas uma vez. Se **inline_recursion** estiver ativado, a função será expandida várias vezes até atingir o valor definido com o [inline_depth](../preprocessor/inline-depth.md) pragma, o valor padrão para as funções recursivas que é definido pela `inline_depth` pragma ou uma capacidade de limite.

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)<br/>
[inline_depth](../preprocessor/inline-depth.md)<br/>
[/Ob (expansão de função embutida)](../build/reference/ob-inline-function-expansion.md)