---
title: C3519 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: bbd140a0bd9509adddc11d71e3fdd043dff52450
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3519"></a>C3519 de erro do compilador
'invalid_param': parâmetro inválido para o atributo embedded_idl  
  
 Um parâmetro passado para o `embedded_idl` atributo de [#import](../../preprocessor/hash-import-directive-cpp.md), mas o compilador não reconhece o parâmetro.  
  
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
