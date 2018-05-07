---
title: C2500 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2500
dev_langs:
- C++
helpviewer_keywords:
- C2500
ms.assetid: 6bff8161-dc9a-48ca-91f1-fd2eefdbbc93
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8c05ffd59e415375dd3c7f94ae9bc377c0fc2b9e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2500"></a>C2500 de erro do compilador
'identifier1': 'identifier2' já é uma classe base direta  
  
 Uma classe ou estrutura aparece mais de uma vez em uma lista de classes base.  
  
 Uma base direta é um mencionado na lista de base. Uma base indireta é uma classe base de uma das classes na lista base.  
  
 Uma classe não pode ser especificada mais de uma vez como uma classe base direta. Uma classe pode ser usada como uma classe base indireta mais de uma vez.  
  
 O exemplo a seguir gera C2500:  
  
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