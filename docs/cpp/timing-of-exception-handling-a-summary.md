---
title: 'Tempo de tratamento de exceções: Um resumo'
description: O tempo e a ordem de execução da manipulação de exceção no Microsoft C++.
ms.date: 08/24/2020
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
ms.openlocfilehash: 2ce501d8d74b6f0f7ca92e193c39f8ce58a66053
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898358"
---
# <a name="timing-of-exception-handling-a-summary"></a>Tempo de tratamento de exceções: Um resumo

Um manipulador de encerramento é executado, independentemente de como o **`__try`** bloco de instrução é encerrado. As causas incluem sair do **`__try`** bloco, uma `longjmp` instrução que transfere o controle do bloco e desenrolando a pilha devido à manipulação de exceção.

> [!NOTE]
> O compilador do Microsoft C++ dá suporte a duas formas das `setjmp` `longjmp` instruções e. A versão rápida ignora a manipulação de término, mas é mais eficiente. Para usar essa versão, inclua o arquivo \<setjmp.h> . A outra versão oferece suporte à manipulação de término conforme descrito no parágrafo anterior. Para usar essa versão, inclua o arquivo \<setjmpex.h> . O aumento no desempenho da versão rápida depende da configuração de hardware.

O sistema operacional executa todos os manipuladores de término na ordem apropriada antes que qualquer outro código possa ser executado, incluindo o corpo de um manipulador de exceção.

Quando a causa da interrupção é uma exceção, o sistema deve primeiro executar a parte de filtro de um ou mais manipuladores de exceções antes de decidir o que terminar. A ordem de eventos é:

1. Uma exceção é acionada.

1. O sistema examina a hierarquia de manipuladores de exceção ativa e executa o filtro do manipulador com precedência mais alta. Esse é o manipulador de exceção instalado mais recentemente e mais profundamente aninhado, indo por blocos e chamadas de função.

1. Se esse filtro passar o controle (retorna 0), o processo continuará até encontrar um filtro que não passe o controle.

1. Se esse filtro retornar-1, a execução continuará onde a exceção foi gerada e nenhum encerramento ocorrerá.

1. Se o filtro retornar 1, ocorrerão os seguintes eventos:

   - O sistema desenrola a pilha: limpa todos os quadros de pilha entre onde a exceção foi gerada e o quadro de pilha que contém o manipulador de exceção.

   - À medida que a pilha é desenrolada, cada manipulador de término na pilha é executado.

   - O próprio manipulador de exceção é executado.

   - O controle passa para a linha de código após o final desse manipulador de exceção.

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)<br/>
[Manipulação de exceção estruturada (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
