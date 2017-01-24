---
title: "Procurar dependentes em caminhos | Microsoft Docs"
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
helpviewer_keywords: 
  - "dependentes, NMAKE"
  - "programa NMAKE, dependentes"
ms.assetid: bf998e47-da74-48b5-891d-d3d8ce57264b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Procurar dependentes em caminhos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada dependente tiver um caminho de pesquisa opcional, especificado como segue:  
  
## Sintaxe  
  
```  
{directory[;directory...]}dependent  
```  
  
## Comentários  
 NMAKE procura um dependentes primeiro no diretório atual, e nos diretórios na ordem especificada.  Uma macro pode especificar a parte ou de todo o caminho de pesquisa.  Incluir nomes de diretório nas chaves \({}\); separe vários diretórios com um ponto\-e\-vírgula \(;\).  Nenhum espaço ou a guia são permitidos.  
  
## Consulte também  
 [Dependentes](../build/dependents.md)