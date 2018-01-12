---
title: C2500 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2500
dev_langs: C++
helpviewer_keywords: C2500
ms.assetid: 6bff8161-dc9a-48ca-91f1-fd2eefdbbc93
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9a7be7320c21469536f6ddada99abd862812d882
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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