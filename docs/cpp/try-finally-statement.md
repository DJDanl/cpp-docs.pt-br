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
ms.openlocfilehash: c26b72f7c675a4130f38c515cf71ecc290328ccc
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2019
ms.locfileid: "69498602"
---
# <a name="try-finally-statement"></a>Instrução try-finally

**Seção específica da Microsoft**

A sintaxe a seguir descreve a instrução **try – finally** :

> **\_\_Tente**<br/>
> {<br/>
> &nbsp;&nbsp;&nbsp;&nbsp;código protegido<br/>
> }<br/>
> **\_\_disso**<br/>
> {<br/>
> &nbsp;&nbsp;&nbsp;&nbsp;código de encerramento<br/>
> }

## <a name="grammar"></a>Gramática

*try-finally-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;instrução try *composto-instrução*  **\_finally composta\_**  **\_ \_**

A instrução **try-finally** é uma extensão da Microsoft para a C C++ e linguagens que permite aos aplicativos de destino garantir a execução do código de limpeza quando a execução de um bloco de código é interrompida. A limpeza consiste em tarefas como desalocar memória, fechar arquivos e liberar identificadores de arquivos. A instrução **try-finally** é especialmente útil para rotinas que têm vários lugares em que uma verificação é feita para um erro que poderia causar um retorno prematuro da rotina.

Para obter informações relacionadas e um exemplo de código, consulte [instrução try-Except](../cpp/try-except-statement.md). Para obter mais informações sobre manipulação de exceção estruturada em geral, consulte [manipulação de exceção estruturada](../cpp/structured-exception-handling-c-cpp.md). Para obter mais informações sobre como lidar com exceções em C++aplicativos gerenciados com a/CLI, consulte [tratamento de exceção em/CLR](../extensions/exception-handling-cpp-component-extensions.md).

> [!NOTE]
> A manipulação de exceção estruturada funciona com Win32 para arquivos de código-fonte em C e C++. No entanto, não é projetada especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, a manipulação de exceção de C++ é mais flexível, pois pode tratar exceções de qualquer tipo. Para C++ programas, é recomendável que você use o C++ mecanismo de tratamento de exceções (instruções[try, catch e throw](../cpp/try-throw-and-catch-statements-cpp.md) ).

A instrução composta após a cláusula **__try** é a seção protegida. A instrução composta após a cláusula **__finally** é o manipulador de terminação. O manipulador especifica um conjunto de ações que são executadas quando você sai da seção protegida, independentemente de a saída da seção protegida ser realizada por uma exceção (encerramento anormal) ou por queda padrão (encerramento normal).

O controle alcança uma instrução **__try** por execução sequencial simples (que se enquadra). Quando o controle entra no **__try**, seu manipulador associado se torna ativo. Se o fluxo de controle chegar ao fim do bloco try, a execução continuará da seguinte maneira:

1. O manipulador de término é invocado.

1. Quando o manipulador de encerramento for concluído, a execução continuará após a instrução **__finally** . Independentemente de como a seção protegida terminar (por exemplo, por meio de uma **goto** fora do corpo protegido ou de uma instrução **Return** ), o manipulador de terminação será executado *antes que* o fluxo de controle seja movido para fora da seção protegida.

   Uma instrução **__finally** não bloqueia a pesquisa de um manipulador de exceção apropriado.

Se ocorrer uma exceção no bloco **__try** , o sistema operacional deverá encontrar um manipulador para a exceção ou o programa falhará. Se um manipulador for encontrado, todos e todos os blocos **__finally** serão executados e a execução será retomada no manipulador.

Por exemplo, imagine que uma série de chamadas de função vincula a função A à função D, conforme mostrado na figura a seguir. Cada função tem um manipulador de encerramento. Se uma exceção for gerada na função D e for manipulada em um, os manipuladores de terminação serão chamados nessa ordem, pois o sistema desenrolará a pilha: D, C, B.

![Ordem de execução&#45;do manipulador de encerramento](../cpp/media/vc38cx1.gif "da&#45;execução do manipulador de encerramento") <br/>
Ordem de execução do manipulador de encerramento

> [!NOTE]
> O comportamento de try – finally é diferente de algumas outras linguagens que dão suporte ao uso de **finally**, C#como.  Um único **__try** pode ter um, mas não ambos, de **__finally** e **__except**.  Se ambos devem ser usados juntos, uma instrução try-except externa deve incluir a instrução interna try-finally.  As regras que especificam quando cada bloco é executado também são diferentes.

Para compatibilidade com as versões anteriores, **_try**, **_finally**e **_leave** são sinônimos para **__try**, **__finally**e **__leave** , a menos que a opção do compilador [/za \(desabilite as extensões de linguagem) ](../build/reference/za-ze-disable-language-extensions.md)é especificado.

## <a name="the-__leave-keyword"></a>A palavra-chave __leave

A palavra-chave **__leave** só é válida na seção protegida de uma instrução **try-finally** e seu efeito é ir para o final da seção protegida. A execução continua na primeira instrução do manipulador de encerramento.

Uma instrução **goto** também pode sair da seção protegida, mas ela degrada o desempenho porque ele invoca o desenrolamento de pilha. A instrução **__leave** é mais eficiente porque não causa o desenrolamento da pilha.

## <a name="abnormal-termination"></a>encerramento anormal

Sair de uma instrução **try – finally** usando a função de tempo de execução [longjmp](../c-runtime-library/reference/longjmp.md) é considerado encerramento anormal. É ilegal pular para uma instrução **__try** , mas legal para saltar de uma. Todas as instruções **__finally** que estão ativas entre o ponto de saída (término normal do bloco **__try** ) e o destino (o bloco **__except** que manipula a exceção) devem ser executados. Isso se chama desenrolamento local.

Se um bloco **try** for encerrado prematuramente por qualquer motivo, incluindo um salto para fora do bloco, o sistema executará o bloco **finally** associado como parte do processo de desenrolar a pilha. Nesses casos, a função [AbnormalTermination](/windows/win32/Debug/abnormaltermination) retornará **true** se for chamada de dentro do bloco **finally** ; caso contrário, retornará **false**.

O manipulador de encerramento não será chamado se um processo for eliminado no meio da execução de uma instrução **try-finally** .

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Sintaxe do manipulador de terminação](/windows/win32/Debug/termination-handler-syntax)