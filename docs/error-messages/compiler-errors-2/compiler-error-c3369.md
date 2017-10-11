---
title: C3369 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3369
dev_langs:
- C++
helpviewer_keywords:
- C3369
ms.assetid: c6ceb9cb-3df9-4334-9a5c-d16db351d476
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 62cd3de9bca4e695d051e150c7dfa45dca28936a
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3369"></a>C3369 de erro do compilador
nome do módulo: idl_module já definido  
  
 O [idl_module](../../windows/idl-module.md) onde você define a DLL de uso somente pode ocorrer uma vez em um programa.  
  
 O exemplo a seguir gera C3369:  
  
```  
// C3369.cpp  
// compile with: /c  
[idl_module(name="name1", dllname="x.dll")]; // C3369  
[idl_module(name="name1", dllname="x.dll")];  
```
