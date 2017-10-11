---
title: C2504 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2504
dev_langs:
- C++
helpviewer_keywords:
- C2504
ms.assetid: c9e002a6-a4ee-4ba7-970e-edf4adb83692
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 0463c762cec98f60b0e8a3811f1f5c9b7e2cdea7
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2504"></a>C2504 de erro do compilador
'class': classe base indefinida  
  
 A classe base é declarada mas nunca foi definida.  Possíveis causas:  
  
1.  Faltando o arquivo de inclusão.  
  
2.  Classe base externo não declarado com [extern](../../cpp/using-extern-to-specify-linkage.md).  
  
 O exemplo a seguir gera C2504:  
  
```  
// C2504.cpp  
// compile with: /c  
class A;  
class B : public A {};   // C2504  
```  
  
 OKEY  
  
```  
class C{};  
class D : public C {};  
```
