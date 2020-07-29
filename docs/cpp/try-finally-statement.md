---
title: Instrução try-finally
ms.date: 11/19/2018
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
ms.openlocfilehash: 6234e8a2d2c18177a1e66475fff850c76f7ef73e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227069"
---
# <a name="try-finally-statement"></a>Instrução try-finally

**Específico da Microsoft**

A sintaxe a seguir descreve a instrução **try – finally** :

> **\_\_Tente**<br/>
> {\
> &nbsp;&nbsp;&nbsp;&nbsp;código protegido \
> }\
> **\_\_disso**\
> {\
> &nbsp;&nbsp;&nbsp;&nbsp;código de encerramento \
> }

## <a name="grammar"></a>Gramática

*try-finally-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;instrução ** \_ \_ try** *composto-instrução* ** \_ \_ finally** *composta*

A instrução **try-finally** é uma extensão da Microsoft para as linguagens C e C++ que permite aos aplicativos de destino garantir a execução do código de limpeza quando a execução de um bloco de código é interrompida. A limpeza consiste em tarefas como desalocar memória, fechar arquivos e liberar identificadores de arquivos. A instrução **try-finally** é especialmente útil para rotinas que têm vários lugares em que uma verificação é feita para um erro que poderia causar um retorno prematuro da rotina.

Para obter informações relacionadas e um exemplo de código, consulte [instrução try-Except](../cpp/try-except-statement.md). Para obter mais informações sobre manipulação de exceção estruturada em geral, consulte [manipulação de exceção estruturada](../cpp/structured-exception-handling-c-cpp.md). Para obter mais informações sobre como lidar com exceções em aplicativos gerenciados com C++/CLI, consulte [tratamento de exceção em/CLR](../extensions/exception-handling-cpp-component-extensions.md).

> [!NOTE]
> A manipulação de exceção estruturada funciona com Win32 para arquivos de código-fonte em C e C++. No entanto, não é projetada especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, a manipulação de exceção de C++ é mais flexível, pois pode tratar exceções de qualquer tipo. Para programas em C++, é recomendável que você use o mecanismo de manipulação de exceções do C++ (instruções[try, catch e throw](../cpp/try-throw-and-catch-statements-cpp.md) ).

A instrução composta após a cláusula **__try** é a seção protegida. A instrução composta após a **`__finally`** cláusula é o manipulador de terminação. O manipulador especifica um conjunto de ações que são executadas quando você sai da seção protegida, independentemente de a saída da seção protegida ser realizada por uma exceção (encerramento anormal) ou por queda padrão (encerramento normal).

O controle alcança uma instrução **__try** por execução sequencial simples (que se enquadra). Quando o controle entra na **__try**, seu manipulador associado se torna ativo. Se o fluxo de controle chegar ao fim do bloco try, a execução continuará da seguinte maneira:

1. O manipulador de término é invocado.

1. Quando o manipulador de encerramento for concluído, a execução continuará após a **`__finally`** instrução. Independentemente de como a seção protegida termina (por exemplo, por meio **`goto`** de um corpo protegido ou uma **`return`** instrução), o manipulador de terminação é executado antes do fluxo de controle ser movido *para* fora da seção protegida.

   Uma **`__finally`** instrução não bloqueia a pesquisa de um manipulador de exceção apropriado.

Se ocorrer uma exceção no bloco de **__try** , o sistema operacional deverá encontrar um manipulador para a exceção ou o programa falhará. Se um manipulador for encontrado, todos os blocos e todos **`__finally`** serão executados e a execução será retomada no manipulador.

Por exemplo, imagine que uma série de chamadas de função vincula a função A à função D, conforme mostrado na figura a seguir. Cada função tem um manipulador de encerramento. Se uma exceção é gerada na função D e tratada na A, os manipuladores de encerramento são chamados nessa ordem à medida que o sistema desenrola a pilha: D, C, B.

![Ordem de encerramento&#45;execução do manipulador](../cpp/media/vc38cx1.gif "Ordem de encerramento&#45;execução do manipulador") <br/>
Ordem de execução do manipulador de encerramento

> [!NOTE]
> O comportamento de try – finally é diferente de algumas outras linguagens que dão suporte ao uso de **finally**, como C#.  Um único **__try** pode ter um, mas não ambos, de **`__finally`** e **`__except`** .  Se ambos devem ser usados juntos, uma instrução try-except externa deve incluir a instrução interna try-finally.  As regras que especificam quando cada bloco é executado também são diferentes.

Para compatibilidade com versões anteriores, **_try**, **_finally**e **_leave** são sinônimos de **__try**, **`__finally`** e **`__leave`** a menos que a opção do compilador [/za \( desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="the-__leave-keyword"></a>A palavra-chave __leave

A **`__leave`** palavra-chave é válida somente na seção protegida de uma instrução **try-finally** e seu efeito é ir para o final da seção protegida. A execução continua na primeira instrução do manipulador de encerramento.

Uma **`goto`** instrução também pode sair da seção protegida, mas ela degrada o desempenho porque ele invoca o desenrolamento de pilha. A **`__leave`** instrução é mais eficiente porque não causa o desenrolamento da pilha.

## <a name="abnormal-termination"></a>encerramento anormal

Sair de uma instrução **try – finally** usando a função de tempo de execução [longjmp](../c-runtime-library/reference/longjmp.md) é considerado encerramento anormal. É ilegal pular para uma instrução **__try** , mas legal para saltar de uma. Todas as **`__finally`** instruções que estão ativas entre o ponto de saída (término normal do bloco de **__try** ) e o destino (o **`__except`** bloco que manipula a exceção) devem ser executados. Isso se chama desenrolamento local.

Se um **`try`** bloco for encerrado prematuramente por qualquer motivo, incluindo um salto para fora do bloco, o sistema executará o bloco **finally** associado como parte do processo de desenrolar a pilha. Nesses casos, a função [AbnormalTermination](/windows/win32/Debug/abnormaltermination) retorna **`true`** se for chamada de dentro do bloco **finally** ; caso contrário, retornará **`false`** .

O manipulador de encerramento não será chamado se um processo for eliminado no meio da execução de uma instrução **try-finally** .

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)<br/>
[Manipulação de exceção estruturada (C/C++)](../cpp/structured-exception-handling-c-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Sintaxe do manipulador de terminação](/windows/win32/Debug/termination-handler-syntax)
