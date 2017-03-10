---
title: "Recomendações para escolher entre funções e macros | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.functions
dev_langs:
- C++
helpviewer_keywords:
- functions [CRT], vs. macros
- macros, vs. functions
ms.assetid: 18a633d6-cf1c-470c-a649-fa7677473e2b
caps.latest.revision: 7
author: corob-msft
ms.author: corob
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
ms.openlocfilehash: 561b62cd48e4e119d59aacbf85f516d7f4d8d6c2
ms.lasthandoff: 02/25/2017

---
# <a name="recommendations-for-choosing-between-functions-and-macros"></a>Recomendações para escolher entre funções e macros
A maioria das rotinas de biblioteca em tempo de execução da Microsoft são funções compiladas ou montadas, mas algumas rotinas são implementadas como macros. Quando um arquivo de cabeçalho declara uma função e uma versão de macro de uma rotina, a definição de macro tem precedência, porque ele sempre aparece depois da declaração de função. Quando você invoca uma rotina que é implementada como uma função e uma macro, você pode forçar o compilador a usar a versão da função de duas maneiras:  
  
-   Coloque o nome da rotina entre parênteses.  
  
    ```  
    #include <ctype.h>  
    a = _toupper(a);    // Use macro version of toupper.  
    a = (_toupper)(a);  // Force compiler to use   
                        // function version of toupper.  
    ```  
  
-   "Indefina" a definição da macro com a diretiva `#undef`:  
  
    ```  
    #include <ctype.h>  
    #undef _toupper  
    ```  
  
 Se você precisa escolher entre uma função e uma implementação de macro de uma rotina de biblioteca, considere as seguintes desvantagens:  
  
-   **Velocidade versus tamanho** O principal benefício do uso de macros é o tempo de execução mais rápido. Durante o pré-processamento, uma macro é expandida (substituída pela sua definição) embutida cada vez que for usada. Uma definição de função ocorre apenas uma vez, independentemente de quantas vezes ele é chamada. Macros podem aumentar o tamanho do código, mas não têm a sobrecarga associada às chamadas de função.  
  
-   **Função de avaliação** Uma função avalia para um endereço; uma macro, não. Assim, não é possível usar um nome de macro em contextos que exigem um ponteiro. Por exemplo, você pode declarar um ponteiro para uma função, mas não um ponteiro para uma macro.  
  
-   **Verificação de tipo** Ao declarar uma função, o compilador pode verificar os tipos de argumento. Como você não pode declarar uma macro, o compilador não pode verificar tipos de argumento de macro; embora ele possa verificar o número de argumentos que você passar para uma macro.  
  
## <a name="see-also"></a>Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
