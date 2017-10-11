---
title: C2333 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2333
dev_langs:
- C++
helpviewer_keywords:
- C2333
ms.assetid: 2636fc1e-d3e7-4e68-8628-3c81a99ba813
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b1ed9e917ebf24509aa133dba18f9167d3a09736
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2333"></a>C2333 de erro do compilador
'function': erro na declaração de função; Ignorando o corpo da função  
  
 Esse erro ocorre após o outro erro, para funções de membro definido dentro de sua classe.  
  
 O exemplo a seguir gera C2333:  
  
```  
// C2333.cpp  
struct s1 {  
   s1(s1) {}   // C2333  
};  
```
