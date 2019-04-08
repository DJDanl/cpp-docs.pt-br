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
ms.openlocfilehash: d2a1c63f686b46aad4e174c86895f6f9fc00d260
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58778332"
---
# <a name="try-finally-statement"></a>Instrução try-finally

**Seção específica da Microsoft**

A sintaxe a seguir descreve o **try-finally** instrução:

> **\_\_try**<br/>
> {<br/>
> &nbsp;&nbsp;&nbsp;&nbsp;código protegido<br/>
> }<br/>
> **\_\_finally**<br/>
> {<br/>
> &nbsp;&nbsp;&nbsp;&nbsp;código de finalização<br/>
> }<br/>

## <a name="grammar"></a>Gramática

*try-finally-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**\_\_try** *compound-statement* **\_\_finally** *compound-statement*

O **try-finally** instrução é uma extensão da Microsoft para as linguagens C e C++ que permite que aplicativos de destino para garantir a execução de código de limpeza quando a execução de um bloco de código é interrompida. A limpeza consiste em tarefas como desalocar memória, fechar arquivos e liberar identificadores de arquivos. O **try-finally** instrução é especialmente útil para rotinas que têm vários locais em que uma verificação é feita para um erro que poderia causar prematura retornam da rotina.

Para obter informações relacionadas e um exemplo de código, consulte [tente-exceto instrução](../cpp/try-except-statement.md). Para obter mais informações em geral de manipulação de exceção estruturada, consulte [Structured Exception Handling](../cpp/structured-exception-handling-c-cpp.md). Para obter mais informações sobre o tratamento de exceções em aplicativos gerenciados com C + + / CLI, consulte [tratamento de exceções em /clr](../extensions/exception-handling-cpp-component-extensions.md).

> [!NOTE]
> A manipulação de exceção estruturada funciona com Win32 para arquivos de código-fonte em C e C++. No entanto, não é projetada especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, a manipulação de exceção de C++ é mais flexível, pois pode tratar exceções de qualquer tipo. Para programas C++, é recomendável que você use o mecanismo de tratamento de exceções do C++ ([try, catch e throw](../cpp/try-throw-and-catch-statements-cpp.md) instruções).

A instrução composta após a **Try** cláusula é a seção protegida. A instrução composta após a **Finally** cláusula é o manipulador de término. O manipulador especifica um conjunto de ações que são executadas quando você sai da seção protegida, independentemente de a saída da seção protegida ser realizada por uma exceção (encerramento anormal) ou por queda padrão (encerramento normal).

O controle atinge uma **Try** instrução em uma execução sequencial simple (queda). Quando o controle entra o **Try**, seu manipulador associado fica ativo. Se o fluxo de controle chegar ao fim do bloco try, a execução continuará da seguinte maneira:

1. O manipulador de término é invocado.

1. Quando o manipulador de término é concluído, a execução continua após o **Finally** instrução. Independentemente de como a seção protegida é encerrada (por exemplo, por meio de um **goto** fora do corpo protegido ou uma **retornar** instrução), o manipulador de término é executado *antes de* o fluxo de controle sai da seção protegida.

   Um **Finally** instrução bloqueia a procura por um manipulador de exceção apropriado.

Se ocorrer uma exceção na **Try** bloco, o sistema operacional deve localizar um manipulador para a exceção ou o programa falhará. Se um manipulador for encontrado, todos os **Finally** blocos são executados e a execução é retomada no manipulador.

Por exemplo, imagine que uma série de chamadas de função vincula a função A à função D, conforme mostrado na figura a seguir. Cada função tem um manipulador de encerramento. Se uma exceção é gerada na função D e tratada na, os manipuladores de encerramento são chamados nessa ordem que o sistema desenrola a pilha: D, C, B.

![Ordem de encerramento&#45;execução do manipulador](../cpp/media/vc38cx1.gif "ordem de término&#45;execução do manipulador") <br/>
Ordem de execução do manipulador de encerramento

> [!NOTE]
> O comportamento de try-finally é diferente de outras linguagens que dão suporte ao uso de **finalmente**, como C#.  Uma única **Try** pode ter, mas não ambos, do **Finally** e **EXCEPT**.  Se ambos devem ser usados juntos, uma instrução try-except externa deve incluir a instrução interna try-finally.  As regras que especificam quando cada bloco é executado também são diferentes.

Para compatibilidade com versões anteriores, **_try**, **_finally**, e **_leave** são sinônimos do **Try**, **_ Por fim**, e **Leave** , a menos que a opção de compilador [/Za \(desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) for especificado.

## <a name="the-leave-keyword"></a>A palavra-chave __leave

O **Leave** palavra-chave é válido somente dentro da seção protegida de um **try-finally** instrução e seu efeito é ignorar ao final da seção protegida. A execução continua na primeira instrução do manipulador de encerramento.

Um **goto** instrução também pode sair da seção protegida, mas prejudica o desempenho porque invoca o desenrolamento de pilha. O **Leave** instrução é mais eficiente, porque ela não causa o desenrolamento de pilha.

## <a name="abnormal-termination"></a>encerramento anormal

Sair de um **try-finally** instrução usando o [longjmp](../c-runtime-library/reference/longjmp.md) função de tempo de execução é considerada um encerramento anormal. É ilegal para ir diretamente para um **Try** instrução, mas legal para sair de uma. Todos os **Finally** instruções que são ativas entre o ponto de partida (encerramento normal da **Try** bloco) e o destino (o **EXCEPT** bloquear que manipula a exceção) deve ser executado. Isso se chama desenrolamento local.

Se um **tente** bloco é encerrado prematuramente por qualquer motivo, incluindo um salto para fora do bloco, o sistema executa associado **finalmente** bloco como parte do processo de desenrolamento de pilha. Nesses casos, o [AbnormalTermination](/windows/desktop/Debug/abnormaltermination) retornos de função **true** se chamado de dentro do **finalmente** bloco; caso contrário, ele retornará **false**.

O manipulador de término não for chamado se um processo for interrompido no meio da execução uma **try-finally** instrução.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Sintaxe do manipulador de término](/windows/desktop/Debug/termination-handler-syntax)