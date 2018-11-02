---
title: Operadores binários
ms.date: 06/14/2018
helpviewer_keywords:
- member-selection operators [C++]
- operators [C++], binary
- binary operators [C++]
ms.assetid: c0e7fbff-bc87-4708-8333-504ac09ee83e
ms.openlocfilehash: 700d8fd784862c3e9f81fcde839063ff0a4696bb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50602392"
---
# <a name="binary-operators"></a>Operadores binários

A tabela a seguir mostra uma lista de operadores que podem ser sobrecarregados.

## <a name="redefinable-binary-operators"></a>Operadores binários redefiníveis

|Operador|Nome|
|--------------|----------|
|**,**|Vírgula|
|**\!=**|Desigualdade|
|**%**|Módulo|
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
|**<=**|Menor ou igual a|
|**=**|Atribuição|
|**==**|Igualdade|
|**>**|Maior que|
|**>=**|Maior ou igual a|
|**>>**|Shift direita|
|**>>=**|Deslocamento para direita/atribuição|
|**^**|OR exclusivo|
|**^=**|Atribuição OR exclusivo|
|**&#124;**|OR inclusivo de bit a bit|
|**&#124;=**|OR inclusivo bit a bit/atribuição|
|**&#124;&#124;**|OR lógico|

Para declarar uma função de operador binário como um membro não estático, você deve declará-la na forma:

> *RET-type* **operador** *op* **(** *arg* **)**

em que *ret-type* é o tipo de retorno *op* é um dos operadores listados na tabela anterior, e *arg* é um argumento de qualquer tipo.

Para declarar uma função de operador binário como uma função global, você deve declará-la na forma:

> *RET-type* **operador** *op* **(** _arg1_**,** _arg2_ **)**

em que *ret-type* e *op* são descritos para funções de operador de membro e *arg1* e *arg2* são argumentos. Ao menos um dos argumentos deve ser do tipo da classe.

> [!NOTE]
> Não há nenhuma restrição quanto aos tipos de retorno dos operadores binários; no entanto, a maioria dos operadores binários definidos pelo usuário retornam um tipo de classe ou uma referência a um tipo de classe.

## <a name="see-also"></a>Consulte também

[Sobrecarga de Operador](../cpp/operator-overloading.md)