---
title: "2.4.3 single Construct | Microsoft Docs"
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
ms.assetid: 15c180cd-e462-4b41-bf8c-cb8b1afb1a9b
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.4.3 single Construct
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **único** diretiva identifica uma construção que especifica que o bloco estruturado associado é executado por apenas um thread na equipe \(não necessariamente o thread mestre\).  A sintaxe do  **único** diretiva é o seguinte:  
  
```  
#pragma omp single [clause[[,] clause] ...] new-line  
   structured-block  
```  
  
 A cláusula é um destes procedimentos:  
  
 **particular \(** *variável\-list* **\)**  
  
 **firstprivate \(** *variável\-list* **\)**  
  
 **copyprivate \(** *variável\-list* **\)**  
  
 **nowait**  
  
 Há uma barreira implícita após o  **único** construir a menos que uma  **nowait** cláusula for especificada.  
  
 Restrições para o  **único** diretiva são os seguintes:  
  
-   Um único  **nowait** cláusula pode aparecer em um  **único** diretiva.  
  
-   O  **copyprivate** cláusula não deve ser usada com o  **nowait** cláusula.  
  
## Entre as referências:  
  
-   **Private**,  **firstprivate**, e  **copyprivate** cláusulas, consulte  [seção 2.7.2](../Topic/2.7.2%20Data-Sharing%20Attribute%20Clauses.md) na página 25.