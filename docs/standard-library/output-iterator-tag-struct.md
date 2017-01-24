---
title: "Struct output_iterator_tag | Microsoft Docs"
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
  - "std::output_iterator_tag"
  - "output_iterator_tag"
  - "xutility/std::output_iterator_tag"
  - "std.output_iterator_tag"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe output_iterator_tag"
  - "Struct output_iterator_tag"
ms.assetid: c23a4331-b069-4fa0-9c3a-1c9be7095553
caps.latest.revision: 19
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct output_iterator_tag
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe que fornece um tipo de retorno para **iterator\_category** função que representa um iterador de saída.  
  
## Sintaxe  
  
```  
  
struct output_iterator_tag {};  
  
```  
  
## Comentários  
 As classes de marca de categoria são usadas como compilar marcas de seleção de algoritmo. A função de modelo precisa localizar a categoria mais específica do seu argumento de iterador para que ele possa usar o algoritmo mais eficiente em tempo de compilação. Para cada iterador do tipo `Iterator`, `iterator_traits`\<`Iterator`\>**:: iterator\_category** deve ser definido para ser a mais específica possível marca de categoria que descreve o comportamento do iterador.  
  
 O tipo é o mesmo que **iterador**\<**Iter**\>**:: iterator\_category** quando **Iter** descreve um objeto que pode servir como um iterador de saída.  
  
 Essa marca não é parametrizada na `value_type` ou `difference_type` para o iterador, assim como acontece com as outras marcas de iterador, porque os iteradores de saída não tem uma um `value_type` ou um `difference_type`.  
  
## Exemplo  
 Consulte [iterator\_traits](../standard-library/iterator-traits-struct.md) ou [random\_access\_iterator\_tag](../standard-library/random-access-iterator-tag-struct.md) para obter um exemplo de como usar **iterator\_tag**s.  
  
## Requisitos  
 **Cabeçalho:** \< iterator \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)