---
title: "Erro do Compilador C3610 | Microsoft Docs"
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
  - "C3610"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3610"
ms.assetid: 9349a348-9d37-4a00-9eab-481039268d31
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3610
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

valuetype “”: o tipo de valor deve ser “encaixotado” antes do método “método pode ser chamado”  
  
 Por padrão, um tipo de valor não está no heap gerenciado.  Antes que você possa chamar métodos das classes de tempo de execução do. .NET, como `Object`, você precisa mover o tipo de valor para o heap gerenciado.  
  
 C3610 é somente **\/clr:oldSyntax**de utilização possível acessá\-lo.  
  
 O seguinte exemplo gera C3610:  
  
```  
// C3610.cpp  
// compile with: /clr:oldSyntax  
#using <mscorlib.dll>  
  
__value class A {};  
  
int main() {  
   A a;  
   a.GetType(); // C3610  
  
   // OK  
   __box A* ovar = __box(a);  
   ovar->GetType();  
}  
```