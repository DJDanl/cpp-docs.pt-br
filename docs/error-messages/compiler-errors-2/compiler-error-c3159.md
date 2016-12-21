---
title: "Erro do Compilador C3159 | Microsoft Docs"
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
  - "C3159"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3159"
ms.assetid: e115cc76-0021-4568-95fd-61a324c41a85
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3159
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“ponteiro”: a matriz dos ponteiros ao tipo de valor não pode ser declarada  
  
 Uma matriz dos ponteiros para um tipo de valor não pode ser declarado.  
  
 C3159 é somente **\/clr:oldSyntax**de utilização possível acessá\-lo.  
  
 O seguinte exemplo gera C3159:  
  
```  
// C3159.cpp  
// compile with: /clr:oldSyntax  
#using <mscorlib.dll>  
  
__value struct B {  
};  
  
void f( B*[] );   // C3159  
  
int main() {  
}  
```