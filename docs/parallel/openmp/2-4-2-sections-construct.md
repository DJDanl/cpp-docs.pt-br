---
title: "2.4.2 sections Construct | Microsoft Docs"
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
ms.assetid: e9e6e3ea-7fc9-4925-8f68-92b8a5bb1e76
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.4.2 sections Construct
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **seções** diretiva identifica uma construção de compartilhamento de trabalho noniterative que especifica um conjunto de construções que deverão ser dividida entre os segmentos em uma equipe.  Cada seção é executada uma vez por um thread na equipe.  A sintaxe do  **seções** diretiva é o seguinte:  
  
```  
#pragma omp sections [clause[[,] clause] ...] new-line  
   {  
   [#pragma omp section new-line]  
      structured-block  
   [#pragma omp section new-line  
      structured-block ]  
...  
}  
```  
  
 A cláusula é um destes procedimentos:  
  
 **particular \(** *variável\-list* **\)**  
  
 **firstprivate \(** *variável\-list* **\)**  
  
 **lastprivate \(** *variável\-list* **\)**  
  
 **reduction\(** *operator* **:**  *variable\-list* **\)**  
  
 **nowait**  
  
 Cada seção é precedida por um  **seção** diretiva, embora o  **seção** diretiva é opcional para a primeira seção.  O  **seção** diretivas devem aparecer dentro da extensão lexical a  **seções** diretiva.  Há uma barreira implícita no final de uma  **seções** construir, a menos que uma  **nowait** é especificado.  
  
 Restrições para o  **seções** diretiva são os seguintes:  
  
-   A  **seção** não pode aparecer fora da extensão lexical da diretiva de  **seções** diretiva.  
  
-   Um único  **nowait** cláusula pode aparecer em um  **seções** diretiva.  
  
## Entre as referências:  
  
-   **Private**,  **firstprivate**,  **lastprivate**, e  **redução** cláusulas, consulte  [seção 2.7.2](../Topic/2.7.2%20Data-Sharing%20Attribute%20Clauses.md) na página 25.