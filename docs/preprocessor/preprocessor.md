---
title: "Pr&#233;-processador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "pré-processador"
ms.assetid: e120eda3-b413-49f1-a07c-e9fb128cf500
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Pr&#233;-processador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O pré\-processador é um processador de texto que manipula o texto de um arquivo de origem como parte da primeira fase da tradução.  O pré\-processador não analisa o texto de origem, mas o divide em tokens com a finalidade de localizar as chamadas macro.  Embora o compilador invoque normalmente o pré\-processador na primeira passagem, o pré\-processador também pode ser invocado separadamente para processar o texto sem compilar.  
  
 O material de referência no pré\-processador inclui as seguintes seções:  
  
-   [Diretivas do pré\-processador](../preprocessor/preprocessor-directives.md)  
  
-   [Operadores do pré\-processador](../preprocessor/preprocessor-operators.md)  
  
-   [Macros predefinidas](../preprocessor/predefined-macros.md)  
  
-   [Pragmas](../preprocessor/pragma-directives-and-the-pragma-keyword.md)  
  
 **Específico da Microsoft**  
  
 Você pode obter uma lista de seu código\-fonte após o pré\-processamento usando a opção de compilador [\/E](../build/reference/e-preprocess-to-stdout.md) ou [\/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md).  As duas opções invocam o pré\-processador e tem como saída o texto resultante no dispositivo de saída padrão que, na maioria dos casos, é o console.  A diferença entre as duas opções é que \/E inclui as políticas `#line` e \/EP as retira.  
  
 **FIM de Específico da Microsoft**  
  
##  <a name="_predir_special_terminology"></a> Terminologia especial  
 Na documentação de pré\-processador, o termo "argumento" refere\-se à entidade passada para uma função.  Em alguns casos, ele é modificado por "atual" ou "formal", que descreve a expressão do argumento especificada na chamada de função e na declaração do argumento especificada na definição de função, respectivamente.  
  
 O termo "variável" se refere a um objeto de dados simples do tipo C.  O termo "objeto" se refere a objetos e variáveis C\+\+; ele é um termo inclusivo.  
  
## Consulte também  
 [Referência de pré\-processador C\/C\+\+](../preprocessor/c-cpp-preprocessor-reference.md)   
 [Fases de translação](../preprocessor/phases-of-translation.md)