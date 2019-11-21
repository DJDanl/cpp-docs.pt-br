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
ms.openlocfilehash: 045d2bf5617c81bcc4d7a202f36b112d5f0142a6
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246299"
---
# <a name="try-finally-statement"></a>Instrução try-finally

**Seção específica da Microsoft**

The following syntax describes the **try-finally** statement:

> **\_\_try**<br/>
> {<br/>
> &nbsp;&nbsp;&nbsp;&nbsp;// guarded code<br/>
> }<br/>
> **\_\_finally**<br/>
> {<br/>
> &nbsp;&nbsp;&nbsp;&nbsp;// termination code<br/>
> }

## <a name="grammar"></a>Gramática

*try-finally-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **\_\_try** *compound-statement* **\_\_finally** *compound-statement*

The **try-finally** statement is a Microsoft extension to the C and C++ languages that enables target applications to guarantee execution of cleanup code when execution of a block of code is interrupted. A limpeza consiste em tarefas como desalocar memória, fechar arquivos e liberar identificadores de arquivos. The **try-finally** statement is especially useful for routines that have several places where a check is made for an error that could cause premature return from the routine.

For related information and a code sample, see [try-except Statement](../cpp/try-except-statement.md). For more information on structured exception handling in general, see [Structured Exception Handling](../cpp/structured-exception-handling-c-cpp.md). For more information on handling exceptions in managed applications with C++/CLI, see [Exception Handling under /clr](../extensions/exception-handling-cpp-component-extensions.md).

> [!NOTE]
> A manipulação de exceção estruturada funciona com Win32 para arquivos de código-fonte em C e C++. No entanto, não é projetada especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, a manipulação de exceção de C++ é mais flexível, pois pode tratar exceções de qualquer tipo. For C++ programs, it is recommended that you use the C++ exception-handling mechanism ([try, catch, and throw](../cpp/try-throw-and-catch-statements-cpp.md) statements).

The compound statement after the **__try** clause is the guarded section. The compound statement after the **__finally** clause is the termination handler. O manipulador especifica um conjunto de ações que são executadas quando você sai da seção protegida, independentemente de a saída da seção protegida ser realizada por uma exceção (encerramento anormal) ou por queda padrão (encerramento normal).

Control reaches a **__try** statement by simple sequential execution (fall through). When control enters the **__try**, its associated handler becomes active. Se o fluxo de controle chegar ao fim do bloco try, a execução continuará da seguinte maneira:

1. O manipulador de término é invocado.

1. When the termination handler completes, execution continues after the **__finally** statement. Regardless of how the guarded section ends (for example, via a **goto** out of the guarded body or a **return** statement), the termination handler is executed *before* the flow of control moves out of the guarded section.

   A **__finally** statement does not block searching for an appropriate exception handler.

If an exception occurs in the **__try** block, the operating system must find a handler for the exception or the program will fail. If a handler is found, any and all **__finally** blocks are executed and execution resumes in the handler.

Por exemplo, imagine que uma série de chamadas de função vincula a função A à função D, conforme mostrado na figura a seguir. Cada função tem um manipulador de encerramento. Se uma exceção é gerada na função D e tratada na A, os manipuladores de encerramento são chamados nessa ordem à medida que o sistema desenrola a pilha: D, C, B.

![Order of termination&#45;handler execution](../cpp/media/vc38cx1.gif "Order of termination&#45;handler execution") <br/>
Ordem de execução do manipulador de encerramento

> [!NOTE]
> The behavior of try-finally is different from some other languages that support the use of **finally**, such as C#.  A single **__try** may have either, but not both, of **__finally** and **__except**.  Se ambos devem ser usados juntos, uma instrução try-except externa deve incluir a instrução interna try-finally.  As regras que especificam quando cada bloco é executado também são diferentes.

For compatibility with previous versions, **_try**, **_finally**, and **_leave** are synonyms for **__try**, **__finally**, and **__leave** unless compiler option [/Za \(Disable language extensions)](../build/reference/za-ze-disable-language-extensions.md) is specified.

## <a name="the-__leave-keyword"></a>A palavra-chave __leave

The **__leave** keyword is valid only within the guarded section of a **try-finally** statement, and its effect is to jump to the end of the guarded section. A execução continua na primeira instrução do manipulador de encerramento.

A **goto** statement can also jump out of the guarded section, but it degrades performance because it invokes stack unwinding. The **__leave** statement is more efficient because it does not cause stack unwinding.

## <a name="abnormal-termination"></a>encerramento anormal

Exiting a **try-finally** statement using the [longjmp](../c-runtime-library/reference/longjmp.md) run-time function is considered abnormal termination. It is illegal to jump into a **__try** statement, but legal to jump out of one. All **__finally** statements that are active between the point of departure (normal termination of the **__try** block) and the destination (the **__except** block that handles the exception) must be run. Isso se chama desenrolamento local.

If a **try** block is prematurely terminated for any reason, including a jump out of the block, the system executes the associated **finally** block as a part of the process of unwinding the stack. In such cases, the [AbnormalTermination](/windows/win32/Debug/abnormaltermination) function returns **true** if called from within the **finally** block; otherwise, it returns **false**.

The termination handler is not called if a process is killed in the middle of executing a **try-finally** statement.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Writing a termination handler](../cpp/writing-a-termination-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Termination-Handler Syntax](/windows/win32/Debug/termination-handler-syntax)