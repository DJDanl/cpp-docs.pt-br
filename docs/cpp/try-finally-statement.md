---
title: Instrução try-finally
description: A referência do Microsoft C++ ao __try e __finally instruções de manipulação de exceção estruturada.
ms.date: 08/25/2020
f1_keywords:
- __try
- _try
- __leave_cpp
- __leave
- __finally_cpp
- __try_cpp
- __finally
- _finally
helpviewer_keywords:
- __try keyword [C++]
- __finally keyword [C++]
- __leave keyword [C++]
- try-catch keyword [C++], try-finally keyword
- try-finally keyword [C++]
- __finally keyword [C++], try-finally statement syntax
- __leave keyword [C++], try-finally statement
- structured exception handling [C++], try-finally
ms.assetid: 826e0347-ddfe-4f6e-a7bc-0398e0edc7c2
ms.openlocfilehash: edabbbe35c86f0305e31f36584c4dfe01f2f88cd
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898638"
---
# <a name="try-finally-statement"></a>Instrução `try-finally`

A `try-finally` instrução é uma extensão **específica da Microsoft** que dá suporte à manipulação de exceção estruturada nas linguagens C e C++.

## <a name="syntax"></a>Sintaxe

A sintaxe a seguir descreve a `try-finally` instrução:

```cpp
    // . . .
    __try {
        // guarded code
    }
    __finally {
        // termination code
    }
    // . . .
```

## <a name="grammar"></a>Gramática

> *`try-finally-statement`*:\
> &emsp;**`__try`** *`compound-statement`* **`__finally`** *`compound-statement`*

A `try-finally` instrução é uma extensão da Microsoft para as linguagens C e C++ que permitem que os aplicativos de destino garantam a execução do código de limpeza quando a execução de um bloco de código é interrompida. A limpeza consiste em tarefas como desalocar memória, fechar arquivos e liberar identificadores de arquivos. A instrução `try-finally` é especialmente útil para rotinas que têm vários locais onde uma verificação é feita para um erro que pode causar o retorno prematuro da rotina.

Para obter informações relacionadas e um exemplo de código, consulte [ `try-except` instrução](../cpp/try-except-statement.md). Para obter mais informações sobre manipulação de exceção estruturada em geral, consulte [manipulação de exceção estruturada](../cpp/structured-exception-handling-c-cpp.md). Para obter mais informações sobre como lidar com exceções em aplicativos gerenciados com C++/CLI, consulte [tratamento de exceção em `/clr` ](../extensions/exception-handling-cpp-component-extensions.md).

> [!NOTE]
> A manipulação de exceção estruturada funciona com Win32 para arquivos de código-fonte em C e C++. No entanto, não é projetada especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, a manipulação de exceção de C++ é mais flexível, pois pode tratar exceções de qualquer tipo. Para programas em c++, é recomendável que você use o mecanismo de manipulação de exceção do c++ (instruções[ `try` , `catch` e `throw` ](../cpp/try-throw-and-catch-statements-cpp.md) ).

A instrução composta após a **`__try`** cláusula é a seção protegida. A instrução composta após a **`__finally`** cláusula é o manipulador de terminação. O manipulador Especifica um conjunto de ações que são executadas quando a seção protegida é encerrada, se ela sai da seção protegida por uma exceção (encerramento anormal) ou, por padrão, se enquadra (término normal).

O controle alcança uma **`__try`** instrução por execução sequencial simples (que se enquadra). Quando o controle entra no **`__try`** , seu manipulador associado se torna ativo. Se o fluxo de controle chegar ao fim do bloco try, a execução continuará da seguinte maneira:

1. O manipulador de término é invocado.

1. Quando o manipulador de encerramento for concluído, a execução continuará após a **`__finally`** instrução. No entanto, a seção protegida termina (por exemplo, por meio **`goto`** de um corpo protegido ou uma **`return`** instrução), o manipulador de terminação é executado *antes* do fluxo de controle ser movido para fora da seção protegida.

   Uma **`__finally`** instrução não bloqueia a pesquisa de um manipulador de exceção apropriado.

Se ocorrer uma exceção no **`__try`** bloco, o sistema operacional deverá encontrar um manipulador para a exceção ou o programa falhará. Se um manipulador for encontrado, todos os blocos e todos **`__finally`** serão executados e a execução será retomada no manipulador.

Por exemplo, imagine que uma série de chamadas de função vincula a função A à função D, conforme mostrado na figura a seguir. Cada função tem um manipulador de encerramento. Se uma exceção é gerada na função D e tratada na A, os manipuladores de encerramento são chamados nessa ordem à medida que o sistema desenrola a pilha: D, C, B.

![Ordem de encerramento&#45;execução do manipulador](../cpp/media/vc38cx1.gif "Ordem de encerramento&#45;execução do manipulador") <br/>
Ordem de execução do manipulador de encerramento

> [!NOTE]
> O comportamento de try – finally é diferente de algumas outras linguagens que dão suporte ao uso do **`finally`** , como o C#.  Um único **`__try`** pode ter um, mas não ambos, de **`__finally`** e **`__except`** .  Se ambos devem ser usados juntos, uma instrução try-except externa deve incluir a instrução interna try-finally.  As regras que especificam quando cada bloco é executado também são diferentes.

Para compatibilidade com versões anteriores,,, **`_try`** **`_finally`** e **`_leave`** são sinônimos para **`__try`** , **`__finally`** e **`__leave`** a menos que a opção do compilador [ `/Za` (desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="the-__leave-keyword"></a>A palavra-chave __leave

A **`__leave`** palavra-chave é válida somente na seção protegida de uma `try-finally` instrução e seu efeito é saltar para o final da seção protegida. A execução continua na primeira instrução do manipulador de encerramento.

Uma **`goto`** instrução também pode sair da seção protegida, mas ela degrada o desempenho porque ele invoca o desenrolamento de pilha. A **`__leave`** instrução é mais eficiente porque não causa o desenrolamento da pilha.

## <a name="abnormal-termination"></a>encerramento anormal

Sair de uma `try-finally` instrução usando a função de tempo de execução [longjmp](../c-runtime-library/reference/longjmp.md) é considerado encerramento anormal. Não é legal pular para uma **`__try`** instrução, mas é legal pular de uma. Todas as **`__finally`** instruções que estão ativas entre o ponto de saída (término normal do **`__try`** bloco) e o destino (o **`__except`** bloco que manipula a exceção) devem ser executados. Ele é chamado de *desenrolamento local*.

Se um **`__try`** bloco for encerrado prematuramente por qualquer motivo, incluindo um salto para fora do bloco, o sistema executará o **`__finally`** bloco associado como parte do processo de desenrolar a pilha. Nesses casos, a [`AbnormalTermination`](/windows/win32/Debug/abnormaltermination) função retorna **`true`** se for chamada de dentro do **`__finally`** bloco; caso contrário, retornará **`false`** .

O manipulador de encerramento não será chamado se um processo for eliminado no meio da execução de uma `try-finally` instrução.

**ENCERRAR específico da Microsoft**

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)<br/>
[Manipulação de exceção estruturada (C/C++)](../cpp/structured-exception-handling-c-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Sintaxe do manipulador de terminação](/windows/win32/Debug/termination-handler-syntax)
