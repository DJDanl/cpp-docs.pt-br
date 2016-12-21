---
title: "C3888 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C3888"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3888"
ms.assetid: 40820812-79c5-4dcd-a19d-b4164d25fc8a
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3888 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'name': não há suporte para a expressão constante associada a este membro de dados literais pelo C \+ \+ \/ CLI  
  
 O *nome* membro de dados que é declarado com o [literal](../../windows/literal-cpp-component-extensions.md) palavra\-chave é inicializada com um valor que o compilador não oferece suporte. O compilador suporta apenas constante integral, enum ou tipos de cadeia de caracteres. A causa provável para o **C3888** erro é que o membro de dados é inicializado com uma matriz de bytes.  
  
### Para corrigir este erro  
  
1.  Verifique se o membro de dados literais declarada é um tipo com suporte.  
  
## Consulte também  
 [literal](../../windows/literal-cpp-component-extensions.md)