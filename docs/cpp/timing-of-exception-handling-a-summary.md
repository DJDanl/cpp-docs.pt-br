---
title: 'Tempo de tratamento de exceções: um resumo'
ms.date: 11/04/2016
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
ms.openlocfilehash: cbff7c4153646fcb3471e18d20a0e633fbd1307f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50477422"
---
# <a name="timing-of-exception-handling-a-summary"></a>Tempo de tratamento de exceções: um resumo

Um manipulador de término é executado, independentemente de como o **Try** bloco de instrução é encerrado. Causas estão: saltar para fora dos **Try** bloco, um `longjmp` instrução que transfere o controle para fora do bloco e desenrolar a pilha devido à manipulação de exceção.

> [!NOTE]
>  O Visual C++ oferece suporte a dois formatos das instruções `setjmp` e `longjmp`. A versão rápida ignora a manipulação de término, mas é mais eficiente. Para usar esta versão, inclua o arquivo \<setjmp >. A outra versão oferece suporte à manipulação de término conforme descrito no parágrafo anterior. Para usar esta versão, inclua o arquivo \<setjmpex >. O aumento no desempenho da versão rápida depende da configuração de hardware.

O sistema operacional executa todos os manipuladores de término na ordem apropriada antes que qualquer outro código possa ser executado, incluindo o corpo de um manipulador de exceção.

Quando a causa da interrupção é uma exceção, o sistema deve primeiro executar a parte de filtro de um ou mais manipuladores de exceções antes de decidir o que terminar. A ordem de eventos é:

1. Uma exceção é acionada.

1. O sistema verifica a hierarquia dos manipuladores de exceções ativas e executa o filtro do manipulador com a precedência mais alta, ou seja, o manipulador de exceção instalado mais recentemente e aninhado mais profundamente, em termos de blocos e chamadas de funções.

1. Se esse filtro passar o controle (retornar 0), o processo continuará até que seja encontrado um filtro que não passe o controle.

1. Se esse filtro retorna -1, a execução continuará onde a exceção foi gerada, e não ocorrerá término.

1. Se o filtro retornar 1, ocorrerão os seguintes eventos:

   - O sistema desenrola a pilha, limpando todos os quadros de pilha entre o código atualmente em execução (onde a exceção foi acionada) e o quadro de pilha que contém o manipulador de exceção que está recebendo o controle.

   - À medida que a pilha é desenrolada, cada manipulador de término na pilha é executado.

   - O próprio manipulador de exceção é executado.

   - O controle passa para a linha de código após o final desse manipulador de exceção.

## <a name="see-also"></a>Consulte também

[Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)