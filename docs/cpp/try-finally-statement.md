---
title: Instrução try-finally | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __try
- __leave_cpp
- __leave
- __finally_cpp
- __try_cpp
- __finally
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6a6457e92b7f4b57c7c181705e369e8582fb54f9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="try-finally-statement"></a>Instrução try-finally
**Seção específica da Microsoft**  
  
 A sintaxe a seguir descreve a instrução `try-finally`:  
  
```  
__try {  
   // guarded code  
}  
__finally {  
   // termination code  
}  
```  
  
## <a name="grammar"></a>Gramática  
 *try-finally-statement*:  
 `__try` *instruções compostas*  
  
 `__finally` *instruções compostas*  
  
 A instrução `try-finally` é uma extensão da Microsoft para as linguagens C e C++ que permite que aplicativos de destino garantam a execução do código de limpeza quando a execução de um bloco de códigos é interrompida. A limpeza consiste em tarefas como desalocar memória, fechar arquivos e liberar identificadores de arquivos. A instrução `try-finally` é especialmente útil para rotinas que têm vários locais onde uma verificação é feita para um erro que pode causar o retorno prematuro da rotina.  
  
 Para obter informações relacionadas e um exemplo de código, consulte [tente-exceto instrução](../cpp/try-except-statement.md). Para obter mais informações sobre em geral de manipulação de exceção estruturada, consulte [tratamento de exceção estruturada](../cpp/structured-exception-handling-c-cpp.md). Para obter mais informações sobre como manipular exceções em aplicativos gerenciados, consulte [manipulação de exceções em /clr](../windows/exception-handling-cpp-component-extensions.md).  
  
> [!NOTE]
>  A manipulação de exceção estruturada funciona com Win32 para arquivos de código-fonte em C e C++. No entanto, não é projetada especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, a manipulação de exceção de C++ é mais flexível, pois pode tratar exceções de qualquer tipo. Para programas em C++, é recomendável que você use o mecanismo de tratamento de exceção C++ ([try, catch e throw](../cpp/try-throw-and-catch-statements-cpp.md) instruções).  
  
 A instrução composta após a cláusula `__try` é a seção protegida. A instrução composta após a cláusula `__finally` é o manipulador de término. O manipulador especifica um conjunto de ações que são executadas quando você sai da seção protegida, independentemente de a saída da seção protegida ser realizada por uma exceção (encerramento anormal) ou por queda padrão (encerramento normal).  
  
 O controle atinge a instrução `__try` em uma execução sequencial simples (queda). Quando o controle entra em `__try`, seu manipulador associado fica ativo. Se o fluxo de controle chegar ao fim do bloco try, a execução continuará da seguinte maneira:  
  
1.  O manipulador de término é invocado.  
  
2.  Quando o manipulador de término é concluído, a execução continua após a instrução `__finally`. Independentemente de como a seção protegida é encerrada (por exemplo, por meio de um `goto` fora do corpo protegido ou de uma instrução `return`), o manipulador de encerramento é executado `before` que o fluxo de controle sai da seção protegida.  
  
     Um **Finally** instrução não bloqueia a pesquisa para um manipulador de exceção apropriada.  
  
 Se ocorrer uma exceção no bloco `__try`, o sistema operacional deve localizar um manipulador para a exceção. Caso contrário, o programa falhará. Se um manipulador for encontrado, todos os blocos `__finally` serão executados, e a execução será retomada no manipulador.  
  
 Por exemplo, imagine que uma série de chamadas de função vincula a função A à função D, conforme mostrado na figura a seguir. Cada função tem um manipulador de encerramento. Se uma exceção é gerada na função D e tratada na A, os manipuladores de encerramento são chamados nessa ordem à medida que o sistema desenrola a pilha: D, C, B.  
  
 ![Ordem de encerramento&#45;execução do manipulador](../cpp/media/vc38cx1.gif "vc38CX1")  
Ordem de execução do manipulador de encerramento  
  
> [!NOTE]
>  O comportamento de try-finally é diferente de outros idiomas que dão suporte ao uso de **finalmente**, como c#.  Um único `__try` pode ter `__finally` ou `__except`, mas não ambos.  Se ambos devem ser usados juntos, uma instrução try-except externa deve incluir a instrução interna try-finally.  As regras que especificam quando cada bloco é executado também são diferentes.  
  
## <a name="the-leave-keyword"></a>A palavra-chave __leave  
 A palavra-chave `__leave` é válida somente na seção protegida de uma instrução `try-finally`, e seu efeito é ir diretamente para o final da seção protegida. A execução continua na primeira instrução do manipulador de encerramento.  
  
 Uma instrução `goto` também pode sair da seção protegida, mas prejudica o desempenho porque invoca o desenrolamento da pilha. A instrução `__leave` é mais eficiente porque não causa o desenrolamento da pilha.  
  
## <a name="abnormal-termination"></a>encerramento anormal  
 Sair de um `try-finally` instrução usando o [longjmp](../c-runtime-library/reference/longjmp.md) função do tempo de execução é considerada o encerramento anormal. Não é permitido ir para uma instrução `__try`, mas é permitido sair de uma. Todas as instruções `__finally` que estão ativas entre o ponto de partida (encerramento normal do bloco `__try`) e o destino (o bloco `__except` que trata a exceção) devem ser executadas. Isso se chama desenrolamento local.  
  
 Se um **tente** bloco é terminado prematuramente por qualquer motivo, incluindo um salto para fora do bloco, o sistema executa associado **finalmente** bloco como parte do processo de desenrolamento de pilha. Nesses casos, o [AbnormalTermination](http://msdn.microsoft.com/library/windows/desktop/ms679265) função retorna TRUE se for chamado de dentro de **finalmente** bloco; caso contrário, retornará FALSE.  
  
 O manipulador de encerramento não é chamado se um processo é interrompido no meio da execução de uma instrução `try-finally`.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)   
 [(C/C++) de tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Sintaxe do manipulador de término](http://msdn.microsoft.com/library/windows/desktop/ms681393)