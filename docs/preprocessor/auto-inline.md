---
title: "auto_inline | Microsoft Docs"
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
  - "auto_inline_CPP"
  - "vc-pragma.auto_inline"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "auto_inline (pragma)"
  - "pragmas, auto_inline"
ms.assetid: f7624cd1-be76-429a-881c-65c9040acf43
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# auto_inline
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Exclui quaisquer funções definidas dentro do intervalo onde **off** é especificado de ser considerado um candidato para a expansão embutida automática.  
  
## Sintaxe  
  
```  
  
#pragma auto_inline( [{on | off}] )  
```  
  
## Comentários  
 Para usar o pragma **auto\_inline**, coloque\-o antes e imediatamente após \(e não dentro\) de uma definição de função.  O pragma entra em vigor na primeira definição de função, após a consideração do pragma.  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)