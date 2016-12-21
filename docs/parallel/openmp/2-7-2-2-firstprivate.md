---
title: "2.7.2.2 firstprivate | Microsoft Docs"
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
ms.assetid: ece6ff12-2be1-4e4f-866c-d39345fd87b5
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.7.2.2 firstprivate
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **firstprivate** cláusula fornece um superconjunto da funcionalidade fornecida pelo  **particular** cláusula.  A sintaxe do  **firstprivate** cláusula é da seguinte maneira:  
  
```  
firstprivate(variable-list)  
```  
  
 Variáveis especificadas na  *variável\-list* tem  **particular** semântica de cláusula, conforme descrito em  [seção 2.7.2.1](../../parallel/openmp/2-7-2-1-private.md) na página 25.  A inicialização ou construção acontece como se ele foi feito uma vez por thread, anterior à execução do segmento da construção.  Para um  **firstprivate** cláusula em uma construção em paralela, o valor inicial do novo objeto particular é o valor do objeto original que existe imediatamente antes da construção paralela para o segmento que encontra\-lo.  Para um  **firstprivate** cláusula em uma construção de compartilhamento de trabalho, o valor inicial do novo objeto particular para cada thread que executa a construção de compartilhamento de trabalho é o valor do objeto original que existe antes do ponto no tempo que o mesmo thread encontra a construção de compartilhamento de trabalho.  Além disso, para objetos em C\+\+, o novo objeto particular para cada thread é construída a partir do objeto original de cópia.  
  
 As restrições para o  **firstprivate** cláusula são os seguintes:  
  
-   Uma variável especificada em um  **firstprivate** cláusula não deve ter um tipo incompleto ou um tipo de referência.  
  
-   Uma variável com um tipo de classe é especificado como  **firstprivate** deve ter um construtor de cópia acessível e objetiva.  
  
-   Variáveis que são privados dentro de uma região paralela ou que aparecem na  **redução** cláusula de um  **paralela** diretiva não pode ser especificada um  **firstprivate** cláusula em uma diretiva de compartilhamento de trabalho que vincula a construção parallel.