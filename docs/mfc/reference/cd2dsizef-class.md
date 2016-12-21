---
title: "Classe de CD2DSizeF | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "afxrendertarget/CD2DSizeF"
  - "CD2DSizeF"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CD2DSizeF"
ms.assetid: f486a1e1-997d-4286-8cb9-26369dc82055
caps.latest.revision: 18
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CD2DSizeF
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um wrapper para D2D1\_SIZE\_F.  
  
## Sintaxe  
  
```  
class CD2DSizeF : public D2D1_SIZE_F;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DSizeF::CD2DSizeF](../Topic/CD2DSizeF::CD2DSizeF.md)|Sobrecarregado.  Constrói um objeto de `CD2DSizeF` do objeto de `D2D1_SIZE_F` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DSizeF::IsNull](../Topic/CD2DSizeF::IsNull.md)|Retorna um valor de `boolean` que indica se uma expressão não contém dados válido \(`null`\).|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CD2DSizeF::operator CSize](../Topic/CD2DSizeF::operator%20CSize.md)|Converte `CD2DSizeF` ao objeto de `CSize` .|  
  
## Hierarquia de herança  
 `D2D1_SIZE_F`  
  
 [CD2DSizeF](../../mfc/reference/cd2dsizef-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)