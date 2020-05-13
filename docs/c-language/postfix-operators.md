---
title: Operadores pós-fixados
ms.date: 11/04/2016
helpviewer_keywords:
- operators [C], postfix
- postfix operators
ms.assetid: 76260011-1624-484e-8bef-72ae7ab556cc
ms.openlocfilehash: a86ede25feeaee3a9fb1c6b146cf9667b85c0c2f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62232241"
---
# <a name="postfix-operators"></a>Operadores pós-fixados

Os operadores pós-fixados tem a precedência mais alta (a associação mais estreita) na avaliação da expressão.

## <a name="syntax"></a>Sintaxe

*expressão de sufixo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*primary-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sufixo-expressão*  **[**  *expressão*  **]**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sufixo-expressão***(***opção de expressão de argumento-lista*<sub>opt</sub> **)**    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de sufixo*  **.**  *identificador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identificador de expressão***->***identifier* de sufixo    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de sufixo*  **++**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de sufixo*  **--**

Os operadores nesse nível de precedência são: subscritos de matriz, chamadas de função, membros de estrutura e união, e operadores de incremento e decremento pós-fixados.

## <a name="see-also"></a>Confira também

[Operadores de C](../c-language/c-operators.md)
