---
title: "Classes de modelo para matrizes, listas e mapas | Microsoft Docs"
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
  - "vc.classes.template"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "matrizes [C++], Classes "
  - "classes de lista"
  - "classes de mapa"
  - "classes de modelo"
  - "classes de modelo, para matrizes/listas e mapas"
ms.assetid: a8331c4b-068a-48f8-a629-b8449601e121
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de modelo para matrizes, listas e mapas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essas classes de coleção são os modelos cujos parâmetros determinam os tipos de objetos armazenados em agregações.  `CArray`, `CMap`, e as classes de `CList` usam as funções globais auxiliar que geralmente devem ser personalizadas.  Para obter mais informações sobre essas funções auxiliares, consulte [Auxiliares da classe de coleção](../mfc/reference/collection-class-helpers.md).  As classes do ponteiro são wrappers para outras classes da biblioteca de classes.  Usando esses wrappers, você inscrever a verificação de tipo do compilador para ajudar a evitar erros.  Para obter mais informações sobre como usar essas classes, consulte [Coleções](../mfc/collections.md).  
  
 Essas classes fornecem modelos que você pode usar para criar matrizes, listas, mapas e usando qualquer tipo você gostaria.  
  
 [CArray](../mfc/reference/carray-class.md)  
 A classe do modelo para fazer matrizes de tipos arbitrários.  
  
 [CList](../mfc/reference/clist-class.md)  
 A classe do modelo para fazer lista de tipos arbitrários.  
  
 [CMap](../mfc/reference/cmap-class.md)  
 A classe do modelo para fazer mapas com chave e tipos de valores arbitrários.  
  
 [CTypedPtrArray](../mfc/reference/ctypedptrarray-class.md)  
 A classe do modelo para matrizes de tipo seguras dos ponteiros.  
  
 [CTypedPtrList](../mfc/reference/ctypedptrlist-class.md)  
 A classe do modelo para listas de tipo seguras de ponteiros.  
  
 [CTypedPtrMap](../Topic/CTypedPtrMap%20Class.md)  
 A classe do modelo para mapas tipo seguro com ponteiros.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)