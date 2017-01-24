---
title: "Aviso do compilador (n&#237;vel 4) C4233 | Microsoft Docs"
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
  - "C4233"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4233"
ms.assetid: 9aa51fc6-8ef3-43b5-bafb-c9333cf60de3
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4233
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

extensão não padrão usada: palavra\-chave “palavra\-chave” com suporte apenas em não C, C\+\+ 2.0  
  
 O compilador criou seu código\-fonte como C e 2.0 em vez de C\+\+, e você usou uma palavra\-chave que é válida apenas em C\+\+.  O compilador cria seu arquivo de origem como C se a extensão do arquivo de origem é .c ou você usa [\/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md).  
  
 Esse aviso é alto automaticamente em um erro.  Se você quiser alterar esse comportamento, use [aviso de \#pragma](../../preprocessor/warning.md).  Por exemplo, para fazer C4233 em um problema de aviso de nível 4,  
  
```  
#pragma warning(2:4233)  
```  
  
 em seu arquivo de código\-fonte.