---
title: "Instrução try-finally (C) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- try_cpp
- try
- finally
- finally_cpp
dev_langs:
- C++
helpviewer_keywords:
- try-catch keyword [C], try-finally keyword [C]
- __finally keyword [C], try-finally statement syntax
- try-finally keyword [C]
- __finally keyword [C]
- try-catch keyword [C]
- structured exception handling, try-finally
ms.assetid: 514400c1-c322-4bf3-9e48-3047240b8a82
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 0112bddf0b33ede90fae2e1fbd2323fa082e34a7
ms.lasthandoff: 02/25/2017

---
# <a name="try-finally-statement-c"></a>Instrução try-finally (C)
**Seção específica da Microsoft**  
  
 A instrução `try-finally` é uma extensão da Microsoft para a linguagem C que permite que aplicativos garantam a execução do código de limpeza quando a execução de um bloco de códigos é interrompida. A limpeza consiste em tarefas como desalocar memória, fechar arquivos e liberar identificadores de arquivos. A instrução `try-finally` é especialmente útil para rotinas que têm vários locais onde uma verificação é feita para um erro que pode causar o retorno prematuro da rotina.  
  
 *try-finally-statement*:  
 **__try**  *compound-statement*  
  
 **__finally**  *compound-statement*  
  
 A instrução composta após a cláusula `__try` é a seção protegida. A instrução composta após a cláusula `__finally` é o manipulador de término. O manipulador especifica um conjunto de ações que são executadas quando você sai da seção protegida, independentemente de a saída da seção protegida ser realizada por uma exceção (término anormal) ou por queda padrão (término normal).  
  
 O controle atinge a instrução `__try` em uma execução sequencial simples (queda). Quando o controle entra na instrução `__try`, seu manipulador associado fica ativo. A execução procede da seguinte maneira:  
  
1.  A seção protegida é executada.  
  
2.  O manipulador de término é invocado.  
  
3.  Quando o manipulador de término é concluído, a execução continua após a instrução `__finally`. Independentemente de como a seção protegida é encerrada (por exemplo, por meio de uma instrução `goto` fora do corpo protegido ou de uma instrução `return`), o manipulador de término é executado antes que o fluxo de controle saia da seção protegida.  
  
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
