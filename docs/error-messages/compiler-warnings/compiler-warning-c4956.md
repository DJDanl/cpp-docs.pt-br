---
title: "C4956 de aviso do compilador | Microsoft Docs"
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
  - "C4956"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4956"
ms.assetid: 9154f2d1-d49f-4e07-90d2-0e9bc028011a
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C4956 de aviso do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': esse tipo não é verificável  
  
 Esse aviso é gerado quando [\/CLR: safe](../../build/reference/clr-common-language-runtime-compilation.md) é especificado e seu código contiver um tipo que não possa ser verificado.  
  
 Para obter mais informações, consulte [Código puro e verificável](../../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
 Esse aviso é emitido como um erro e pode ser desabilitado com o [Aviso](../../preprocessor/warning.md) pragma ou [\/wd](../../build/reference/compiler-option-warning-level.md) opção de compilador.  
  
 O exemplo a seguir gera C4956:  
  
```  
// C4956.cpp // compile with: /clr:safe int* p;   // C4956  
```