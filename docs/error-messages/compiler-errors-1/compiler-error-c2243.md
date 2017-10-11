---
title: C2243 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2243
dev_langs:
- C++
helpviewer_keywords:
- C2243
ms.assetid: b90065bb-d251-4ba9-8b4c-280ee13fa9c0
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: d9725239c7e7b8899c23584aa56d26ed77bd757a
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2243"></a>C2243 de erro do compilador
conversão de 'tipo de conversão' de 'type1' em 'type2' existe, mas é inacessível  
  
 Proteção de acesso (`protected` ou `private`) impediu a conversão de um ponteiro para uma classe derivada para um ponteiro para a classe base.  
  
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
  
 Classes com base `protected` ou `private` acesso não são acessíveis aos clientes da classe derivada. Esses níveis de controle de acesso são usados para indicar que a classe base é um detalhe de implementação que deve ser visíveis para os clientes. Use derivação pública se desejar que os clientes da classe derivada para ter acesso a conversão implícita de um ponteiro de classe derivada em um ponteiro para a classe base.
