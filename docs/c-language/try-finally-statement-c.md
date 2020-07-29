---
title: Instrução try-finally (C)
ms.date: 11/04/2016
helpviewer_keywords:
- try-finally keyword [C]
- __finally keyword [C], try-finally statement syntax
- __finally keyword [C]
- structured exception handling, try-finally
ms.assetid: 514400c1-c322-4bf3-9e48-3047240b8a82
ms.openlocfilehash: b800daa7689cef769ce3a3b070c957f18e8794c9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213704"
---
# <a name="try-finally-statement-c"></a>Instrução try-finally (C)

**Específico da Microsoft**

A instrução `try-finally` é uma extensão da Microsoft para a linguagem C que permite que aplicativos garantam a execução do código de limpeza quando a execução de um bloco de códigos é interrompida. A limpeza consiste em tarefas como desalocar memória, fechar arquivos e liberar identificadores de arquivos. A instrução `try-finally` é especialmente útil para rotinas que têm vários locais onde uma verificação é feita para um erro que pode causar o retorno prematuro da rotina.

*try-finally-statement*: **__try**  *compound-statement*

**`__finally`**  *instrução composta*

A instrução composta após a cláusula `__try` é a seção protegida. A instrução composta após a **`__finally`** cláusula é o manipulador de terminação. O manipulador especifica um conjunto de ações que são executadas quando você sai da seção protegida, independentemente de a saída da seção protegida ser realizada por uma exceção (término anormal) ou por queda padrão (término normal).

O controle atinge a instrução `__try` em uma execução sequencial simples (queda). Quando o controle entra na instrução `__try`, seu manipulador associado fica ativo. A execução procede da seguinte maneira:

1. A seção protegida é executada.

1. O manipulador de término é invocado.

1. Quando o manipulador de encerramento for concluído, a execução continuará após a **`__finally`** instrução. Independentemente de como a seção protegida termina (por exemplo, por meio **`goto`** de uma instrução fora do corpo protegido ou por meio de uma **`return`** instrução), o manipulador de terminação é executado antes do fluxo de controle ser movido para fora da seção protegida.

A ** `__leave** keyword is valid within a ` ` statement block. The effect of **` __leave de try – finally** é ir para o final do `try-finally` bloco. O manipulador de término é executado imediatamente. Embora uma **`goto`** instrução possa ser usada para atingir o mesmo resultado, uma **`goto`** instrução causa o desenrolamento da pilha. A instrução **' __leave** é mais eficiente porque não envolve o desenrolamento de pilha.

Sair de uma `try-finally` instrução usando uma **`return`** instrução ou a `longjmp` função de tempo de execução é considerado encerramento anormal. Não é permitido ir para uma instrução `__try`, mas é permitido sair de uma. Todas as **`__finally`** instruções que estão ativas entre o ponto de partida e o destino devem ser executadas. Isso se chama "desenrolamento local".

O manipulador de término não é chamado se um processo é interrompido durante a execução de uma instrução `try-finally`.

> [!NOTE]
> A manipulação de exceção estruturada funciona com arquivos de código-fonte em C e C++. No entanto, não é projetada especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, o mecanismo de tratamento de exceções de C++ é muito mais flexível, pois pode tratar exceções de qualquer tipo.

> [!NOTE]
> Para programas C++, o tratamento de exceção de C++ deve ser usado em vez de manipulação de exceção estruturada. Para obter mais informações, consulte [Tratamento de exceções](../cpp/exception-handling-in-visual-cpp.md) na *Referência da linguagem C++*.

Veja o exemplo da [instrução try-except](../c-language/try-except-statement-c.md) para saber como a instrução `try-finally` funciona.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Instrução try – finally](../cpp/try-finally-statement.md)
