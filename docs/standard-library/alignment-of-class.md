---
title: "Classe alignment_of | Microsoft Docs"
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
  - "std.tr1.alignment_of"
  - "std::tr1::alignment_of"
  - "alignment_of"
  - "std.alignment_of"
  - "std::alignment_of"
  - "type_traits/std::alignment_of"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe alignment_of [TR1]"
  - "alignment_of"
ms.assetid: 4141c59a-f94e-41c4-93fd-9ea578b27387
caps.latest.revision: 22
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe alignment_of
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém o alinhamento do tipo especificado.  Essa estrutura é implementada em termos de [alignof](../cpp/alignof-and-alignas-cpp.md).  Use `alignof` diretamente quando você simplesmente precisa consultar um valor de alinhamento.  Use alignment\_of quando você precisa de uma constante integral, por exemplo, ao fazer a expedição de marca.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct alignment_of;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## Comentários  
 A consulta de tipo mantém o valor do alinhamento do tipo `Ty`.  
  
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [Classe aligned\_storage](../standard-library/aligned-storage-class.md)