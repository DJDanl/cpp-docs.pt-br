---
title: "Erro do Compilador C2679 | Microsoft Docs"
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
  - "C2679"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2679"
ms.assetid: 1a5f9d00-9190-4aa6-bc72-949f68ec136f
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2679
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

operador binário “”: nenhum operador detectou que tem um operando à direita do tipo “tipo” \(ou se não houver nenhuma conversão aceitável\)  
  
 Para usar o operador, você deve sobrecarregá\-la do tipo especificado ou definir uma conversão de em um tipo para o qual o operador está definido.  
  
 O seguinte exemplo gera C2679:  
  
```  
// C2679.cpp  
class C {  
public:  
   C();   // no constructor with an int argument  
} c;  
  
class D {  
public:  
   D(int) {}  
   D(){}  
} d;  
  
int main() {  
   c = 10;   // C2679  
   d = 10;   // OK  
}  
```