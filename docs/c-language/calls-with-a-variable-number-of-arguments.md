---
title: "Chamadas com um número variável de argumentos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- arguments [C++], function
- arguments [C++], variable number of
- VARARGS.H
- ellipses (...), variable number of arguments
- STDARGS.H
- function calls, arguments
- '... ellipsis'
- function calls, variable number of arguments
ms.assetid: 8808fb26-4822-42f5-aba3-ac64b54e151b
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
ms.openlocfilehash: f51f5c4356e3b5045bf14b220137d3ee3b0b80a1
ms.lasthandoff: 02/25/2017

---
# <a name="calls-with-a-variable-number-of-arguments"></a>Chamadas com um número variável de argumentos
Uma lista de parâmetros parcial pode ser finalizada pela notação de reticências, uma vírgula seguida de três pontos (**, ...**), para indicar que pode haver mais argumentos transmitidos à função, mas não são fornecidas mais informações sobre eles. A verificação de tipo não é executada nesses argumentos. Pelo menos um parâmetro deve preceder a notação de reticências, e a notação de reticências deve ser o token mais recente na lista de parâmetros. Sem a notação de reticências, o comportamento de uma função é indefinido se receber parâmetros além daqueles declarados na lista de parâmetros.  
  
 Para chamar uma função com um número variável de argumentos, basta especificar qualquer número de argumentos na chamada de função. Um exemplo é a função `printf` da biblioteca em tempo de execução C. A chamada de função deve incluir um argumento para cada nome do tipo declarado na lista de parâmetros ou na lista de tipos de argumento.  
  
 Todos os argumentos especificados na chamada de função são colocados na pilha, a menos que a convenção de chamada `__fastcall` seja especificada. O número de parâmetros declarados para a função determina quantos dos argumentos são obtidos da pilha e atribuídos aos parâmetros. Você é responsável por recuperar todos os argumentos adicionais da pilha e por determinar quantos argumentos estão presentes. O arquivo STDARG.H contém macros estilo ANSI para acessar argumentos das funções que possuem um número variável de argumentos. Além disso, macros de estilo XENIX em VARARGS.H têm suporte.  
  
 Esse exemplo de declaração é para uma função que chama um número variável de argumentos:  
  
```  
int average( int first, ...);  
```  
  
## <a name="see-also"></a>Consulte também  
 [Chamadas de função](../c-language/function-calls.md)
