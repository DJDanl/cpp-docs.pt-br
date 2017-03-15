---
title: "VERSION (C/C++) | Microsoft Docs"
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
  - "VERSION"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instrução de arquivo .def VERSION"
ms.assetid: 3533b97c-5183-45f9-9ca8-4e63462b5d26
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# VERSION (C/C++)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Informa o LINK para colocar um número no cabeçalho do arquivo .exe ou da DLL.  
  
```  
VERSION major[.minor]  
```  
  
## Comentários  
 Os argumentos *principais* e *secundárias* são números decimais no intervalo de 0 a 65.535.  O padrão é a versão 0,0.  
  
 Equivalente uma maneira de especificar um número de versão é com o padrão de [Informações de versão](../Topic/-VERSION%20\(Version%20Information\).md) \(\/VERSION\).  
  
## Consulte também  
 [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)