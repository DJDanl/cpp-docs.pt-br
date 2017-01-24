---
title: "Erro do Compilador C2243 | Microsoft Docs"
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
  - "C2243"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2243"
ms.assetid: b90065bb-d251-4ba9-8b4c-280ee13fa9c0
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2243
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

conversão de 'tipo de conversão' de 'type1' em 'type2' existe, mas está inacessível  
  
 Proteção de acesso \(`protected` ou `private`\) impediu a conversão de um ponteiro para uma classe derivada em um ponteiro para a classe base.  
  
 O exemplo a seguir gera C2243:  
  
```  
// C2243.cpp  
// compile with: /c  
class B {};  
class D : private B {};  
class E : public B {};  
  
D d;  
B *p = &d;   // C2243  
  
E e;  
B *p2 = &e;  
```  
  
 Classes com base `protected` ou `private` acesso não estão acessíveis para os clientes da classe derivada.  Esses níveis de controle de acesso são usados para indicar que a classe base é um detalhe de implementação deve ser invisível para os clientes.  Use derivação pública se desejar que os clientes da classe derivada para ter acesso a conversão implícita de um ponteiro de classe derivada em um ponteiro para a classe base.