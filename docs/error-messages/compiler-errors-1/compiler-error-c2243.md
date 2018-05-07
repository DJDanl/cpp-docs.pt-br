---
title: C2243 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2243
dev_langs:
- C++
helpviewer_keywords:
- C2243
ms.assetid: b90065bb-d251-4ba9-8b4c-280ee13fa9c0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 16bc95540488b0723869c735b7fc80b15f6e763b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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