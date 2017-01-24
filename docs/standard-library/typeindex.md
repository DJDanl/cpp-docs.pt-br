---
title: "&lt;typeindex&gt; | Microsoft Docs"
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
  - "<typeindex>"
dev_langs: 
  - "C++"
ms.assetid: a9551137-f74b-4f02-af64-ff00214cea1f
caps.latest.revision: 14
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;typeindex&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inclua o typeindex padrão do cabeçalho\> \<para definir uma classe e para funcionar que oferece suporte à indexação de objetos da classe [type\_information](../cpp/type-info-class.md).  
  
## Sintaxe  
  
```cpp  
#include <typeindex>  
```  
  
## Comentários  
 [Estrutura hash](../standard-library/hash-structure.md) define `hash function` que é apropriado para mapear valores de tipo [type\_index](../standard-library/type-index-class.md) a uma distribuição de valores de índice.  
  
 A classe de `type_index` envolve um ponteiro para um objeto de `type_info` para facilitar a indexação.  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)