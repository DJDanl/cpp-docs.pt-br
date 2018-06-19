---
title: C2488 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2488
dev_langs:
- C++
helpviewer_keywords:
- C2488
ms.assetid: cd435909-43e4-43c6-a57c-5d02468ef75f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7cb64ea76ae38901b2db14ec4b68bba9db69f39c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33225287"
---
# <a name="compiler-error-c2488"></a>C2488 de erro do compilador
'Identificador': 'naked' só pode ser aplicado às definições de função não membro  
  
 O [naked](../../cpp/naked-cpp.md) atributo foi aplicado a uma declaração de função.  
  
 O exemplo a seguir gera C2488:  
  
```  
// C2488.cpp  
// compile with: /c  
// processor: x86  
__declspec( naked ) void func();   // C2488  declaration, not definition  
__declspec( naked ) void i;   // C2488  i is not a function  
  
__declspec( naked ) void func() {}   // OK  
```