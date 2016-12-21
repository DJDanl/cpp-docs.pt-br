---
title: "Erro do Compilador C2663 | Microsoft Docs"
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
  - "C2663"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2663"
ms.assetid: 1e93e368-fd52-42bf-9908-9b6df467c8c9
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2663
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: as sobrecargas do número não têm nenhuma conversão legais para “esse ponteiro”  
  
 O compilador não pode converter `this` a algumas das versões sobrecarregadas da função de membro.  
  
 Esse erro pode ser causado invocando uma função de membro não de`const` em um objeto de `const` .  Resoluções possíveis:  
  
1.  Remover `const` de declaração do objeto.  
  
2.  Adicionar `const` a uma das sobrecargas da função de membro.  
  
 O seguinte exemplo gera C2663:  
  
```  
// C2663.cpp  
struct C {  
   void f() volatile {}  
   void f() {}  
};  
  
struct D {  
   void f() volatile;  
   void f() const {}  
};  
  
const C *pcc;  
const D *pcd;  
  
int main() {  
   pcc->f();    // C2663  
   pcd->f();    // OK  
}  
```