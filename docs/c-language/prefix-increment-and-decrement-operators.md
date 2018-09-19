---
title: Operadores de incremento e de decremento pré-fixados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- increment operators, types of
- decrement operators, syntax
- decrement operators
ms.assetid: 9a441bb9-d94a-4b6a-9db2-0d0d76bc480d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7077e1b40701f8586ce8322ac9922517ac77b22b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46018282"
---
# <a name="prefix-increment-and-decrement-operators"></a>Operadores de incremento e de decremento pré-fixados

Os operadores unários (`++` e **--**) são chamados de operadores de incremento ou decremento "pré-fixados" quando os operadores de incremento ou decremento aparecem antes do operando. O incremento e a diminuição de pós-fixação têm precedência maior que o incremento e a diminuição de prefixo. O operando deve ter tipo integral, flutuante ou de ponteiro e deve ser uma expressão I-value modificável (uma expressão sem o atributo **const**). O resultado é um l-value.

Quando o operador aparecer antes de seu operando, o operando será incrementado ou diminuído, e seu novo valor será o resultado da expressão.

Um operando tipo integral ou flutuante é incrementado ou decrementado pelo valor inteiro 1. O tipo do resultado é igual ao tipo do operando. Um operando do tipo ponteiro é incrementado ou decrementado pelo tamanho do objeto pertinente. Um ponteiro incrementado aponta para o próximo objeto;um ponteiro decrementado aponta para o objeto anterior.

## <a name="example"></a>Exemplo

Este exemplo ilustra o operador unário de diminuição de prefixo:

```
if( line[--i] != '\n' )
    return;
```

Neste exemplo, a variável `i` é diminuída antes de ser usada como um subscrito para `line`.

## <a name="see-also"></a>Consulte também

[Operadores unários C](../c-language/c-unary-operators.md)