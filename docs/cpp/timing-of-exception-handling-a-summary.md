---
title: "Tempo de tratamento de exceção: um resumo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- sequence
- sequence, of handlers
- exception handling, timing
- SETJMPEX.H
- termination handlers, timing
- SETJMP.H
- handlers, order of exception
- structured exception handling, timing
ms.assetid: 5d1da546-73fd-4673-aa1a-7ac0f776c420
caps.latest.revision: 6
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 0ba1075095381229667c7164aa7de7f3e4537486
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="timing-of-exception-handling-a-summary"></a>Tempo de tratamento de exceções: um resumo
Um manipulador de término é executado não importa como o bloco de instruções `__try` é terminado. Entre as causas estão: saltar para fora do bloco `__try`, uma instrução `longjmp` que transfere o controle para fora do bloco e desenrolar a pilha devido à manipulação de exceções.  
  
> [!NOTE]
>  O Visual C++ oferece suporte a dois formatos das instruções `setjmp` e `longjmp`. A versão rápida ignora a manipulação de término, mas é mais eficiente. Para usar essa versão, inclua o arquivo SETJMP.H. A outra versão oferece suporte à manipulação de término conforme descrito no parágrafo anterior. Para usar essa versão, inclua o arquivo SETJMPEX.H. O aumento no desempenho da versão rápida depende da configuração de hardware.  
  
 O sistema operacional executa todos os manipuladores de término na ordem apropriada antes que qualquer outro código possa ser executado, incluindo o corpo de um manipulador de exceção.  
  
 Quando a causa da interrupção é uma exceção, o sistema deve primeiro executar a parte de filtro de um ou mais manipuladores de exceções antes de decidir o que terminar. A ordem de eventos é:  
  
1.  Uma exceção é acionada.  
  
2.  O sistema verifica a hierarquia dos manipuladores de exceções ativas e executa o filtro do manipulador com a precedência mais alta, ou seja, o manipulador de exceção instalado mais recentemente e aninhado mais profundamente, em termos de blocos e chamadas de funções.  
  
3.  Se esse filtro passar o controle (retornar 0), o processo continuará até que seja encontrado um filtro que não passe o controle.  
  
4.  Se esse filtro retorna -1, a execução continua onde a exceção foi gerada, e não há terminação ocorre.  
  
5.  Se o filtro retornar 1, ocorrerão os seguintes eventos:  
  
    -   O sistema desenrola a pilha, limpando todos os quadros de pilha entre o código atualmente em execução (onde a exceção foi acionada) e o quadro de pilha que contém o manipulador de exceção que está recebendo o controle.  
  
    -   À medida que a pilha é desenrolada, cada manipulador de término na pilha é executado.  
  
    -   O próprio manipulador de exceção é executado.  
  
    -   O controle passa para a linha de código após o final desse manipulador de exceção.  
  
## <a name="see-also"></a>Consulte também  
 [Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)   
 [Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
