---
title: "Erro do Compilador C2790 | Microsoft Docs"
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
  - "C2790"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2790"
ms.assetid: 38d4fce1-ba00-413d-8bc1-e8aa43d7bc1f
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2790
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“super”: essa palavra\-chave só pode ser usado no corpo da função de membro da classe  
  
 Essa mensagem de erro será exibida se o usuário tentar nunca usa a palavra\-chave [super](../../cpp/super.md) fora do contexto de uma função de membro.  
  
 O seguinte exemplo gera C2790:  
  
```  
// C2790.cpp  
void f() {  
   __super::g();   // C2790  
}  
```