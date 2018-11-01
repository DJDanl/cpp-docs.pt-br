---
title: Usando setjmp e o longjmp
ms.date: 08/14/2018
f1_keywords:
- longjmp_cpp
- setjmp_cpp
helpviewer_keywords:
- C++ exception handling, setjmp/longjmp functions
- setjmpex.h
- longjmp function in C++ programs
- setjmp.h
- setjmp function
- setjmp function, C++ programs
ms.assetid: 96be8816-f6f4-4567-9a9c-0c3c720e37c5
ms.openlocfilehash: 4ead12f79701899b3977993c9de3c3803023150f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50525704"
---
# <a name="using-setjmp-and-longjmp"></a>Usando setjmp e o longjmp

Quando [setjmp](../c-runtime-library/reference/setjmp.md) e [longjmp](../c-runtime-library/reference/longjmp.md) são usados juntos, eles fornecem uma maneira de executar um não-local **goto**. Eles são normalmente usados no código C para transmitir o controle de execução para o código de tratamento de erros ou recuperação em uma rotina anteriormente chamada anteriormente sem usar o padrão de chamada convenções ou de retornam.

> [!CAUTION]
> Porque `setjmp` e `longjmp` não oferecem suporte a destruição correta dos objetos de quadro de pilha forma portátil entre os compiladores de C++ e como podem prejudicar o desempenho evitando a otimização em variáveis locais, não recomendamos seu uso em C++ programas. É recomendável que você use **tente** e **catch** constrói em vez disso.

Se você decidir usar `setjmp` e `longjmp` em um programa C++, também incluem \<setjmp > ou \<setjmpex > para garantir a interação correta entre as funções e a exceção de tratamento de exceção estruturada (SEH) ou C++ manipulação.

**Seção específica da Microsoft**

Se você usar um [/EH](../build/reference/eh-exception-handling-model.md) opção para compilar código C++, os destruidores de objetos locais são chamados durante o desenrolamento de pilha. No entanto, se você usar **/EHs** ou **/EHsc** para compilação e uma de suas funções que usa [noexcept](../cpp/noexcept-cpp.md) chamadas `longjmp`, em seguida, o destruidor de desenrolamento para essa função poderá não ocorrer, dependendo do estado de otimizador.

No código portátil, quando um `longjmp` chamada é executada, destruição correta dos objetos baseados em quadro explicitamente não é garantida por padrão e pode não ter suporte por outros compiladores. Para permitir que você sabe, no nível de aviso 4, uma chamada para `setjmp` faz com que o aviso C4611: interação entre 'setjmp' e a destruição de objeto de C++ é não portátil.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Combinação de exceções C (estruturadas) e C++](../cpp/mixing-c-structured-and-cpp-exceptions.md)
