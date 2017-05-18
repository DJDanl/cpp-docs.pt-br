---
title: C2500 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2500
dev_langs:
- C++
helpviewer_keywords:
- C2500
ms.assetid: 6bff8161-dc9a-48ca-91f1-fd2eefdbbc93
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 5d705dfaf7c54e7bf50f89f088c2ca95096d0fea
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2500"></a>C2500 de erro do compilador
'identifier1': 'identifier2' já é uma classe base direta  
  
 Uma classe ou estrutura aparece mais de uma vez em uma lista de classes base.  
  
 Uma base direta é um mencionado na lista base. Uma base indireta é uma classe base de uma das classes na lista base.  
  
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
