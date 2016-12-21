---
title: "exclude (#import) | Microsoft Docs"
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
  - "exclude"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "atributo exclude"
ms.assetid: 0883248a-d4bf-420e-9848-807b28fa976e
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# exclude (#import)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico do C\+\+**  
  
 Exclui itens dos arquivos de cabeçalho da biblioteca de tipos que estão sendo gerados.  
  
## Sintaxe  
  
```  
exclude("Name1"[, "Name2",...])  
```  
  
#### Parâmetros  
 `Name1`  
 O primeiro item a ser excluído.  
  
 `Name2`  
 O segundo item a ser excluído \(se necessário\).  
  
## Comentários  
 As bibliotecas de tipos podem conter definições dos itens definidos em cabeçalhos do sistema ou em outras bibliotecas de tipos.  Esse atributo pode usar qualquer número de argumentos, cada um sendo um item da biblioteca de tipos de nível superior a ser excluído.  
  
 **FIM de Específico do C\+\+**  
  
## Consulte também  
 [Atributos \#import](../preprocessor/hash-import-attributes-cpp.md)   
 [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md)