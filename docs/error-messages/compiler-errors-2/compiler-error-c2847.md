---
title: "Erro do Compilador C2847 | Microsoft Docs"
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
  - "C2847"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2847"
ms.assetid: 9ad9a0e0-8b16-49d9-a5be-f8eda2372aa9
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2847
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível aplicar sizeof gerenciado ou tipo WinRT 'class'  
  
 O [sizeof](../../cpp/sizeof-operator.md) operador obtém o valor de um objeto em tempo de compilação.  O tamanho de um gerenciado ou classe WinRT, interface ou tipo de valor é dinâmico e não pode ser conhecido em tempo de compilação.  
  
 Por exemplo, o exemplo a seguir gera C2847:  
  
```  
// C2847.cpp  
// compile with: /clr  
ref class A {};  
  
int main() {  
   A ^ xA = gcnew A;  
   sizeof(*xA);   // C2847 cannot use sizeof on managed object  
}  
```  
  
 O exemplo a seguir gera C2847:  
  
```  
// C2847_b.cpp  
// compile with: /clr:oldSyntax  
__gc class A {};  
  
int main() {  
   A *xA = new A;  
   sizeof(*xA);   // C2847 cannot use sizeof on managed object  
}  
```