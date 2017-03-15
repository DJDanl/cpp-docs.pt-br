---
title: "ML Nonfatal Error A2008 | Microsoft Docs"
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
  - "A2008"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A2008"
ms.assetid: ca24157f-c88a-4678-ae06-3bc3cd956001
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Nonfatal Error A2008
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**Erro de sintaxe:**  
  
 Um token no local atual causou um erro de sintaxe.  
  
 Pode ter ocorrido um dos seguintes:  
  
-   Um prefixo de ponto foi adicionado ao ou omitido de uma diretiva.  
  
-   Uma palavra reservada \(como  **c** ou  **tamanho**\) foi usado como um identificador.  
  
-   Foi usada uma instrução que não estavam disponíveis com a seleção atual do processador ou o coprocessador.  
  
-   Um operador de comparação tempo de execução \(como `==`\) foi usado em uma instrução condicional assembly em vez de um operador relacional \(como  [EQ](../../assembler/masm/operator-eq.md)\).  
  
-   Uma instrução ou a diretiva foi dada poucos operandos.  
  
-   Uma diretiva obsoleta foi usada.  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)