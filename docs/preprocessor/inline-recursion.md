---
title: Pragma inline_recursion
ms.date: 08/29/2019
f1_keywords:
- inline_recursion_CPP
- vc-pragma.inline_recursion
helpviewer_keywords:
- pragmas, inline_recursion
- inline_recursion pragma
ms.assetid: cfef5791-63b7-45ac-9574-623747b9b9c9
ms.openlocfilehash: 0169e06e8e47f7b0a7b3f73e809ddc988bcf1e95
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220957"
---
# <a name="inline_recursion-pragma"></a>Pragma inline_recursion

Controla a expansão embutida das chamadas de função diretas ou mutuamente recursivas.

## <a name="syntax"></a>Sintaxe

> **#pragma inline_recursion (** [ **on** | **off** }] **)**

## <a name="remarks"></a>Comentários

Use este pragma para controlar funções marcadas como [embutidas](../cpp/inline-functions-cpp.md) e [__inline](../cpp/inline-functions-cpp.md) ou funções que o compilador expande automaticamente `/Ob2` na opção. O uso deste pragma requer uma configuração de opção de compilador [/OB](../build/reference/ob-inline-function-expansion.md) de 1 ou 2. O estado padrão de **inline_recursion** é off. Esse pragma entra em vigor na primeira chamada de função depois que pragma é visto e não afeta a definição da função.

O pragma **inline_recursion** controla como as funções recursivas são expandidas. Se **inline_recursion** estiver off e se uma função embutida chamar a si mesma, direta ou indiretamente, a função será expandida apenas uma vez. Se **inline_recursion** for on, a função será expandida várias vezes até atingir o valor definido com o pragma [inline_depth](../preprocessor/inline-depth.md) , o valor padrão para funções recursivas que é `inline_depth` definida pelo pragma ou um limite de capacidade.

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)\
[inline_depth](../preprocessor/inline-depth.md)\
[/Ob (expansão de função embutida)](../build/reference/ob-inline-function-expansion.md)
