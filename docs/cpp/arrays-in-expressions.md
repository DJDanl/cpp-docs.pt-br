---
title: "Matrizes em express&#245;es | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "matrizes [C++], em expressões"
  - "expressões [C++], matrizes em"
ms.assetid: 6e5a795b-d6bd-4e39-b313-6a20d47c4d4b
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Matrizes em express&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando um identificador de um tipo de matriz aparece em uma expressão que não seja `sizeof`, address\-of \(**&**\) ou a inicialização de uma referência, ele é convertido em um ponteiro para o primeiro elemento da matriz.  Por exemplo:  
  
```  
char szError1[] = "Error: Disk drive not ready.";  
char *psz = szError1;  
```  
  
 O ponteiro `psz` aponta para o primeiro elemento da matriz `szError1`.  Observe que as matrizes, ao contrário dos ponteiros, não são l\-values modificáveis.  Dessa forma, a atribuição a seguir é inválida:  
  
```  
szError1 = psz;  
```  
  
## Consulte também  
 [Matrizes](../Topic/Arrays%20\(C++\).md)