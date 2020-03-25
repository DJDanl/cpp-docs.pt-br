---
title: 'Tempo de manipulação de exceção: um resumo'
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
ms.openlocfilehash: 3ed2e02412bd84663674a2df2c4454d21e83575a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188110"
---
# <a name="timing-of-exception-handling-a-summary"></a>Tempo de manipulação de exceção: um resumo

Um manipulador de encerramento é executado, independentemente de como o bloco de instrução de **__try** é encerrado. As causas incluem a saída do bloco de **__try** , uma instrução `longjmp` que transfere o controle do bloco e desenrolando a pilha devido à manipulação de exceção.

> [!NOTE]
>  O compilador C++ da Microsoft dá suporte a duas formas das instruções `setjmp` e `longjmp`. A versão rápida ignora a manipulação de término, mas é mais eficiente. Para usar essa versão, inclua o arquivo \<setjmp. h >. A outra versão oferece suporte à manipulação de término conforme descrito no parágrafo anterior. Para usar essa versão, inclua o arquivo \<setjmpex. h >. O aumento no desempenho da versão rápida depende da configuração de hardware.

O sistema operacional executa todos os manipuladores de término na ordem apropriada antes que qualquer outro código possa ser executado, incluindo o corpo de um manipulador de exceção.

Quando a causa da interrupção é uma exceção, o sistema deve primeiro executar a parte de filtro de um ou mais manipuladores de exceções antes de decidir o que terminar. A ordem de eventos é:

1. Uma exceção é acionada.

1. O sistema verifica a hierarquia dos manipuladores de exceções ativas e executa o filtro do manipulador com a precedência mais alta, ou seja, o manipulador de exceção instalado mais recentemente e aninhado mais profundamente, em termos de blocos e chamadas de funções.

1. Se esse filtro passar o controle (retornar 0), o processo continuará até que seja encontrado um filtro que não passe o controle.

1. Se esse filtro retornar-1, a execução continuará onde a exceção foi gerada e nenhum encerramento ocorrerá.

1. Se o filtro retornar 1, ocorrerão os seguintes eventos:

   - O sistema desenrola a pilha, limpando todos os quadros de pilha entre o código atualmente em execução (onde a exceção foi acionada) e o quadro de pilha que contém o manipulador de exceção que está recebendo o controle.

   - À medida que a pilha é desenrolada, cada manipulador de término na pilha é executado.

   - O próprio manipulador de exceção é executado.

   - O controle passa para a linha de código após o final desse manipulador de exceção.

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de encerramento](../cpp/writing-a-termination-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
