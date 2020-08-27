---
title: Instrução try-finally (C)
description: O Microsoft C/C++ implementa o tratamento de exceção estruturado (SEH) usando uma extensão de linguagem de instrução try-finally.
ms.date: 08/24/2020
helpviewer_keywords:
- try-finally keyword [C]
- __finally keyword [C], try-finally statement syntax
- __finally keyword [C]
- structured exception handling, try-finally
ms.assetid: 514400c1-c322-4bf3-9e48-3047240b8a82
ms.openlocfilehash: 6f9cf901ed0a82b355880225c902ec4fc3e1082b
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898713"
---
# <a name="try-finally-statement-c"></a>Instrução try-finally (C)

**Específico da Microsoft**

A instrução `try-finally` é uma extensão da Microsoft para a linguagem C que permite que aplicativos garantam a execução do código de limpeza quando a execução de um bloco de códigos é interrompida. A limpeza consiste em tarefas como desalocar memória, fechar arquivos e liberar identificadores de arquivos. A instrução `try-finally` é especialmente útil para rotinas que têm vários locais onde uma verificação é feita para um erro que pode causar o retorno prematuro da rotina.

> *`try-finally-statement`*:\
> &emsp;**`__try`** *`compound-statement`* **`__finally`** *`compound-statement`*

A instrução composta após a **`__try`** cláusula é a seção protegida. A instrução composta após a **`__finally`** cláusula é o manipulador de terminação. O manipulador Especifica um conjunto de ações que são executadas quando a seção protegida é encerrada. Não importa se a seção protegida é encerrada por uma exceção (encerramento anormal) ou por padrão percorrem (término normal).

O controle alcança uma **`__try`** instrução por execução sequencial simples (que se enquadra). Quando o controle entra na **`__try`** instrução, seu manipulador associado se torna ativo. A execução procede da seguinte maneira:

1. A seção protegida é executada.

1. O manipulador de término é invocado.

1. Quando o manipulador de encerramento for concluído, a execução continuará após a **`__finally`** instrução. Não importa como a seção protegida termina (por exemplo, por meio **`goto`** de uma instrução fora do corpo protegido ou por meio de uma **`return`** instrução), o manipulador de terminação é executado antes do fluxo de controle ser movido para fora da seção protegida.

A **`__leave`** palavra-chave é válida dentro de um `try-finally` bloco de instruções. O efeito de **`__leave`** é saltar para o final do `try-finally` bloco. O manipulador de término é executado imediatamente. Embora uma **`goto`** instrução possa ser usada para atingir o mesmo resultado, uma **`goto`** instrução causa o desenrolamento da pilha. A **`__leave`** instrução é mais eficiente porque não envolve o desenrolamento de pilha.

Sair de uma `try-finally` instrução usando uma **`return`** instrução ou a `longjmp` função de tempo de execução é considerado encerramento anormal. Não é legal pular para uma **`__try`** instrução, mas legal para saltar de uma. Todas as **`__finally`** instruções que estão ativas entre o ponto de partida e o destino devem ser executadas. Ele é chamado de *desenrolamento local*.

O manipulador de encerramento não será chamado se um processo for encerrado durante a execução de uma `try-finally` instrução.

> [!NOTE]
> A manipulação de exceção estruturada funciona com arquivos de código-fonte em C e C++. No entanto, ele não foi projetado especificamente para C++. Para programas Portable C++, a manipulação de exceção do C++ deve ser usada em vez de manipulação de exceção estruturada. Além disso, o mecanismo de tratamento de exceções de C++ é muito mais flexível, pois pode tratar exceções de qualquer tipo. Para obter mais informações, consulte [tratamento de exceção](../cpp/exception-handling-in-visual-cpp.md) na referência da *linguagem C++*.

Consulte o exemplo para a [ `try-except` instrução](../c-language/try-except-statement-c.md) para ver como a `try-finally` instrução funciona.

**ENCERRAR específico da Microsoft**

## <a name="see-also"></a>Confira também

[`try-finally` instrução (C++)](../cpp/try-finally-statement.md)
