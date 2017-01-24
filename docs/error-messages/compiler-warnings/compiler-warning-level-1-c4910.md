---
title: "Compilador C4910 de aviso (n&#237;vel 1) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4910"
ms.assetid: 67963560-fbca-4ca7-93db-06beaf7055f0
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4910 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'\< identificador \>': 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita  
  
 A instanciação explícita de modelo chamada *\< identificador \>* é modificado por ambos os `__declspec(dllexport)` e `extern` palavras\-chave. No entanto, essas palavras\-chave é mutuamente exclusivos. O `__declspec(dllexport)` palavra\-chave significa criar uma instância da classe de modelo, enquanto o `extern` meios de palavra\-chave não instanciar a classe de modelo automaticamente.  
  
## Consulte também  
 [Instanciação explícita](../Topic/Explicit%20Instantiation.md)   
 [dllexport, dllimport](../../cpp/dllexport-dllimport.md)   
 [Regras gerais e limitações](../../cpp/general-rules-and-limitations.md)