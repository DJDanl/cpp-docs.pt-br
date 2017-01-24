---
title: "Erro do Compilador C2500 | Microsoft Docs"
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
  - "C2500"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2500"
ms.assetid: 6bff8161-dc9a-48ca-91f1-fd2eefdbbc93
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2500
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identifier1”: o “identifier2” já é uma classe base direta  
  
 Uma classe ou estrutura aparecem mais de uma vez em uma lista de classes base.  
  
 Uma base direta é uma mencionada na lista de base.  Uma base indireta é uma classe base a partir de uma das classes na lista de base.  
  
 Uma classe não pode ser especificada como uma classe base direta mais de uma vez.  Uma classe pode ser usada como uma classe base indireta mais de uma vez.  
  
 O seguinte exemplo gera C2500:  
  
```  
// C2500.cpp  
// compile with: /c  
class A {};  
class B : public A, public A {};    // C2500  
  
// OK  
class C : public A {};  
class D : public A {};  
class E : public C, public D {};  
```