---
title: Operadores binários
ms.date: 06/14/2018
helpviewer_keywords:
- member-selection operators [C++]
- operators [C++], binary
- binary operators [C++]
ms.assetid: c0e7fbff-bc87-4708-8333-504ac09ee83e
ms.openlocfilehash: f44217b68f6700603218c6f4f3e846075b7e7d55
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229123"
---
# <a name="binary-operators"></a>Operadores binários

A tabela a seguir mostra uma lista de operadores que podem ser sobrecarregados.

## <a name="redefinable-binary-operators"></a>Operadores binários redefiníveis

|Operador|Nome|
|--------------|----------|
|**,**|Vírgula|
|**!=**|Desigualdade|
|**%**|Modulus|
|**%=**|Módulo/atribuição|
|**&**|AND bit a bit|
|**&&**|AND lógico|
|**&=**|Atribuição AND bit a bit|
|**&#42;**|Multiplicação|
|**&#42;=**|Atribuição/multiplicação|
|**+**|Adição|
|**+=**|Atribuição/adição|
|**-**|Subtração|
|**-=**|Subtração/atribuição|
|**->**|Seleção de membro|
|**->&#42;**|Seleção de ponteiro para membro|
|**/**|Divisão|
|**/=**|Divisão/atribuição|
|**<**|Menor que|
|**<<**|Shift esquerda|
|**<<=**|Deslocamento para a esquerda/atribuição|
|**<=**|Menor que ou igual a|
|**=**|Atribuição|
|**==**|Igualitário|
|**>**|Maior que|
|**>=**|Maior que ou igual a|
|**>>**|Shift direita|
|**>>=**|Deslocamento para direita/atribuição|
|**^**|OR exclusivo|
|**^=**|Atribuição OR exclusivo|
|**&#124;**|OR inclusivo bit a bit|
|**&#124;=**|OR inclusivo bit a bit/atribuição|
|**&#124;&#124;**|OR lógico|

Para declarar uma função de operador binário como um membro não estático, você deve declará-la na forma:

> *RET-tipo* **`operator`** *op* **(** *ARG* **)**

em que *RET-Type* é o tipo de retorno, *op* é um dos operadores listados na tabela anterior e *ARG* é um argumento de qualquer tipo.

Para declarar uma função de operador binário como uma função global, você deve declará-la na forma:

> *RET-tipo* **`operator`** *op* **(** _arg1_**,** _arg2_ **)**

em que *RET-Type* e *op* são descritos como descrito para funções de operador de membro e *arg1* e *arg2* são argumentos. Ao menos um dos argumentos deve ser do tipo da classe.

> [!NOTE]
> Não há nenhuma restrição quanto aos tipos de retorno dos operadores binários; no entanto, a maioria dos operadores binários definidos pelo usuário retornam um tipo de classe ou uma referência a um tipo de classe.

## <a name="see-also"></a>Confira também

[Sobrecarga de operador](../cpp/operator-overloading.md)
