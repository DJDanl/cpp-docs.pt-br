---
title: Compilador aviso (nível 1 e nível 4) C4949 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4949
dev_langs:
- C++
helpviewer_keywords:
- C4949
ms.assetid: 34f45a05-c115-49cb-9f67-0bd4f0735d9b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3dbf80f85db7334d4bcb46402851cac601d258f2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33279640"
---
# <a name="compiler-warning-level-1-and-level-4-c4949"></a>Compilador C4949 de aviso (nível 1 e nível 4)
pragmas 'managed' e 'unmanaged' são significativos apenas quando compilado com ' / clr [: opção]'  
  
 O compilador ignora o [gerenciado](../../preprocessor/managed-unmanaged.md) e não gerenciados pragmas se o código-fonte não é compilado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md). Esse aviso é informativo.  
  
 O exemplo a seguir gera C4949:  
  
```  
// C4949.cpp  
// compile with: /LD /W1  
#pragma managed   // C4949  
```  
  
 Quando **#pragma não gerenciado** é usado sem **/clr**, C4949 é um aviso de nível 4.  
  
 O exemplo a seguir gera C4949:  
  
```  
// C4949b.cpp  
// compile with: /LD /W4  
#pragma unmanaged   // C4949  
```