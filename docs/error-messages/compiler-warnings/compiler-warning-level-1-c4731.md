---
title: "Aviso C4731 (compilador) (n&#237;vel 1) | Microsoft Docs"
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
  - "C4731"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4731"
ms.assetid: 5658c24c-3e6f-4505-835b-1fb92d47cab0
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso C4731 (compilador) (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“ponteiro”: o registro “registro” do ponteiro do quadro alterado pelo código do assembly embutido  
  
 Um registro do ponteiro do quadro foi alterado.  Você deve salvar e restaurar o registro no bloco de variável embutida ou do quadro de assembly \(local ou parâmetro, dependendo do registro alterado\), ou seu código pode não funcionar corretamente.  
  
 O seguinte exemplo gera C4731:  
  
```  
// C4731.cpp  
// compile with: /W1 /LD  
// processor: x86  
// C4731 expected  
void bad(int p) {  
   __asm  
   {  
      mov ebp, 1  
   }  
  
   if (p == 1)  
   {  
      // ...  
   }  
}  
```  
  
 O EBP é o ponteiro do quadro \(FPO não é permitido\) e está sendo alterado.  Quando `p` é referenciado posteriormente, é referenciado em relação a `EBP`.  Mas `EBP` foi substituído pelo código, assim que o programa não funcionará corretamente e pode até mesmo criticar.