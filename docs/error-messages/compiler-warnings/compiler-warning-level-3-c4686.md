---
title: "Aviso do compilador (n&#237;vel 3) C4686 | Microsoft Docs"
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
  - "C4686"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4686"
ms.assetid: 767c83c2-9e4b-4f9e-88c8-02128ba563f4
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 3) C4686
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**'**   
 ***user\-defined type* ' : possible change in behavior, change in UDT return calling convention**  
  
 Uma classe a especialização de modelo que não foi definida antes que esteve usada em um tipo de retorno.  Qualquer coisa que cria uma instância da classe C4686; resolverá declarar uma instância ou acessar um membro \(\<\>Cint::anything\) também são opções.  
  
 Esse aviso é o resultado do trabalho para fazer o compilador do Visual C\+\+ .NET 2003 estar em conformidade com o padrão ISO C\+\+.  
  
 Esse aviso é desativada por padrão.  Consulte [Avisos do compilador que estão por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para obter mais informações.  
  
 Tente o seguinte,  
  
```  
// C4686.cpp  
// compile with: /W3  
#pragma warning (default : 4686)  
template <class T>  
class C;  
  
template <class T>  
C<T> f(T);  
  
template <class T>  
class C {};  
  
int main() {  
   f(1);   // C4686  
}  
  
template <class T>  
C<T> f(T) {  
   return C<int>();  
}  
```