---
title: 'Tempo de manipulação de exceção: Um resumo'
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
ms.openlocfilehash: 17d1c250a98afc2b86c198735602df7d80118bd4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81316603"
---
# <a name="timing-of-exception-handling-a-summary"></a>Tempo de manipulação de exceção: Um resumo

Um manipulador de rescisão é executado não importa como o bloco de declaração **__try** seja encerrado. As causas incluem saltar para fora `longjmp` do bloco **de __try,** uma declaração que transfere o controle para fora do bloco e desenrolar a pilha devido ao manuseio de exceção.

> [!NOTE]
> O compilador Microsoft C++ suporta duas `setjmp` `longjmp` formas de declarações. A versão rápida ignora a manipulação de término, mas é mais eficiente. Para usar esta versão, \<inclua o arquivo setjmp.h>. A outra versão oferece suporte à manipulação de término conforme descrito no parágrafo anterior. Para usar esta versão, \<inclua o arquivo setjmpex.h>. O aumento no desempenho da versão rápida depende da configuração de hardware.

O sistema operacional executa todos os manipuladores de término na ordem apropriada antes que qualquer outro código possa ser executado, incluindo o corpo de um manipulador de exceção.

Quando a causa da interrupção é uma exceção, o sistema deve primeiro executar a parte de filtro de um ou mais manipuladores de exceções antes de decidir o que terminar. A ordem de eventos é:

1. Uma exceção é acionada.

1. O sistema verifica a hierarquia dos manipuladores de exceções ativas e executa o filtro do manipulador com a precedência mais alta, ou seja, o manipulador de exceção instalado mais recentemente e aninhado mais profundamente, em termos de blocos e chamadas de funções.

1. Se esse filtro passar o controle (retornar 0), o processo continuará até que seja encontrado um filtro que não passe o controle.

1. Se este filtro retornar -1, a execução continuará onde a exceção foi levantada e nenhuma rescisão ocorrerá.

1. Se o filtro retornar 1, ocorrerão os seguintes eventos:

   - O sistema desenrola a pilha, limpando todos os quadros de pilha entre o código atualmente em execução (onde a exceção foi acionada) e o quadro de pilha que contém o manipulador de exceção que está recebendo o controle.

   - À medida que a pilha é desenrolada, cada manipulador de término na pilha é executado.

   - O próprio manipulador de exceção é executado.

   - O controle passa para a linha de código após o final desse manipulador de exceção.

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de rescisão](../cpp/writing-a-termination-handler.md)<br/>
[Tratamento estruturado de exceções (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
