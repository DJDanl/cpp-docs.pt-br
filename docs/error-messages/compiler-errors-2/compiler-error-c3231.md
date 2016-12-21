---
title: "Erro do Compilador C3231 | Microsoft Docs"
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
  - "C3231"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3231"
ms.assetid: fe5dc352-e634-45fa-9534-3da176294c98
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3231
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“arg”: o argumento de tipo de modelo não pode usar um parâmetro de tipo genérico  
  
 Os modelos são criados uma instância em tempo de compilação, mas os produtos genéricas serão instanciados em tempo de execução.  Consequentemente, não é possível gerar o código genérico que pode chamar o modelo porque o modelo não pode ser criada uma instância em tempo de execução quando o tipo genérico é conhecido por fim.  
  
 O seguinte exemplo gera C3231:  
  
```  
// C3231.cpp  
// compile with: /clr /LD  
template <class T> class A;  
  
generic <class T>  
ref class C {  
   void f() {  
      A<T> a;   // C3231  
   }  
};  
```