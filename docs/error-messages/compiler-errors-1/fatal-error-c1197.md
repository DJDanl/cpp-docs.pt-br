---
title: "Erro fatal C1197 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C1197"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1197"
ms.assetid: 22b801b7-e792-41f6-a461-973c03c69f25
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1197
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não pode fazer referência a “mscorlib.dll\_1” porque o programa já tem referenciado “mscorlib.dll\_2”  
  
 O compilador corresponde a uma versão do Common Language Runtime.  Porém, uma tentativa foi feita para fazer referência a uma versão de um arquivo de Common Language Runtime de uma versão anterior.  
  
 Para resolver este erro, os arquivos de referência da versão do Common Language Runtime que o é enviada com a versão do Visual C\+\+ estão criando com.  
  
## Exemplo  
 O seguinte exemplo gera C1197:  
  
```  
// C1197.cpp  
// compile with: /clr /c  
// processor: x86  
#using "C:\Windows\Microsoft.NET\Framework\v1.1.4322\mscorlib.dll"   // C1197  
// try the following line instead  
// #using "mscorlib.dll"  
```