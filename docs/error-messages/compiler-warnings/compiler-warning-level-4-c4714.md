---
title: "Aviso do compilador (n&#237;vel 4) C4714 | Microsoft Docs"
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
  - "C4714"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4714"
ms.assetid: 22c7fd0c-899d-4e9b-95f3-725b2c49fb46
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4714
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a função “function” marcada como \_\_forceinline será embutida  
  
 A função determinada foi selecionada para a expansão embutido, mas o compilador não executou inlining.  
  
 Embora `__forceinline` é uma indicação mais forte ao compilador do que `__inline`, inlining é executada na discreção do compilador, mas nenhuma heurística é usada para determinar os benefícios de inlining essa função.  
  
 Em alguns casos, o compilador não embutida uma função específica para razões mecânicas.  Por exemplo, o compilador não embutida:  
  
-   Uma função se você ficará com misturar ambos ELA e C\+\+ EH.  
  
-   Algumas funções com os objetos criados cópia passados pelo valor \- GX\/EHs\/EHa quando está ativado.  
  
-   Funções retornando um objeto unwindable pelo valor \- GX\/EHs\/EHa quando está ativado.  
  
-   Funções embutidas com assembly ao construir sem \- Og\/Ox\/O1\/O2.  
  
-   Funções com uma lista de argumento de variável.  
  
-   Uma função com uma instrução de **try** \(manipulação de exceção C\+\+\).  
  
 O seguinte exemplo gera C4714:  
  
```  
// C4714.cpp  
// compile with: /Ob1 /GX /W4  
__forceinline void func1()  
{  
   try  
   {  
   }  
   catch (...)  
   {  
   }  
}  
  
void func2()  
{  
   func1();   // C4714  
}  
  
int main()  
{  
}  
```