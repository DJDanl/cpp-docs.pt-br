---
title: "Classe unchecked_array_iterator | Microsoft Docs"
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
  - "unchecked_array_iterator"
  - "stdext::unchecked_array_iterator"
dev_langs: 
  - "C++"
ms.assetid: 693b3b30-4e3a-465b-be06-409700bc50b1
caps.latest.revision: 15
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe unchecked_array_iterator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe `unchecked_array_iterator` permite que você encapsule uma matriz ou um ponteiro em um iterador não verificado.  Use essa classe como um wrapper \(usando a função [make\_unchecked\_array\_iterator](../Topic/make_unchecked_array_iterator.md)\) para matrizes ou ponteiros brutos como uma maneira direcionada de gerenciar avisos de ponteiros não verificados, em vez de silenciar esses avisos globalmente.  Se possível, prefira a versão verificada dessa classe, [checked\_array\_iterator](../standard-library/checked-array-iterator-class.md).  
  
> [!NOTE]
>  Essa classe é uma extensão da Biblioteca Padrão do C\+\+ da Microsoft.  O código implementado usando essa função não é portátil para ambientes de criação do C\+\+ Standard que não oferecem suporte a essa extensão da Microsoft.  
  
## Sintaxe  
  
```  
template <class Iterator>  
    class unchecked_array_iterator;  
```  
  
## Comentários  
 Essa classe é definida no namespace [stdext](../Topic/stdext%20Namespace.md).  
  
 Esta é a versão não verificada da [classe checked\_array\_iterator](../standard-library/checked-array-iterator-class.md) e oferece suporte a todos os mesmos membros e sobrecargas.  Para obter mais informações sobre o recurso de iterador verificado com exemplos de código, consulte [Iteradores Verificados](../standard-library/checked-iterators.md).  
  
## Requisitos  
 **Cabeçalho:** \<iterator\>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [\<iterator\>](../standard-library/iterator.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)