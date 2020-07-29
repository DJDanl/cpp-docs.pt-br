---
title: Expressões de constante C
ms.date: 06/14/2018
helpviewer_keywords:
- constant expressions, syntax
- constant expressions
- expressions [C++], constant
ms.assetid: d48a6c47-e44c-4be2-9c8b-7944c7ef8de7
ms.openlocfilehash: 38d4eff6cf764a30bf409032ac692189d1300315
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213730"
---
# <a name="c-constant-expressions"></a>Expressões de constante C

Uma expressão constante é avaliada em tempo de compilação, não o tempo de execução, e pode ser usada em qualquer local em que uma constante pode ser usada. A expressão constante deve ser avaliada como uma constante que está no intervalo de valores representáveis para esse tipo. Os operandos de uma expressão constante podem ser constantes inteiras, constantes de caractere, constantes de ponto flutuante, constantes de enumeração, conversões de tipo, **`sizeof`** expressões e outras expressões de constante.

## <a name="syntax"></a>Sintaxe

*expressão de constante*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão condicional*

*expressão condicional*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*logical-OR-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão or lógica* **?** *expression* **:** *expressão condicional*

*expressão*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de atribuição*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão* **,** expressão *de atribuição*

*assignment-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão condicional*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*unary-expression* *assignment-operator* *assignment-expression*

*assignment-operator*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**=****&#42;=** **/=** **%=** **+=** **-=** **\<\<=** **>>=** **&=** **^=** **&#124;=**

Os não terminais para struct declarator, enumerator, direct declarator, direct-abstract declarator, and labeled statement contêm não terminais *constant-expression*.

Uma expressão constante integral deve ser usada para especificar o tamanho de um membro de campo de bits de uma estrutura, o valor de uma constante de enumeração, o tamanho de uma matriz ou o valor de uma **`case`** constante.

As expressões constantes usadas em políticas de pré-processador estão sujeitas às restrições adicionais. Em virtude disso, elas são conhecidas como “expressões constantes restritas.” Uma expressão constante restrita não pode conter **`sizeof`** expressões, constantes de enumeração, conversões de tipo para qualquer tipo ou constantes de tipo flutuante. No entanto, ela pode conter a expressão constante especial **definida (** _identifier_ **)**.

## <a name="see-also"></a>Confira também

- [Operandos e expressões](../c-language/operands-and-expressions.md)
