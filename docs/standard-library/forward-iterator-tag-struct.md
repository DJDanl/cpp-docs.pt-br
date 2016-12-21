---
title: "Struct forward_iterator_tag | Microsoft Docs"
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
  - "std.forward_iterator_tag"
  - "forward_iterator_tag"
  - "std::forward_iterator_tag"
  - "xutility/std::forward_iterator_tag"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe forward_iterator_tag"
  - "Struct forward_iterator_tag"
ms.assetid: 68b633ac-b135-4e9e-837d-14248a262ec5
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct forward_iterator_tag
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe que fornece um tipo de retorno da função de **iterator\_category** que representa um iterador para frente.  
  
## Sintaxe  
  
```  
  
   struct forward_iterator_tag  
: public input_iterator_tag {};  
```  
  
## Comentários  
 As classes da marca de categoria são usadas como criar marcas para a seleção do algoritmo.  A função do modelo precisar descobrir o que é a mais a categoria específica do argumento de iterador de forma que possa usar o algoritmo mais eficiente em tempo de compilação.  Para cada iterador do tipo `Iterator`, `iterator_traits`\<`Iterator`\>**::iterator\_category** deve ser definido para ser a marca para mais específica da categoria que descreve o comportamento de iterador.  
  
 O tipo é o mesmo que **iterator**\<**Iter**\>**::iterator\_category** quando **Iter** descreve um objeto que pode servir como um iterador para frente.  
  
## Exemplo  
 Consulte [iterator\_traits](../standard-library/iterator-traits-struct.md) ou [random\_access\_iterator\_tag](../standard-library/random-access-iterator-tag-struct.md) para obter um exemplo de como usar **iterator\_tag**S.  
  
## Requisitos  
 **Cabeçalho:** \<iterator\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Struct input\_iterator\_tag](../standard-library/input-iterator-tag-struct.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)