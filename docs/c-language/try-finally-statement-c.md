---
title: Instrução try-finally (C)
ms.date: 11/04/2016
helpviewer_keywords:
- try-finally keyword [C]
- __finally keyword [C], try-finally statement syntax
- __finally keyword [C]
- structured exception handling, try-finally
ms.assetid: 514400c1-c322-4bf3-9e48-3047240b8a82
ms.openlocfilehash: ada38f80ff16f91a676803134854bca0b0dd4f14
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50523843"
---
# <a name="try-finally-statement-c"></a>Instrução try-finally (C)

**Seção específica da Microsoft**

A instrução `try-finally` é uma extensão da Microsoft para a linguagem C que permite que aplicativos garantam a execução do código de limpeza quando a execução de um bloco de códigos é interrompida. A limpeza consiste em tarefas como desalocar memória, fechar arquivos e liberar identificadores de arquivos. A instrução `try-finally` é especialmente útil para rotinas que têm vários locais onde uma verificação é feita para um erro que pode causar o retorno prematuro da rotina.

*try-finally-statement*: **__try**  *compound-statement*

**__finally**  *compound-statement*

A instrução composta após a cláusula `__try` é a seção protegida. A instrução composta após a cláusula `__finally` é o manipulador de término. O manipulador especifica um conjunto de ações que são executadas quando você sai da seção protegida, independentemente de a saída da seção protegida ser realizada por uma exceção (término anormal) ou por queda padrão (término normal).

O controle atinge a instrução `__try` em uma execução sequencial simples (queda). Quando o controle entra na instrução `__try`, seu manipulador associado fica ativo. A execução procede da seguinte maneira:

1. A seção protegida é executada.

1. O manipulador de término é invocado.

1. Quando o manipulador de término é concluído, a execução continua após a instrução `__finally`. Independentemente de como a seção protegida é encerrada (por exemplo, por meio de uma instrução `goto` fora do corpo protegido ou de uma instrução `return`), o manipulador de término é executado antes que o fluxo de controle saia da seção protegida.

A palavra-chave `__leave` é válida dentro de um bloco de instruções `try-finally`. O efeito de `__leave` é ignorar ao final do bloco `try-finally`. O manipulador de término é executado imediatamente. Embora uma instrução `goto` possa ser usada para alcançar o mesmo resultado, uma instrução `goto` causa o desenrolar da pilha. A instrução `__leave` é mais eficiente porque não envolve o desenrolar da pilha.

Sair de uma instrução `try-finally` usando uma instrução `return` ou a função de tempo de execução `longjmp` é considerado um encerramento anormal. Não é permitido ir para uma instrução `__try`, mas é permitido sair de uma. Todas as instruções `__finally` que são ativas entre o ponto de partida e o destino devem ser executadas. Isso se chama "desenrolamento local".

O manipulador de término não é chamado se um processo é interrompido durante a execução de uma instrução `try-finally`.

> [!NOTE]
>  A manipulação de exceção estruturada funciona com arquivos de código-fonte em C e C++. No entanto, não é projetada especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, o mecanismo de tratamento de exceções de C++ é muito mais flexível, pois pode tratar exceções de qualquer tipo.

> [!NOTE]
>  Para programas C++, o tratamento de exceção de C++ deve ser usado em vez de manipulação de exceção estruturada. Para obter mais informações, consulte [Tratamento de exceções](../cpp/exception-handling-in-visual-cpp.md) na *Referência da linguagem C++*.

Veja o exemplo da [instrução try-except](../c-language/try-except-statement-c.md) para saber como a instrução `try-finally` funciona.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Instrução try-finally](../cpp/try-finally-statement.md)