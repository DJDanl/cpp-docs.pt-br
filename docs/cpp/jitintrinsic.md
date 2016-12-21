---
title: "jitintrinsic | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "jitintrinsic"
  - "jitintrinsic_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++], jitintrinsic"
  - "modificador jitintrinsic __declspec"
ms.assetid: 23dbe416-7ef6-442b-b16d-9a81aab04fa6
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# jitintrinsic
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Marca a função como significante para o Common Language Runtime de 64 bits.  Isso é usado em determinadas funções em bibliotecas fornecidas pela Microsoft.  
  
## Sintaxe  
  
```  
__declspec(jitintrinsic)  
```  
  
## Comentários  
 `jitintrinsic` adiciona um MODOPT \(<xref:System.Runtime.CompilerServices.IsJitIntrinsic>\) a uma assinatura de função.  
  
 Não é aconselhável que os usuários usem esse modificador `__declspec`, porque resultados inesperados podem ocorrer.  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)