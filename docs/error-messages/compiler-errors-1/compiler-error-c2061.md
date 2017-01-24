---
title: "Erro do Compilador C2061 | Microsoft Docs"
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
  - "C2061"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2061"
ms.assetid: b0e61c0c-a205-4820-b9aa-301d6c6fe6eb
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2061
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

erro de sintaxe: identificador e a mensagem”  
  
 O compilador encontrou um identificador que não se espera.  Certifique\-se de que `identifier` é declarada antes que você use.  
  
 Um inicializador pode ser incluído por parênteses.  Para evitar esse problema, coloque o declarator entre parênteses ou faça\-lhe `typedef`.  
  
 Esse erro pode ser causado quando o compilador detectar uma expressão como um argumento de modelo da classe; o uso [typename](../Topic/typename.md) informar ao compilador é.  
  
 O seguinte exemplo gera C2061:  
  
```  
// C2061.cpp  
// compile with: /c  
template < A a >   // C2061  
// try the following line instead  
// template < typename b >  
class c{};  
```  
  
 C2061 pode ocorrer se você passar um nome de instância a [typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md):  
  
```  
// C2061b.cpp  
// compile with: /clr  
ref struct G {  
   int i;  
};  
  
int main() {  
   G ^ pG = gcnew G;  
   System::Type ^ pType = typeid<pG>;   // C2061  
   System::Type ^ pType2 = typeid<G>;   // OK  
}  
```