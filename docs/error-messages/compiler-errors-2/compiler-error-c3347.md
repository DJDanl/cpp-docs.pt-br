---
title: C3347 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3347
dev_langs:
- C++
helpviewer_keywords:
- C3347
ms.assetid: e939ad29-0b78-4681-9618-9bdae5675cee
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 75d81462324690ae126938ffeab5a8eea9334426
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3347"></a>C3347 de erro do compilador
'arg': necessário argumento não for especificado no atributo idl_module  
  
 Um argumento necessário não foi passado para o [idl_module](../../windows/idl-module.md) atributo.  
  
 O exemplo a seguir gera C3347:  
  
```  
// C3347.cpp  
// compile with: /c  
[module(name="xx")];  
  
[idl_module(dllname="x")];    // C3347  
// try the following line instead  
// [idl_module(name="test", dllname="x")];  
```
