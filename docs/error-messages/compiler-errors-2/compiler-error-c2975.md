---
title: "Erro do Compilador C2975 | Microsoft Docs"
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
  - "C2975"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2975"
ms.assetid: 526f6b9d-6c76-4c12-9252-1b1d7c1e06c7
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2975
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“arg”: argumento inválido do modelo para o tipo”, “expressão constante do tempo de compilação  
  
 O argumento do modelo não corresponde à declaração do modelo; uma expressão constante deve aparecer dentro dos colchetes angulares.  As variáveis não são permitidos como argumentos reais do modelo.  Verifique se a definição de modelo para encontrar os tipos corretos.  
  
 O seguinte exemplo gera C2975:  
  
```  
// C2975.cpp  
template<int I>  
class X {};  
  
int main() {  
   int i = 4, j = 2;  
   X<i + j> x1;   // C2975  
   X<6> x2;   // OK  
}  
```  
  
 C2975 também ocorrerá quando você usa o \_\_LINE como uma constante de tempo de compilação com [\/ZI](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md).  Uma solução seria compile com [\/Zi](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) em vez de **\/ZI**.  
  
```  
// C2975b.cpp  
// compile with: /ZI  
// processor: x86  
template<long line>   
void test(void) {}  
  
int main() {  
   test<__LINE__>();   // C2975  
}  
```