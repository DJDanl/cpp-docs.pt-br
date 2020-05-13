---
title: Expressões de constante C
ms.date: 06/14/2018
helpviewer_keywords:
- constant expressions, syntax
- constant expressions
- expressions [C++], constant
ms.assetid: d48a6c47-e44c-4be2-9c8b-7944c7ef8de7
ms.openlocfilehash: f6984c47ef8acde462a8e92e01b72ef26a61eddc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62325735"
---
# <a name="c-constant-expressions"></a>Expressões de constante C

Uma expressão constante é avaliada em tempo de compilação, não o tempo de execução, e pode ser usada em qualquer local em que uma constante pode ser usada. A expressão constante deve ser avaliada como uma constante que está no intervalo de valores representáveis para esse tipo. Os operandos de uma expressão constante podem ser constantes de inteiro, constantes de caractere, constantes de ponto flutuante, constantes de enumeração, conversões de tipos, expressões **sizeof** e outras expressões constantes.

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
&nbsp;&nbsp;&nbsp;&nbsp;**=****&#42;** **/=** **%=** = **+=** **-=** **&#124;** = ** \< \< ** **>>=** **&=** **^=**

Os não terminais para struct declarator, enumerator, direct declarator, direct-abstract declarator, and labeled statement contêm não terminais *constant-expression*.

Uma expressão constante integral deve ser usada para especificar o tamanho de um membro de campo de bit de uma estrutura, o valor de uma constante de enumeração, o tamanho de uma matriz ou o valor de uma constante **case**.

As expressões constantes usadas em políticas de pré-processador estão sujeitas às restrições adicionais. Em virtude disso, elas são conhecidas como “expressões constantes restritas.” Uma expressão constante restrita não pode conter expressões **sizeof**, constantes de enumeração, conversões de tipos para qualquer tipo ou constantes do tipo flutuantes. No entanto, ela pode conter a expressão constante especial **definida (** _identifier_ **)**.

## <a name="see-also"></a>Confira também

- [Operandos e expressões](../c-language/operands-and-expressions.md)
