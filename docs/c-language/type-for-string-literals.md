---
title: "Tipo para literais da cadeia de caracteres | Microsoft Docs"
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
  - "literais String, Tipo "
  - "tipos [C], literais String"
ms.assetid: f50a28af-20c1-4440-bdc6-564c86a309c8
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipo para literais da cadeia de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As literais de cadeias de caracteres têm a matriz do tipo `char` \(ou seja, **char\[ \]**\). \(As cadeias de caracteres amplos têm a matriz do tipo `wchar_t` \(ou seja, **wchar\_t\[ \]**\)\). Isso significa que uma cadeia de caracteres é uma matriz com elementos do tipo `char`.  O número de elementos na matriz é igual ao número de caracteres na cadeia de caracteres mais um, para o caractere nulo de encerramento.  
  
## Consulte também  
 [literais String C](../c-language/c-string-literals.md)