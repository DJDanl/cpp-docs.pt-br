---
title: "Classe SafeIntException | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "SafeIntException Class"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe SafeIntException"
ms.assetid: 88bef958-1f48-4d55-ad4f-d1f9581a293a
caps.latest.revision: 8
caps.handback.revision: 8
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Classe SafeIntException
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de `SafeInt` usa `SafeIntException` para identificar como uma operação matemática não pode ser concluída.  
  
## Sintaxe  
  
```  
class SafeIntException;  
```  
  
## Membros  
  
### Construtores Públicos  
 [SafeIntException::SafeIntException](../Topic/SafeIntException::SafeIntException.md)  
 Cria um objeto `SafeIntException`.  
  
## Comentários  
 [Classe SafeInt](../windows/safeint-class.md) é a única classe que usa a classe de `SafeIntException` .  
  
## Hierarquia de Herança  
 [SafeIntException Class](../windows/safeintexception-class.md)  
  
## Requisitos  
 **Cabeçalho:** safeint.h  
  
 msl::utilities de**Namespace:**  
  
## Consulte também  
 [Biblioteca de SafeInt](../windows/safeint-library.md)   
 [Classe SafeInt](../windows/safeint-class.md)