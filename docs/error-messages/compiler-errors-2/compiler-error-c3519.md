---
title: C3519 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3519
dev_langs:
- C++
helpviewer_keywords:
- C3519
ms.assetid: ca24b2bc-7e90-4448-ae84-3fedddf9bca7
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c655c8ba0513bcf25d5bc9666d65352a7f587374
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3519"></a>C3519 de erro do compilador
'invalid_param': parâmetro inválido para atributo embedded_idl  
  
 Foi passado um parâmetro para o `embedded_idl` atributo de [#import](../../preprocessor/hash-import-directive-cpp.md), mas o compilador não reconheceu o parâmetro.  
  
 Os únicos parâmetros que são permitidos para `embedded_idl` são `emitidl` e `no_emitidl`.  
  
 O exemplo a seguir gera C3519:  
  
```  
// C3519.cpp  
// compile with: /LD  
[module(name="MyLib2")];  
#import "C:\testdir\bin\importlib.tlb" embedded_idl("no_emitidcl")     
// C3519  
#import "C:\testdir\bin\importlib.tlb" embedded_idl("no_emitidl")     
// OK  
```
