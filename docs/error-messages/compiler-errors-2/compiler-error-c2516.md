---
title: C2516 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2516
dev_langs:
- C++
helpviewer_keywords:
- C2516
ms.assetid: cd3accc1-0179-4a13-9587-616908c4ad1d
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 4d0e25a0c9e61a82d8d6bccec8d2501df1671ec2
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2516"></a>C2516 de erro do compilador
'name': não é uma classe base válida  
  
 A classe é derivada de um nome de tipo definido por um `typedef` instrução.  
  
 O exemplo a seguir gera C2516:  
  
```  
// C2516.cpp  
typedef unsigned long ulong;  
class C : public ulong {}; // C2516  
```
