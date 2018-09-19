---
title: Operadores de incremento e de decremento pós-fixados C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- increment operators, syntax
- scalar operators
- types [C], scalar
ms.assetid: 56ba218d-65f9-405f-8684-caccc0ca33aa
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 57fe65f83cff8e4a469270100eb68ec1f29cbb1e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46110257"
---
# <a name="c-postfix-increment-and-decrement-operators"></a>Operadores de incremento e de decremento pós-fixados C

Os operandos dos operadores de incremento e decremento pós-fixados são tipos escalares que são l-values modificáveis.

## <a name="syntax"></a>Sintaxe

*postfix-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*postfix-expression*  **++**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*postfix-expression*  **--**

O resultado da operação de incremento ou decremento pós-fixada é o valor do operando. Depois que o resultado é obtido, o valor do operando é incrementado (ou decrementado). O código a seguir ilustra o operador de incremento pós-fixado.

```
if( var++ > 0 )
    *p++ = *q++;
```

Nesse exemplo, a variável `var` é comparada a 0 e depois incrementada. Se `var` era positiva antes de ser incrementada, a próxima instrução é executada. Primeiro, o valor do objeto para o qual `q` aponta é atribuído ao objeto para o qual `p` aponta. Em seguida, `q` e `p` são incrementados.

## <a name="see-also"></a>Consulte também

[Operadores de incremento e de decremento pós-fixados: ++ e --](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)