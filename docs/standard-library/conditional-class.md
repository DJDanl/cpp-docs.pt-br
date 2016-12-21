---
title: "Classe conditional | Microsoft Docs"
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
  - "std::tr1::conditional"
  - "std.tr1.conditional"
  - "conditional"
  - "std.conditional"
  - "std::conditional"
  - "type_traits/std::conditional"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe conditional [TR1]"
  - "conditional"
ms.assetid: ece9f539-fb28-4e26-a79f-3264bc984493
caps.latest.revision: 22
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe conditional
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Seleciona um dos dois tipos, dependendo da condição especificada.  
  
## Sintaxe  
  
```  
template <bool B, class T1, class T2>  
    struct conditional;  
  
template <bool _Test, class _T1, class _T2>  
    using conditional_t = typename conditional<_Test, _T1, _T2>::type;  
```  
  
#### Parâmetros  
 `B`  
 O valor que determina o tipo selecionado.  
  
 `T1`  
 O resultado de tipo quando B é true.  
  
 `T2`  
 O resultado de tipo quando B é false.  
  
## Comentários  
 A definição de membro de modelo `conditional<B, T1, T2>::type` é avaliada como `T1` quando `B` for avaliada como `true`, e avalia a `T2` quando `B` for avaliada como `false`.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)