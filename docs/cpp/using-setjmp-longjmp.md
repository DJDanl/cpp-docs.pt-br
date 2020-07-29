---
title: Usando setjmp e longjmp
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
ms.openlocfilehash: 6adbe22eb684c9a1dda080f6d35a99c55d6c3d30
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226991"
---
# <a name="using-setjmp-and-longjmp"></a>Usando setjmp e longjmp

Quando [setjmp](../c-runtime-library/reference/setjmp.md) e [longjmp](../c-runtime-library/reference/longjmp.md) são usados juntos, eles fornecem uma maneira de executar um não local **`goto`** . Normalmente, eles são usados no código C para passar o controle de execução para tratamento de erros ou código de recuperação em uma rotina chamada anteriormente sem usar as convenções de chamada ou de retorno padrão.

> [!CAUTION]
> Como `setjmp` e `longjmp` não oferecem suporte à destruição correta de objetos de quadro de pilha portalmente entre compiladores C++, e como eles podem prejudicar o desempenho, impedindo a otimização em variáveis locais, não recomendamos seu uso em programas em C++. É recomendável usar **`try`** e **`catch`** construir em vez disso.

Se você decidir usar `setjmp` o e `longjmp` o em um programa C++, também incluirá \<setjmp.h> ou \<setjmpex.h> para garantir a interação correta entre as funções e a manipulação de exceção estruturada (SEH) ou o tratamento de exceções do C++.

**Específico da Microsoft**

Se você usar uma opção [/eh](../build/reference/eh-exception-handling-model.md) para compilar código C++, os destruidores para objetos locais serão chamados durante o desenrolamento da pilha. No entanto, se você usar **o/EHS** ou **/EHsc** para compilar e uma de suas funções que usa chamadas [noexcept](../cpp/noexcept-cpp.md) `longjmp` , o desenrolador de destruidor para essa função poderá não ocorrer, dependendo do estado do otimizador.

No código portátil, quando uma `longjmp` chamada é executada, a destruição correta de objetos baseados em quadros não é garantida explicitamente pelo padrão e pode não ter suporte de outros compiladores. Para informá-lo, no nível de aviso 4, uma chamada para `setjmp` causa aviso C4611: a interação entre ' _setjmp ' e a destruição de objeto do C++ não é portátil.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Misturando exceções C (estruturadas) e C++](../cpp/mixing-c-structured-and-cpp-exceptions.md)
