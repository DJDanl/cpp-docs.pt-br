---
title: "Recomenda&#231;&#245;es para escolher entre fun&#231;&#245;es e macros | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.functions"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Funções [CRT], vs. macros"
  - "Macros , vs. funções"
ms.assetid: 18a633d6-cf1c-470c-a649-fa7677473e2b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Recomenda&#231;&#245;es para escolher entre fun&#231;&#245;es e macros
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maioria das rotinas de biblioteca de tempo de execução da Microsoft são criadas ou funções montadas, mas algumas rotinas são implementadas como macros.  Quando um arquivo de cabeçalho declara uma função e uma versão macro de uma rotina, a definição macro prevalece, porque sempre aparece depois da declaração de função.  Quando você invoca uma rotina que é implementada como uma função e uma macro, você pode forçar o compilador para usar a versão da função de duas maneiras:  
  
-   Incluir o nome de rotina entre parênteses.  
  
    ```  
    #include <ctype.h>  
    a = _toupper(a);    // Use macro version of toupper.  
    a = (_toupper)(a);  // Force compiler to use   
                        // function version of toupper.  
    ```  
  
-   “Undefine” a definição macro com a política de `#undef` :  
  
    ```  
    #include <ctype.h>  
    #undef _toupper  
    ```  
  
 Se você precisa escolher entre uma função e uma macro implementação de uma rotina de biblioteca, considere o seguinte as compensações:  
  
-   **Speed versus size** o principal benefício de usar macros é um tempo de execução mais rápidos.  Durante o pré\-processamento, uma macro é \(substituído por sua definição\) embutido expandido cada vez que é usada.  Uma definição de função ocorre apenas uma única vez independentemente de quantas vezes é chamada.  Macros podem aumentar o tamanho de código mas não têm a sobrecarga associada com as chamadas de função.  
  
-   A função de**Function evaluation** A avaliar um endereço; uma macro não.  Portanto você não pode usar um nome macro nos contextos que exigem um ponteiro.  Por exemplo, você pode declarar um ponteiro para uma função, mas não um ponteiro para uma macro.  
  
-   **Type\-checking** quando declara uma função, o compilador pode verificar os tipos do argumento.  Como você não pode declarar uma macro, o compilador não pode verificar tipos macro de argumento; embora possa verificar o número de argumentos você passa a uma macro.  
  
## Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)