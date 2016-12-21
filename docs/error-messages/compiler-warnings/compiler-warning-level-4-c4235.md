---
title: "Compilador C4235 de aviso (n&#237;vel 4) | Microsoft Docs"
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
  - "C4235"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4235"
ms.assetid: d4214799-d62c-4674-b4e2-9e201c303303
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4235 de aviso (n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

extensão não padrão usada: palavra\-chave “palavra\-chave” não tem suporte nesta arquitetura  
  
 O compilador não oferece suporte à palavra\-chave usado.  
  
 Esse aviso é alto automaticamente em um erro.  Se você quiser alterar esse comportamento, use [aviso de \#pragma](../../preprocessor/warning.md).  Por exemplo, para fazer C4235 em um nível 2 que a direita, use a seguinte linha de código  
  
```  
#pragma warning(2:4235)  
```  
  
 em seu arquivo de código\-fonte.