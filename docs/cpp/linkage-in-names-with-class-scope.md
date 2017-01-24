---
title: "Liga&#231;&#227;o em nomes com escopo de classe | Microsoft Docs"
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
  - "nomes de classe [C++], vinculação"
  - "escopo de classe [C++], vinculação em nomes com"
  - "classes [C++], nomes"
  - "classes [C++], escopo"
  - "vinculação externa, regras de vinculação de escopo"
  - "vinculação [C++], regras de vinculação de escopo"
  - "nomes [C++], regras de vinculação de escopo"
  - "escopo [C++], nomes de classe"
  - "escopo [C++], regras de vinculação"
ms.assetid: 45275ff3-6e94-4967-82c8-ba540ef4da28
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Liga&#231;&#227;o em nomes com escopo de classe
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As regras de vinculação a seguir se aplicam aos nomes com escopo de classe:  
  
-   Os membros da classe Static têm vinculação externa.  
  
-   As funções de membro da classe têm vinculação externa.  
  
-   Os enumeradores e os nomes `typedef` não têm vínculo.  
  
 **Específico da Microsoft**  
  
-   As funções declaradas como `friend` devem ter vinculação externa.  Declarar uma função estática como `friend` gera um erro.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Programa e ligação](../cpp/program-and-linkage-cpp.md)