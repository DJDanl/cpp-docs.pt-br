---
title: Pragma inline_depth
ms.date: 08/29/2019
f1_keywords:
- inline_depth_CPP
- vc-pragma.inline_depth
helpviewer_keywords:
- pragmas, inline_depth
- inline_depth pragma
ms.assetid: 2bba60fe-43ea-4d09-90f7-aafaba3bad07
ms.openlocfilehash: be57178280e278683b85db1413ff5724b5260aef
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220975"
---
# <a name="inline_depth-pragma"></a>Pragma inline_depth

Especifica a profundidade de pesquisa heurística embutida. As funções em uma profundidade no grafo de chamada maior que o valor especificado não são embutidas.

## <a name="syntax"></a>Sintaxe

> **#pragma inline_depth (** [ *n* ] **)**

## <a name="remarks"></a>Comentários

Esse pragma controla a incorporação de funções marcadas como inline e [__inline](../cpp/inline-functions-cpp.md), ou [embutidas](../cpp/inline-functions-cpp.md) automaticamente sob `/Ob` a opção.

*n* pode ser um valor entre 0 e 255, em que 255 significa profundidade ilimitada no grafo de chamada. Um valor de 0 inibe A expansão embutida. Quando *n* não é especificado, o valor padrão 254 é usado.

O pragma **inline_depth** controla o número de vezes que uma série de chamadas de função pode ser expandida. Por exemplo, suponha que a profundidade embutida seja 4. Se uma chamada B e B chamar C, todas as três chamadas serão expandidas em linha. No entanto, se a expansão de profundidade embutida mais próxima for 2, apenas A e B serão expandidas e C permanecerá como uma chamada de função.

Para usar esse pragma, você deve definir a `/Ob` opção do compilador como 1 ou superior. A profundidade definida com esse pragma entra em vigor na primeira chamada de função após o pragma.

A profundidade embutida pode ser diminuída durante a expansão, mas não aumentada. Se a profundidade embutida for 6 e, durante a expansão, o pré-processador encontrar um pragma de **inline_depth** com um valor de 8, a profundidade permanecerá 6.

O pragma **inline_depth** não tem nenhum efeito nas funções marcadas com `__forceinline`.

> [!NOTE]
> As funções recursivas podem ser substituídas embutidas até a profundidade máxima de 16 chamadas.

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)\
[inline_recursion](../preprocessor/inline-recursion.md)
