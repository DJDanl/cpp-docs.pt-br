---
title: "Struct input_iterator_tag | Microsoft Docs"
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
  - "input_iterator_tag"
  - "std.input_iterator_tag"
  - "std::input_iterator_tag"
  - "xutility/std::input_iterator_tag"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe input_iterator_tag"
  - "Struct input_iterator_tag"
ms.assetid: ad68a4c6-f315-4ce1-8b74-c1fc71bd1577
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct input_iterator_tag
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe que fornece um tipo de retorno da função de **iterator\_category** que representa um iterador de entrada.  
  
## Sintaxe  
  
```  
  
struct input_iterator_tag {};  
  
```  
  
## Comentários  
 As classes da marca de categoria são usadas como criar marcas para a seleção do algoritmo.  A função do modelo precisa localizar a categoria a mais específica do argumento de iterador de forma que possa usar o algoritmo mais eficiente em tempo de compilação.  Para cada iterador do tipo `Iterator`, `iterator_traits`\<`Iterator`\>**::iterator\_category** deve ser definido para ser a marca para mais específica da categoria que descreve o comportamento de iterador.  
  
 O tipo é o mesmo que **iterator**\<**Iter**\>**::iterator\_category** quando **Iter** descreve um objeto que pode servir como um iterador de entrada.  
  
## Exemplo  
 Consulte [iterator\_traits](../standard-library/iterator-traits-struct.md) ou [random\_access\_iterator\_tag](../standard-library/random-access-iterator-tag-struct.md) para obter um exemplo de como usar **iterator\_tag**S.  
  
## Requisitos  
 **Cabeçalho:** \<iterator\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)