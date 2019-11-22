---
title: 'Timing of exception handling: A summary'
ms.date: 05/07/2019
helpviewer_keywords:
- sequence [C++]
- sequence, of handlers
- exception handling [C++], timing
- setjmpex.h
- termination handlers [C++], timing
- setjmp.h
- handlers [C++], order of exception
- structured exception handling [C++], timing
ms.assetid: 5d1da546-73fd-4673-aa1a-7ac0f776c420
ms.openlocfilehash: 870606c3661df3654581760214e48ef2bdfb1987
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246329"
---
# <a name="timing-of-exception-handling-a-summary"></a>Timing of exception handling: A summary

A termination handler is executed no matter how the **__try** statement block is terminated. Causes include jumping out of the **__try** block, a `longjmp` statement that transfers control out of the block, and unwinding the stack due to exception handling.

> [!NOTE]
>  The Microsoft C++ compiler supports two forms of the `setjmp` and `longjmp` statements. A versão rápida ignora a manipulação de término, mas é mais eficiente. To use this version, include the file \<setjmp.h>. A outra versão oferece suporte à manipulação de término conforme descrito no parágrafo anterior. To use this version, include the file \<setjmpex.h>. O aumento no desempenho da versão rápida depende da configuração de hardware.

O sistema operacional executa todos os manipuladores de término na ordem apropriada antes que qualquer outro código possa ser executado, incluindo o corpo de um manipulador de exceção.

Quando a causa da interrupção é uma exceção, o sistema deve primeiro executar a parte de filtro de um ou mais manipuladores de exceções antes de decidir o que terminar. A ordem de eventos é:

1. Uma exceção é acionada.

1. O sistema verifica a hierarquia dos manipuladores de exceções ativas e executa o filtro do manipulador com a precedência mais alta, ou seja, o manipulador de exceção instalado mais recentemente e aninhado mais profundamente, em termos de blocos e chamadas de funções.

1. Se esse filtro passar o controle (retornar 0), o processo continuará até que seja encontrado um filtro que não passe o controle.

1. If this filter returns -1, execution continues where the exception was raised, and no termination takes place.

1. Se o filtro retornar 1, ocorrerão os seguintes eventos:

   - O sistema desenrola a pilha, limpando todos os quadros de pilha entre o código atualmente em execução (onde a exceção foi acionada) e o quadro de pilha que contém o manipulador de exceção que está recebendo o controle.

   - À medida que a pilha é desenrolada, cada manipulador de término na pilha é executado.

   - O próprio manipulador de exceção é executado.

   - O controle passa para a linha de código após o final desse manipulador de exceção.

## <a name="see-also"></a>Consulte também

[Writing a termination handler](../cpp/writing-a-termination-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)